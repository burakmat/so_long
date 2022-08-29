/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:58:02 by bmat              #+#    #+#             */
/*   Updated: 2022/03/29 16:21:28 by bmat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <unistd.h>
# include <stdlib.h>

int		string_length(char *str);
int		check_newline(char *ptr);
char	*append_string(char *str, char *buf);
char	*create_first_string(char *buf);
char	*get_line(char *str);
char	*reading_from_file(int fd, char *str);
char	*shift_to_endline(char *str);
char	*get_next_line(int fd);
#endif
