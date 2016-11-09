/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:56:04 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/09 11:56:05 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

int		main(int argc, char **argv)
{
	t_env	env;

	if (argc < 2)
	{
		ft_putendl_fd("npuzzle: usage: npuzzle <puzzle file name>", 2);
		exit(EXIT_FAILURE);
	}
	read_file(&env, argv[1]);
	dump_puzzle(&env, env.puzzle);
	return (1);
}
