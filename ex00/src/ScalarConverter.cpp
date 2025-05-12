/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:51:40 by ebonutto          #+#    #+#             */
/*   Updated: 2025/05/12 16:54:16 by ebonutto         ###   ########.fr       */
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
	char	*end;
	long	nb = std::strtol(input.c_str(), &end, 10);
	if (end == input.c_str() || *end != '\0')
		return (false);
	if (nb > 2147483647 || nb < -2147483648)
		return (false);
	return (true);
}

bool	ScalarConverter::isFloat( const std::string &input ) {
	char	*end;
	float	nb = std::strtof(input.c_str(), &end);
	(void)nb;
	if (end == input.c_str() || *end != 'f' || *(end + 1) != '\0')
		return (false);
	return (true);
}

ScalarConverter::e_type	ScalarConverter::parseType( const std::string &input ) {
	if (ScalarConverter::isChar(input))
		return (CHARACTER);
	else if (ScalarConverter::isInteger(input))
		return (INTEGER);
	else if (ScalarConverter::isFloat(input))
		return (FLOAT);
	std::cout << "Ptn mais pq ??" << std::endl;
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
	int	nb = atoi(input.c_str());
	if (nb >= 32 && nb <= 126)
		std::cout << "char: " << "\'" << static_cast<char>(nb) << "\'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	std::cout << "int: " << input << std::endl;
	std::cout << "float: " << input << ".0f" << std::endl;
	std::cout << "double: " << input << ".0" << std::endl;
}

void	ScalarConverter::printFloat( const std::string &input ) {
	float	nb = std::strtof(input.c_str(), NULL);
	if (nb >= 32 && nb <= 126)
		std::cout << "char: " << "\'" << static_cast<char>(nb) << "\'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	// if (std::floor(nb) >= -2147483648 && nb <= 2147483647)
	// 	std::cout << "int: " << static_cast<int>(nb) << std::endl;
	// else
	// 	std::cout << "int: " << "Non displayable" << std::endl;
	std::cout << "float: " << input << std::endl;
	std::cout << "double: " << input << std::endl;
}

// Convert function
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
			ScalarConverter::printFloat(input);
			break;

		case DOUBLE:
			break;

		case OTHER:
			break;
	}
}
