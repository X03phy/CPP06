/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:09:37 by ebonutto          #+#    #+#             */
/*   Updated: 2025/05/13 17:59:29 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <stdint.h>
#include <iostream>
#include "Data.hpp"

class	Serialization
{
private:
// Default constructor and Destructor
	Serialization( void );
	~Serialization( void );

// Copy constructor
	Serialization(const Serialization &other);

// Copy assignment operator
	Serialization	&operator=( const Serialization &other );

public:
// Special class functions
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};

#endif
