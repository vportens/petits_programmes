/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:43:42 by anclarma          #+#    #+#             */
/*   Updated: 2022/05/15 20:27:49 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDLE_HPP
# define WORDLE_HPP

# include <vector>

# define WORDLE_NB_LINE		6U
# define WORDLE_NB_LETTER	5U

# define WORDLE_DEFAULT_PWD	"antoi"

# define COLOR_GREEN		"\033[1;32m"
# define COLOR_YELOW		"\033[1;33m"
# define COLOR_RESET		"\033[0m"

class	wordle
{
	public:
		wordle(void);
		wordle(wordle const &src);
		wordle(std::string const &filename);
		virtual	~wordle(void);

		wordle	&operator=(wordle const &rhs);
		void	printTitle(void) const;
		void	printGrid(void) const;
		void	getAttemp(void);
		void	attempt(std::string const &word);
		bool	game(void);
		bool	isWin(void) const;
		bool	isWord(std::string const &word) const;
		bool	isValidWord(std::string const &word) const;
		bool	chooseSecretWord(void);
	private:
		std::string					_lines[WORDLE_NB_LINE];
		unsigned int				_index;
		std::string					_secretWord;
		std::string					_wordList;
		std::vector<std::string>	_vectorPasswd;
};

#endif
