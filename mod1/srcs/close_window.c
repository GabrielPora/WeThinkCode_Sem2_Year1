/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 10:47:38 by ggroener          #+#    #+#             */
/*   Updated: 2016/10/26 10:47:39 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

int	close_window(t_env *env)
{
	free(&env);
	exit(0);
}
