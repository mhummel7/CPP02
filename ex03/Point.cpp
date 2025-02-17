/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:09:56 by mhummel           #+#    #+#             */
/*   Updated: 2025/02/10 13:10:22 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Default constructor
Point::Point() : x(0), y(0) {
}

// Float constructor
Point::Point(const float x, const float y) : x(x), y(y) {
}

// Copy constructor
Point::Point(const Point &src) : x(src.x), y(src.y) {
}

// Destructor
Point::~Point() {
}

// Copy assignment operator
Point &Point::operator=(const Point &rhs)
{
	// Can't modify const members, so this is a no-op
	(void)rhs;
	return (*this);
}

// Getters
Fixed Point::getX() const
{
	return (x);
}

Fixed Point::getY() const
{
	return (y);
}
