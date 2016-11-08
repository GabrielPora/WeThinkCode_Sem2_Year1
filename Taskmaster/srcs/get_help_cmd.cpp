/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_help_cmd.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 07:08:55 by khansman          #+#    #+#             */
/*   Updated: 2016/11/04 07:08:56 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "taskmaster.h"

void	get_help_cmd(vector<string> args) {
	string	topic;
	int		k = -1;

	if (!args.size()) {
		print("\ndefault commands (type help):\n");
		print("=================================\n");
		print("status\tstart\tstop\treload\t\trestart\tedit\texit\t\n");
	}
	else {
		while (++k < args.size()) {
			if (args[k].length())
				topic += args[k];
			if ((k + 1) < args.size())
				topic += " ";
		}
		if (topic == "status") {
			print("status\t\tget all processes status\n");
			print("status <name>\tget status on multiple or single processes");
		}
		else if (topic == "start") {
			print("start <name>\tStart on multiple or single processes, by name\n");
			print("start all\t\tStart all processes");
		}
		else if (topic == "reload") {
			print("reload config\t\tReloads the config file");
		}
		else if (topic == "restart") {
			print("restart <name>\tRestart multiple or single processes by name\n");
			print("stop all\t\tRestarts all processes");
		}
		else if (topic == "edit") {
			print("edit <program_name> <variable;value>\t Edit or add a variable in a program");
		}
		else if (topic == "exit") {
			print("exit\t\tQuit Taskmaster");
		}
		else {
			print_fd("No help avaliable on " + topic, 2);
		}
	}
	topic.clear();
}
