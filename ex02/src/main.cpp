/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:46:50 by ebonutto          #+#    #+#             */
/*   Updated: 2025/05/14 17:49:53 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main( void ) {
	Base	*base;
	A		a;

	base = generate();
	identify(&a);
	identify(a);
	delete base;
	return (0);
}
