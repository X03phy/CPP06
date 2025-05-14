/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:08:33 by ebonutto          #+#    #+#             */
/*   Updated: 2025/05/14 17:46:32 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

class	Base {
public:
	virtual ~Base( void );
};

class	A: public Base {};
class	B: public Base {};
class	C: public Base {};

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif
