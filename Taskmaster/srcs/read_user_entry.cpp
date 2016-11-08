/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_user_entry.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 07:10:35 by khansman          #+#    #+#             */
/*   Updated: 2016/11/04 07:10:37 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "taskmaster.h"

int		get_ascii_value(string tmp_line) {
	int		k = -1;
	int		value = 0;

	while (tmp_line.c_str()[++k])
		value += tmp_line.c_str()[k];
	return (value);
}

int		cursor_do(int to_print) {
	write(1, &to_print, 1);
	return (to_print);
}

void	refresh_stdout() {
	int		tmp = UserEntry::Current().cursor + 1;

	tputs(tgetstr((char *)"sc", NULL), 0, cursor_do);
	while (--tmp)
		tputs(tgetstr((char *)"le", NULL), 0, cursor_do);
	tputs(tgetstr((char *)"cd", NULL), 0, cursor_do);
	print(UserEntry::Current().cmd);
	tputs(tgetstr((char *)"rc", NULL), 0, cursor_do);
	tputs(tgetstr((char *)"nd", NULL), 0, cursor_do);
}

void	delete_x_characters(int to_del) {
	tputs(tgoto((char *)tgetstr((char *)"DC", NULL), 0, to_del), 1, cursor_do);
}

void	delete_current_and_print_history(string to_set, string tmp) {
	int		k = -1;

	if (!UserEntry::Current().cmd.length() && !tmp.length()) {
		UserEntry::Current().cursor = 0;
		while (++k < to_set.length()) {
			write(1, &to_set[k], 1);
			UserEntry::Current().cursor++;
		}
		UserEntry::Current().cmd.clear();
		UserEntry::Current().cmd = to_set;
	}
	else {
		while (k++ != UserEntry::Current().cmd.length())
			tputs(tgetstr((char *)"le", NULL), 0, cursor_do);
		tputs(tgetstr((char *)"cd", NULL), 0, cursor_do);
		UserEntry::Current().cursor = 0;
		k = -1;
		while (++k < to_set.length()) {
			write(1, &to_set[k], 1);
			UserEntry::Current().cursor++;
		}
		UserEntry::Current().cmd.clear();
		UserEntry::Current().cmd = to_set;
	}
}

void	read_entry(string tmp_line, vector<program> program_list) {
	struct termios	*term;
	int				ascii_value;
	int				tmp;

	tmp_line.clear();
	if (!(term = (struct termios *)malloc(sizeof(struct termios))))
		return ;
	if (!(tgetent(NULL, getenv("TERM"))))
		return ;
	tcgetattr(0, term);
	term->c_lflag &= ~(ICANON | ECHONL);
	tcsetattr(0, TCSANOW, term);
	read(0, (void *)tmp_line.c_str(), 16);
	ascii_value = get_ascii_value(tmp_line);
	if (ascii_value == ENTRY)
		UserEntry::Current().end_cmd = true;
	else if (ascii_value == ARROW_LEFT && UserEntry::Current().cursor) {
		tputs(tgetstr((char *)"le", NULL), 0, cursor_do);
		UserEntry::Current().cursor--;
	}
	else if (ascii_value == ARROW_RIGHT && (UserEntry::Current().cmd[(UserEntry::Current().cursor + 1)] ||
			UserEntry::Current().cursor == (UserEntry::Current().cmd.length() -1))) {
		tputs(tgetstr((char *)"nd", NULL), 0, cursor_do);
		UserEntry::Current().cursor++;
	}
	else if (ascii_value == BACKSPACE) /* && (UserEntry::Current().cmd[(UserEntry::Current().cursor -1)]) &&
			UserEntry::Current().cursor >= 1)*/ {
/*		UserEntry::Current().cmd.erase((UserEntry::Current().cursor -1), 1);
		tmp = UserEntry::Current().cursor;
		tputs(tgetstr((char *)"sc", NULL), 0, cursor_do);
		while (UserEntry::Current().cursor >= 1) {
			tputs(tgetstr((char *)"le", NULL), 0, cursor_do);
			UserEntry::Current().cursor--;
		}
		if (!UserEntry::Current().cmd.length())
			delete_x_characters(1);
		else
			delete_x_characters(UserEntry::Current().cmd.length());
		print(UserEntry::Current().cmd);
		UserEntry::Current().cursor = tmp;
		tputs(tgetstr((char *)"rc", NULL), 0, cursor_do);
		tputs(tgetstr((char *)"le", NULL), 0, cursor_do);
		UserEntry::Current().cursor--;
		if (UserEntry::Current().cmd.length())
			UserEntry::Current().cursor = 0;*/
/*		print("\nCursor = '");
		ft_putstr(ft_itoa(UserEntry::Current().cursor));
		print("'\n");*/
		if (UserEntry::Current().cursor) {
			UserEntry::Current().cmd[UserEntry::Current().cursor] = '\0';
			if (UserEntry::Current().cursor-- + 1) {
				print("\b \b");
				UserEntry::Current().cmd[UserEntry::Current().cursor] = '\0';
			}
			else
				UserEntry::Current().cmd.clear();
		}
		print("\b\b  \b\b");
	}
	else if (ascii_value == CLEAR_SCREEN) {
		print(TO_PRINT_FOR_CLEAR);
		tputs(tgoto((char *)tgetstr((char *)"cm", NULL), 0, 0), 1, cursor_do);
		print("taskmaster> ");
		print(UserEntry::Current().cmd);
	}
	else if (ascii_value == ARROW_UP) {
		print("\b\b\b\b    \b\b\b\b\rtaskmaster> ");
		if (!UserEntry::Current().cmd_history.size() || !UserEntry::Current().history_pos)
			return ;
		if (UserEntry::Current().cmd_history[(UserEntry::Current().history_pos -1)].length() &&
				UserEntry::Current().history_pos <= UserEntry::Current().cmd_history.size()) {
			UserEntry::Current().history_pos--;
			delete_current_and_print_history(UserEntry::Current().cmd_history[(UserEntry::Current().history_pos)], tmp_line);
		}
		print("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                    \rtaskmaster> " + UserEntry::Current().cmd);
	}
	else if (ascii_value == ARROW_DOWN) {
		print("\b\b\b\b    \b\b\b\b\rtaskmaster> ");
		if (!UserEntry::Current().cmd_history.size())
			return ;
		if ((UserEntry::Current().history_pos + 1) > (UserEntry::Current().cmd_history.size() - 1))
			return ;
		if (UserEntry::Current().cmd_history[(UserEntry::Current().history_pos + 1)].length() &&
				UserEntry::Current().history_pos <= UserEntry::Current().cmd_history.size()) {
			UserEntry::Current().history_pos++;
			delete_current_and_print_history(UserEntry::Current().cmd_history[UserEntry::Current().history_pos], tmp_line);
		}
		print("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                    \rtaskmaster> " + UserEntry::Current().cmd);
	}
	else if (ascii_value == TABULATION) {
		(UserEntry::Current().cursor > 0) ? print("\b\b\b\b\b") : print("\b\b\b\b");
		((UserEntry::Current().cmd.find(' ')) == -1) ? get_command() : get_program_name(program_list);
	}
	else if (isprint(ascii_value)) {
		/*if (UserEntry::Current().cursor <= 1) {
			int	k = UserEntry::Current().cmd.length();
			while (--k >= 0)
				UserEntry::Current().cmd = '\0';
			UserEntry::Current().cursor = 0;
		}*/
		if (UserEntry::Current().cmd[(UserEntry::Current().cursor + 1)]) {
			UserEntry::Current().cmd.insert(UserEntry::Current().cursor, 1, tmp_line[0]);
			refresh_stdout();
			UserEntry::Current().cursor++;
		}
		else {
			print(tmp_line);
			UserEntry::Current().cmd += tmp_line[0];
			UserEntry::Current().cursor++;
		}
	}
}

