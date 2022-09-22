/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 15:12:28 by dpestana          #+#    #+#             */
/*   Updated: 2022/07/22 12:13:43 by dpestana         ###   ########.fr       */
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

//     -----------     
//        DATA         
//     -----------     
typedef struct s_data
{
	char			*input;
	t_line			line;
	t_env_var		env;

}	t_data;

#endif