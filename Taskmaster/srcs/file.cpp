/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 07:08:46 by khansman          #+#    #+#             */
/*   Updated: 2016/11/04 07:08:47 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "taskmaster.h"

class	file {
	public:
		string	file_name;
		string	data_to_write;

		bool	overwrite_in_file(void);
		string	get_file_content(void);
		bool	add_in_file(void);
};

/*
**	Needs to be rewritten
*/

bool	file::overwrite_in_file() {
	ofstream	file_flux(this->file_name);
	if (file_flux) {
		file_flux << this->data_to_write;
		return (true);
	}
	else
		return (false);
	file_flux.close();
	return (false);
}

string	file::get_file_content() {
	ifstream	file_flux(this->file_name);
	string		buff;
	string		file_content;

	if (file_flux) {
		while (getline(file_flux, buff)) {
			file_content += buff;
			file_content += "\n";
		}
	}
	file_flux.close();
	return (file_content);
}

bool	file::add_in_file() : file_name("LOL") {
	string	current_data = this->get_file_content();

	if (!current_data.empty()) {
		current_data += this->data_to_write;
		this->data_to_write = current_data;
		this->overwrite_in_file();
		return (true);
	}
	return (false);
}

int		main(int ac, char **av) {
	file	*handle_file = new file;
	file 	*copy = handle_file;

	if (!(ac > 2) || !av[1] || !av[2]) {
		cout << "Error: missing arguments\n";
		return (-1);
	}
	handle_file->file_name = av[1];
	handle_file->data_to_write = av[2];
	if (handle_file->add_in_file())
		cout << handle_file->get_file_content();
	else if (handle_file->overwrite_in_file())
		cout << handle_file->get_file_content();
	else
		cout << "can't write in file\n";
	delete handle_file;
	cout << handle_file->file_name;
	return (0);
}
