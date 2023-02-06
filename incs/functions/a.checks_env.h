/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.checks_env.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:07:51 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/06 16:16:22 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_CHECKS_ENV_H
# define A_CHECKS_ENV_H

// 1.CHECKS_ENV
void	checks_env(char **env);

// 1.CHECKS_ENV > 1.is_valid
void	is_valid_env_var(char **env);
void	is_valid_stdin_fd(void);

#endif