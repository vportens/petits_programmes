/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:38:53 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/31 12:41:40 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*Version modifiee de strjoin pour prendre en compte une s2 qui ne se finit
pas par un nulbyte. S1 peut egalement etre NULL (utile pour le passage de
la mainstr qui vaut NULL lors du premier passage et ne pas avoir a l'init
avec un nullbyte*/

static char	*ft_strrawjoin(char const *s1, char const *s2, int s2len)
{
	char	*join;
	int		i;
	int		s1len;

	join = NULL;
	i = -1;
	if (! s1 && ! s2)
		return (NULL);
	if (! s1)
		s1len = 0;
	else
		s1len = ft_strlen(s1);
	join = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (! join)
		return (NULL);
	while (++i < s1len)
		join[i] = s1[i];
	i = -1;
	while (++i < s2len)
		join[s1len + i] = s2[i];
	join[s1len + i] = '\0';
	return (join);
}

static void	multi_freenull(char **s1, char **s2, char **s3, char **s4)
{
	if (s1 && *s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2 && *s2)
	{
		free(*s2);
		*s2 = NULL;
	}
	if (s3 && *s3)
	{
		free(*s3);
		*s3 = NULL;
	}
	if (s4 && *s4)
	{
		free(*s4);
		*s4 = NULL;
	}
}

static int	load_content(int fd, char **dest)
{
	char	buf[BUFFER_SIZE];
	char	*content;
	int		cntsize;

	content = NULL;
	cntsize = read(fd, buf, BUFFER_SIZE);
	if (cntsize <= 0)
		return (cntsize);
	content = ft_strrawjoin(*dest, buf, cntsize);
	if (! content)
	{
		multi_freenull(dest, NULL, NULL, NULL);
		return (-2);
	}
	free(*dest);
	*dest = content;
	return (cntsize);
}

static void	update_str(char **togive, char **mainstr)
{
	char	*tmp;

	*togive = ft_substr(*mainstr, 0, ft_strchr(*mainstr, '\n') - *mainstr + 1);
	if (! *togive)
	{
		free(*mainstr);
		*togive = NULL;
		return ;
	}
	tmp = ft_strdup(*mainstr);
	if (! tmp)
	{
		multi_freenull(mainstr, togive, NULL, NULL);
		return ;
	}
	free(*mainstr);
	*mainstr = ft_substr(tmp, ft_strchr(tmp, '\n') - tmp + 1, ft_strlen(tmp));
	if (! *mainstr)
	{
		multi_freenull(&tmp, mainstr, togive, NULL);
		return ;
	}
	if (! ft_strlen(*mainstr))
		multi_freenull(mainstr, NULL, NULL, NULL);
	free(tmp);
}

char	*get_next_line(int fd)
{
	static char	*mainstr = NULL;
	char		*togive;
	int			read;
	int			cumulread;

	read = 0;
	cumulread = 0;
	if (load_content(fd, &mainstr) <= 0 && ! mainstr)
		return (NULL);
	while (! ft_strchr(mainstr + cumulread, '\n'))
	{
		read = load_content(fd, &mainstr);
		if (read <= 0)
		{
			if (read == -2)
				return (NULL);
			togive = ft_strdup(mainstr);
			free(mainstr);
			mainstr = NULL;
			return (togive);
		}
		cumulread += read;
	}
	update_str(&togive, &mainstr);
	return (togive);
}
