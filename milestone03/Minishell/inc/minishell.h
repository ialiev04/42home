/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 01:17:10 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/11 02:24:18 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "execute.h"
# include "parsing.h"
# include "../libft/include/libft.h"
# include <stdio.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <unistd.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <stdlib.h>
# include <string.h>

extern volatile sig_atomic_t	g_signal_status;

typedef struct s_file_node
{
	char				*filename;
	int					redir_type;
	struct s_file_node	*next;
}	t_file_node;

typedef struct s_file_list
{
	t_file_node		*head;
	t_file_node		*tail;
	ssize_t			size;
}	t_file_list;

typedef struct s_env_node
{
	char				*key;
	char				*value;
	struct s_env_node	*next;
}	t_env_node;

typedef struct s_env_list
{
	t_env_node	*head;
	t_env_node	*tail;
	ssize_t		size;
}	t_env_list;

typedef struct s_cmd_node
{
	int					cmd_type;
	char				**cmd;
	t_file_list			*files;
	struct s_cmd_node	*next;
}	t_cmd_node;

typedef struct s_cmd_list
{
	t_cmd_node	*head;
	t_cmd_node	*tail;
	t_env_list	*env_list;
	ssize_t		size;
}	t_cmd_list;

typedef struct s_parser
{
	t_token		*tokens;
	t_token		*current;
	t_env_list	*env_list;
	int			last_exit_status;
}	t_parser;

typedef struct s_expand_ctx
{
	t_env_list	*env;
	int			status;
}	t_expand_ctx;

typedef enum commad_flags
{
	CMD,
	BUILTIN
}	t_cmd_flags;

typedef enum redir_types
{
	INFILE,
	HERE_DOC,
	OUTFILE,
	APPEND
}	t_redir_types;

int			builtin_cd(t_cmd_node *cmd_node, t_env_list *env_list,
				int *last_exit_status);
void		builtin_echo(t_cmd_node *cmd_node, int *last_exit_status);
void		builtin_exit(t_cmd_node *cmd_node, int *last_exit_status);
void		builtin_export(t_cmd_node *cmd_node, t_env_list *env_list,
				int *last_exit_status);
void		builtin_pwd(int *last_exit_status);
void		check_cmd_or_builtin(t_cmd_node *node, int *last_exit_status,
				t_cmd_list *cmd_list, char *input);
void		execute_cmd(t_cmd_node *node, int *last_exit_status,
				t_cmd_list *cmd_list, char *input);
int			check_what_builtin(t_cmd_node *node, t_env_list *env_list,
				int *last_exit_status);
int			process(t_cmd_list *cmd_list, int *last_exit_status, char *input);
int			redir_heredoc(t_file_node *file_node, t_env_list *env_list,
				char *tmpfile);
int			check_redir(t_file_node *file_node);
int			redir_infile(t_file_node *file_node);
int			redir_outfile(t_file_node *file_node);
int			redir_append(t_file_node *file_node);
void		builtin_env(t_env_list *env_list, int *last_exit_status);
void		builtin_unset(t_cmd_node *cmd_node, t_env_list *env_list,
				int *last_exit_status);
t_env_node	**sort_list(t_env_list *env_list);
int			free_argv(char **argv);
char		*key_plus_val(t_env_node *current);
char		*find_path(char *cmd, t_env_list *env_lists);
int			is_valid_key(char *str);
void		handle_signals_heredoc(void);
void		handle_signals_main(void);
int			setup_redir(t_cmd_node *node);
int			heredoc_setup(t_cmd_list *cmd_list);
int			*non_interactice_shell(t_env_list *env_list);
void		mute_signals(void);
char		*get_env_value(t_env_list *env_list, const char *key);
void		update_env(t_env_list *env_list, const char *old, const char *new);
void		invalid_error(t_cmd_node *cmd_node, int *last_exit_status, int i);
int			free_child(int *last_exit_status, t_cmd_list *cmd_list,
				char *input);
void		handle_sigint_main(int sig);
void		handle_sigint_heredoc(int sig);
void		handle_sigquit_heredoc(int sig);
void		empty_error(int *last_exit_status, t_env_list *env_list);
void		malexit(t_env_list *env_list);
void		status_handler(int *last_exit_status);
int			isempty(char *input);
int			count_args(t_token *current);
char		**build_args_array(t_token **args, int count, t_parser *parser);
int			parse_single_redirect(t_parser *parser, t_file_list *files);
t_token		*advance(t_parser *parser);
int			get_word_len(char *input, int i);
t_token		*tokenize(char *input);
t_token		*create_token(t_token_type type, char *value);
void		add_token(t_token **head, t_token *new_token);
void		free_tokens(t_token *tokens);
int			skip_whitespace(char *input, int i);
t_cmd_list	*parse_input(char *input, t_env_list *env_list,
				int last_exit_status);
t_cmd_node	*parse_command(t_parser *parser);
t_file_list	*parse_redirections(t_parser *parser);
char		**parse_arguments(t_parser *parser);
char		*expand_variables(char *str, t_env_list *env_list,
				int last_exit_status);
char		*get_var_name(char *str, int *i);
char		*get_var_value(char *var_name, t_env_list *env_list,
				int last_exit_status);
char		*expand_in_double_quotes(char *str, t_env_list *env_list,
				int last_exit_status);
char		*expand_regular(char *str, t_env_list *env_list,
				int last_exit_status);
char		*expand_env_var(char *str, t_env_list *env_list,
				int last_exit_status);
char		*remove_quotes(char *str);
int			is_quoted(char *str, int index);
int			is_builtin(char *cmd);
int			is_whitespace(char c);
int			is_special_char(char c);
char		*get_env_var(t_env_list *env_list, char *key);
int			validate_syntax(t_token *tokens);
int			has_unclosed_quote(const char *s);
t_file_node	*create_file_node(char *filename, int redir_type);
void		add_file_node(t_file_list *list, t_file_node *node);
t_cmd_node	*create_cmd_node(void);
void		add_cmd_node(t_cmd_list *list, t_cmd_node *node);
t_cmd_list	*init_cmd_list(t_env_list *env_list);
t_env_list	*init_env_list(char **envp);
void		free_env_list(t_env_list *env_list);
void		free_cmd_list(t_cmd_list *cmd_list);
char		*ft_strjoin_free(char *s1, char *s2);
char		*get_input(int is_tty);
int			handle_empty_input(char *input);
void		shell_loop(t_env_list *env_list, int is_tty);
char		*get_unique_name(void);

#endif