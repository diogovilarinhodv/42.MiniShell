/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_end_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:23:47 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/06 11:25:12 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	invalid_end_char(t_data *data, char c)
{
    int len;

    len = ft_strlen(data->input);
    if (*(data->input + len - 1) == c)
        return (FAIL);
    return (SUCCESS);
}