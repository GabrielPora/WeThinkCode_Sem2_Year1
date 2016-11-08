/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 07:08:27 by khansman          #+#    #+#             */
/*   Updated: 2016/11/04 07:08:29 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "taskmaster.h"

int	config_infos::check_if_config_exist(void) {
	struct stat		*config;

	if (!(config = (struct stat*)malloc(sizeof(struct stat))))
		return (-1);
	if (lstat(this->config_file_name.c_str(), config) < 0) {
		print(this->config_file_name);
		print_error(-1, "taskmaster: invalid config file.");
		return (0);
	}
	if (S_ISDIR(config->st_mode)) {
		print_error(-1, "taskmaster: config file set is a directory");
	}
	else if (S_ISLNK(config->st_mode)) {
		print_error(-1, "taskmaster: config file set is a symbilic link.");
	}
	else if (config->st_mode & S_IRUSR)
		return (1);
	else {
		print_error(-1, "taskmaster: config file permissions denied.");
	}
	return (0);
}

string delete_space(string &str) {
	int first = str.find_first_not_of(' ');
	int last = str.find_last_not_of(' ');

	if (first == -1 || last == -1)
		return (str);
	return (str.substr(first, (last - first + 1)));
}

string delete_tab(string &str) {
	int first = str.find_first_not_of('\t');
	int	last = str.find_last_not_of('\t');

	if (last == -1)
		return (str);
	return (str.substr(first, (last - first + 1)));
}

vector<program> config_infos::get_config_value(vector<program> program_list, vector<string> data) {
	int	k = -1;
	bool taskmaster_var = true;

	while (++k != data.size()) {
		if (data[k][0] == VAR_SYNTHAX && taskmaster_var)
			handle_taskmaster_var(data[k], k);
		else if (data[k][0] == NEW_PROGRAM_SYNTHAX) {
			program_list.push_back(get_new_program(data, k));
			taskmaster_var = false;
		}
	}
	return (program_list);
}

vector<program>	config_infos::read_config(vector<program> program_list) {
	int				k = -1;
	ifstream		flux(this->config_file_name);
	string			buff;
	vector<string>	config_content;
	vector<string>	clear_content;

	if (flux) {
		while (getline(flux, buff))
			config_content.push_back(buff);
		if (!config_content.size()) {
			print_error(-1, "taskmaster: empty configoration file.");
			return (program_list);
		}
		if (config_content[0] != "[taskmaster]" ||
			config_content[(config_content.size() - 1)] != "[end_taskmaster]") {
				print_error(-1, "taskmaster: config file header not present.");
				return (program_list);
		}
		else {
			k++;
			while (++k != (config_content.size() - 1)) {
				config_content[k] = delete_space(config_content[k]);
				config_content[k] = delete_tab(config_content[k]);
				if (config_content[k][0] != '\0' && config_content[k][0] != '\t')
					clear_content.push_back(config_content[k]);
			}
			return (this->get_config_value(program_list, clear_content));
		}
		flux.close();
	}
	else
		print_error(-1, "taskmaster: invalid configoration file");
	return (program_list);
}
