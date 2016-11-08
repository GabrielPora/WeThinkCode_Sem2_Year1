/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_config.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 07:09:29 by khansman          #+#    #+#             */
/*   Updated: 2016/11/04 07:09:30 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "taskmaster.h"

bool	program_to_auto_start(vector<program> program_list) {
	int		k = -1;

	while (++k < program_list.size())
		if (program_list[k].auto_start)
			return (true);
	return (false);
}

/*
**	Check if it can handle multiple auto restarting programs...
*/

void	auto_restart_program(vector<program> program_list) {
	pid_t	pid;
	int		fd;
	int		k;
	vector<string> args;

	args.push_back("default");
	if ((pid = fork()) == 0) {
		while (1) {
			k = -1;
			while (++k != program_list.size()) {
				if (program_list[k].auto_restart) {
					if (program_list[k].time_for_restart != 0)
						sleep(program_list[k].time_for_restart);
					if (program_list[k].pid == 0) {
						args[0] = program_list[k].program_name;
					}
					fd = dup(1);
					close(1);
					program_list = start_program(args, program_list);
					dup2(fd, 1);
					print("The program " + program_list[k].program_name + " was automatically started");
				}
			}
		}
	}
}

void	handle_config(string config_name) {
	config_infos config;
	vector<program> program_list;
	int		k = -1;

	config.config_file_name = config_name;
	TaskMasterValue::Current().ExitProgramOnError = true;
	UserEntry::Current().auto_completion_get = 0;
	if (config.check_if_config_exist())
		program_list = config.read_config(program_list);
	if (!TaskMasterValue::Current().LogFilePath.length())
		TaskMasterValue::Current().LogFilePath = "taskmaster.log";
	if (!TaskMasterValue::Current().LogFilePathExist)
		add_in_logs(TaskMasterValue::Current().LogFilePath, "Config file generated");
	if (check_all_program(program_list)) {
		if (program_to_auto_start(program_list)) {
			print("Auto started programs:\n");
			while (++k < program_list.size())
				if (program_list[k].auto_start)
					program_list = handle_program(program_list[k], k, program_list);
			print("end of auto start list\n");
		}
		auto_restart_program(program_list);
		TaskMasterValue::Current().ConfigFileName = config_name;
		print("taskmaster> ");
		read_user_entry(program_list);
	}
}
