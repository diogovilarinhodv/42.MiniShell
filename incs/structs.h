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
//        INPUT         
//     -----------     
typedef struct s_lst_cmd
{
	char	*cmd;
	char	**args;
	int		qty_args;

}	t_lst_cmd;

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
	char			*line;
	t_lst_cmd		*lst_cmd;
	t_env_var		env;
	int				qty_pipes;

}	t_data;

#endif