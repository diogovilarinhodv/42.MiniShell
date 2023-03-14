#################################################################################################
# 										VARIABLES												#
#################################################################################################

#	MAKEFLAGS += --silent

#NAME
NAME						=	minishell

# Compiler
Compile						=	cc -Wall -Wextra -Werror -fsanitize=address

# Flags for Compiler
O_FLAG 						=	-o
C_FLAG 						=	-c

# Command for Library
AR							=	ar rc

INC							=	-I includes

# Folder Management
RM							=	rm -rf
CREATE_FOLDER 				=	mkdir -p

# Norminette
NORM 						=	norminette

#################################################################################################
# 										FOLDERS													#
#################################################################################################

SRC_FOLDER					=	srcs
OBJ_FOLDER					=	objs
INC_FOLDER					=	incs
LIB_FOLDER					=	libs


#################################################################################################
# 										FILES													#
#################################################################################################

OBJS						=	$(SOURCE:.c=.o)

LIB_FILE					=	libft.a

SOURCE						= srcs/1.checks_env/1.is_valid/is_valid_env_var.c \
								srcs/1.checks_env/1.is_valid/is_valid_stdin_fd.c \
								srcs/1.checks_env/checks_env.c \
								srcs/2.initialize/1.initialize_env/set_env_lst_alloc_name.c \
								srcs/2.initialize/1.initialize_env/set_env_lst_alloc_value.c \
								srcs/2.initialize/1.initialize_env/set_env_lst_get_name.c \
								srcs/2.initialize/1.initialize_env/set_env_lst_get_value_idx.c \
								srcs/2.initialize/1.initialize_env/set_env_lst_get_value.c \
								srcs/2.initialize/1.initialize_env/set_env_lst_set_qty.c \
								srcs/2.initialize/1.initialize_env/set_env_lst.c \
								srcs/2.initialize/1.initialize_env/shlvl_env_default_config.c \
								srcs/2.initialize/1.initialize_env/shlvl_env_increase.c \
								srcs/2.initialize/2.initialize_termcaps/set_termcap_backspace.c \
								srcs/2.initialize/2.initialize_termcaps/set_termcap_buffer.c \
								srcs/2.initialize/2.initialize_termcaps/set_termcap_cursor.c \
								srcs/2.initialize/2.initialize_termcaps/set_termcap_delete.c \
								srcs/2.initialize/2.initialize_termcaps/set_termcap_keys_on_off.c \
								srcs/2.initialize/2.initialize_termcaps/set_termcap_keys_up_down.c \
								srcs/2.initialize/2.initialize_termcaps/set_termcap_old_term.c \
								srcs/2.initialize/2.initialize_termcaps/valid_termcap_config.c \
								srcs/2.initialize/3.initialize_signals/signal_catch_sigint.c \
								srcs/2.initialize/3.initialize_signals/signal_catch_sigquit.c \
								srcs/2.initialize/initialize.c \
								srcs/2.initialize/initialize_env.c \
								srcs/2.initialize/initialize_signals.c \
								srcs/2.initialize/initialize_termcaps.c \
								srcs/2.initialize/initialize_fd.c \
								srcs/2.initialize/initialize_history.c \
								srcs/2.initialize/initialize_input.c \
								srcs/2.initialize/initialize_table.c \
								srcs/3.read_line/1.is/is_arrow.c \
								srcs/3.read_line/1.is/is_backspace.c \
								srcs/3.read_line/1.is/is_ctrl_c.c \
								srcs/3.read_line/1.is/is_ctrl_d.c \
								srcs/3.read_line/1.is/is_ctrl.c \
								srcs/3.read_line/1.is/is_down_arrow.c \
								srcs/3.read_line/1.is/is_up_arrow.c \
								srcs/3.read_line/1.is/is_tab.c \
								srcs/3.read_line/2.execute/execute_delete_char.c \
								srcs/3.read_line/2.execute/execute_down_arrow.c \
								srcs/3.read_line/2.execute/execute_up_arrow.c \
								srcs/3.read_line/2.execute/execute_tab.c \
								srcs/3.read_line/3.history/add_first_line_to_history.c \
								srcs/3.read_line/3.history/add_line_to_history.c \
								srcs/3.read_line/3.history/add_other_line_to_history.c \
								srcs/3.read_line/3.history/has_history.c \
								srcs/3.read_line/3.history/select_history_cmd.c \
								srcs/3.read_line/3.history/set_history_idx.c \
								srcs/3.read_line/4.input/get_input_str.c \
								srcs/3.read_line/4.input/set_input_line.c \
								srcs/3.read_line/read_char.c \
								srcs/3.read_line/read_line.c \
								srcs/3.read_line/reset_line.c \
								srcs/3.read_line/write_prompt.c \
								srcs/4.check_line/1.is/is_line_empty.c \
								srcs/4.check_line/2.remove/remove_left_spaces.c \
								srcs/4.check_line/2.remove/remove_right_spaces.c \
								srcs/4.check_line/2.remove/remove_spaces_bysides.c \
								srcs/4.check_line/3.checks_unexpected_token/checks_chars.c \
								srcs/4.check_line/3.checks_unexpected_token/checks_sequences.c \
								srcs/4.check_line/3.checks_unexpected_token/has_char_at_begin.c \
								srcs/4.check_line/3.checks_unexpected_token/has_char_at_end.c \
								srcs/4.check_line/3.checks_unexpected_token/has_forbidden_sequence.c \
								srcs/4.check_line/3.checks_unexpected_token/has_open_quotes.c \
								srcs/4.check_line/3.checks_unexpected_token/has_spaces.c \
								srcs/4.check_line/4.checks_invalid_token/invalid_and.c \
								srcs/4.check_line/4.checks_invalid_token/invalid_token.c \
								srcs/4.check_line/4.checks_invalid_token/space_between_char.c \
								srcs/4.check_line/checks_input.c \
								srcs/4.check_line/checks_invalid_token.c \
								srcs/4.check_line/checks_unexpected_token.c \
								srcs/5.input_handler/1.token_creation/create_token.c \
								srcs/5.input_handler/1.token_creation/exist_token.c \
								srcs/5.input_handler/1.token_creation/is_quote.c \
								srcs/5.input_handler/2.token_creation_get/get_quote_pos_end.c \
								srcs/5.input_handler/2.token_creation_get/get_token_pos_begin.c \
								srcs/5.input_handler/2.token_creation_get/get_token_pos_end.c \
								srcs/5.input_handler/2.token_creation_get/get_tokens.c \
								srcs/5.input_handler/3.set_tokens/cmd_limiter_run.c \
								srcs/5.input_handler/3.set_tokens/non_cmd_limiter_run.c \
								srcs/5.input_handler/4.set_tokens_is/is_cmd_delimiter.c \
								srcs/5.input_handler/4.set_tokens_is/is_first_cmd.c \
								srcs/5.input_handler/4.set_tokens_is/is_first_table.c \
								srcs/5.input_handler/4.set_tokens_is/is_redirection.c \
								srcs/5.input_handler/4.set_tokens_is/is_table_delimiter.c \
								srcs/5.input_handler/5.set_tokens_add_table/add_another_table.c \
								srcs/5.input_handler/5.set_tokens_add_table/add_first_table.c \
								srcs/5.input_handler/6.set_tokens_add_cmd/add_another_cmd.c \
								srcs/5.input_handler/6.set_tokens_add_cmd/add_first_cmd.c \
								srcs/5.input_handler/7.set_tokens_add_token/add_another_token.c \
								srcs/5.input_handler/7.set_tokens_add_token/add_first_token.c \
								srcs/5.input_handler/7.set_tokens_add_token/add_token.c \
								srcs/5.input_handler/8.set_tokens_add_redirections/add_another_redirection.c \
								srcs/5.input_handler/8.set_tokens_add_redirections/add_delimiter.c \
								srcs/5.input_handler/8.set_tokens_add_redirections/add_first_redirection.c \
								srcs/5.input_handler/8.set_tokens_add_redirections/add_redirection_token.c \
								srcs/5.input_handler/8.set_tokens_add_redirections/add_redirection_type.c \
								srcs/5.input_handler/organize.c \
								srcs/5.input_handler/running.c \
								srcs/8.execute/1.heredoc/heredoc_delete.c \
								srcs/8.execute/1.heredoc/heredoc_execute.c \
								srcs/8.execute/1.heredoc/heredoc_read_char.c \
								srcs/8.execute/1.heredoc/is_heredoc.c \
								srcs/8.execute/1.heredoc/heredoc_write_on_file.c \
								srcs/8.execute/1.heredoc/is_heredoc_terminator_str.c \
								srcs/8.execute/1.heredoc/heredoc_reset_line.c \
								srcs/8.execute/1.heredoc/heredoc_ctrl_c.c \
								srcs/8.execute/1.heredoc/heredoc_ctrl_d.c \
								srcs/8.execute/1.heredoc/heredoc_delete_char.c \
								srcs/8.execute/2.file_open/file_open.c \
								srcs/8.execute/2.file_open/file_open_double_right_arrow.c \
								srcs/8.execute/2.file_open/file_open_double_left_arrow.c \
								srcs/8.execute/2.file_open/file_open_left_arrow.c \
								srcs/8.execute/2.file_open/file_open_right_arrow.c \
								srcs/8.execute/3.replace_tokens/replace_tokens_quotes.c \
								srcs/8.execute/3.replace_tokens/push_one_char.c \
								srcs/8.execute/3.replace_tokens/replace_double_quotes.c \
								srcs/8.execute/3.replace_tokens/is_double_quote.c \
								srcs/8.execute/3.replace_tokens/is_cipher.c \
								srcs/8.execute/builtins.c \
								srcs/8.execute/children_process.c \
								srcs/8.execute/close_std_fd.c \
								srcs/8.execute/execute_cmd.c \
								srcs/8.execute/execute_table.c \
								srcs/8.execute/execute.c \
								srcs/8.execute/execve_error.c \
								srcs/8.execute/exit_table.c \
								srcs/8.execute/non_builtin.c \
								srcs/8.execute/replace_redirects.c \
								srcs/8.execute/replace_tokens.c \
								srcs/8.execute/save_std_fd.c \
								srcs/8.execute/set_env_var_full.c \
								srcs/8.execute/set_exit_status_env.c \
								srcs/8.execute/set_last_cmd_env.c \
								srcs/8.execute/set_redirects.c \
								srcs/8.execute/unset_env_var_full.c \
								srcs/8.execute/wait_child_pids.c \
								srcs/9.replace_tokens/remove_double_quotes.c \
								srcs/9.replace_tokens/remove_single_quotes.c \
								srcs/9.replace_tokens/replace_env_var.c \
								srcs/9.replace_tokens/replace_home_dir.c \
								srcs/9.replace_tokens/token_has_cipher.c \
								srcs/9.replace_tokens/token_has_single_quotes.c \
								srcs/9.replace_tokens/token_has_double_quotes.c \
								srcs/9.replace_tokens/token_has_tilde.c \
								srcs/10.replace_env_vars/append_tkn_replace.c \
								srcs/10.replace_env_vars/create_tkn_replace.c \
								srcs/10.replace_env_vars/get_str_one_replace.c \
								srcs/10.replace_env_vars/get_str_two_replace.c \
								srcs/10.replace_env_vars/tkn_replace.c \
								srcs/10.replace_env_vars/new_tkn_replace.c \
								srcs/11.builtins/builtin_cd.c \
								srcs/11.builtins/builtin_echo.c \
								srcs/11.builtins/builtin_env.c \
								srcs/11.builtins/builtin_exit.c \
								srcs/11.builtins/builtin_export.c \
								srcs/11.builtins/builtin_history.c \
								srcs/11.builtins/builtin_pwd.c \
								srcs/11.builtins/builtin_unset.c \
								srcs/11.builtins/1.builtin_cd/cd_arg.c \
								srcs/11.builtins/1.builtin_cd/cd_back.c \
								srcs/11.builtins/1.builtin_cd/cd_execute_no_arg.c \
								srcs/11.builtins/1.builtin_cd/cd_execute_one_arg.c \
								srcs/11.builtins/1.builtin_cd/cd_update_pwd_oldpwd.c \
								srcs/11.builtins/2.builtin_echo/echo_has_new_line.c \
								srcs/11.builtins/3.builtin_export/export_set_name.c \
								srcs/11.builtins/3.builtin_export/export_set_value.c \
								srcs/12.file_descriptors/close_all_fd.c \
								srcs/12.file_descriptors/close_fd.c \
								srcs/12.file_descriptors/is_first_cmd_fd.c \
								srcs/12.file_descriptors/is_last_cmd_fd.c \
								srcs/12.file_descriptors/is_middle_cmd_fd.c \
								srcs/12.file_descriptors/is_only_one_cmd_fd.c \
								srcs/12.file_descriptors/set_dup2.c \
								srcs/13.path_handler/get_path.c \
								srcs/13.path_handler/is_correct_path.c \
								srcs/13.path_handler/path_handler.c \
								srcs/13.path_handler/set_path.c \
								srcs/14.env_handler/get_env_idx.c \
								srcs/14.env_handler/get_env_value.c \
								srcs/14.env_handler/set_env.c \
								srcs/14.env_handler/unset_env.c \
								srcs/15.utils/count_chr.c \
								srcs/15.utils/end_program.c \
								srcs/15.utils/set_cur.c \
								srcs/15.utils/turn_off_canonical.c \
								srcs/15.utils/turn_on_canonical.c \
								srcs/15.utils/unset_cur.c \
								srcs/15.utils/get_str_without_spaces.c \
								srcs/15.utils/is_number.c \
								srcs/15.utils/jump_quotes.c \
								srcs/15.utils/write_str.c \
								srcs/16.libft/ft_atoi.c \
								srcs/16.libft/ft_bzero.c \
								srcs/16.libft/ft_isascii.c \
								srcs/16.libft/ft_isspace.c \
								srcs/16.libft/ft_itoa.c \
								srcs/16.libft/ft_putint.c \
								srcs/16.libft/ft_putstr.c \
								srcs/16.libft/ft_strchr.c \
								srcs/16.libft/ft_strcmp.c \
								srcs/16.libft/ft_strcpy.c \
								srcs/16.libft/ft_strdup.c \
								srcs/16.libft/ft_strjoin.c \
								srcs/16.libft/ft_strlen.c \
								srcs/16.libft/ft_strncmp.c \
								srcs/16.libft/ft_strndup.c \
								srcs/16.libft/ft_substr.c \
								srcs/17.errors/invalid_input.c \
								srcs/18.free/free_env.c \
								srcs/18.free/free_input.c \
								srcs/18.free/free_store.c \
								srcs/18.free/free_str_bd_src.c \
								srcs/18.free/free_str_bidimensional.c \
								srcs/18.free/free_str.c \
								srcs/18.free/free_table_all_fd.c \
								srcs/18.free/free_table_fd.c \
								srcs/18.free/free_termcaps.c \
								srcs/main.c

#################################################################################################
# 										RULES													#
#################################################################################################

# all
all: $(NAME)

# Build Project
$(NAME): $(OBJS)
					$(Compile) $(OBJS) -o $(NAME) -lncurses -ltermcap

# Clean Project
clean:
					$(RM) $(OBJ_FILES) $(OBJS)
					$(RM) $(NAME)

fclean:				clean
					$(RM) $(NAME)

# Clean and Build Project
re:					fclean $(NAME)

# Phony (it makes clear that isn't a file but a command of the Makefile)
.PHONY:				all clean fclean re