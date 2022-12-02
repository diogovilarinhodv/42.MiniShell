/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:18:53 by dpestana          #+#    #+#             */
/*   Updated: 2022/12/01 15:35:56 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "../../incs/minishell.h"

void    open_file(t_data *data, t_redir *redir, int prev_fd, int flags, mode_t permissions)
{
    int file;

    file = open(file_name, flags, permissions);
    if (file == -1)
        data->exit_status = 1;
    else
    {
        if (ft_strcmp(redir->type, "<") == 0)
			dup2(file, STDIN_FILENO);

		else if (ft_strcmp(redir->type, ">") == 0 || ft_strcmp(redir->type, ">>") == 0)
			dup2(file, STDOUT_FILENO);
			
		close(file);
    }
}

void    set_redirects(t_data *data)
{
    
}
*/