/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <viporten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 02:56:33 by victor            #+#    #+#             */
/*   Updated: 2022/01/01 20:04:09 by viporten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub.h"
#include "./include/error.h"

int	write_error(t_data *data, int error)
{
	free_all(data);
	write(2, "Error\n", 6);
	write(2, g_error_message[error], g_error_len[error]);
	return (error);
}

void	init_cub_data(t_data *data)
{
	data->setting = NULL;
	data->engine = NULL;
}

int	main(int ac, char *av[])
{
	t_data	cub_data;
	int		ret;

	init_cub_data(&cub_data);
	if (ac != 2)
		return (write_error(&cub_data, ARG_NBR));
	ret = parsing(av[1], &cub_data);
	if (ret != 0)
		return (write_error(&cub_data, ret));
	ret = start(&cub_data);
	if (ret != 0)
		return (write_error(&cub_data, INFO));
	return (0);
}
