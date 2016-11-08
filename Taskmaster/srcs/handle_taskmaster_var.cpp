/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_taskmaster_var.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 07:09:50 by khansman          #+#    #+#             */
/*   Updated: 2016/11/04 07:09:51 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "taskmaster.h"

vector<string>	get_args(string line, vector<string> args, char delimiter) {
	int		k = -1;
	char	**tmp;

	line = line.substr(1, line.length());
	tmp = ft_strsplit(line.c_str(), delimiter);
	while (tmp[++k])
		args.push_back(tmp[k]);
	args.push_back("\0");
	return (args);
}

string 			get_correct_path(string path) {
	int		k = -1;
	bool	found = false;

	while (path[++k])
		if (path[k] == '~') {
			found = true;
			break;
		}
	if (found) {
		path.erase(k, (k + 1));
		path.insert(k, getenv("HOME"));
	}
	return (path);
}

static int		get_variable_state(string var) {
	if (var == "taskmaster_log_file")
		return (LOG_FILE);
	return (UNKNOWN_VARIABLE);
}

static bool		check_log_file_path(string full_path) {
	struct stat	*log_file;
	bool		ret = false;

	if (!(log_file = (struct stat *)malloc(sizeof(struct stat))))
		return (ret);
	else if (lstat(full_path.c_str(), log_file) < 0 && (ret = true))
		TaskMasterValue::Current().LogFilePathExist = false;
	else if (S_ISDIR(log_file->st_mode))
		print_error(-1, "taskmaster: set log file is a directory");
	else if (S_ISLNK(log_file->st_mode))
		print_error(-1, "taskmaster: set log file is a symbolic link");
	else if ((log_file->st_mode & S_IRUSR) && (ret = true))
		TaskMasterValue::Current().LogFilePathExist = true;
	else
		print_error(-1, "taskmaster: logfile permissions denied");
	return (ret);
}

void			handle_taskmaster_var(string line, int pos) {
	vector<string>	args;
	int				k = -1;
	int				tmp;

	pos += 2;
	args = get_args(line, args, ';');
	if (args.size()) {
		tmp = get_variable_state(args[0]);
		if (tmp == LOG_FILE) {
			if (args[1].length()) {
				args[1] = get_correct_path(args[1]);
				if (check_log_file_path(args[1]))
					TaskMasterValue::Current().LogFilePath = args[1];
				else
					print_error(pos, "Invalid log file path");
			}
			else
				print_error(pos, "Missing log file path");
		}
		else {
			print_error(pos, "Unknown variable " + args[0]);
		}
	}
	else
		print_error(pos, "Missing or invalid variable name");
}
