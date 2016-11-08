/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 07:10:40 by khansman          #+#    #+#             */
/*   Updated: 2016/11/04 07:10:41 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "taskmaster.h"

vector<program>	reload(vector<string> args, vector<program> program_list) {
	vector<program>	new_list;
	config_infos	config;

	if (!args.size())
		print_fd("Missing Arguments", 2);
	else if (args[0] == "config") {
		TaskMasterValue::Current().ExitProgramOnError = false;
		config.config_file_name = TaskMasterValue::Current().ConfigFileName;
		if (config.check_if_config_exist())
			new_list = config.read_config(new_list);
		check_all_program(new_list);
		if (TaskMasterValue::Current().Errors == 0) {
			print("Config file has been reloaded");
			add_in_logs(TaskMasterValue::Current().LogFilePath, "The Config file was reloaded.");
			return (new_list);
		}
		else {
			print("\n Can't reload the config file die to ");
			ft_putstr_fd((const char *)ft_itoa(TaskMasterValue::Current().Errors), 1);
			print("errors");
			TaskMasterValue::Current().Errors = 0;
		}
	}
	else
		print_fd("Invalid arguments", 2);
	return (program_list);
}
