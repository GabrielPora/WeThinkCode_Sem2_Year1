/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 07:10:15 by khansman          #+#    #+#             */
/*   Updated: 2016/11/04 07:10:17 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "taskmaster.h"

int		check_env(char **env) {
	int		k = -1;
	bool	term = false;
	bool	home = false;

	if (!env)
		return (0);
	while (env[++k]) {
		if (strstr(env[k], "TERM"))
			if (strstr(env[k], "xterm-256color"))
				term = true;
		if (strstr(env[k], "HOME"))
			home = true;
	}
	if (!term)
		cerr << "taskmaster: Invalid enviroment: $TERM is missing or invalid" << endl;
	if (!home)
		cerr << "taskmaster: INvalid enviroment: $HOME is missing or invalid" << endl;
	return ((term && home));
}

int		main(int ac, char **av, char **env) {
	int		k = 0;
	bool	args = false;
	bool	other = false;
	string	flags;
	string	current_flag;
	string	config_file;

	if (check_env(env) == 0)
		return (-1);
	if (ac == 1)
		cerr << "taskmaster: no argument given" << endl;
	else {
		while (av[++k]) {
			if (av[k][0] == '-') {
				if (!other) {
					current_flag = av[k];
					current_flag = current_flag.substr(1, current_flag.length());
					flags += current_flag;
					args = true;
				}
				else {
					cerr << "taskmasgter: bad syntax (argument - config file)" << endl;
					return (-1);
				}
			}
			else {
				if (!args) {
					cerr << "taskmaster: bad syntax (arguments - config file)" << endl;
					return (-1);
				}
				else {
					config_file = av[k];
					other = true;
				}
			}
		}
		if (strchr(flags.c_str(), 'c') && other) {
			TaskMasterValue::Current().DefaultEnvironment = get_environment_vector(env);
			handle_config(config_file);
		}
		else
			cerr << "taskmaster: missing config file" << endl;
	}
	return (0);
}
