/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colour.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:40:29 by khansman          #+#    #+#             */
/*   Updated: 2016/11/25 09:40:33 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

int		set_colour(float r, float g, float b)
{
	g_red = r;
	g_green = g;
	g_blue = b;
	return (1);
}
