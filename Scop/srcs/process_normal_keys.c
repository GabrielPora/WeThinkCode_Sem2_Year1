/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_normal_keys.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:38:30 by khansman          #+#    #+#             */
/*   Updated: 2016/11/25 09:38:39 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	process_normal_keys(unsigned char key, int x, int y)
{
	(void)x;
	(void)y;
	if (key == KEY_ESC)
		exit_prog();
}
