/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:15:09 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/09 11:58:18 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOYPES_H

char	*get_next_line(int fd);
void	read_file(t_env *env, char *file);
int		valid_int(char *str);
void	dump_puzzle(t_env *env, int **puzzle);

#endif