void	handle_history() {
	if (UserEntry::Current().cmd.length()) {
		UserEntry::Current().cmd_history.push_back(UserEntry::Current().cmd);
		UserEntry::Current().history_pos = UserEntry::Current().cmd_history.size();
	}
}

/*
** Change to reset_userinput
*/

void	reset_value() {
	int		k = -1;

	UserEntry::Current().end_cmd = false;
	UserEntry::Current().cursor = 0;
	while (UserEntry::Current().cmd[++k])
		UserEntry::Current().cmd[k] = '\0';
	UserEntry::Current().cmd.clear();
	UserEntry::Current().auto_completion_get = 0;
}

string	trim(const string &s) {
	string::const_iterator			k = s.begin() -1;
	string::const_reverse_iterator	l = s.rbegin() -1;

	while (++k < s.end() && isspace(*k));
	while (++l, l.base() != k && isspace(*l));
	return (string(k, l.base()));
}

void	read_user_entry(vector<program> program_list) {
	string	tmp;

	read_entry(tmp, program_list);
	if (UserEntry::Current().end_cmd) {
		UserEntry::Current().cmd = trim(UserEntry::Current().cmd);
		if (UserEntry::Current().cmd.length())
			program_list = handle_cmd(UserEntry::Current().cmd, program_list);
		print("\ntaskmaster> ");
		handle_history();
		reset_value();
	}
	read_user_entry(program_list);
}
