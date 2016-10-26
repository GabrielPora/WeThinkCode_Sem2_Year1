/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 10:55:37 by ggroener          #+#    #+#             */
/*   Updated: 2016/10/26 10:55:38 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_draw_water
{
	double		t;
	int			r;
	int			g;
	int			b;
	int			xd;
	int			yd;
	int			i;	
}				t_draw_water;

typedef struct	s_draw
{
	int			dx;
	int			dy;
	int			y;
	int			x;
	int			togoy;
	int			i;
	char		*str;
}				t_draw;

typedef struct	s_flow_rain
{
	int			add;
	int			flowest[4];
	int			lower;
	int			lowest;
	int			x;
	int			y;
}				t_flow_rain;

#endif
