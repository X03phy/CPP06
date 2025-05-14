/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:13:12 by ebonutto          #+#    #+#             */
/*   Updated: 2025/05/14 17:50:47 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <cstdlib>

// Default destructor
Base::~Base( void ) {
	std::cout << "Base default Destructor called" << std::endl;
}

Base	*generate(void) {
	int	rnb = std::rand() % 3;

	switch (rnb) {
		case 0:
			std::cout << "A got instantiated" << std::endl;
			return (new A);
		case 1:
			std::cout << "B got instantiated" << std::endl;
			return (new B);
		case 2:
			std::cout << "C got instantiated" << std::endl;
			return (new C);
	}
	return (NULL);
}

void	identify(Base *p) {
	std::cout << "Identifying from pointer" << std::endl;
	if (dynamic_cast<A *>(p))
		std::cout << "p -> A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "p -> B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "p -> C" << std::endl;	
	else
		std::cout << "p -> WTF"<< std::endl;
}

void	identify(Base &p) {
	std::cout << "Identifying from reference" << std::endl;
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "p = A" << std::endl;	
		return ;
	} catch (...) {}
	try {
		(void)dynamic_cast<B &>(p);
		std::cout << "p = B" << std::endl;	
		return ;
	} catch (...) {}
	try {
		(void)dynamic_cast<C &>(p);
		std::cout << "p = C" << std::endl;
		return ;
	} catch (...) {}
	std::cout << "p = WTF"<< std::endl;
}
