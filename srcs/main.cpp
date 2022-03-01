/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarien <cmarien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:43:27 by cmarien           #+#    #+#             */
/*   Updated: 2022/03/01 13:19:00 by cmarien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorClass.hpp"
#include <vector>

int	main(void)
{
	ft::vector<std::string> x;
	x.push_back("ABC");
	ft::vector<std::string>::iterator it1 = x.end();
	std::cout << *it1 << std::endl;
	x.push_back("DEF");
	ft::vector<std::string>::iterator it = x.begin();
	std::cout << *it << std::endl;
	std::cout << *it1 << std::endl;
	std::vector<std::string> y;
	y.push_back("abc");
	std::vector<std::string> z(y);
	y[0] = "def";
	std::cout << *y.begin() << std::endl;
	std::cout << *z.begin() << std::endl;
	return (0);
} 