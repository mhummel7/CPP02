/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:26:05 by mhummel           #+#    #+#             */
/*   Updated: 2025/02/10 12:55:11 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Int constructor
Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	value = n << fractionalBits;
}

// Float constructor
Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	value = roundf(n * (1 << fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed& src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->value = rhs.getRawBits();
	return *this;
}



// Comparison operators
bool Fixed::operator>(const Fixed& rhs) const
{
	return this->value > rhs.getRawBits();
}

bool Fixed::operator<(const Fixed& rhs) const
{
	return this->value < rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed& rhs) const
{
	return this->value >= rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed& rhs) const
{
	return this->value <= rhs.getRawBits();
}

bool Fixed::operator==(const Fixed& rhs) const
{
	return this->value == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed& rhs) const
{
	return this->value != rhs.getRawBits();
}



// Arithmetic operators
Fixed Fixed::operator+(const Fixed& rhs) const
{
	Fixed result;
	result.setRawBits(this->value + rhs.value);
	return result;
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
	Fixed result;
	result.setRawBits(this->value - rhs.value);
	return result;
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
	Fixed result;
	result.setRawBits((this->value * rhs.value) >> fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
	if (rhs.value == 0)
		throw std::runtime_error("Division by zero");
	Fixed result;
	result.setRawBits((this->value << fractionalBits) / rhs.value);
	return result;
}



// Increment and decrement operators
Fixed& Fixed::operator++() // Pre-increment
{
	this->value++;
	return *this;
}

Fixed Fixed::operator++(int) // Post-increment
{
	Fixed temp(*this);
	operator++();
	return temp;
}

Fixed& Fixed::operator--() // Pre-decrement
{
	this->value--;
	return *this;
}

Fixed Fixed::operator--(int) // Post-decrement
{
	Fixed temp(*this);
	operator--();
	return temp;
}



// Static member functions
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return a < b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return a > b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return a > b ? a : b;
}



// Returns the raw value of the fixed-point value
int Fixed::getRawBits(void) const
{
	return this->value;
}

// Sets the raw value of the fixed-point value
void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

// Converts the fixed-point value to a floating point value
float Fixed::toFloat(void) const
{
	return static_cast<float>(this->value) / (1 << fractionalBits);
}

// Converts the fixed-point value to an integer value
int Fixed::toInt(void) const
{
	return this->value >> fractionalBits;
}

// Stream insertion operator overload
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}
