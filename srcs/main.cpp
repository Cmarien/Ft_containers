/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:43:27 by cmarien           #+#    #+#             */
/*   Updated: 2022/03/02 17:08:34 by user42           ###   ########.fr       */
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
	x.front() = "XYZ";
	std::cout << "front :" << x.front() << std::endl;
	std::cout << "back :" << x.back() << std::endl;
	ft::vector<std::string>::iterator it1 = x.end();
	it = x.begin();
	std::cout << "end: " << *--it1 << std::endl;
	std::cout << "newBegin: " << *it << std::endl;
	it++;
	std::cout << "newBegin+1: " << *it << std::endl;
	ft::vector<std::string>::reverse_iterator rii = x.rend();
	std::cout << "rend: " << *--rii << std::endl;

	ft::vector<int> full(7, 15);
	ft::vector<int>::iterator input = full.begin();
	ft::vector<int>::iterator output = full.end();
	ft::vector<int> fullb(input, output);
	ft::vector<int>::iterator aat = fullb.begin();
	ft::vector<int>::iterator at = full.begin();
	std::cout << std::endl << "Show both vectors" << std::endl;
	std::cout << "---------" << std::endl;
	for (int i = 0; i < 8; i++){
		std::cout << *at << std::endl;
		std::cout << *aat << std::endl;
		aat++;
		at++;
		std::cout << "---------" << std::endl;
	}
	std::cout << "Output - input: ";
	std::cout << output - input << std::endl;

	// std::vector<int> fulla(7, 15);
	// std::vector<int>::iterator fir = fulla.begin();
	// std::vector<int>::iterator las = fulla.end();
	// std::cout << las - fir << std::endl;
	// int ind = 0;
	// while (fir++ != las)
	// 	ind++;
	// std::cout << ind << std::endl;
	// std::vector<std::string> vec;
	// vec.push_back("ABC");
	// vec.push_back("DEF");
	// std::vector<std::string>::reverse_iterator rit = vec.rend();
	// std::cout << *--rit << std::endl;
	return (0);
} 