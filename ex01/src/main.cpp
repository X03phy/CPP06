/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:14:52 by ebonutto          #+#    #+#             */
/*   Updated: 2025/05/13 18:02:16 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serialization.hpp"

int main() {
    Data d;
    d.id = 42;
    d.name = "Pierre";

    uintptr_t raw = Serialization::serialize(&d);
    Data* restored = Serialization::deserialize(raw);

    std::cout << "Original: " << &d << "\n";
    std::cout << "Restored: " << restored << "\n";
    std::cout << "ID: " << restored->id << ", Name: " << restored->name << std::endl;

    return 0;
}