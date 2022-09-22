/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:48:56 by dpestana          #+#    #+#             */
/*   Updated: 2022/07/21 00:47:30 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static	int	have_newline_builtin_echo(t_data *data, int *y)
{
	if (data->line.cmd->qty > 1)
	{
		if (ft_strncmp(*data->line.cmd->token, "-n", ft_strlen(*data->line.cmd->token)) == 0)
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

	str = ft_substr(*(data->line.cmd->token + y), beg_pos, x - beg_pos);
	env_val = get_env_value(data, str);
	free(str);
	if (env_val != NULL)
	{
		printf("%s", env_val);
		if (y + 1 < data->line.cmd->qty)
			if (*(*(data->line.cmd->token + y) + x) != '$')
				printf(" ");
	}
}

static	void	print_args(t_data *data, int y, int x, int beg_pos)
{
	char	*str;

	str = ft_substr(*(data->line.cmd->token + y), beg_pos, x - beg_pos);
	printf("%s", str);
	if (y + 1 < data->line.cmd->qty)
		if (*(*(data->line.cmd->token + y) + x) != '$')
			printf(" ");
	free(str);
}

static	void	execute_builtin_echo(t_data *data, int y, int x)
{
	int		count;
	int		beg_pos;

	count = 0;
	beg_pos = 0;
	while (*(*(data->line.cmd->token + y) + x) != '\0')
	{
		if (*(*(data->line.cmd->token + y) + x) == '$')
		{
			if (x > 0 && count == 0)
				print_args(data, y, x, beg_pos);
			else if (x > 0)
				print_env_value(data, y, x, beg_pos);
			count++;
			beg_pos = x + 1;
		}
		x++;
	}
	if (count == 0)
		print_args(data, y, x, beg_pos);
	if (count > 0)
		print_env_value(data, y, x, beg_pos);
}

void	builtin_echo(t_data *data)
{
	int		x;
	int		y;
	int		has_newline;

	x = 0;
	y = 0;
	has_newline = have_newline_builtin_echo(data, &y);
	while (y < data->line.cmd->qty)
	{
		execute_builtin_echo(data, y, x);
		y++;
	}
	if (has_newline == 1)
		printf("\n");
}
