/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <viporten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:05:09 by viporten          #+#    #+#             */
/*   Updated: 2021/12/26 15:12:56 by viporten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define MALLOC_ERROR_TXT "Malloc error\n"
# define MALLOC_ERROR_TXT_LEN 13

static const char	*g_error_message[12] = {"none\n", "Malloc Error\n",
	"Open Error\n", "Read Error\n", "Bad name, must finish with '.cub'\n",
	"Texture invalide\n", "bad rgb for floor\n", "bad rgb for ceiling\n",
	"bad map\n", "Information Error\n",
	"Bad number of arg\n", "Invalid argument\n"};
static const int	g_error_len[12] = {5, 13, 11, 11, 34, 17, 18,
	20, 8, 18, 18, 17};

typedef enum e_error
{
	NONE,
	MALLOC,
	OPEN,
	READ,
	NAME,
	TEXTURE,
	RGB_F,
	RGB_C,
	MAP,
	INFO,
	ARG_NBR,
	ARG_INVALID
}				t_error;

int	write_error(t_data *data, int error);

#endif