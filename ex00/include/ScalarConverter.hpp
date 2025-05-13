/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:51:43 by ebonutto          #+#    #+#             */
/*   Updated: 2025/05/13 15:05:31 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cfloat>
#include <cmath>
#include <iomanip>

class	ScalarConverter {
private:
// Structures
	enum e_type {
		CHARACTER,
		INTEGER,
		FLOAT,
		DOUBLE,
		OTHER,
		SPECIAL
	};

// Default constructor and Destructor
	ScalarConverter( void );
	~ScalarConverter( void );

// Copy constructor
	ScalarConverter(const ScalarConverter &other);

// Copy assignment operator
	ScalarConverter	&operator=( const ScalarConverter &other );

// Special class functions
	static e_type	parseType( const std::string &input );
	static bool		isChar( const std::string &input );
	static bool		isInteger( const std::string &input );
	static bool		isFloat( const std::string &input );
	static bool		isDouble( const std::string &input );
	static bool		isSpecialConvertion( const std::string &input );

// Print functions
	static void	printChar( const std::string &input );
	static void	printInteger( const std::string &input );
	static int	getPrecision( const std::string &input );
	static void	printFloat( const std::string &input );
	static void	printDouble( const std::string &input );
	static void	printOther( void );
	static void	printSpecialConvertion( const std::string &input );

public:
// Special class functions
	static void	convert( const std::string &input );

};

#endif
