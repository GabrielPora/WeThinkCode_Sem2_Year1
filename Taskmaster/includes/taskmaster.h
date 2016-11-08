/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taskmaster.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:06:58 by khansman          #+#    #+#             */
/*   Updated: 2016/11/03 10:07:00 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TASKMASTER_H
# define TASKMASTER_H
/*
** ----------\
** Includes   |
** ----------/
*/
# include <iostream>
# include <fstream>
# include <vector>
# include <sys/stat.h> 
# include <signal.h>
# include <errno.h>
# include <unistd.h>

# include <iomanip>
# include <fstream>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <termios.h>
# include <term.h>
# include <fcntl.h>
# include <time.h>
# include <curses.h>
# include <dirent.h>
# include <sys/ioctl.h>

using namespace std;

/*
** ----------\
** Defines    |
** ----------/
*/

/*
** Config file
*/
# define VAR_SYNTHAX			'%'
# define NEW_PROGRAM_SYNTHAX	'#'
# define LOG_FILE				0
# define UNKNOWN_VARIABLE		666
# define EXECUTABLE_PATH		10
# define EXECUTABLE_ARGUMENT	11
# define SET_ENV				12
# define WORKING_DIR			13
# define AUTO_START				14
# define SET_UMASK				15
# define STDERROR_TO			16
# define STDOUT_TO				17
# define STDERROR_CLOSE			18
# define STDOUT_CLOSE			19
# define PRINT_ON_TASKMASTER	20
# define EXIT_SIGNAL			21
# define AUTO_RESTART			22
# define START_TIME				23
# define STOP_TIME				24
# define EXIT_CODE				25

/*
** Special Strings
*/
# define WHITE_COLOR			"\e[1;37m"
# define TO_PRINT_FOR_CLEAR		"\033[2J"

/*
** Keys
*/
# define TABULATION				9
# define ENTRY					10
# define CLEAR_SCREEN			12
# define BACKSPACE				127
# define ARROW_UP				183
# define ARROW_DOWN				184
# define ARROW_RIGHT			185
# define ARROW_LEFT				186

/*
** Defaults
*/
# define DEFAULT_ARGS_SIZE		1024
# define DEFAULT_ENV_SIZE		1024
/*
** Other
*/
DIR								*open_dir(char *path);

/*
** ----------\
** Structures |
** ----------/
*/

class program {
	public:
	string			program_name;
	string			executable_path;
	string			executable_argument;
	vector<string>	env_to_set;
	bool			auto_start;
	string			exit_signal_to_set;
	string			working_dir;
	string			set_umask;
	string			stderr_to_file;
	string			stdout_to_file;
	bool			auto_restart;
	bool			print_on_taskmaster;
	bool			close_stdout;
	bool			close_stderror;
	int				start_time;
	int				stop_time;
	vector<string>	Environment_Data;
	int				pid;
	int				exit_code;
	int				time_for_restart;
	void			GetEnvToSet(vector<string> env_to_set);
	void			FindAndSet(char *variable, char *value);
};

class TaskMasterValue {
	public:
	string			LogFilePath;
	string			ConfigFileName;
	bool			LogFilePathExist;
	bool			ExitProgramOnError;
	int				Errors;
	vector<string>	DefaultEnvironment;
	static TaskMasterValue &Current() {
		static TaskMasterValue	Singleton;
		return Singleton;
	}
};

class UserEntry {
	public:
	bool			end_cmd;
	string			cmd;
	int				cursor;
	vector<string>	cmd_history;
	int				history_pos;
	int				auto_completion_get;
	static UserEntry &Current() {
		static UserEntry Singleton;
		return Singleton;
	}
};

class config_infos {
	public:
	int				check_if_config_exist();
	vector<program>	read_config(vector<program> program_list);
	vector<program>	get_config_value(vector<program> program_list,
			vector<string> data);
	string			config_file_name;
};

/*
class	file {
	public:
	string	file_name;
	string	data_to_write;
	bool	overwrite_in_file(void);
	string	get_file_content(void);
	bool	add_in_file(void);
};*/

/*
** ----------\
** Prototypes |
** ----------/
*/

