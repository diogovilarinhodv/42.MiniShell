/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 15:12:28 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/08 15:19:14 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

//		--------
//		  NES
//		--------
typedef struct s_nes
{
	int			val;

}	t_nes;

//     -----------     
//        TERMS CAPS      
//     -----------  
typedef struct s_termcaps
{
	struct termios	old_term;
	struct termios	new_term;
	char			*buffer;
	char			*keys_on;
	char			*keys_off;
	char			*up_arrow;
	char			*down_arrow;
	char			*backspace;
	char			*del_line;
	char			*set_cursor_begin;

}	t_termcaps;

//     -----------     
//        ENV VAR         
//     -----------     
typedef struct s_env_var
{
	char			**name;
	char			**value;
	char			**full;
	int				qty;

}	t_env_var;

//		--------
//		 INPUT
//		--------
typedef struct s_input
{
	char			*line;
	int				idx;
	char			*buf;
	int				buf_idx;
	char			*cur_buf;

}	t_input;

//		--------
//		REDIRECT
//		--------
typedef struct s_red
{
	char	*token;
	int		type;

}	t_red;

//     -----------     
//        CMD        
//     -----------   
typedef struct s_cmd
{
	char			**token;
	int				qty_tkn;
	t_red			*red;
	int				is_heredoc;
	int				is_red;
	int				qty_red;
	int				pid;
	int				is_builtin;
	int				not_execute_heredoc;

}	t_cmd;

//     -----------     
//        TABLE        
//     -----------     
typedef struct s_table
{
	t_cmd			*cmd;
	int				**fd;
	int				qty_cmd;
	int				delimiter;

}	t_table;

//     -----------     
//        STORAGE         
//     -----------    
typedef struct s_storage
{
	t_table			*table;
	int				qty_tbl;

}	t_storage;

//		--------
//		CURRENT
//		--------
typedef struct s_current
{
	t_table	*table;
	t_cmd	*cmd;
	char	*token;
	int		idx_cmd;

}	t_current;

//		--------
//		HISTORY
//		--------
typedef struct s_history
{
	char	**str;
	int		qty_str;
	int		idx;

}	t_history;

//     -----------     
//        DATA         
//     -----------     
typedef struct s_data
{
	t_input			input;
	t_storage		store;
	t_current		cur;
	t_env_var		env;
	t_termcaps		termcaps;
	t_history		hist;
	int				exit_status;

}	t_data;

#endif