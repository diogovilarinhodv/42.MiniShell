/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 15:12:28 by dpestana          #+#    #+#             */
/*   Updated: 2022/11/05 10:33:36 by dpestana         ###   ########.fr       */
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
//		  TMP
//		--------
typedef struct s_tmp_vars
{
	int				**fd;
	int				*pid;

}	t_tmp_vars;

//		--------
//		CURRENT
//		--------
typedef struct s_current
{
	t_table	*table;
	t_cmd	*cmd;
	int		idx_cmd;

}	t_current;

//     -----------     
//        DATA         
//     -----------     
typedef struct s_data
{
	t_input			input;
	t_storage		store;
	t_current		cur;
	t_env_var		env;
	t_tmp_vars		tmp;

}	t_data;

#endif