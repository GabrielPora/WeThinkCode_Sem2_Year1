/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_program.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 07:09:00 by khansman          #+#    #+#             */
/*   Updated: 2016/11/04 07:09:01 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "taskmaster.h"

string		get_function_name(string data) {
	string	tmp;
	int		k = -1;

	data = data.substr(1, data.length());
	while (data[++k] && data[k] != '{')
		tmp += data[k];
	return (tmp);
}

string		get_name(string data) {
	string	tmp;
	int		k = -1;

	data = data.substr(1, data.length());
	while (data[++k] && data[k] != '{');
	while (data[k]) {
		tmp += data[k];
		k++;
	}
	return (tmp);
}

int			get_function_end(vector<string> data, int k) {
	while (k != data.size()) {
		if (data[k] == ")")
			return (k);
		k++;
	}
	return (-1);
}

program		get_new_program(vector<string> data, int k) {
	program	new_program;
	string	function_name;
	string	name;
	int		function_end;

	function_name = get_function_name(data[k]);
	if (!function_name.length())
		print_error((k + 2), "missing function name");
	if (function_name == "new_program") {
		name = get_name(data[k]);
		function_end = get_function_end(data, k);
		if ((name[0] == '{') && (name[(name.length() - 1)] == '}')) {
			if (data[k + 1] != "(")
				print_error((k + 3), "missing \'(\' in function opening");
			if (function_end == -1) {
				TaskMasterValue::Current().ExitProgramOnError = true;
				print_error((k + 2), "missing \')\' at function end");
			}
			new_program = get_program_args((k + 2), data, function_end, name);
		}
		else
			print_error((k + 2), "bad syntax near " + name);
	}
	else
		print_error((k + 2), "unknown function " + function_name);
	return (new_program);
}
