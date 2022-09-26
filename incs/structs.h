/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 15:12:28 by dpestana          #+#    #+#             */
/*   Updated: 2022/09/26 10:38:26 by dpestana         ###   ########.fr       */
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
	int		qty;

}	t_cmd;

//     -----------     
//        LINE        
//     -----------     
typedef struct s_line
{
	t_cmd			*cmd;
	int				qty_pipes;

}	t_line;

//		--------
//		TMP VARS
//		--------
typedef struct s_tmp_vars
{
	t_cmd	*cmd;
	int		idx;
	int		*fd;

}	t_tmp_vars;


//     -----------     
//        DATA         
//     -----------     
typedef struct s_data
{
	char			*input;
	t_line			line;
	t_env_var		env;
	t_tmp_vars		tmp;

}	t_data;

#endif