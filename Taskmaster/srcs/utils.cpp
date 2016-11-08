/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 07:11:05 by khansman          #+#    #+#             */
/*   Updated: 2016/11/04 07:11:06 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "taskmaster.h"

int		check_folder(string folder, string program_name) {
	struct stat *folder_stat;

	if (!(folder_stat = (struct stat*)malloc(sizeof(struct stat))))
		return (-1);
	if (lstat(folder.c_str(), folder_stat) < 0)
		print_error(-1, "--- Invalid working directory for the program " + program_name + "\n");
	else if (S_ISDIR(folder_stat->st_mode))
		if (folder_stat->st_mode & S_IRUSR)
			return (1);
	print_error(-1, "--- Invalid working directory for the program " + program_name + "\n");
	return (0);
}

vector<string>	get_environment_vector(char **env) {
	int			k = -1;
	vector<string>	new_env;

	if (!env)
		return (new_env);
	while (env[++k])
		new_env.push_back(env[k]);
	return (new_env);
}
