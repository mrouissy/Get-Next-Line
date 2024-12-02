/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouissy <mrouissy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:30:47 by mrouissy          #+#    #+#             */
/*   Updated: 2024/12/02 11:03:04 by mrouissy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

char	*ft_strjoin(char *s1, const char *s2);
char	*ft_strdup(const char *src);
char	*get_next_line(int fd);
int		ft_strlen(const char *str);

#endif
