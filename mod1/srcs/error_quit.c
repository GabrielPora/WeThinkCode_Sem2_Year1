/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 10:47:56 by ggroener          #+#    #+#             */
/*   Updated: 2016/10/26 10:48:00 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

void	error_quit(char *error_message)
{
	ft_putstr_fd("An error happened: ", 2);
	ft_putendl_fd(error_message, 2);
	exit(-1);
}
