/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:23:49 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/04 16:32:26 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <cstddef>

template <typename T>
class Array
{
	private:
		T*		_array;
		size_t	_size;

	public:
		Array();
		Array(size_t n);
		Array(const Array &other);
		~Array();
		Array	&operator =(const Array &other);

		T		&operator [](size_t index);
		size_t	size(void) const;
};

# include "template/Array.tpp"

#endif