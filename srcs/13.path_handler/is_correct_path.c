/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_correct_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:45:39 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/02 22:36:22 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	is_correct_path(char *path)
{
	struct stat	statbuf;

	if (stat(path, &statbuf) == EXIT_SUCCESS)
		return (YES);
	return (NO);
}
