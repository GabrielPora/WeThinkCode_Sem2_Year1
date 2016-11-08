/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_program_args.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 07:09:11 by khansman          #+#    #+#             */
/*   Updated: 2016/11/04 07:09:13 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "taskmaster.h"

/*
**	Need to find why 7777 is relavent to umask
*/

static int		get_variable_state(string var) {
	if (var == "executable_path")
		return (EXECUTABLE_PATH);
	else if (var == "executable_argument")
		return (EXECUTABLE_ARGUMENT);
	else if (var == "set_env")
		return (SET_ENV);
	else if (var == "working_dir")
		return (WORKING_DIR);
	else if (var == "auto_start")
		return (AUTO_START);
	else if (var == "set_umask")
		return (SET_UMASK);
	else if (var == "stdout_to_file")
		return (STDOUT_TO);
	else if (var == "stderr_to_file")
		return (STDERROR_TO);
	else if (var == "close_stderror")
		return (STDERROR_CLOSE);
	else if (var == "close_stdout")
		return (STDOUT_CLOSE);
	else if (var == "print_on_taskmaster")
		return (PRINT_ON_TASKMASTER);
	else if (var == "exit_signal")
		return (EXIT_SIGNAL);
	else if (var == "auto_restart")
		return (AUTO_RESTART);
	else if (var == "start_time")
		return (START_TIME);
	else if (var == "stop_time")
		return (STOP_TIME);
	else if (var == "exit_code")
		return (EXIT_CODE);
	else
		return (UNKNOWN_VARIABLE);
}

