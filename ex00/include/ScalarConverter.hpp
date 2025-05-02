/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:51:43 by ebonutto          #+#    #+#             */
/*   Updated: 2025/05/02 16:44:54 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

class	ScalarConverter {
private:
// Structures
	enum e_type {
		CHARACTER,
		INTEGER,
		FLOAT,
		DOUBLE,
		OTHER
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
	static bool			isChar( const std::string &input );
	static bool			isInteger( const std::string &input );

// Print functions 
	static void	printChar( const std::string &input );
	static void	printInteger( const std::string &input );
	
public:
// Special class functions
	static void	convert( const std::string &input );

};

#endif
