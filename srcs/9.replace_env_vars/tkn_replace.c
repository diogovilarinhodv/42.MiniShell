/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_replace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:56:54 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/13 02:57:06 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

char	*tkn_replace(t_data *data, int *inc_chr, int pos, char *new_tkn)
{
	char	*str_one;
	char	*str_two;

	str_one = get_str_one_replace(data, &inc_chr, pos);
	str_two = get_str_two_replace(data, &inc_chr);
	new_tkn = create_tkn_replace(str_one, str_two, new_tkn);
	free_str(&str_one);
	return (new_tkn);
}
