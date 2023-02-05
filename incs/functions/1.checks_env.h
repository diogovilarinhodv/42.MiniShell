/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.checks_env.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:07:51 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/05 20:08:32 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKS_ENV_H
# define CHECKS_ENV_H

// 1.CHECKS_ENV
void	checks_env(char **env);

// 1.CHECKS_ENV > 1.is_valid
void	is_valid_env_var(char **env);
void	is_valid_stdin_fd(void);

#endif