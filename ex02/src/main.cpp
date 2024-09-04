/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:02:30 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/04 16:33:30 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

static void	test_default_constructor(void)
{
	std::cout <<"-------------- Default Constructor --------------"<< std::endl;
	Array<int>			numbers;
	Array<std::string>	strings;
	Array<double>		doubles;

	if (numbers.size() != 0)
		std::cerr << "Error: numbers.size() != 0" << std::endl;
	else if (strings.size() != 0)
		std::cerr << "Error: strings.size() != 0" << std::endl;
	else if (doubles.size() != 0)
		std::cerr << "Error: doubles.size() != 0" << std::endl;
	else
		std::cout << "The default constructor works fine" << std::endl;
}

static void	test_constructor_n(void)
{
	std::cout <<"----------------- Constructor n -----------------"<< std::endl;
	Array<int>	numbers(10);
	int			*mirror = new int[10];

	for (int i = 0; i < 10; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	for (int i = 0; i < 10; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return ;
		}
	}
	delete [] mirror;
	if (numbers.size() != 10)
		std::cerr << "Error: numbers.size() != 10" << std::endl;
	else
		std::cout << "The constructor n works fine" << std::endl;
}

static void	print_arrays_value_i(Array<int> &numbers, Array<int> &assignment_op,
	Array<int> &copy_ct, const int &index = 0)
{
	std::cerr << "numbers[i] = " << numbers[index];
	std::cerr << ", assignment_op[i] = " << assignment_op[index];
	std::cerr << ", copy_ct[i] = " << copy_ct[index] << std::endl;
}

static void	test_copy_constructor_and_assignment_operator(void)
{
	std::cout <<"-------- Copy Constructor and = Operator --------"<< std::endl;
	Array<int>	numbers(10);

	for (int i = 0; i < 10; i++)
		numbers[i] = rand();
	Array<int>	assignment_op;
	assignment_op = numbers;
	Array<int>	copy_ct(numbers);

	for (int i = 0; i < 10; i++)
	{
		if (numbers[i] != assignment_op[i] || numbers[i] != copy_ct[i])
		{
			print_arrays_value_i(numbers, assignment_op, copy_ct, i);
			std::cerr << "The arrays are not equal" << std::endl;
			return ;
		}
	}
	if (numbers[0] != 42)
		numbers[0] = 42;
	else
		numbers[0] = 0;

	if (assignment_op[0] == numbers[0] || copy_ct[0] == numbers[0])
	{
		print_arrays_value_i(numbers, assignment_op, copy_ct);
		std::cerr << "The arrays are not independent" << std::endl;
		return ;
	}
	std::cout << "The copy constructor and = operator work fine" << std::endl;
}

#define NO_EXCEPTION_ERROR "Invalid Index did not throw an exception"

static void	test_invalid_index(void)
{
	std::cout <<"----------------- Invalid Index -----------------"<< std::endl;
	{
	Array<int>	numbers(10);

	try
	{
		numbers[-2] = 0;
		std::cerr << NO_EXCEPTION_ERROR << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[10] = 0;
		std::cerr << NO_EXCEPTION_ERROR << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	}
	std::cout << "The invalid index exception works fine" << std::endl;
}

static void	test_size(void)
{
	std::cout <<"--------------------- Size ----------------------"<< std::endl;
	bool		error = false;

	{
		Array<int>	numbers(42);
		if (numbers.size() != 42)
		{
			std::cerr << "Error: numbers.size() != 42" << std::endl;
			error = true;
		}
	}
	{
		Array<std::string>	strings(125453);
		if (strings.size() != 125453)
		{
			std::cerr << "Error: strings.size() != 125453" << std::endl;
			error = true;
		}
	}
	{
		Array<double>	doubles(0);
		if (doubles.size() != 0)
		{
			std::cerr << "Error: doubles.size() != 0" << std::endl;
			error = true;
		}
	}
	{
		Array<int>	numbers;
		if (numbers.size() != 0)
		{
			std::cerr << "Error: numbers.size() != 0" << std::endl;
			error = true;
		}
	}
	if (!error)
		std::cout << "The size method works fine" << std::endl;
}

int	main(void)
{
	srand(time(NULL));
	test_default_constructor();
	std::cout << std::endl;
	test_constructor_n();
	std::cout << std::endl;
	test_copy_constructor_and_assignment_operator();
	std::cout << std::endl;
	test_invalid_index();
	std::cout << std::endl;
	test_size();
	std::cout << std::endl;
	return (0);
}
