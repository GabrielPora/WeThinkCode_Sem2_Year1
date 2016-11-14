/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_solvable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:22:44 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/14 15:22:45 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static void	fill_odd(t_env *env, int **puzzle, int *numbers)
{
	int i;
	int x;
	int y;
	int z;

	i = 0;
	z = 0;
	while (z < env->size / 2)
	{
		x = z - 1;
		y = z;
		while (++x < env->size - z)
			numbers[i++] = puzzle[y][x];
		x--;
		while (++y < env->size - z)
			numbers[i++] = puzzle[y][x];
		y--;
		while (--x >= z)
			numbers[i++] = puzzle[y][x];
		x++;
		while (--y > z)
			numbers[i++] = puzzle[y][x];
		z++;
	}
	numbers[i++] = puzzle[env->size / 2][env->size / 2];
}

static void fill_even(t_env *env, int **puzzle, int *numbers)
{
	int i;
	int x;
	int y;
	int z;

	i = 1;
	z = 0;
	while (z < env->size / 2 - 1)
	{
		x = z - 1;
		y = z;
		while (++x < env->size - z)
			numbers[i++] = puzzle[y][x];
		x--;
		while (++y < env->size - z)
			numbers[i++] = puzzle[y][x];
		y--;
		while (--x >= z)
			numbers[i++] = puzzle[y][x];
		x++;
		while (--y > z)
			numbers[i++] = puzzle[y][x];
		z++;
	}
	numbers[i++] = puzzle[env->size / 2 - 1][env->size / 2 - 1];
	numbers[i++] = puzzle[env->size / 2 - 1][env->size / 2];
	numbers[i++] = puzzle[env->size / 2][env->size / 2];
	numbers[i++] = puzzle[env->size / 2][env->size / 2 - 1];
}

static void fill_numbers(t_env *env, int **puzzle, int *numbers)
{
	if (env->size % 2 == 1)
	{
		fill_odd(env, puzzle, numbers);
	}
	else
	{
		fill_even(env, puzzle, numbers);
	}
}

static int get_inversions(t_env *env, t_state *state)
{
	int *numbers;
	int total;
	int i;
	int j;

	if (!(numbers = malloc(sizeof(*numbers) * (env->size * env->size))))
	{
		ft_putendl_fd("npuzzle: can't malloc", 2);
		exit(EXIT_FAILURE);
	}
	fill_numbers(env, state->puzzle, numbers);
	i = 0;
	while (i < env->size * env->size)
	{
		i++;
	}
	i = 0;
	total = 0;
	while (i < env->size * env->size)
	{
		if (numbers[i] == 0)
		{
			i++;
			continue;
		}
		j = i + 1;
		while (j < env->size * env->size)
		{
			if (numbers[j] != 0 && numbers[j] < numbers[i])
				total++;
			j++;
		}
		i++;
	}
	return (total);
}

static int blank_line(t_env *env, t_state *end)
{
	int y;
	int x;

	y = 0;
	while (y < env->size)
	{
		x = 0;
		while (x < env->size)
		{
			if (end->puzzle[y][x] == 0)
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}

int is_solvable(t_env *env)
{
	int start_inversions;

	start_inversions = get_inversions(env, env->start);
	if (env->size % 2 == 0)
	{
		printf("%d\n", (start_inversions + blank_line(env, env->start)) % 2);
		return (1);
		//return ((start_inversions + blank_line(env, env->start)) % 2 == blank_line(env, env->end) % 2);
	}
	else
		return (start_inversions % 2 == 0);

