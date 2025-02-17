/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:08:39 by mhummel           #+#    #+#             */
/*   Updated: 2025/02/10 13:08:50 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Calculate the area of a triangle using the cross product method
static Fixed	calculateArea(Point const &a, Point const &b, Point const &c)
{
	Fixed	area;

	area = ((b.getX() - a.getX()) * (c.getY() - a.getY()) - (c.getX()
				- a.getX()) * (b.getY() - a.getY())) / Fixed(2);
	return (area < Fixed(0) ? area * Fixed(-1) : area);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	// Calculate area of the main triangle
	Fixed totalArea = calculateArea(a, b, c);

	// Calculate areas of three triangles formed by the point and two vertices
	Fixed area1 = calculateArea(point, a, b);
	Fixed area2 = calculateArea(point, b, c);
	Fixed area3 = calculateArea(point, c, a);

	// Check if point is on any edge or vertex (areas would be 0)
	if (area1 == Fixed(0) || area2 == Fixed(0) || area3 == Fixed(0))
	{
		return (false);
	}

	// Point is inside if sum of three areas equals the total area
	return ((area1 + area2 + area3) == totalArea);
}
