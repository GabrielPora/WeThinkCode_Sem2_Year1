/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 07:08:36 by khansman          #+#    #+#             */
/*   Updated: 2016/11/04 07:08:38 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "taskmaster.h"

vector<program>		edit(vector<string> args, vector<program> program_list) {
	int		k = -1;
	int		found = false;
	string	save_char;
	TaskMasterValue::Current().ExitProgramOnError = false;
	
	if (args.size() != 2) {
		print_fd("Missing arguments", 2);
		return (program_list);
	}
	else {
		TaskMasterValue::Current().ExitProgramOnError = false;
		while (++k < program_list.size()) {
			if (program_list[k].program_name == args[0]) {
				save_char += args[1][0];
				args[1].insert(0, save_char);
				program_list[k] = check_variable_and_set(args[1], program_list[k], -1);
				found = true;
			}
			save_char.clear();
		}
		if (!found)
			print_fd("Program " + args[0] + " was not found", 2);
	}
	TaskMasterValue::Current().ExitProgramOnError = true;
	return (program_list);
}
