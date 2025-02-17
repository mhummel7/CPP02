/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:21:03 by mhummel           #+#    #+#             */
/*   Updated: 2025/02/10 13:34:57 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <unistd.h>

int	main(void)
{
	// Create a triangle with vertices at (0,0), (4,0), and (2,4)
	Point a(0.0f, 0.0f);
	Point b(4.0f, 0.0f);
	Point c(2.0f, 4.0f);

	std::cout << "Triangle ABC" << std::endl;
	std::cout << "a: " << a.getX() << " " << a.getY() << std::endl;
	std::cout << "b: " << b.getX() << " " << b.getY() << std::endl;
	std::cout << "c: " << c.getX() << " " << c.getY() << std::endl;

	std::cout << "\n       c (2,4)" << std::endl;
	std::cout << "      /  \\" << std::endl;
	std::cout << "     /    \\" << std::endl;
	std::cout << "    /      \\" << std::endl;
	std::cout << "   /        \\" << std::endl;
	std::cout << "  /          \\" << std::endl;
	std::cout << " a (0,0)-----b (4,0)\n" << std::endl;


	// Inside points
    Point inside1(2.0f, 2.0f);    // Center
    Point inside2(1.0f, 1.0f);    // Lower left
    Point inside3(3.0f, 1.0f);    // Lower right
    Point inside4(2.0f, 3.0f);    // Upper middle

    // Outside points
    Point outside1(4.0f, 4.0f);   // Far top right
    Point outside2(-1.0f, 2.0f);  // Left side
    Point outside3(5.0f, 2.0f);   // Right side
    Point outside4(2.0f, 5.0f);   // Above triangle

    // Edge points
    Point edge1(2.0f, 0.0f);      // Bottom edge middle
    Point edge2(1.0f, 2.0f);      // Left edge
    Point edge3(3.0f, 2.0f);      // Right edge

    // Vertex points (corners)
    Point vertex1(0.0f, 0.0f);    // Point a
    Point vertex2(4.0f, 0.0f);    // Point b
    Point vertex3(2.0f, 4.0f);    // Point c

	// Test
	Point test1(1.5f, 0.1f);

    std::cout << "Testing points inside the triangle:" << std::endl;
    std::cout << "Center point (2,2): " << (bsp(a, b, c, inside1) ? "true" : "false") << std::endl;
    std::cout << "Lower left (1,1): " << (bsp(a, b, c, inside2) ? "true" : "false") << std::endl;
    std::cout << "Lower right (3,1): " << (bsp(a, b, c, inside3) ? "true" : "false") << std::endl;
    std::cout << "Upper middle (2,3): " << (bsp(a, b, c, inside4) ? "true" : "false") << std::endl;

    std::cout << "\nTesting points outside the triangle:" << std::endl;
    std::cout << "Far top right (4,4): " << (bsp(a, b, c, outside1) ? "true" : "false") << std::endl;
    std::cout << "Left side (-1,2): " << (bsp(a, b, c, outside2) ? "true" : "false") << std::endl;
    std::cout << "Right side (5,2): " << (bsp(a, b, c, outside3) ? "true" : "false") << std::endl;
    std::cout << "Above triangle (2,5): " << (bsp(a, b, c, outside4) ? "true" : "false") << std::endl;

    std::cout << "\nTesting points on the edges:" << std::endl;
    std::cout << "Bottom edge (2,0): " << (bsp(a, b, c, edge1) ? "true" : "false") << std::endl;
    std::cout << "Left edge (1,2): " << (bsp(a, b, c, edge2) ? "true" : "false") << std::endl;
    std::cout << "Right edge (3,2): " << (bsp(a, b, c, edge3) ? "true" : "false") << std::endl;

    std::cout << "\nTesting vertices (corners):" << std::endl;
    std::cout << "Vertex A (0,0): " << (bsp(a, b, c, vertex1) ? "true" : "false") << std::endl;
    std::cout << "Vertex B (4,0): " << (bsp(a, b, c, vertex2) ? "true" : "false") << std::endl;
    std::cout << "Vertex C (2,4): " << (bsp(a, b, c, vertex3) ? "true" : "false") << std::endl;

	std::cout << "\nRandom test:" << std::endl;
	std::cout << "Test 1 (0,5): " << (bsp(a, b, c, test1) ? "true\n" : "false\n") << std::endl;

    return (0);
}
