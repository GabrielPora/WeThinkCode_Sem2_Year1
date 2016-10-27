/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 10:07:59 by khansman          #+#    #+#             */
/*   Updated: 2016/10/27 10:08:00 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

void	print_menu(t_env *env)
{
	if (env->print_menu)
	{
		MPUTSTR(700, 10, "OPTIONS:");
		MPUTSTR(700, 35, "P: Pause/Play");
		MPUTSTR(700, 55, "F: Pause/Play Flow");
		MPUTSTR(700, 75, "E: Empty (Rain Only)");
		MPUTSTR(700, 95, "R: Reset");
		MPUTSTR(700, 115, "V: Drain");
		MPUTSTR(700, 135, "I: Display/Hide This Menu");
		MPUTSTR(700, 155, "ESC: Exit Program");
		MPUTSTR(700, 175, "SPACE: Inc Scenario Count");
	}
}
