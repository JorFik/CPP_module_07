/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:30:46 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/04 16:19:08 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include <cstddef>
# include <stdexcept>
# include <iostream>
# include <typeinfo>

template <typename T>
Array<T>::Array() : _array(nullptr), _size(0)
{
	std::cout << "Default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(size_t n) : _array(new T[n]), _size(n)
{
	std::cout << "Constructor n called" << std::endl;
}

template <typename T>
Array<T>	&Array<T>::operator =(const Array &other)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &other)
	{
		delete[] _array;
		this->_array = new T[other._size];
		this->_size = other._size;
		for (size_t i = 0; i < _size; i++)
			this->_array[i] = other._array[i];
	}
	return (*this);
}

template <typename T>
Array<T>::Array(const Array &other) : _array(nullptr)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "Destructor called" << std::endl;
	delete[] _array;
}

template <typename T>
T	&Array<T>::operator [](size_t index)
{
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return (_array[index]);
}

template <typename T>
size_t	Array<T>::size(void) const
{
	return (_size);
}

#endif