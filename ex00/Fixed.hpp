/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:42:13 by mhummel           #+#    #+#             */
/*   Updated: 2025/02/10 09:56:16 by mhummel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int value;								// Fixed-point number value
		static const int fractionalBits = 8;	// Number of fractional bits

	public:
		Fixed();								// Default constructor
		Fixed(const Fixed& src);				// Copy constructor
		~Fixed();								// Destructor

		Fixed& operator=(const Fixed& rhs);		// Copy assignment operator

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif