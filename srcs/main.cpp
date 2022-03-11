/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:43:27 by cmarien           #+#    #+#             */
/*   Updated: 2022/03/11 19:49:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorClass.hpp"
#include <vector>
#include <utility>

bool mycompare(char c1, char c2)
{
	return std::tolower(c1)<std::tolower(c2);
}

bool comp_int(int i1, int i2)
{
	return i1==i2;
}

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
	for (size_t i = 0; i < x.size(); i++){
		std::cout << x[i] << std::endl;
	}
	std::cout << std::endl;
	for (size_t i = 0; i < y.size(); i++){
		std::cout << y[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << "ERASE" << *y.erase(&y[0], &y[3])  << " SIZE" << y.size() << std::endl;
	for (size_t i = 0; i < y.size(); i++){
		std::cout << y[i] << std::endl;
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
	ft::vector<std::string> cop = y;
	std::cout << (y >= cop) << std::endl;
	cop.push_back("op");
	std::cout << (y >= cop) << std::endl;
	// std::vector<std::string> aie;
	// aie.push_back("NON");
	// aie.push_back("OUI");
	// std::vector<std::string>::const_iterator cit = aie.begin();
	// std::cout << *cit << std::endl;
	// std::vector<std::string>::iterator vit = aie.end();
	// --vit;
	// *vit = *cit;
	// std::cout << *cit << std::endl;
	// std::cout << *vit.base() << std::endl;

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

	// full.resize(0);
	// std::cout << "full size: " << full.size()  << " Capacity: " << full.capacity() << std::endl;
	// std::cout << full.front() << " " << full.back() << std::endl;
	// std::cout << "empty ? " << full.empty() << std::endl;

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

	char first_string[] = "Apple";
	char second_string[] = "appartment";
	std::cout << "Ft Default compare: " << ft::lexicographical_compare(first_string, first_string+5, second_string, second_string+9) << std::endl;
	std::cout << "Ft My compare: " << ft::lexicographical_compare(first_string, first_string+5, second_string, second_string+9, mycompare) << std::endl;
	std::cout << "Std Default compare: " << std::lexicographical_compare(first_string, first_string+5, second_string, second_string+9) << std::endl;
	std::cout << "Std My compare: " << std::lexicographical_compare(first_string, first_string+5, second_string, second_string+9, mycompare) << std::endl;
	int	first_ints[] = {0, 20, 40, 60, 80, 100};
	int	second_ints[] = {0, 20, 40, 60, 80, 100};
	int	third_ints[] = {0, 20, 40, 60, 77, 100};
	std::cout << "(is equal)Ft Default equal: " << ft::equal(first_ints, first_ints+5, second_ints) << std::endl;
	std::cout << "(is equal)Ft My equal: " << ft::equal(first_ints, first_ints+5, second_ints, comp_int) << std::endl;
	std::cout << "(is not equal)Ft Default equal: " << ft::equal(first_ints, first_ints+5, third_ints) << std::endl;
	std::cout << "(is not equal)Ft My equal: " << ft::equal(first_ints, first_ints+5, third_ints, comp_int) << std::endl;
	std::cout << "(is equal)std Default equal: " << std::equal(first_ints, first_ints+5, second_ints) << std::endl;
	std::cout << "(is equal)std My equal: " << std::equal(first_ints, first_ints+5, second_ints, comp_int) << std::endl;
	std::cout << "(is not equal)std Default equal: " << std::equal(first_ints, first_ints+5, third_ints) << std::endl;
	std::cout << "(is not equal)std My equal: " << std::equal(first_ints, first_ints+5, third_ints, comp_int) << std::endl;
	
	std::vector<int> cons;
	cons.push_back(5);
	std::vector<int>::const_iterator coit = cons.begin();
	std::cout << coit[0] << std::endl;
	ft::vector<int>fcons;
	fcons.push_back(6);
//	ft::vector<int>::iterator coiit = fcons.begin();
	ft::vector<int>::const_iterator fcoit = fcons.begin();
	std::cout << fcoit[0] << std::endl;
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