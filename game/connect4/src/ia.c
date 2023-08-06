#include "connect4.h"
#include "libft.h"
#include "stdlib.h"

int	ai_random_move(t_game *game)
{
	int	try_answer;

	try_answer = rand() % game->columns;
	while (!check_ai_input(game, try_answer))
		try_answer = rand() % game->columns;
	return (try_answer);
}

//Try to make a win in one move
int	find_obvious_win(t_game *game)
{
	int	i = -1;
	int predicted_try_score;

	while (++i < game->columns)
	{
		if (!check_ai_input(game, i))
			continue ;
		else
		{
			make_move(game, i, AI);
			predicted_try_score = get_max_align(game, AI);
			if (predicted_try_score >= 4)
			{
				ft_putstr_fd("Found a winning move\n", 1);
				return (remove_move(game, i), i);
			}
			remove_move(game, i);
		}
	}
	return (-1);
}

//Try to block a win in one move from player
int	find_obvious_counter(t_game *game)
{
	int	i = -1;
	while (++i < game->columns)
	{
		if (!check_ai_input(game, i))
			continue ;
		else
		{
			make_move(game, i, PLAYER);
			if (check_winner(game, SILENT))
			{
				ft_putstr_fd("Found a block for player winning move\n", 1);
				return (remove_move(game, i), i);
			}
			remove_move(game, i);
		}
	}
	return (-1);
}

int	ai_pseudo_smart_move(t_game *game)
{
	int	obvious_move;
	if ((obvious_move = find_obvious_win(game)) != -1)
		return (obvious_move);
	if ((obvious_move = find_obvious_counter(game)) != -1)
		return (obvious_move);

	int i = -1; 
	int current_max = 0;
	int current_max_sum = 0;
	int best_move = -1;
	int best_second_move = -1;
	int current_try_score = get_max_align(game, AI);
	int current_sum_score = get_align_score(game, AI);
	int predicted_sum_score;
	int predicted_try_score;
	int preference;
	int preference_prev = 0;

	while (++i < game->columns)
	{
		if (!check_ai_input(game, i))
		{
			preference_prev = preference;
			continue ;
		}
		else
		{
			make_move(game, i, AI);
			predicted_try_score = get_max_align(game, AI);
			predicted_sum_score = get_align_score(game, AI);
			//preference for center to build up
			if (i == game->columns / 2 || i == game->columns / 2 + 1)
				preference = 2;
			else if (i == game->columns / 2 - 1|| i == game->columns / 2 + 2)
				preference = 1;
			else
				preference = 0;
			//Try to find a move that increases the number of aligned tokens
			if (((predicted_try_score > current_max) || (predicted_try_score == current_max && preference > preference_prev))
				&& predicted_try_score > current_try_score)
			{
				current_max = predicted_try_score;
				best_move = i;
				preference_prev = preference;
			}
			//Try to find a move that increases the overall score
			if (predicted_sum_score > current_max_sum && predicted_sum_score > current_sum_score + 1)
			{
				current_max_sum = predicted_sum_score;
				best_second_move = i;
			}
			remove_move(game, i);
		}
	}
	if (best_move != -1)
		return (ft_putstr_fd("Found a move increasing number of aligned token\n", 1), best_move);
	else if (best_second_move != -1)
		return (ft_putstr_fd("Found a move increasing sum score\n", 1), best_second_move);
	else 
		return (ft_putstr_fd("No interesing move to make : going random\n", 1), ai_random_move(game));
}
