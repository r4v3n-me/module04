/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchakoub <hchakoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:17:14 by hchakoub          #+#    #+#             */
/*   Updated: 2022/06/20 14:33:28 by hchakoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	this->type = "Cat";
	std::cout << "Cat default constructor has been called" << std::endl;
}


Cat::Cat(const std::string type) {
	this->type = type;
	std::cout << "Cat paramitrized constructor has been called" << std::endl;
}


Cat::Cat(const Cat& cat) {
	this->type = cat.getType();
	std::cout << "Cat copy constructor has been called" << std::endl;
}

Cat& Cat::operator=(const Cat& cat) {
	if (this == &cat)
		return (*this);
	this->type = cat.getType();
	std::cout << "cat assignment operator has been called" << std::endl;
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructor has been called " << std::endl;
}

void Cat::makeSound() const {
	std::cout << "the Cat meows" << std::endl;
}