/*
** check_all_program.cpp
*/
bool				check_all_program(vector<program> program_list);
/*
** check_cmd.cpp
*/
vector<string>		clear_args(vector<string> cmd_args);
vector<program>		check_cmd(string cmd, vector<string> cmd_args, vector<program> program_list, string orig_cmd);
/*
** config.cpp
*/
string 				delete_space(string &str);
string 				delete_tab(string &str);
/*
** edit.cpp
*/
vector<program>		edit(vector<string> args, vector<program> program_list);
/*
** env.cpp
*/
string				GetVarName(string line);
string 				UpdateVar(string line, char *value);
/*
** file.cpp
*/

/*
** find_path.cpp
*/
int					scan_dir(char *s, char *path);
char				*add_path(char *path, char *extension);
char				*find_path(char *s);

/*
** get_help_cmd.cpp
*/
void				get_help_cmd(vector<string> args);
/*
** get_new_program.cpp
*/
string				get_function_name(string data);
string				get_name(string data);
int					get_function_end(vector<string> data, int k);
program				get_new_program(vector<string> data, int k);
/*
** get_process_status.cpp
*/
void				print_program_informations(vector<program> program_list, int p_id);
void				get_process_status(vector<string> args, vector<program> program_list);
/*
** get_program_args.cpp
*/
program				check_variable_and_set(string line, program tmp, int pos);
program				get_program_args(int start, vector<string> data, int end, string name);
/*
** handle_cmd.cpp
*/
string				get_cmd(string cmd);
vector<string>		get_args(string cmd);
vector<program>		handle_cmd(string cmd, vector<program> program_list);
/*
** handle_config.cpp
*/
bool				program_to_auto_start(vector<program> program_list);
void				auto_restart_program(vector<program> program_list);
void				handle_config(string config_name);
/*
** handle_program.cpp
*/
vector<string> 		split(char *str, const char *delim);
char				**get_program_args(string executable_path, string args);
char				**get_program_env(vector<string> data);
vector<program>		handle_program(program to, int pos, vector<program> program_list);
/*
** handle_tabulation.cpp
*/
void				get_command();
void				get_program_name(vector<program> program_list);
/*
** handle_taskmaster_var.cpp
*/
vector<string>		get_args(string line, vector<string> args, char delimiter);
string 				get_correct_path(string path);
void				handle_taskmaster_var(string line, int pos);
/*
** libft.cpp
*/
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(const char *s);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strnew(size_t size);
char				*ft_strdup(const char *s1);
char				*ft_strchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int value);
char				*ft_itoa_base(int value, int base);
char				*ft_strjoin(char const *s1, char const *s2);

void				print_2d(char **sa);
int					ft_is_all_print(char *str);
void				print_fd(string str, int fd);
void				print(string str);
/*
** logs.cpp
*/
string				get_current_time();
string				add_day_n_hour(string content);
void				add_in_logs(string file_path, string content);
/*
** main.cpp
*/
int					check_env(char **env);
int					main(int ac, char **av, char **env);
/*
** print_error.cpp
*/
void				print_error(int pos, string str);
/*
** read_user_entry.cpp
*/
int					get_ascii_value(string tmp_line);
int					cursor_do(int to_print);
void				refresh_stdout();
void				delete_x_characters(int to_del);
void				delete_current_and_print_history(string to_set, string tmp);
void				read_entry(string tmp_line, vector<program> program_list);
void				handle_history();
void				reset_value();
string				trim(const string &s);
void				read_user_entry(vector<program> program_list);
/*
** reload.cpp
*/
vector<program>		reload(vector<string> args, vector<program> program_list);
/*
** restart_program.cpp
*/
vector<program>		restart_program(vector<string> args, vector<program> program_list);
/*
** start_program.cpp
*/
vector<program>		start_program(vector<string> args, vector<program> program_list);
/*
** stop_program.cpp
*/
int					sigstr_to_int(string str);
vector<program>		close_without_waiting(vector<program> program_list, int k);
vector<program>		wait_and_close(vector<program> program_list, int k);
vector<program>		stop_program(vector<string> args, vector<program> program_list);
/*
** term_lines.cpp
*/
int					ft_termsize(int y);
void				re_print_line(string line);
/*
** utils.cpp
*/
int					check_folder(string folder, string program_name);
vector<string>		get_environment_vector(char **env);

/*
**                                /----------\                                **
** ----- ----- ----- ----- ----- |  The End   | ----- ----- ----- ----- ----- **
**                                \----------/                                **
*/
#endif