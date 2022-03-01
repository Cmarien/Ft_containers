/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorClass.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:45:02 by cmarien           #+#    #+#             */
/*   Updated: 2022/03/01 18:48:30 by user42           ###   ########.fr       */
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
		size_type		_size;
		pointer 		start;
	public:
		iterator begin(void){
			return (&start[0]);
		}

		iterator end(void){
			return (&start[_cap]);
		}

		reference front(void){
			return start[0];
		}

		reference back(void){
			return start[_cap - 1];
		}

		explicit vector() : _cap(0), _size(0), start(){
		}

		vector(const vector& newvector){
			*this = newvector;
		}
		~vector(){
		}

		void reserve(size_type n)
		{
			if (n > _size)
			{
				size_type i = -1;
				pointer tmp;
				tmp = _allocator.allocate(n);
				_size = n;
				while (++i < _cap)
					tmp[i] = start[i];
				_allocator.deallocate(start, _cap);
				start = tmp;
			}
		}

		void	push_back(const value_type &x){
			reserve(_cap + 1);
			start[_cap++] = x;
		}
	};
}

#endif