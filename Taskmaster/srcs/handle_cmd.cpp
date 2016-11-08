/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 07:09:24 by khansman          #+#    #+#             */
/*   Updated: 2016/11/04 07:09:25 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "taskmaster.h"

string			get_cmd(string cmd) {
	int				k = -1;
	string			tmp;

	while (cmd[++k] && cmd[k] != ' ')
		tmp += cmd[k];
	return (tmp);
}

vector<string>	get_args(string cmd) {
	int				k = -1;
	string			tmp;
	vector<string>	tmp_args;

	while (cmd[++k] && cmd[k] != ' ');
	while (cmd[++k]) {
		if (cmd[k] != ' ') {
			k--;
			while (cmd[++k] && cmd[k] != ' ')
				tmp += cmd[k];
			if (ft_is_all_print((char *)tmp.c_str()) || tmp.find(';') != -1)
				tmp_args.push_back(tmp);
			tmp.clear();
		}
	}
	return (tmp_args);
}

vector<program>	handle_cmd(string cmd, vector<program> program_list) {
	string			cmd_to = get_cmd(cmd);
	vector<string>	cmd_args = get_args(cmd);

	return (check_cmd(cmd_to, cmd_args, program_list, cmd));
}
