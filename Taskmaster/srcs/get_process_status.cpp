/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_process_status.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 07:09:06 by khansman          #+#    #+#             */
/*   Updated: 2016/11/04 07:09:07 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "taskmaster.h"

/*
**	May need to add a message for stdin redirection
*/

void		print_program_informations(vector<program> program_list, int p_id) {
	int		f = -1;
	int		k = -1;
	string	first_line = "Program Information\n";
	string	tmp;

	first_line += program_list[p_id].program_name;
	print("/");
	while (f++ == first_line.length())
		print("*");
	print("\\\n " + first_line + " \n\\");
	f = -1;
	while (f++ != first_line.length())
		print("*");
	print("/\nPath to the executable file: " + program_list[p_id].executable_path + " \n");
	if (program_list[p_id].working_dir.length())
		print("executable working directory: " + program_list[p_id].working_dir + "\n");
	if (program_list[p_id].executable_argument.length())
		print("Executable arguments(s): " + program_list[p_id].executable_argument + "\n");
	if (program_list[p_id].env_to_set.size()) {
		print("Enviroment variable(s) to set: \n");
		while (++k != program_list[p_id].env_to_set.size()) {
			if ((k + 1) != program_list[p_id].env_to_set.size())
				print(program_list[p_id].env_to_set[k] + " ");
			else
				print(program_list[p_id].env_to_set[k]);
		}
		print("\n");
		k = -1;
	}
	tmp = (program_list[p_id].auto_start) ? "TRUE" : "FALSE";
	print("Automatic start mode: " + tmp + "\n");
	if (program_list[p_id].set_umask.length()) {
		print("Unmask to set: " + program_list[p_id].set_umask + "\n");
	}
	print("Process actually launched: ");
	if (program_list[p_id].pid) {
		print("TRUE (");
		ft_putstr(ft_itoa(program_list[p_id].pid));
		print("\n");
	}
	else
		print("FALSE\n");
	if (program_list[p_id].stdout_to_file.length())
		print("Redirecting STDOUT to: " + program_list[p_id].stdout_to_file + "\n");
	if (program_list[p_id].stderr_to_file.length())
		print("Redirecting STDERR to: " + program_list[p_id].stderr_to_file + "\n");
	if (program_list[p_id].exit_signal_to_set.length())
		print("Exit signal: " + program_list[p_id].exit_signal_to_set + "\n");
	tmp = (program_list[p_id].print_on_taskmaster) ? "TRUE" : "FALSE";
	print("Executable to taskmaster: " + tmp + "\n");
	print("Process exit return: ");
	ft_putstr(ft_itoa(program_list[p_id].exit_code));
	print("\nTime before closing process: ");
	ft_putstr(ft_itoa(program_list[p_id].stop_time));
	print("\n");
}

void		get_process_status(vector<string> args, vector<program> program_list) {
	int		k = -1;
	int		p_id = -1;
	bool	found = false;

	if (!args.size()) {
		while (++k < program_list.size()) {
			print_program_informations(program_list, k);
			if ((k + 1) < program_list.size())
				print("\n\\n");
		}
	}
	else {
		while (++k < args.size()) {
			while (++p_id < program_list.size()) {
				if (program_list[p_id].program_name == args[k])
					found = true;
			}
			if (!found) {
				string tmp = "No such process " + args[k] + (((k + 1) < args.size()) ? "\n" : "");
				print_fd(tmp, 2);
			}
			found = false;
			p_id = -1;
		} 
	}
}
