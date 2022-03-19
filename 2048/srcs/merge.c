/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:17:54 by marnaudy          #+#    #+#             */
/*   Updated: 2022/03/19 20:41:08 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	merge_left(int board[5][5], int size, int *score)
{
	int	i;
	int	j;
	int	k;
	int	ret;

	i = 0;
	ret = 1;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (board[i][j] != 0)
			{
				k = j + 1;
				while (k < size)
				{
					if (board[i][k] == board[i][j])
					{
						board[i][j] *= 2;
						*score = *score + board[i][j];
						board[i][k] = 0;
						ret = 0;
						break ;
					}
					if (board[i][k] != 0)
						break ;
					k++;	
				}
			}
			j++;
		}
		i++;
	}
	return (ret);
}

int	merge_right(int board[5][5], int size, int *score)
{
	int	i;
	int	j;
	int	k;
	int	ret;

	i = 0;
	ret = 1;
	while (i < size)
	{
		j = size - 1;
		while (j > 0)
		{
			if (board[i][j] != 0)
			{
				k = j - 1;
				while (k >= 0)
				{
					if (board[i][k] == board[i][j])
					{
						board[i][j] *= 2;
						*score = *score + board[i][j];
						board[i][k] = 0;
						ret = 0;
						break ;
					}
					if (board[i][k] != 0)
						break ;
					k--;	
				}
			}
			j--;
		}
		i++;
	}
	return (ret);
}

int	merge_up(int board[5][5], int size, int *score)
{
	int	i;
	int	j;
	int	k;
	int	ret;

	i = 0;
	ret = 1;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (board[j][i] != 0)
			{
				k = j + 1;
				while (k < size)
				{
					if (board[k][i] == board[j][i])
					{
						board[j][i] *= 2;
						*score = *score + board[j][i];
						board[k][i] = 0;
						ret = 0;
						break ;
					}
					if (board[k][i] != 0)
						break ;
					k++;	
				}
			}
			j++;
		}
		i++;
	}
	return (ret);
}

int	merge_down(int board[5][5], int size, int *score)
{
	int	i;
	int	j;
	int	k;
	int	ret;

	i = 0;
	ret = 1;
	while (i < size)
	{
		j = size - 1;
		while (j > 0)
		{
			if (board[j][i] != 0)
			{
				k = j - 1;
				while (k >= 0)
				{
					if (board[k][i] == board[j][i])
					{
						board[j][i] *= 2;
						*score = *score + board[j][i];
						board[k][i] = 0;
						ret = 0;
						break ;
					}
					if (board[k][i] != 0)
						break ;
					k--;	
				}
			}
			j--;
		}
		i++;
	}
	return (ret);
}
