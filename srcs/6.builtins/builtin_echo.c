/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:48:56 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/05 17:39:02 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static	int	has_newline_func(t_data *data, int *y)
{
	if (data->tmp.cmd->qty_tkn > 1)
	{
		if (ft_strncmp(*data->tmp.cmd->token, "-n", ft_strlen(*data->tmp.cmd->token)) == 0)
		{
			(*y)++;
			return (NO);
		}
	}
	return (YES);
}

static	void	print_env_value(t_data *data, int y, int x, int beg_pos)
{
	char	*str;
	char	*env_val;

	str = ft_substr(*(data->tmp.cmd->token + y), beg_pos, x - beg_pos);
	env_val = get_env_value(data, str);
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	if (env_val != NULL)
	{
		printf("%s", env_val);
		if (y + 1 < data->tmp.cmd->qty_tkn)
			if (*(*(data->tmp.cmd->token + y) + x) != '$')
				printf(" ");
	}
}

static	void	print_str(t_data *data, int y, int x, int beg_pos)
{
	char	*str;

	str = ft_substr(*(data->tmp.cmd->token + y), beg_pos, x - beg_pos);
	printf("%s", str);
	if (y + 1 < data->tmp.cmd->qty_tkn)
		if (*(*(data->tmp.cmd->token + y) + x) != '$')
			printf(" ");
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
}

static	void	execute_builtin_echo(t_data *data, int y, int x)
{
	int		count;
	int		beg_pos;

	count = 0;
	beg_pos = 0;
	while (*(*(data->tmp.cmd->token + y) + x) != '\0')
	{
		if (*(*(data->tmp.cmd->token + y) + x) == '$')
		{
			if (x > 0 && count == 0)
				print_str(data, y, x, beg_pos);
			else if (x > 0)
				print_env_value(data, y, x, beg_pos);
			count++;
			beg_pos = x + 1;
		}
		x++;
	}
	if (count == 0)
		print_str(data, y, x, beg_pos);
	if (count > 0)
		print_env_value(data, y, x, beg_pos);
}

void	builtin_echo(t_data *data)
{
	int		x;
	int		y;
	int		has_newline;

	x = 0;
	y = 1;
	has_newline = has_newline_func(data, &y);
	while (y < data->tmp.cmd->qty_tkn)
	{
		execute_builtin_echo(data, y, x);
		y++;
	}
	if (has_newline == 1)
		printf("\n");
}
