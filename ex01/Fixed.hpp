/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:05:11 by mhummel           #+#    #+#             */
/*   Updated: 2025/02/10 11:32:35 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int value; 								// Fixed-point value
		static const int fractionalBits = 8; 	// Number of fractional bits

	public:
		Fixed(); 								// Default constructor
		Fixed(const int n); 					// Int constructor
		Fixed(const float n); 					// Float constructor
		Fixed(const Fixed& src); 				// Copy constructor
		~Fixed(); 								// Destructor

		Fixed& operator=(const Fixed& rhs); 	// Copy assignment operator

		int getRawBits(void) const; 			// Returns the raw value of the fixed-point value
		void setRawBits(int const raw); 		// Sets the raw value of the fixed-point value
		float toFloat(void) const; 				// Returns the floating point value of the fixed-point value
		int toInt(void) const; 					// Returns the integer value of the fixed-point value
};

// Stream insertion operator overload
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
