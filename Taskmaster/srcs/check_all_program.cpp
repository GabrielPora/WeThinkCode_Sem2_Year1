/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_program.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 07:08:12 by khansman          #+#    #+#             */
/*   Updated: 2016/11/04 07:08:14 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "taskmaster.h"

bool check_all_program(vector<program> program_list) {
	int		k;

	k = -1;
	while (++k != program_list.size()) {
		if (!program_list[k].program_name.length())
			print_error(-1, "taskmaster: missing program");
		if (!program_list[k].executable_path.length())
			print_error(-1, "taskmaster: missing executable path" +
				program_list[k].program_name);
	}
	return (k > 0);
}
