/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 15:12:28 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/09 21:23:20 by dpestana         ###   ########.fr       */
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
	int				is_red;
	int				qty_red;

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
	char	*token;
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
	int				exit_status;

}	t_data;

#endif