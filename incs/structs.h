/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 15:12:28 by dpestana          #+#    #+#             */
/*   Updated: 2022/07/20 18:26:36 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

//     -----------     
//        INPUT         
//     -----------     
typedef struct s_input_line
{
	char	*line;
	char	*cmd;
	char	**args;
	int		qty_args;

}	t_input_line;

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
//        DATA         
//     -----------     
typedef struct s_data
{
	t_input_line	input;
	t_env_var		env;
	char			*pwd;

}	t_data;

#endif