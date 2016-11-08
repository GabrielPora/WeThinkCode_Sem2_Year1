/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_program.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 07:09:34 by khansman          #+#    #+#             */
/*   Updated: 2016/11/04 07:09:36 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "taskmaster.h"

vector<string> 	split(char *str, const char *delim) {
    char *save;
    char *tmp = strtok_r(str, delim, &save);
    vector<string> ret;

    while(tmp != NULL) {
        ret.push_back(tmp);
        tmp = strtok_r(NULL, delim, &save);
    }
    return (ret);
}

char			**get_program_args(string executable_path, string args) {
	char	**args_new;
	int		k = -1;
	char	**args_executable;
	vector<string> tmp;

	if (!(args_new = (char**)malloc(sizeof(char*) * DEFAULT_ARGS_SIZE)))
		return (NULL);
	while (args_new[++k])
		args_new[k] = NULL;
	args_new[0] = strdup(executable_path.c_str());
	tmp = split((char*)args.c_str(), " ");
	k = -1;
	while (++k != tmp.size())
		args_new[k + 1] = strdup(tmp[k].c_str()); 
	return (args_new);
}

char			**get_program_env(vector<string> data) {
	char	**new_env;
	int		k = -1;

	if (!(new_env = (char**)malloc(sizeof(char*) * 8192)))
		return (NULL);
	while (new_env[++k])
		new_env[k] = NULL;
	k = -1;
	while (++k != data.size())
		new_env[k] = strdup(data[k].c_str());
	new_env[k] = NULL;
	return (new_env);
}

vector<program>	handle_program(program to, int pos, vector<program> program_list) {
	int		f_stdout = 0;
	int		f_stderror = 0;
	pid_t	pid;
	int		status = 0;
	int		fd[2];

	if (program_list[pos].pid != 0) {
		print("Program " + program_list[pos].program_name + " already started");
	}
	TaskMasterValue::Current().ExitProgramOnError = false;
	if (check_folder(to.working_dir, to.program_name)) {
		add_in_logs(TaskMasterValue::Current().LogFilePath, "The program " +
			to.program_name + " was launched");
		to.Environment_Data = TaskMasterValue::Current().DefaultEnvironment;
		if (to.env_to_set.size())
			to.GetEnvToSet(to.env_to_set);
		if (to.stdout_to_file.length()) {
			f_stdout = open(to.stdout_to_file.c_str(), O_RDWR);
			if (f_stdout == -1) {
				close(f_stdout);
				if ((f_stdout = open(to.stdout_to_file.c_str(), O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO)) == -1)
					print_error(-1, "Can't set the stdout to the required file");
				else {
					close(f_stdout);
					f_stdout = open(to.stdout_to_file.c_str(), O_RDWR);
				}
			}
		}
		if (to.stderr_to_file.length()) {
			f_stderror = open(to.stderr_to_file.c_str(), O_RDWR);
			if (f_stderror == -1) {
				close(f_stderror);
				if ((f_stderror = open(to.stderr_to_file.c_str(), O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO) == -1))
					print_error(-1, "can't set stderror to rquired file");
				else {
					close(f_stderror);
					f_stderror = open(to.stderr_to_file.c_str(), O_RDWR);
				}
			}
		}
		pipe(fd);
		pid = fork();
		if (pid == 0) {
			char	**env;

			if (f_stdout)
				dup2(f_stdout, 1);
			if (f_stderror)
				dup2(f_stderror, 2);
			pid = getpid();
			ft_putnbr_fd(pid, fd[1]);
			close(fd[1]);
			if (to.set_umask.length())
				umask((unsigned short)atoi(to.set_umask.c_str()));
			env = get_program_env(to.Environment_Data);
			if (!to.print_on_taskmaster) {
				close(0);
				if (f_stdout == 0 || f_stdout == -1)
					close(1);
				if (f_stderror == 0 || f_stderror == -1)
					close(2);
			}
			chdir(to.working_dir.c_str());
			execve(to.executable_path.c_str(), get_program_args(to.executable_path, to.executable_argument), env);
			exit(program_list[pos].exit_code);
		}
		else {
			if (to.print_on_taskmaster)
				wait(&status);
			else {
				char	program_pid[1024];
				int		res = read(fd[0], program_pid, 1024);

				program_pid[res] = '\0';
				program_list[pos].pid = atoi(program_pid);
				print("Program " + to.program_name + " was successfully launched\n");
				return (program_list);
			}
		}
	}
	else {
		add_in_logs(TaskMasterValue::Current().LogFilePath, " Can't launch the program " + 
			to.program_name + "due to an invalid working directory\n");
		print("Can't launch the program " + to.program_name + "\n");
	}
	TaskMasterValue::Current().Errors = 0;
	return (program_list);
}
