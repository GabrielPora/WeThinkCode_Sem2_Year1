/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restart_program.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 07:10:45 by khansman          #+#    #+#             */
/*   Updated: 2016/11/04 07:10:46 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "taskmaster.h"

vector<program>	restart_program(vector<string> args, vector<program> program_list) {
	if (!args.size() || !args[0].length())
		print_fd("Missing arguments", 2);
	else {
		program_list = stop_program(args, program_list);
		print("\n");
		program_list = start_program(args, program_list);
	}
	return (program_list);
}
