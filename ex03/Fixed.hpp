/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:22:52 by mhummel           #+#    #+#             */
/*   Updated: 2025/02/10 12:33:04 by mhummel          ###   ########.fr       */
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

		// Comparison operators
		bool operator>(const Fixed& rhs) const;
		bool operator<(const Fixed& rhs) const;
		bool operator>=(const Fixed& rhs) const;
		bool operator<=(const Fixed& rhs) const;
		bool operator==(const Fixed& rhs) const;
		bool operator!=(const Fixed& rhs) const;

		// Arithmetic operators
		Fixed operator+(const Fixed& rhs) const;
		Fixed operator-(const Fixed& rhs) const;
		Fixed operator*(const Fixed& rhs) const;
		Fixed operator/(const Fixed& rhs) const;

		// Increment and decrement operators
		Fixed& operator++(); 					// Pre-increment
		Fixed operator++(int); 					// Post-increment
		Fixed& operator--(); 					// Pre-decrement
		Fixed operator--(int); 					// Post-decrement

		// Static member functions
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);

		int getRawBits(void) const; 			// Returns the raw value of the fixed-point value
		void setRawBits(int const raw); 		// Sets the raw value of the fixed-point value
		float toFloat(void) const; 				// Returns the floating point value of the fixed-point value
		int toInt(void) const; 					// Returns the integer value of the fixed-point value
};

// Stream insertion operator overload
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
