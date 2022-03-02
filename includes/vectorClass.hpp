/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorClass.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarien <cmarien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:45:02 by cmarien           #+#    #+#             */
/*   Updated: 2022/03/02 12:10:53 by cmarien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORCLASS_HPP
# define VECTORCLASS_HPP

# include <iostream>
#include <cstdio>
#include <memory>
#include "random_access_iterator.hpp"
#include "rev_random_access_iterator.hpp"
#include "input_iterator.hpp"

namespace ft
{
	template<class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T														value_type;
		typedef Alloc													allocator_type;
		typedef value_type												&reference;
		typedef const value_type										&const_reference;
		typedef value_type												*pointer;
		typedef const value_type										*const_pointer;
		typedef ft::random_access_iterator<pointer, vector>				iterator;
		typedef ft::random_access_iterator<const_pointer, vector>		const_iterator;
		typedef ft::rev_random_access_iterator<pointer, vector>			reverse_iterator;
		typedef ft::rev_random_access_iterator<const_pointer, vector>	const_reverse_iterator;
		typedef std::size_t												size_type;
		typedef	ptrdiff_t												differerence_type;
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

		const_iterator cbegin(void){
			return (&start[0]);
		}

		const_iterator	cend(void){
			return (&start[_cap]);
		}

		reverse_iterator	rbegin(void){
			return (&start[_cap - 1]);
		}

		reverse_iterator	rend(void){
			return (&start[-1]);
		}

		const_reverse_iterator	crbegin(void){
			return (&start[_cap - 1]);
		}

		const_reverse_iterator	crend(void){
			return (&start[-1]);
		}

		reference front(void){
			return start[0];
		}

		reference back(void){
			return start[_cap - 1];
		}

		explicit vector(const allocator_type& alloc = allocator_type()) : _allocator(alloc), _cap(0), _size(0), start(){
			start = _allocator.allocate(_cap);
		}

		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _allocator(alloc), _cap(n), _size(n){
			start = _allocator.allocate(_cap);
			for (size_type i = 0; i < n; i++){
				start[i] = val;
			}
		}
		
		template <class InputIterator>
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), true) : _allocator(alloc){
			differerence_type i = last - first;
			_cap = i;
			start = _allocator.allocate(_cap);
			_size = _cap;
			for (differerence_type j = 0; j < i; j++){
				start[j] = *first;
				first++;
			} 
		}

		vector(const vector& newvector){
			this->_allocator = newvector._allocator;
			this->_cap = newvector._cap;
			this->_size = newvector._size;
			this->start = this->_allocator.allocate(_cap);
			for (size_type i = 0; i < _cap; i++){
				this->start[i] = newvector.start[i];
			}
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