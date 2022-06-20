/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 15:12:28 by dpestana          #+#    #+#             */
/*   Updated: 2022/06/19 18:10:10 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H


//     -----------     
//        COMMAND         
//     -----------     
typedef struct s_input_line
{
	char	*line;
	char	*cmd;
	char	**args;
	int		qty_args;

}	t_input_line;

//     -----------     
//        DATA         
//     -----------     
typedef struct s_data
{
	t_input_line	input;
	char			*pwd;

}	t_data;

#endif