/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:51:40 by ebonutto          #+#    #+#             */
/*   Updated: 2025/05/02 17:06:57 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Default constructor and Destructor
ScalarConverter::ScalarConverter( void ) {}
ScalarConverter::~ScalarConverter( void ) {}

// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	(void)other;
}

// Copy assignment operator
ScalarConverter	&ScalarConverter::operator=( const ScalarConverter &other ) {
	(void)other;
	return (*this);
}

// Special class functions

// Check type functions
bool	ScalarConverter::isChar( const std::string &input ) {
	if (input.length() == 1 && !std::isdigit(input[0]))
		return (true);
	return (false);
}

bool	ScalarConverter::isInteger( const std::string &input ) {
	if (input.length() > 11)
		return (false);
	char	*end;
	long	nb = std::strtol(input.c_str(), &end, 10);
	if (nb > 2147483647 || nb < -2147483648)
		return (false);
	return (false);
}

ScalarConverter::e_type	ScalarConverter::parseType( const std::string &input ) {
	if (ScalarConverter::isChar(input))
		return (CHARACTER);
	else if (ScalarConverter::isChar(input))
		return (INTEGER);
	return (OTHER);
}

// Print functions
void	ScalarConverter::printChar( const std::string &input ) {
	char	c = input[0];
	std::cout << "char: " << "\'" << c << "\'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	ScalarConverter::printInteger( const std::string &input ) {
	char	c = input[0];
	std::cout << "char: " << "\'" << c << "\'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	ScalarConverter::convert( const std::string &input ) {
	ScalarConverter::e_type type = ScalarConverter::parseType(input);

	switch (type) {
		case CHARACTER:
			ScalarConverter::printChar(input);
			break;

		case INTEGER:
			ScalarConverter::printInteger(input);
			break;

		case FLOAT:
			break;

		case DOUBLE:
			break;

		case OTHER:
			break;
	}
}
