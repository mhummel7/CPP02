/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:09:01 by mhummel           #+#    #+#             */
/*   Updated: 2025/02/10 13:09:45 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;

	public:
		Point();								// Default constructor
		Point(const float x, const float y);	// Float constructor
		Point(const Point &src);				// Copy constructor
		~Point();								// Destructor

	Point &operator=(const Point &rhs); // Copy assignment operator

	// Getters
	Fixed getX() const;
	Fixed getY() const;
};

// BSP function declaration
bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