program			check_variable_and_set(string line, program tmp, int pos) {
	vector<string>	args;
	int				k = -1;
	bool			found = false;
	struct stat		*current;

	args = get_args(line, args, ';');
	switch (get_variable_state(args[0])) {
		case EXECUTABLE_PATH:
			if (args.size() == 3 && args[1].length()) {
				args[1] = get_correct_path(args[1]);
				if (!(current = (struct stat*)malloc(sizeof(struct stat))))
					return (tmp);
				if (lstat(args[1].c_str(), current) < 0)
					print_error(-1, "taskmaster: invalid executable path");
				if (S_ISDIR(current->st_mode))
					print_error(-1, "taskmaster: executable file is a dicrectory.");
				else if (!(current->st_mode & S_IRUSR))
					print_error(-1, "taskmaster: executable path permissions denied.");
				tmp.executable_path = args[1];
			}
			else {
				if (args.size() != 3)
					print_error(pos, "taskmaster: executable_path can only take one argument");
				else
					print_error(pos, "taskmaster: executable_path arguments are missing");
			}
		break;
		case EXECUTABLE_ARGUMENT:
			if (args.size() == 3) {
				if (args[1].length())
					tmp.executable_argument = args[1];
				else
					print_error(pos, "taskmaster: executable_arguments are set, but are missing");
			}
			else
				print_error(pos, "taskmaster: bad syntax on executable argument");
		break;
		case SET_ENV:
			if (args.size() == 4) {
				if (args[1].length() && args[2].length())
					tmp.env_to_set.push_back(args[1] + "," + args[2]);
				else
					print_error(pos, "taskmaster: set_env arguments are set, but missing");
			}
			else
				print_error(pos, "taskmaster: bad syntax on set_env");
		break;
		case WORKING_DIR:
			if (args.size() == 3 && args[1].length()) {
				if (!(current = (struct stat *)malloc(sizeof(struct stat))))
					return (tmp);
				args[1] = get_correct_path(args[1]);
				if (lstat(args[1].c_str(), current) < 0)
					print_error(pos, "taskmaster: invalid working dir path");
				if (S_ISLNK(current->st_mode))
					print_error(-1, "taskmaster: set working dir is a suymbolic link");
				if (!(current->st_mode & S_IRUSR))
					print_error(-1, "taskmaster: working dir permissions denied");
				if (S_ISDIR(current->st_mode))
					tmp.working_dir = args[1];
			}
			else {
				if (!(args.size() == 3))
					print_error(pos, "taskmaster: bad syntax on working dir");
				else
					print_error(pos, "taskmaster: working_dir arguments are set, but missing");
			}
		break;
		case AUTO_START:
			if (args[1] == "true")
				tmp.auto_start = true;
		break;
		case SET_UMASK:
			if (args.size() == 3 && args[1].length()) {
				if (atoi(args[1].c_str()) <= 7777)
					tmp.set_umask = args[1];
				else
					print_error(pos, "taskmaster: invalid permissions on set_umask");
			}
			else {
				if (args.size() != 3)
					print_error(pos, "taskmaster: bad syntax on set_umask");
				else
					print_error(pos, "taskmaster: set_umask variable is set, but missing");
			}
		break;
		case STDERROR_TO:
			if (args.size() == 3 && args[1].length()) {
				tmp.stderr_to_file = get_correct_path(args[1]);
			}
			else {
				if (args.size() != 3)
					print_error(pos, "taskmaster: bad syntax on stderr_to_file");
				else
					print_error(pos, "taskmaster: stderr_to_file is set, but missing");
			}
		break;
		case STDOUT_TO:
			if (args.size() == 3 && args[1].length()) {
				tmp.stdout_to_file = get_correct_path(args[1]);
			}
			else {
				if (args.size() != 3)
					print_error(pos, "taskmaster: bad syntax on stdout_to_file");
				else
					print_error(pos, "taskmaster: stdout_to_file is set, but missing");
			}
		break;
		case STDERROR_CLOSE:
			if (args.size() == 3) {
				tmp.close_stdout = (args[1] == "true") ? true : false;
			}
			else {
				print_error(pos, "taskmaster: bad syntax on close_stderror");
			}
		break;
		case STDOUT_CLOSE:
			if (args.size() == 3) {
				tmp.close_stdout = (args[1] == "true") ? true : false;
			}
			else
				print_error(pos, "taskmaster: bad syntax on close_stderror");
		break;
		case PRINT_ON_TASKMASTER:
			if (args.size() == 3) {
				tmp.print_on_taskmaster = (args[1] == "true") ? true : false;
			}
			else {
				print_error(pos, "taskmaster: bad syntax on print_stdout");
			}
		break;
		case EXIT_SIGNAL:
			if (args.size() == 3 && args[1].length()) {
				tmp.exit_signal_to_set = args[1];
			}
			else {
				if (args.size() != 3)
					print_error(pos, "taskmaster: bad syntax on exit_signal");
				else
					print_error(pos, "taskmaster: exit_signal is set, but has missing value");
			}
		break;
		case AUTO_RESTART:
			if ((args.size() == 3 || args.size() == 4) && (args[1].length() && args[2].length())) {
				if (args[1] == "true")
					tmp.auto_restart = true;
				if (atoi(args[2].c_str()) > 0 && atoi(args[2].c_str()) <= 1000)
					tmp.time_for_restart = atoi(args[2].c_str());
			}
			else {
				if (args.size() != 3 && args.size() != 4)
					print_error(pos, "taskmaster: bad syntax on auto_restart");
				else
					print_error(pos, "taskmaster: auto_restart is set, but missing");
			}
		break;
		case START_TIME:
			if (args.size() == 3 && args[1].length()) {
				while (args[1][++k]) {
					if (!isdigit(args[1][k]))
						found = true;
				}
				if (!found)
					tmp.start_time = atoi((const char *)args[1].c_str());
				else
					print_error(pos, "taskmaster: start_time must be entirely numeric");
			}
			else {
				if (args.size() != 3)
					print_error(pos, "taskmaster: bad syntax on start time");
				else
					print_error(pos, "taskmaster: start_time is set, but missing");
			}
		break;
		case STOP_TIME:
			if (args.size() == 3 && args[1].length()) {
				while (args[1][++k]) {
					if (!isdigit(args[1][k]))
						found = true;
				}
				if (!found)
					tmp.stop_time = atoi((const char *)args[1].c_str());
				else
					print_error(pos, "taskmaster: stop time must be entirely numeric");
			}
			else {
				if (args.size() != 3)
					print_error(pos, "taskmaster: bad syntax on stop_time");
				else
					print_error(pos, "taskmaster: stop_time is set, but missing");
			}
		break;
		case EXIT_CODE:
			if (args.size() == 3 && args[1].length()) {
				while (args[1][++k]) {
					if (!isdigit(args[1][k]) && args[1][k] != '-')
						found = true;
				}
				if (!found)
					tmp.exit_code = atoi((const char *)args[1].c_str());
				else
					print_error(pos, "taskmaster: exit_code must be entirely numeric");
			}
			else {
				if (args.size() != 3)
					print_error(pos, "taskmaster: bad syntax on exit_code");
				else
					print_error(pos, "taskmaster: exit_code is set, but missing");
			}
		break;
		default:
			if (args[0][0] != '/')
				print_error(pos, "taskmaster: Unknown variable " + args[0]);
		break;
	}
	return (tmp);
}

program			get_program_args(int start, vector<string> data, int end, string name) {
	program		tmp;

	name = name.substr(1, name.length());
	name = name.substr(0, (name.length() - 1));
	if (!name.length())
		print_error(start, "program name is missing");
	tmp.program_name = name;
	tmp.auto_start = false;
	tmp.print_on_taskmaster = false;
	tmp.auto_restart = false;
	tmp.start_time = 0;
	tmp.exit_code = 0;
	tmp.stop_time = 0;
	tmp.pid = 0;
	start--;
	while (++start != end)
		tmp = check_variable_and_set(data[start], tmp, (start + 2));
	return (tmp);
}
