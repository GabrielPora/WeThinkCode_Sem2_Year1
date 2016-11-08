/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_program.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 07:10:52 by khansman          #+#    #+#             */
/*   Updated: 2016/11/04 07:10:53 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "taskmaster.h"

vector<program>	start_program(vector<string> args, vector<program> program_list) {
	int		k = -1;
	int		l = -1;
	bool	found = false;

	if (!args.size())
		print_fd("Missing Arguments", 2);
	else if (args[0] == "all") {
		if (!program_list.size()) {
			print_error(-1, "No processes to launch");
			add_in_logs(TaskMasterValue::Current().LogFilePath, "No processes to launch");
		}
		while (++k < program_list.size())
			program_list = handle_program(program_list[k], k, program_list);
	}
	else {
		while (++k < args.size()) {
			while (++l < program_list.size())
				if (program_list[l].program_name == args[k] && (found = true))
					program_list = handle_program(program_list[l], l, program_list);
			if (!found) {
				string tmp = "Process " + args[k] + "not_found" + (((k + 1) < args.size()) ? "\n" : "");
				print_fd(tmp, 2);
				add_in_logs(TaskMasterValue::Current().LogFilePath, "No process (" + args[k] + ")");
			}
			l = -1;
			found = false;
		}
	}
	return (program_list);
}
