/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:43:27 by cmarien           #+#    #+#             */
/*   Updated: 2022/03/30 20:28:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorClass.hpp"
#include <vector>
#include <utility>
#include <list>


int	main(void)
{
	ft::vector<std::string> x;
	ft::vector<std::string> y;
	x.push_back("ABC");
	ft::vector<std::string>::iterator it = x.begin();
	std::cout << "Begin: " << *it << std::endl;
	x.push_back("DEF");
	x.push_back("GHI");
	std::cout << "[1]" << x.at(1) << std::endl;
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
	y = x;
	x = ft::vector<std::string>();
	x.push_back("BOH");
	std::cout << "COPY" << std::endl;
	std::cout << "end: " << *--y.end() << std::endl;
	std::cout << "begin: " << *y.begin() << std::endl;
	std::cout << *x.begin() << std::endl;
	ft::vector<std::string>::iterator vit = y.begin();
	std::cout << *vit << std::endl;
	std::cout << x.max_size() << std::endl;
	std::vector<std::string> oh;
	std::cout << oh.max_size() << std::endl;
	ft::vector<char> ahouais;
	std::cout << ahouais.max_size() << std::endl;
	std::vector<char> ah;
	std::cout << ah.max_size() << std::endl;
	x.insert(x.begin(), 5, "OUI");
	std::cout << x[5] << std::endl;
	std::cout << *++x.begin() << std::endl;
	std::cout << x[3] << std::endl;
	std::cout << "insert" <<  *x.insert(&x[2], "non") << std::endl;
	std::cout << x[2] << std::endl;
	x.insert(x.end(), y.begin(), --y.end());
	std::cout << std::endl;
	for (size_t i = 0; i < x.size(); i++){
		std::cout << x[i] << std::endl;
	}
	std::cout << std::endl;
	for (size_t i = 0; i < y.size(); i++){
		std::cout << y[i] << std::endl;
	}
	std::cout << std::endl;
	ft::vector<std::string>::iterator erit;
	std::cout << "ERASE" << " SIZE" << x.size() << std::endl;
	x[1] = "first";
	erit = x.erase(x.begin(), x.begin() + 1);
	for (size_t i = 0; i < x.size(); i++){
		std::cout << *erit++ << std::endl;
	}
	std::vector<std::string> era;
	era.push_back("a");
	era.push_back("b");
	era.push_back("c");
	era.push_back("d");
	era.push_back("e");
	era.push_back("f");
	std::cout << era.size() << std::endl;
	std::cout << "ERASE" << *era.erase(era.begin(), era.end()) << " SIZE" << era.size();
	std::cout << era[0] << std::endl;
	std::cout << "Y" << std::endl;
	for (size_t i = 0; i < y.size(); i++){
		std::cout << y[i] << std::endl;
	}
	std::cout << "X" << std::endl;
	for (size_t i = 0; i < x.size(); i++){
		std::cout << x[i] << std::endl;
	}
	swap(x, y);
	std::cout << "Y" << std::endl;
	for (size_t i = 0; i < y.size(); i++){
		std::cout << y[i] << std::endl;
	}
	std::cout << "X" << std::endl;
	for (size_t i = 0; i < x.size(); i++){
		std::cout << x[i] << std::endl;
	}
	std::cout << std::endl;
	ft::vector<std::string> cop = y;
	std::cout << (y >= cop) << std::endl;
	cop.push_back("op");
	std::cout << (y >= cop) << std::endl;

	ft::vector<std::string> toins;
	toins.push_back("1");
	ft::vector<std::string> tmp = toins;
	toins.insert(toins.begin(), tmp.begin(), tmp.end());
	std::cout << "SIZE" << toins.size() << std::endl;
	std::cout << *++toins.begin() << std::endl;

	ft::vector<int> full(7, 15);
	std::vector<int> testfull(7, 15);
	ft::vector<int>emptyone;
	std::vector<int>emptytwo;
	ft::vector<int>::iterator input = full.begin();
	ft::vector<int>::iterator output = full.end();
	ft::vector<int> fullb(input, output);
	ft::vector<int>::iterator aat = fullb.begin();
	ft::vector<int>::iterator at = full.begin();
	std::cout << std::endl << "Show both vectors" << std::endl;
	std::cout << "---------" << std::endl;
	for (int i = 0; i < 7; i++){
		std::cout << *at << std::endl;
		std::cout << *aat << std::endl;
		aat++;
		at++;
		std::cout << "---------" << std::endl;
	}
	std::cout << "Output - input: ";
	std::cout << output - input << std::endl;

	std::cout << "full size: " << full.size() << " Capacity: " << full.capacity() << std::endl;
	std::cout << full.front() << " " << full.back() << std::endl;
	full.resize(25, 18);
	std::cout << "full size: " << full.size()  << " Capacity: " << full.capacity() << std::endl;
	std::cout << full.front() << " " << full.back() << std::endl;
	std::cout << "empty ? " << full.empty() << std::endl;


	ft::vector<int> to_assign;
	to_assign.assign(16, 8);
	std::cout << " ASSIGNED " << to_assign[15] << std::endl;
	std::cout << to_assign.size() << " " << to_assign.capacity() << std::endl;

	std::cout << "Pair conversion: ";
	ft::pair<int, int> abc;
	abc = ft::make_pair(5.5, 'A');
	std::cout << abc.second << std::endl;
	std::cout << "Pair conversion at init: ";
	ft::pair<int, int> boh(5.6, 'a');
	std::cout << boh.second << std::endl;


	std::vector<int> cons;
	cons.push_back(5);
	const std::vector<int> copco(cons);
	std::cout << copco[0] << std::endl;
	std::vector<int>::const_iterator coit = cons.begin();
	std::cout << coit[0] << std::endl;
	ft::vector<int>fcons;
	fcons.push_back(6);
	const ft::vector<int> copfco(fcons);
	std::cout << copfco[0] << std::endl;
	ft::vector<int>::const_iterator fcoit = fcons.begin();
	std::cout << fcoit[0] << std::endl;
	return (0);
} 