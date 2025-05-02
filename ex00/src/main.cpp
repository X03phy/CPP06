/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 10:57:12 by ebonutto          #+#    #+#             */
/*   Updated: 2025/05/02 15:10:40 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main( int argc, char **argv ) {
	if (argc != 2) {
		std::cout << "Error" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}