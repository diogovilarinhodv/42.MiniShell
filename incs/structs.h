/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 15:12:28 by dpestana          #+#    #+#             */
/*   Updated: 2022/11/14 01:26:33 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

//     -----------     
//        ENV VAR         
//     -----------     
typedef struct s_env_var
{
	char			**name;
	char			**value;
	int				qty;

}	t_env_var;

//		--------
//		 INPUT
//		--------
typedef struct s_input
{
	char			*line;
	int				idx;

}	t_input;

//     -----------     
//        CMD        
//     -----------   
typedef struct s_cmd
{
	char			**token;
	int				qty_tkn;

}	t_cmd;

//     -----------     
//        TABLE        
//     -----------     
typedef struct s_table
{
	t_cmd			*cmd;
	int				**fd;
	int				qty_cmd;

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
	int		idx_cmd;

}	t_current;

//		--------
//		REDIRECTIONS
//		--------
typedef struct s_redirect
{
	char	*token;
	int		type;

}	t_redirect;

//     -----------     
//        DATA         
//     -----------     
typedef struct s_data
{
	t_input			input;
	t_storage		store;
	t_current		cur;
	t_env_var		env;
	t_redirect		*redirect;
	int				is_reditect;
	int				exit_status;

}	t_data;

#endif