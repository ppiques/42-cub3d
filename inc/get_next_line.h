/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:38:44 by user42            #+#    #+#             */
/*   Updated: 2022/06/23 19:49:37 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdlib.h>
# include <unistd.h>

int		for_the_norme(char *stock);
int		next_endl(char *s);
int		gnl_strlen(char *s);
char	*append(char *buf, char *stock, int nb_read);
char	*gnl_strdup(char *s);
char	*almost_split(char *stock, char **line, int next);
int		main_get_next_line(int fd, char **line);
int		get_next_line(int fd, char **line);

#endif
