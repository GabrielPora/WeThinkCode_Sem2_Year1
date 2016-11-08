# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggroener <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/28 11:16:22 by ggroener          #+#    #+#              #
#    Updated: 2016/10/08 10:32:05 by khansman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = taskmaster

CFLAGS = -ltermcap

CC = g++

INCLUDES_PATH = includes/

SRCS_PATH = srcs/

SRCS_NAME = main.cpp 					\
			config.cpp 					\
			handle_config.cpp 			\
			handle_taskmaster_var.cpp 	\
			print_error.cpp 			\
			get_new_program.cpp 		\
			get_program_args.cpp 		\
			check_all_program.cpp 		\
			handle_cmd.cpp 				\
			check_cmd.cpp 				\
			get_help_cmd.cpp 			\
			get_process_status.cpp 		\
			reload.cpp 					\
			start_program.cpp 			\
			handle_program.cpp 			\
			logs.cpp 					\
			utils.cpp 					\
			env.cpp 					\
			stop_program.cpp 			\
			restart_program.cpp 		\
			edit.cpp 					\
			handle_tabulation.cpp 		\
			read_user_entry.cpp			\
			libft.cpp	 				\
			find_path.cpp				\
			term_lines.cpp				\

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = objs/

OBJS_NAME = $(SRCS_NAME:.cpp=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

#uncomment these to work on Mac and comment to work on Linux.
LIBRARY = #-lmlx -L libft/ -lft -framework OpenGL -framework AppKit

INCLUDES = -I includes/ #-I libft/includes

#uncomment these to work on Linux and comment to work on Mac.
#LIBRARY = -L /usr/X11/lib -lmlx -lX11 -lm -lXext -L libft/ -lft
 
#INCLUDES = -I includes/ -I libft/includes -I /usr/X11/include

HEADER = 	$(INCLUDES_PATH)taskmaster.h		\

all: qme odir $(NAME)

define colourecho
	@tput setaf 14
	@echo $1
	@tput sgr0
endef

define colourecho2
	@tput setaf 2
	@echo $1
	@tput sgr0
endef

$(NAME): $(OBJS)
	@$(call colourecho, " - Making $(NAME)")
	@clear
	@$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBRARY) $(INCLUDES) -I$(INCLUDES_PATH)
	@clear
	@$(call colourecho, "Make Done!")

$(OBJS_PATH)%.o: $(SRCS_PATH)%.cpp
	@$(call colourecho, " - Compiling $<")
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $< -I$(INCLUDES_PATH)
	@$(call colourecho, "Compiling Done!")

odir:
	@mkdir -p $(OBJS_PATH)

clean:
	@$(call colourecho, " - Clearing object files")
	@rm -f $(OBJS)
	@$(call colourecho, "clean done!")

fclean: clean
	@$(call colourecho, "Clearing executable files")
	@rm -f $(NAME)
	@$(call colourecho, "fclean done")

re: fclean all
	@$(call colourecho, "re Done!")

format: norme me

norme: norm

norm:
	@clear
	@$(call colourecho2, "Norminette:")
	@norminette $(SRCS)
	@norminette $(HEADER)

qme:
	@if [ ! -f author ]; then \
		whoami > author; \
	fi
	
me: qme
	cat -e author

.PHONY: clean fclean re odir
