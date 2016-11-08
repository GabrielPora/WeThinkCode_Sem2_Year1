/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 07:08:41 by khansman          #+#    #+#             */
/*   Updated: 2016/11/04 07:08:42 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "taskmaster.h"

string	GetVarName(string line) {
	string	tmp;
	int		k = -1;

	while (line[++k] && line[k] != '=')
		tmp += line[k];
	return (tmp);
}

string 	UpdateVar(string line, char *value) {
	int		k = -1;
	string	tmp;

	while (line[++k] && line[k] != '=')
		tmp += line[k];
	tmp += "=";
	tmp += value;
	return (tmp);
}

void	program::FindAndSet(char *variable, char *value) {
	int		k = -1;
	bool	found = false;
	string	new_line;

	while (++k < this->Environment_Data.size()) {
		if (!strcmp(GetVarName(this->Environment_Data[k]).c_str(), variable)) {
			this->Environment_Data[k] = UpdateVar(this->Environment_Data[k], value);
			found = true;
		}
	}
	if (!found) {
		new_line += variable;
		new_line += "=";
		new_line += value;
		this->Environment_Data.push_back(new_line);
	}
}

void	program::GetEnvToSet(vector<string> env_to_set) {
	int		k = -1;
	char	**to_set;

	while (++k < env_to_set.size()) {
		to_set = ft_strsplit((char *)env_to_set[k].c_str(), ',');
		if (strlen(to_set[0]) && strlen(to_set[1]))
			this->FindAndSet(to_set[0], to_set[1]);
	}
}
