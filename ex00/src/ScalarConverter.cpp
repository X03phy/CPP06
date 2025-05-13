/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:51:40 by ebonutto          #+#    #+#             */
/*   Updated: 2025/05/13 15:15:48 by ebonutto         ###   ########.fr       */
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

bool	ScalarConverter::isDouble( const std::string &input ) {
	char	*end;
	double	nb = std::strtod(input.c_str(), &end);
	(void)nb;
	if (end == input.c_str() || *(end) != '\0')
		return (false);
	return (true);
}

bool	ScalarConverter::isSpecialConvertion( const std::string &input )
{
	if (input == "-inff" || input == "+inff" || input == "nanf" || input == "-inf" || input == "+inf" || input == "nan")
		return (true);
	return (false);
}

ScalarConverter::e_type	ScalarConverter::parseType( const std::string &input ) {
	if (ScalarConverter::isSpecialConvertion(input))
		return (SPECIAL);
	else if (ScalarConverter::isChar(input))
		return (CHARACTER);
	else if (ScalarConverter::isInteger(input))
		return (INTEGER);
	else if (ScalarConverter::isFloat(input))
		return (FLOAT);
	else if (ScalarConverter::isDouble(input))
		return (DOUBLE);
	return (OTHER);
}

// Print functions
void	ScalarConverter::printChar( const std::string &input ) {
	char	c = input[0];
	std::cout << "char: " << "\'" << c << "\'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << 'f' << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void	ScalarConverter::printInteger( const std::string &input ) {
	int	nb = atoi(input.c_str());
	if (nb >= 32 && nb <= 126)
		std::cout << "char: " << "\'" << static_cast<char>(nb) << "\'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	std::cout << "int: " << nb << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(nb) << 'f' << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(nb) << std::endl;
}

int	ScalarConverter::getPrecision( const std::string &input ) {
	int	i = 0;

	while (input[i] && input[i] != '.')
		i++;
	if (input[i] == '\0')
		return (1);
	i++;
	int	count = 0;
	while (input[i + count] && input[i + count] != 'f' && count < 6)
		count++;
	return (count);
}

void	ScalarConverter::printFloat( const std::string &input ) {
	float	nb = std::strtof(input.c_str(), NULL);

	if (nb >= 32 && nb <= 126)
		std::cout << "char: " << "\'" << static_cast<char>(nb) << "\'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;

	if (static_cast<float>(-2147483648) <= nb && nb <= static_cast<float>(2147483647))
		std::cout << "int: " << static_cast<int>(nb) << std::endl;
	else
		std::cout << "int: " << "Non displayable" << std::endl;

	int	precision = ScalarConverter::getPrecision(input);
	std::cout << "float: " << std::fixed << std::setprecision(precision) << nb << 'f' <<std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(precision) << static_cast<double>(nb) << std::endl;
}

void	ScalarConverter::printDouble( const std::string &input ) {
	double	nb = std::strtod(input.c_str(), NULL);
	if (nb >= 32 && nb <= 126)
		std::cout << "char: " << "\'" << static_cast<char>(nb) << "\'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;

	if (static_cast<double>(-2147483648) <= nb && nb <= static_cast<double>(2147483647))
		std::cout << "int: " << static_cast<int>(nb) << std::endl;
	else
		std::cout << "int: " << "Non displayable" << std::endl;

	int	precision = ScalarConverter::getPrecision(input);
	if (-FLT_MAX <= nb && nb <= FLT_MAX)
		std::cout << "float: " << std::fixed << std::setprecision(precision) << static_cast<float>(nb) << 'f' <<std::endl;
	else
		std::cout << "float: " << "Non displayable" << std::endl;

	std::cout << "double: " << std::fixed << std::setprecision(precision) << nb << std::endl;
}

void	ScalarConverter::printOther( void )
{
	std::cout << "char: " << "Non displayable" << std::endl;
	std::cout << "int: " << "Non displayable" << std::endl;
	std::cout << "float: " << "Non displayable" << std::endl;
	std::cout << "double: " << "Non displayable" << std::endl;
}

void	ScalarConverter::printSpecialConvertion( const std::string &input )
{
	std::cout << "char: " << "Impossible" << std::endl;
	std::cout << "int: " << "Impossible" << std::endl;
	if (input == "-inff") {
		std::cout << "float: " << "-inff" << std::endl;
		std::cout << "double: " << "-inf" << std::endl;
	} else if (input == "+inff") {
		std::cout << "float: " << "+inff" << std::endl;
		std::cout << "double: " << "+inf" << std::endl;
	} else if (input == "nanf") {
		std::cout << "float: " << "nanf" << std::endl;
		std::cout << "double: " << "nan" << std::endl;
	} else {	
		std::cout << "float: " << "Impossible" << std::endl;
		std::cout << "double: " << input << std::endl;
	}
}

// Convert function
void	ScalarConverter::convert( const std::string &input ) {
	ScalarConverter::e_type type = ScalarConverter::parseType(input);

	switch (type) {
		case SPECIAL:
			ScalarConverter::printSpecialConvertion(input);
			break;

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
			ScalarConverter::printDouble(input);
			break;

		case OTHER:
			ScalarConverter::printOther();
			break;
	}
}
