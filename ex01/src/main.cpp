/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:45:56 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/04 13:16:36 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Iter.hpp"

void	add_one(int &n)
{
	n++;
}

void	capitalize(char &c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
}

enum class TestEnum
{
	ONE,
	TWO,
	THREE,
	FOUR
};

std::ostream &operator <<(std::ostream &o, TestEnum &e)
{
	switch (e)
	{
		case TestEnum::ONE:
			o << "ONE";
			break;
		case TestEnum::TWO:
			o << "TWO";
			break;
		case TestEnum::THREE:
			o << "THREE";
			break;
		case TestEnum::FOUR:
			o << "FOUR";
			break;
	}
	return (o);
}

void	plus_one(TestEnum &e)
{
	e = static_cast<TestEnum>(static_cast<int>(e) + 1);
}

template <typename T>
static void	test_iter(T *array, size_t size, void (*func)(T &))
{
	std::cout << "Original array: ";
	for (size_t i = 0; i < size; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
	iter(array, size, func);
	std::cout << "Modified array: ";
	for (size_t i = 0; i < size; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

int	main(void)
{
	{
	int		array[] = {1, 2, 3, 4, 5};
	size_t	size = sizeof(array) / sizeof(array[0]);
	
	test_iter(array, size, add_one);
	}
	{
	char	array[] = {'a', 'b', 'c', 'd', 'e'};
	size_t	size = sizeof(array) / sizeof(array[0]);

	test_iter(array, size, capitalize);
	}
	{
	TestEnum	array[] = {TestEnum::ONE, TestEnum::TWO, TestEnum::THREE};
	size_t		size = sizeof(array) / sizeof(array[0]);

	test_iter(array, size, plus_one);
	}
	return (0);
}
