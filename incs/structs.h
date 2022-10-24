/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 15:12:28 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/24 13:59:56 by dpestana         ###   ########.fr       */
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
	int				qty_pipes;

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
	t_cmd			*cmd;
	int				idx;
	int				**fd;
	int				*pid;

}	t_tmp_vars;

//     -----------     
//        DATA         
//     -----------     
typedef struct s_data
{
	t_input			input;
	t_storage		store;
	t_env_var		env;
	t_tmp_vars		tmp;

}	t_data;

#endif