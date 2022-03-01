/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:43:27 by cmarien           #+#    #+#             */
/*   Updated: 2022/03/01 18:48:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorClass.hpp"
#include <vector>

int	main(void)
{
	ft::vector<std::string> x;
	x.push_back("ABC");
	ft::vector<std::string>::iterator it = x.begin();
	std::cout << "Begin: " << *it << std::endl;
	x.push_back("DEF");
	x.push_back("GHI");
	std::cout << "front :" << x.front() << std::endl;
	std::cout << "back :" << x.back() << std::endl;
	x.front() = "JKL";
	x.back() = x.front();
	x.front() = "DEF";
	std::cout << "front :" << x.front() << std::endl;
	std::cout << "back :" << x.back() << std::endl;
	ft::vector<std::string>::iterator it1 = x.end();
	it = x.begin();
	std::cout << "end: " << *--it1 << std::endl;
	std::cout << "newBegin: " << *it << std::endl;
	it++;
	std::cout << "newBegin+1: " << *it << std::endl;
	return (0);
} 