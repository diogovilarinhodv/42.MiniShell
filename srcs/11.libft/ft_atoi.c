/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 01:12:03 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/14 01:28:23 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static int	is_negative(int cnt, const char *nptr)
{
	if (*(nptr + cnt) == '-'
		 && ('0' <= *(nptr + (cnt + 1)) && *(nptr + (cnt + 1)) <= '9'))
		return (1);
	return (0);
}

static int	is_invalid(int cnt, const char *nptr)
{
	if ((*(nptr + cnt) == '-' || *(nptr + cnt) == '+')
		 && !('0' <= *(nptr + (cnt + 1)) && *(nptr + (cnt + 1)) <= '9'))
		return (1);
	return (0);
}

static int	is_special_char(int cnt, const char *nptr, int foundNum)
{
	if ((*(nptr + cnt) == '+' || *(nptr + cnt) == '-'
			|| (9 <= *(nptr + cnt) && *(nptr + cnt) <= 13)
			|| *(nptr + cnt) == 32)
		&& foundNum == 0)
		return (1);
	return (0);
}

static int	add_number(int cnt, const char *nptr, int *num)
{
	*num *= 10;
	*num += (*(nptr + cnt) - 48);
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	num;
	int	cnt;
	int	found_num;
	int	is_negative_num;

	num = 0;
	cnt = 0;
	found_num = 0;
	is_negative_num = 0;
	while (*(nptr + cnt) != '\0')
	{
		if (is_special_char(cnt, nptr, found_num) && is_invalid(cnt, nptr))
			return (num);
		else if (is_special_char(cnt, nptr, found_num))
			is_negative_num = is_negative(cnt, nptr);
		else if ('0' <= *(nptr + cnt) && *(nptr + cnt) <= '9')
			found_num = add_number(cnt, nptr, &num);
		else
			break ;
		cnt++;
	}
	if (is_negative_num == 1)
		num *= (-1);
	return (num);
}
