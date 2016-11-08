/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 07:10:26 by khansman          #+#    #+#             */
/*   Updated: 2016/11/04 07:10:27 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "taskmaster.h"

void	print_error(int pos, string str) {
	if (pos != -1)
		cerr << "taskmaster: configoration error at the line " << pos << ": " << endl;
	cerr << str << endl;
	TaskMasterValue::Current().Errors++;
	if (TaskMasterValue::Current().ExitProgramOnError)
		exit(0);
}
