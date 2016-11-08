/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_lines.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:02:46 by khansman          #+#    #+#             */
/*   Updated: 2016/11/05 13:02:48 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/taskmaster.h"

int			ft_termsize(int y)
{
	size_t			ret;
	struct ttysize	twin;
	struct winsize	win;

	ret = 0;
	if (!ioctl(0, TIOCGSIZE, &twin))
		ret = (y) ? twin.ts_lines : twin.ts_cols;
	else if (!ioctl(0, TIOCGWINSZ, &win))
		ret = (y) ? win.ws_row : win.ws_col;
	else
	{
		print("ioctl Error: Failed to determine window size.\n.");
		exit(0);
	}
	return ((size_t)ret);
}

void		re_print_line(string line) {
	int				size = ft_termsize(0);
	int				k = -1;
	string			cl_str = "\r";

	while (++k < size)
		cl_str += " ";
	print(cl_str);
	print("\rtaskmaster >" + line);
}
