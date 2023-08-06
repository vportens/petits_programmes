/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:42:40 by anclarma          #+#    #+#             */
/*   Updated: 2022/05/14 04:36:23 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "wordle.hpp"

int	main(int ac, char **av)
{
	std::string	filename;

	if (ac == 2)
		filename = av[1];
	else
		filename = "words.txt";
	srand(time(NULL));
	{
		wordle	w(filename);

		if (w.game() == true)
			return (0);
		else
			return (1);
	}
}
