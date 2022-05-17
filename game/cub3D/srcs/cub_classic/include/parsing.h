/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <viporten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 02:44:00 by victor            #+#    #+#             */
/*   Updated: 2021/12/25 18:02:55 by viporten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

int	get_next_line(int fd, char **line);
int	parsing(char *av, t_data *to_fill);

#endif
