/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 07:08:20 by khansman          #+#    #+#             */
/*   Updated: 2016/11/04 07:08:21 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "taskmaster.h"

vector<string>	clear_args(vector<string> cmd_args) {
	int		k;

	k = -1;
	while (++k < cmd_args.size()) {
		cmd_args[k] = "\0";
	}
	return (cmd_args);
}

static void		exit_taskmaster() {
	add_in_logs(TaskMasterValue::Current().LogFilePath, "Taskmaster exited.");
	exit(0);
}

void			exec_cmd(string cmd) {
	extern char		**environ;

	char 			**cm = ft_strsplit(((const char *)cmd.c_str()), ' ');

	cm[0] = find_path(cm[0]);
	if (fork() == 0) {
		execve(cm[0], cm, environ);
		print_fd("Error: unknown syntax: " + cmd + "\n", 2);
		exit(1);
	}
	else {
		wait(0);
	}
}

vector<program>	check_cmd(string cmd, vector<string> cmd_args, vector<program> program_list, string orig_cmd) {
	write(1, "\n", 1);
	if (cmd == "help")
		get_help_cmd(cmd_args);
	else if (cmd == "status")
		get_process_status(cmd_args, program_list);
	else if (cmd == "reload")
		program_list = reload(cmd_args, program_list);
	else if (cmd == "start")
		program_list = start_program(cmd_args, program_list);
	else if (cmd == "stop")
		program_list = stop_program(cmd_args, program_list);
	else if (cmd == "restart")
		program_list = restart_program(cmd_args, program_list);
	else if (cmd == "exit")
		exit_taskmaster();
	else if (cmd== "edit")
		program_list = edit(cmd_args, program_list);
	else
		exec_cmd(orig_cmd);
	cmd_args = clear_args(cmd_args);
	cmd_args.clear();
	return (program_list);
}
