/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       ::      ::    ::   */
/*                                                    : :         :     */
/*   By: ggroener <marvin@42.fr>                    #  :       #        */
/*                                                #####   #           */
/*   Created: 2016/11/09 11:15:09 by ggroener          ##    ##             */
/*   Updated: 2016/11/09 11:58:18 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOYPES_H

char			*get_next_line(int fd);
void			read_file(t_env *env, char *file);
int				valid_int(char *str);
void			dump_puzzle(t_env *env, int **puzzle);
void			dump_state(t_env *env, t_state *state);
void			state_list_push(t_state_list **lst, t_state *state);
void			state_list_remove(t_state_list **lst, t_state *state);
void			astar(t_env *env);
t_state			*state_new();
void 			build_end(t_env *env);
t_state			*state_new_size(t_env *env);
int				state_equals(t_env *env, t_state *s1, t_state *s2);
int				state_list_contains(t_env *env, t_state_list *lst, t_state *state);
void			state_list_free(t_state_list *lst);
void			state_free(t_env *env, t_state *state);
t_state_list	*state_expend(t_env *env, t_state *state);
t_state 		*copy_state(t_env *env, t_state *from);
int				manhattan(t_env *env, t_state *state);
void			generate_random(t_env *env);
int				is_solvable(t_env *env);
long			timing(void);
void			print_solution(t_env *env, t_state *state);
int				state_list_size(t_state_list *lst);
int				misplaced(t_env *env, t_state *state);
int				row_column(t_env *env, t_state *state);

#endif
