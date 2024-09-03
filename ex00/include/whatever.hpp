/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:20:51 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/03 20:39:55 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T &a, T &b)
{
	const T	tmp = a;

	a = b;
	b = tmp;
}

template <typename T>
T	min(T const &a, T const &b)
{
	return (a < b ? a : b);
}

template <typename T>
T	max(T const &a, T const &b)
{
	return (a > b ? a : b);
}

#endif