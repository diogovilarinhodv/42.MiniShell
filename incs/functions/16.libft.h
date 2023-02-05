/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   16.libft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:15:43 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/05 20:15:57 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// 16.LIBFT
size_t	ft_strlen(const char *s);
char	*ft_strchr(char *str, char ch);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, int qty);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_isspace(int c);
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
void	ft_bzero(void *s, size_t n);
int		ft_isascii(int c);
int		ft_putint(int c);
char	*ft_strcpy(char *dest, const char *src);
int		ft_putstr(char *str);

#endif