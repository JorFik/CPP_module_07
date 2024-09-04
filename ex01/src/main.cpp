/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:45:56 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/04 13:06:09 by JFikents         ###   ########.fr       */
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

int	main(void)
{
	int int_array[] = {1, 2, 3, 4, 5};
	size_t size = sizeof(int_array) / sizeof(int_array[0]);

	std::cout << "Original int_array: ";
	for (size_t i = 0; i < size; i++)
		std::cout << int_array[i] << " ";
	std::cout << std::endl;
	iter(int_array, size, add_one);
	std::cout << "Modified int_array: ";
	for (size_t i = 0; i < size; i++)
		std::cout << int_array[i] << " ";
	std::cout << std::endl;

	char char_array[] = {'a', 'b', 'c', 'd', 'e'};
	size = sizeof(char_array) / sizeof(char_array[0]);
	std::cout << std::endl << "Original char_array: ";
	for (size_t i = 0; i < size; i++)
		std::cout << char_array[i] << " ";
	std::cout << std::endl;
	iter(char_array, size, capitalize);
	std::cout << "Modified char_array: ";
	for (size_t i = 0; i < size; i++)
		std::cout << char_array[i] << " ";
	std::cout << std::endl;

	TestEnum enum_array[] = {TestEnum::ONE, TestEnum::TWO, TestEnum::THREE};
	size = sizeof(enum_array) / sizeof(enum_array[0]);
	std::cout << std::endl << "Original enum_array: ";
	for (size_t i = 0; i < size; i++)
		std::cout << enum_array[i] << " ";
	std::cout << std::endl;
	iter(enum_array, size, plus_one);
	std::cout << "Modified enum_array: ";
	for (size_t i = 0; i < size; i++)
		std::cout << enum_array[i] << " ";
	std::cout << std::endl;
	return (0);
}
