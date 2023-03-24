/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_catch_sigquit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:13:49 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/24 11:14:46 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	catch_sigquit(int signum)
{
	(void)signum;
	write_str("Quit (core dumped)\n");
	kill(0, SIGCHLD);
}
