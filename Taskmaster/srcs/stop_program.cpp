/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_program.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 07:10:56 by khansman          #+#    #+#             */
/*   Updated: 2016/11/04 07:10:58 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "taskmaster.h"

int					sigstr_to_int(string str) {
	if (str == "SIGHUP") return (SIGHUP); /*1*/
	if (str == "SIGINT") return (SIGINT); /*2*/
	if (str == "SIGQUIT") return (SIGQUIT); /*3*/
	if (str == "SIGILL") return (SIGILL); /*4*/
	if (str == "SIGTRAP") return (SIGTRAP); /*5*/
	if (str == "SIGABRT") return (SIGABRT); /*6*/
	if (str == "SIGEMT") return (SIGEMT); /*7*/
	if (str == "SIGFPE") return (SIGFPE); /*8*/
	if (str == "SIGKILL") return (SIGKILL); /*9*/
	if (str == "SIGBUS") return (SIGBUS); /*10*/
	if (str == "SIGSEGV") return (SIGSEGV); /*11*/
	if (str == "SIGSYS") return (SIGSYS); /*12*/
	if (str == "SIGPIPE") return (SIGPIPE); /*13*/
	if (str == "SIGALRM") return (SIGALRM); /*14*/
	if (str == "SIGTERM") return (SIGTERM); /*15*/
	if (str == "SIGURG") return (SIGURG); /*16*/
	if (str == "SIGSTOP") return (SIGSTOP); /*17*/
	if (str == "SIGTSTP") return (SIGTSTP); /*18*/
	if (str == "SIGCONT") return (SIGCONT); /*19*/
	if (str == "SIGCHLD") return (SIGCHLD); /*20*/
	if (str == "SIGTTIN") return (SIGTTIN); /*21*/
	if (str == "SIGTTOU") return (SIGTTOU); /*22*/
	if (str == "SIGIO") return (SIGIO); /*23*/
	if (str == "SIGXCPU") return (SIGXCPU); /*24*/
	if (str == "SIGXFSZ") return (SIGXFSZ); /*25*/
	if (str == "SIGVTALRM") return (SIGVTALRM); /*26*/
	if (str == "SIGPROF") return (SIGPROF); /*27*/
	if (str == "SIGWINCH") return (SIGWINCH); /*28*/
	if (str == "SIGINFO") return (SIGINFO); /*29*/
	if (str == "SIGUSR1") return (SIGUSR1); /*30*/
	if (str == "SIGUSR2") return (SIGUSR2); /*31*/
	return ((atoi((const char *)str.c_str()) > 0) ? atoi((const char *)str.c_str()) : SIGKILL);
}

vector<program>		close_without_waiting(vector<program> program_list, int k) {
	int		sig = (!program_list[k].exit_signal_to_set.length()) ? 1 : sigstr_to_int(program_list[k].exit_signal_to_set);

	if (kill(program_list[k].pid, sig) != -1) {
		print("Program " + program_list[k].program_name + " (");
		ft_putstr(ft_itoa(program_list[k].pid));
		print(") stopped.\n");
		program_list[k].pid = 0;
		add_in_logs(TaskMasterValue::Current().LogFilePath, "Program " + program_list[k].program_name + " was stopped.");
	}
	return (program_list);
}

vector<program>		wait_and_close(vector<program> program_list, int k) {
	pid_t	pid;
	int		sig;

	print("Program " + program_list[k].program_name + " (");
	ft_putstr(ft_itoa(program_list[k].pid));
	print(") will be stopped in ");
	ft_putstr(ft_itoa(program_list[k].stop_time));
	print("seconds.\n");
	if ((pid = fork()) == 0) {
		close(0);
		close(1);
		close(2);
		sleep(program_list[k].stop_time);
		sig = ((!program_list[k].exit_signal_to_set.length()) ? 1 : sigstr_to_int(program_list[k].exit_signal_to_set));
		if (kill(program_list[k].pid, sig) != -1)
			add_in_logs(TaskMasterValue::Current().LogFilePath, "Program " + program_list[k].program_name + " was stopped.");
		exit(0);
	}
	else
		program_list[k].pid = 0;
	return (program_list);
}

vector<program>		stop_program(vector<string> args, vector<program> program_list) {
	int		k = -1;
	int		l = -1;
	bool	found = false;

	if (args[0] == "all") {
		while (++k < program_list.size())
			if (program_list[k].pid != 0) {
				program_list = (program_list[k].stop_time == 0) ? close_without_waiting(program_list, k) : wait_and_close(program_list, k);
				found = true;
			}
		if (!found)
			print("No process started.\n");
	}
	else {
		while (++k < args.size()) {
			while (++l < program_list.size()) {
				if (program_list[l].program_name == args[k]) {
					if (program_list[k].pid != 0 && (found = true))
						program_list = (program_list[k].stop_time == 0) ? close_without_waiting(program_list, k) : wait_and_close(program_list, k);
					else {
						print("Program " + program_list[k].program_name + " hasn't been started.\n");
						program_list[l].pid = 0;
					}
				}
			}
			if (!found)
				print("Process " + args[k] + " was not found.");
			found = false;
			l = -1;
		}
	}
	return (program_list);
}
