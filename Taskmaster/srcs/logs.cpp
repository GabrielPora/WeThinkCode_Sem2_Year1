/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 07:10:11 by khansman          #+#    #+#             */
/*   Updated: 2016/11/04 07:10:12 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "taskmaster.h"

string	get_current_time() {
	time_t		now = time(0);
	struct tm	tstruct;
	char		buff[80];

	tstruct = *localtime(&now);
	strftime(buff, sizeof(buff), "m/%d at %H:%M:%S", &tstruct);
	return (buff);
}

string	add_day_n_hour(string content) {
	return (content.insert(0, "[" + get_current_time() + "]" ));
}

void	add_in_logs(string file_path, string content) {
	string		logs_content;
	char		buff[1024];
	int			fd = 0;
	int			res = 0;

	fd = open(file_path.c_str(), O_RDWR);
	if (fd == -1) {
		close(fd);
		if ((fd = open(file_path.c_str(), O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO)) == -1)
			print_error(-1, "can't open the log file");
		else {
			close(fd);
			fd = open(file_path.c_str(), O_RDWR);
		}
	}
	content += "\n";
	while ((res = read(fd, buff, 1024)) > 0) {
		buff[res] = '\0';
		logs_content += buff;
	}
	logs_content += content;
	content = add_day_n_hour(content);
	write(fd, content.c_str(), strlen(content.c_str()));
	close(fd);
}
