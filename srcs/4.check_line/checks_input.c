/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:40:44 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 17:09:59 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	checks_input(t_data *data)
{
	if (first_check(data) == FAIL)
		return (FAIL);
	remove_spaces_bysides(data);
	if (second_check(data) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
/*
int	valid_input(const char *input)
{
	int		check;
	char	erro_msg[100];

	ft_bzero(erro_msg, 0);
	if (*input == '\0' || ft_strisspace((char *)input))
		check = 0;
	else if (!input_valid_unexpectd_token(input, erro_msg)
			|| !input_valid_not_supported(input, erro_msg))
	{
		check = 0;
		// ERRO MSG
	}
	else
		check = 1;
	return (check);
}

int	input_valid_unexpectd_token(const char *input, char *erro_msg)
{
	int	check;

	if(quotes_open(input, erro_msg)
		|| char_at_beginning(input, '|', erro_msg)
		|| char_at_beginning(input, ';', erro_msg)
		|| char_at_end(input, '|', erro_msg)
		|| char_at_end(input, '<', erro_msg)
		|| char_at_end(input, '>', erro_msg)
		|| char_at_end(input, '&', erro_msg)
		|| forbiden_sequence(input, ";;", erro_msg)
		|| forbiden_sequence(input, "|;", erro_msg)
		|| forbiden_sequence(input, "&;", erro_msg)
		|| forbiden_sequence(input, ";|", erro_msg)
		|| forbiden_sequence(input, ";&", erro_msg)
		|| forbiden_sequence(input, ">>>", erro_msg)
		|| spaces_between_char(input, '|', erro_msg)
		|| spaces_between_char(input, '>', erro_msg))
		check = 0;
	else
		check = 1;
	return (check);
}

int	input_valid_not_supported(const char *input, char *erro_msg)
{
	int	check;

	if (non_supported(input, "<<", erro_msg)
		|| non_supported(input, "*", erro_msg)
		|| non_supported(input, "\\", erro_msg)
		|| non_supported(input, "&", erro_msg))
		check = 0;
	else
		check = 1;
	return (check);
}

int	quotes_open(const char *input, char *erro_msg)
{
	int	check;
	int	has_double_quotes_open;
	int	has_single_quotes_open;

	check = 1;
	has_double_quotes_open = 0;
	has_single_quotes_open = 0;
	while (*input)
	{
		if(*input == '"' && has_single_quotes_open == 0)
			has_double_quotes_open = !has_double_quotes_open;
		else if (*input == '\'' && has_double_quotes_open == 0)
			has_single_quotes_open = !has_single_quotes_open;
		input++;
	}
	if (has_double_quotes_open || has_single_quotes_open)
	{
		check = 1;
		ft_strcpy(erro_msg, "ERRO\nopen quotes\n");
	}
	else
		check = 0;
	return (check);
}

int	char_at_beginning(const char *input, char c, char *erro_msg)
{
	int		check;
	char	*tmp;

	tmp = ft_strtrim(input, ' ');
	if (!tmp)
		// quit program
	if (tmp[0] == c)
	{
		check = 1;
		ft_strcpy(erro_msg, "ERRO\nunexpected token '");
		ft_strncat(erro_msg, &c, 1);
		ft_strncat(erro_msg, "'\n", 2);
	}
	else
		check = 0;
	free(tmp);
	return (check);
}

int	char_at_end(const char *input, char c, char *erro_msg)
{
	int		check;
	char	*tmp;
	int		len;

	tmp = ft_strtrim(input, ' ');
	if (!tmp)
		//quit program
	len = ft_strlen(tmp);
	if (tmp[len - 1] == c)
	{
		check = 1;
		ft_strcpy(erro_msg, "ERRO\nunexpected token '");
		ft_strncat(erro_msg, &c, 1);
		ft_strncat(erro_msg, "'\n", 2);
	}
	else
		check = 0;
	free(tmp);
	return (check);
}

int	forbidden_sequence(const char *input, char *test, char *erro_msg)
{
	int		check;
	char	*tmp;

	tmp = ft_strtrim_all(input, ' ');
	if (!tmp)
		//quit program
	if (ft_strstr_quotes(tmp, test) != 0)
	{
		check = 1;
		ft_strcpy(erro_msg, "ERRO\nunexpected token '");
		ft_strncat(erro_msg, test, 1);
		ft_strcat(erro_msg, "'\n", 2);
	}
	else
		check = 0;
	free(tmp);
	return (check);
}

int	space_between_char(const char *input, char c, char *erro_msg)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '"' || input[i] == '\'')
			skip_quotes(input, &i);
		if (input[i] == c && input[i + 1] == ' ')
		{
			i++;
			skip_spaces((char *)input, &i);
			if (input[i] == c)
			{
				ft_strcpy(erro_msg, "ERRO\nunexpected token '");
				ft_strncat(erro_msg, &c, 1);
				ft_strcat(erro_msg, "'\n", 2);
				return (1);
			}
		}
		if (input[i])
			i++;
	}
	return (0);
}

int	non_supported(const char *input, char *test, char *erro_msg)
{
	int	check;

	if (ft_strstr_quotes((char *)input, test) != 0)
	{
		check = 1;
		ft_strcpy(erro_msg, "\"");
		ft_strcat(erro_msg, test);
		ft_strcat(erro_msg, "ERRO\n\' not supported");
	}
	else
		check = 0;
	return (check);
}

int	non_supported_one(const char *input, char *test, char *erro_msg)
{
	int		check;
	char	*tmp;

	check = 0;
	tmp = (char *)input;
	while (tmp)
	{
		tmp = ft_strstr_quotes(tmp, test);
		if (tmp != 0 && *(tmp + 1) != *test)
		{
			check = 1;
			break;
		}
		else if (tmp != 0 && *(tmp + 1) == *test)
			tmp += 2;
	}
	if (check)
	{
		ft_strcpy(erro_msg, "\"");
		ft_strcat(erro_msg, test);
		ft_strcat(erro_msg, "ERRO\n\' not supported");
	}
	return (check);
}
*/