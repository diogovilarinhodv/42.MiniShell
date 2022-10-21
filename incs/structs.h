/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 15:12:28 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/21 13:40:03 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

//     -----------     
//        ENV VAR         
//     -----------     
typedef struct s_env_var
{
	char	**name;
	char	**value;
	int		qty;

}	t_env_var;

//     -----------     
//        CMD        
//     -----------   
typedef struct s_cmd
{
	char	**token;
	int		qty_tkn;

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

//		--------
//		TMP VARS
//		--------
typedef struct s_tmp_vars
{
	t_cmd	*cmd;
	int		idx;
	int		**fd;
	int		*pid;

}	t_tmp_vars;

//		--------
//		 INPUT
//		--------
typedef struct s_input
{
	char	*line;
	int		idx;

}	t_input;


//     -----------     
//        DATA         
//     -----------     
typedef struct s_data
{
	t_input			input;
	t_table			*table;
	t_env_var		env;
	t_tmp_vars		tmp;

}	t_data;

#endif