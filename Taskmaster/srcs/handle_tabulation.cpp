/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_tabulation.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 07:09:44 by khansman          #+#    #+#             */
/*   Updated: 2016/11/04 07:09:46 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "taskmaster.h"

static void		update_stdout() {
	int		k = -1;

	refresh_stdout();
	UserEntry::Current().cursor++;
	while (UserEntry::Current().cursor) {
		UserEntry::Current().cursor--;
		tputs(tgetstr((char *)"le", NULL), 0, cursor_do);
	}
	while (++k != UserEntry::Current().cmd.length()) {
		UserEntry::Current().cursor++;
		tputs(tgetstr((char *)"nd", NULL), 0, cursor_do);
	}
}

static void		delete_name(vector<program> program_list) {
	int		k = UserEntry::Current().cmd.length() + 1;

	while (UserEntry::Current().cmd[--k] != ' ') {
		tputs(tgetstr((char *)"de", NULL), 0, cursor_do);
		tputs(tgetstr((char *)"le", NULL), 0, cursor_do);
		UserEntry::Current().cmd[k] = '\0';
		UserEntry::Current().cmd.erase(k, 1);
	}
	UserEntry::Current().cmd[++k] = '\0';
	UserEntry::Current().cmd.erase(k, 1);
	UserEntry::Current().cmd.insert(k, program_list[UserEntry::Current().auto_completion_get].program_name + "\0");
	print(" ");
	k = -1;
	while (program_list[UserEntry::Current().auto_completion_get].program_name[++k])
		write(1, &program_list[UserEntry::Current().auto_completion_get].program_name[k], 1);
	UserEntry::Current().cursor = 0;
	k = -1;
	while (++k != UserEntry::Current().cmd.length())
		UserEntry::Current().cursor++;
}

void			get_command() {
	if (UserEntry::Current().cmd == "edit")
		UserEntry::Current().cmd = "exit";
	else if (UserEntry::Current().cmd == "status")
		UserEntry::Current().cmd = "start";
	else if (UserEntry::Current().cmd == "reload")
		UserEntry::Current().cmd = "restart";
	else if (UserEntry::Current().cmd == "restart")
		UserEntry::Current().cmd = "reload";
	else if (UserEntry::Current().cmd == "exit")
		UserEntry::Current().cmd = "edit";
	else if (UserEntry::Current().cmd == "start")
		UserEntry::Current().cmd = "stop";
	else if (UserEntry::Current().cmd == "stop")
		UserEntry::Current().cmd = "status";
	else if (UserEntry::Current().cmd[0] == 'h' && UserEntry::Current().cmd.length() < 4)
		UserEntry::Current().cmd = "help";
	else if (UserEntry::Current().cmd[0] == 's' && UserEntry::Current().cmd.length() < 4)
		UserEntry::Current().cmd = "status";
	else if (UserEntry::Current().cmd[0] == 'e' && UserEntry::Current().cmd.length() < 4)
		UserEntry::Current().cmd = "edit";
	else if (UserEntry::Current().cmd[0] == 'r' && UserEntry::Current().cmd.length() < 4)
		UserEntry::Current().cmd = "restart";
	else
		return ;
	update_stdout();
}

void			get_program_name(vector<program> program_list) {
	if (UserEntry::Current().auto_completion_get != program_list.size()) {
		if ((UserEntry::Current().cmd.find(' ') != -1) && !UserEntry::Current().cmd[(UserEntry::Current().cursor + 1)])
			delete_name(program_list);
		UserEntry::Current().auto_completion_get++;
	}
	else
		UserEntry::Current().auto_completion_get = 0;
}
