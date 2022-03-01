/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorClass.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarien <cmarien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:45:02 by cmarien           #+#    #+#             */
/*   Updated: 2022/03/01 13:23:12 by cmarien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORCLASS_HPP
# define VECTORCLASS_HPP

# include <iostream>
#include <cstdio>
#include <memory>
#include "random_access_iterator.hpp"

namespace ft
{
	template<class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T													value_type;
		typedef Alloc												allocator_type;
		typedef value_type											&reference;
		typedef const value_type									&const_reference;
		typedef value_type											*pointer;
		typedef const value_type									*const_pointer;
		typedef ft::random_access_iterator<pointer, vector>			iterator;
		typedef ft::random_access_iterator<const_pointer, vector>	const_iterator;
		typedef std::size_t											size_type;
	private:
		allocator_type	_allocator;
		size_type		_cap;
		pointer 		start;
		pointer 		finish;
		pointer 		end_storage;
	public:
		iterator begin(void)
		{
			return (start);
		}

		iterator end(void)
		{
			if (_cap == 1)
				return (start);
			return (finish);
		}

		pointer& setup_finish(pointer &ptr)
		{
			return ptr;
		}

		explicit vector() : start(), finish(), end_storage(){
			finish = start;
			_cap =  0;
		}

		vector(const vector& newvector){
			*this = newvector;
		}
		~vector(){
		}

		void	push_back(value_type x){
			if (!start)
				start = &x;
			else
				finish = &x;
			_cap++;
		}
	};
}

#endif