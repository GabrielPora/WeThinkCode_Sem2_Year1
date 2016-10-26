/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 10:53:07 by ggroener          #+#    #+#             */
/*   Updated: 2016/10/26 10:53:09 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

int		valid_int(char *arg)
{
	if (arg[0] == '-')
	{
		if (ft_strlen(arg) > 11)
			return (0);
	}
	else if (ft_strlen(arg) > 10)
		return (0);
	if (ft_atol(arg) > INT_MAX || ft_atol(arg) < INT_MIN)
		return (0);
	return (1);
}
