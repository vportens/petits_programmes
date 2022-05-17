#include <ncurses.h>
#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char	*start;

	if (b == NULL)
		return (NULL);
	start = b;
	while (len)
	{
		*start = c;
		start++;
		len--;
	}
	return (b);
}

void	*ft_memalloc(size_t size)
{
	void	*result;

	result = malloc(size + 1);
	if (result != NULL)
	{
		ft_memset(result, '\0', size);
	}
	return (result);
}

int	len_int(int nbr, int *sign)
{
	int	i;

	*sign = 1;
	i = 1;
	if (nbr < 0)
	{
		*sign = -1;
		i++;
	}
	while (nbr >= 10)
	{
		i++;
		nbr = nbr / 10;
	}
	return (i);
}

void	fill_new(char *new, int sign, int nbr, int j)
{
	long	cp;
	int		divid;

	cp = nbr * sign;
	divid = 1000000000;
	while (divid > cp)
		divid = divid / 10;
	while (divid >= 10)
	{
		new[j] = cp / divid + '0';
		j++;
		cp = cp % divid;
		divid = divid / 10;
	}
	new[j] = cp + '0';
	new[j + 1] = '\0';
}

char	*ft_itoa(int nbr)
{
	int		sign;
	char	*new;
	int		j;

	j = 0;
	new = ft_memalloc(len_int(nbr, &sign));
	if (new == NULL)
		return (NULL);
	if (sign == -1)
	{
		new[0] = '-';
		j++;
	}
	fill_new(new, sign, nbr, j);
	return (new);
}
