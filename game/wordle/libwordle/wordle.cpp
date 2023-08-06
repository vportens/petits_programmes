/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:43:08 by anclarma          #+#    #+#             */
/*   Updated: 2022/05/15 22:24:37 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <vector>
#include <string>
#include "wordle.hpp"

wordle::wordle(void) :
	_index(0),
	_secretWord(),
	_wordList(),
	_vectorPasswd()
{
	char	buf[WORDLE_NB_LETTER + 1];

	memset(buf, '_', WORDLE_NB_LETTER);
	buf[WORDLE_NB_LETTER] = '\0';
	for (unsigned int i = 0; i < WORDLE_NB_LINE; ++i)
		_lines[i] = buf;
	return ;
}

wordle::wordle(wordle const &src) :
	_index(),
	_secretWord(),
	_wordList(),
	_vectorPasswd()
{
	*this = src;
	return ;
}

wordle::wordle(std::string const &filename) :
	_index(0),
	_secretWord(),
	_wordList(filename),
	_vectorPasswd()
{
	char	buf[WORDLE_NB_LETTER + 1];

	memset(buf, '_', WORDLE_NB_LETTER);
	buf[WORDLE_NB_LETTER] = '\0';
	for (unsigned int i = 0; i < WORDLE_NB_LINE; ++i)
		_lines[i] = buf;
	return ;
}

wordle::~wordle(void)
{
	return ;
}

wordle	&wordle::operator=(wordle const &rhs)
{
	if (this != &rhs)
	{
		for (unsigned int i = 0; i < WORDLE_NB_LINE; ++i)
			this->_lines[i] = rhs._lines[i];
		this->_index = rhs._index;
		this->_secretWord = rhs._secretWord;
		this->_wordList = rhs._wordList;
	}
	return (*this);
}

void	wordle::printTitle(void) const
{
	std::cout
		<< " __          __           _ _      " << std::endl
		<< " \\ \\        / /          | | |     " << std::endl
		<< "  \\ \\  /\\  / /__  _ __ __| | | ___ " << std::endl
		<< "   \\ \\/  \\/ / _ \\| '__/ _` | |/ _ \\" << std::endl
		<< "    \\  /\\  / (_) | | | (_| | |  __/" << std::endl
		<< "     \\/  \\/ \\___/|_|  \\__,_|_|\\___|" << std::endl
		<< "                                   " << std::endl
		<< "                                   " << std::endl;
}

void	wordle::printGrid(void) const
{
	for (unsigned int i = 0; i < WORDLE_NB_LINE; ++i)
	{
		std::cout << "\t";
		for (unsigned int j = 0; j < WORDLE_NB_LETTER; ++j)
		{
			if (_lines[i][j] == toupper(_secretWord[j]))
				std::cout << COLOR_GREEN;
			else if (_secretWord.find(_lines[i][j]) != std::string::npos)
				std::cout << COLOR_YELOW;
			std::cout << _lines[i][j] << COLOR_RESET;
			if (j + 1 < WORDLE_NB_LETTER)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
}

void	wordle::getAttemp(void)
{
	std::string	word;

	std::cout << "input: ";
	std::getline(std::cin, word);
	std::transform(word.begin(), word.end(), word.begin(), ::toupper);
	if (word.size() != WORDLE_NB_LETTER)
		std::cout << "this word is not strictly equal to " << WORDLE_NB_LETTER
            << " letter" << std::endl;
	else if (!this->isWord(word))
		std::cout << "this word is not in the given word dictionary."
			<< std::endl;
	else
		this->attempt(word);
}

void	wordle::attempt(std::string const &word)
{
	for (unsigned int i = 0; word[i]; ++i)
		_lines[_index][i] = word[i];
	++this->_index;
}

bool	wordle::game(void)
{
	this->printTitle();
	if (!this->chooseSecretWord())
		return (false);
	this->printGrid();
	while (this->_index < WORDLE_NB_LINE)
	{
		this->getAttemp();
		if (std::cin.eof())
		{
			std::cout << "unexpected end of file" << std::endl;
			return (false);
		}
		this->printGrid();
		if (this->isWin())
		{
			std::cout << "Congratulations you found word " << this->_secretWord
				<< " in " << this->_index << " guesses" << std::endl;
			return (true);
		}
	}
	std::cout << "unfortunately you did not find the word " << this->_secretWord
		<< " despite " << WORDLE_NB_LINE << " guesses" << std::endl;
	return (false);
}

bool	wordle::isWin(void) const
{
	if (_index > 0)
	{
		if (_lines[_index - 1] != _secretWord)
			return (false);
		return (true);
	}
	return (false);
}

bool	wordle::isWord(std::string const &word) const
{
	if (word == _secretWord || std::find(_vectorPasswd.begin(), _vectorPasswd.end(), word)
			!= _vectorPasswd.end())
		return (true);
	return (false);
}

bool	wordle::isValidWord(std::string const &word) const
{
	if (word.length() != WORDLE_NB_LETTER)
		return (false);
	for (unsigned int i = 0; i < WORDLE_NB_LETTER; ++i)
		if (!isalpha(word[i]))
			return (false);
	return (true);
}

bool	wordle::chooseSecretWord(void)
{
	std::ifstream	infile;

	infile.open(this->_wordList.c_str());
	if (infile.is_open())
	{
		std::string					word;

		while (!infile.eof())
		{
			std::getline(infile, word);
			std::transform(word.begin(), word.end(), word.begin(), ::toupper);
			if (this->isValidWord(word))
				this->_vectorPasswd.push_back(word);
		}
		infile.close();
		std::cout << "Total words available: " << this->_vectorPasswd.size()
			<< std::endl;
		if (this->_vectorPasswd.size() > 0)
			this->_secretWord = this->_vectorPasswd[rand() % this->_vectorPasswd.size()];
		else
		{
			std::cout << "not enough words, please enter a valid dictionary"
				<< std::endl;
			return (false);
		}
	}
	else
	{
			std::cout << "Failed to open file " << _wordList
				<< ", please enter a valid dictionary" << std::endl;
			return (false);
	}
	return (true);
}
