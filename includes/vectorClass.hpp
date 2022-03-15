/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorClass.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:45:02 by cmarien           #+#    #+#             */
/*   Updated: 2022/03/15 13:30:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORCLASS_HPP
# define VECTORCLASS_HPP

# include <iostream>
#include <cstdio>
#include <memory>
#include "random_access_iterator.hpp"
#include "rev_random_access_iterator.hpp"
#include "enable_if.hpp"
#include "pair.hpp"
#include "equal.hpp"
#include <math.h>
#include <limits>

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
		typedef ft::random_access_iterator<T>				iterator;
		typedef ft::random_access_iterator<T>		const_iterator;
		typedef ft::rev_random_access_iterator<T>			reverse_iterator;
		typedef ft::rev_random_access_iterator<T>	const_reverse_iterator;
		typedef std::size_t												size_type;
		typedef	ptrdiff_t												differerence_type;
	private:
		allocator_type	_allocator;
		size_type		_cap;
		size_type		_size;
		pointer 		start;
	public:

		//constructors
		explicit vector(const allocator_type& alloc = allocator_type()) : _allocator(alloc), _cap(0), _size(0), start(0){
			// start = _allocator.allocate(_cap);
		}

		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _allocator(alloc), _cap(n), _size(n){
			start = _allocator.allocate(_cap);
			for (size_type i = 0; i < n; i++){
				_allocator.construct(&start[i], val);
			}
		}

		template <class InputIterator>
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<ft::is_integral<InputIterator>::value>::type* = 0)
			: _allocator(alloc), _size(0){
			differerence_type i = last - first;
			_cap = i;
			start = _allocator.allocate(_cap);
			for (differerence_type j = 0; j < i; j++){
				_allocator.construct(&start[j], *first);
				first++;
				_size++;
			} 
		}

		vector(const vector& newvector){
			this->_allocator = newvector._allocator;
			this->_cap = newvector._cap;
			this->_size = newvector._size;
			this->start = this->_allocator.allocate(_cap);
			for (size_type i = 0; i < _size; i++){
				_allocator.construct(&start[i], newvector.start[i]);
			}
		}
		////////////////////////////////////////////////////
		//Destructor
		~vector(){
			for (size_type i = 0; i < _size; i++){
				_allocator.destroy(&start[i]);
			}
			_allocator.deallocate(start, _cap);
		}
		////////////////////////////////////////////////////
		//Iterators functions
		iterator begin(){
			return (iterator(start));
		}

		const_iterator begin() const{
			return (const_iterator(start));
		}
		
		iterator end(void){
			return (iterator(&start[_size]));
		}

		const_iterator end(void) const{
			return (const_iterator(&start[_size]));
		}

		reverse_iterator	rbegin(void){
			return (reverse_iterator(&start[_size - 1]));
		}

		const_reverse_iterator	rbegin(void) const{
			return (const_reverse_iterator(&start[_size - 1]));
		}

		reverse_iterator	rend(void){
			return (reverse_iterator(&start[-1]));
		}

		const_reverse_iterator	rend(void) const{
			return (const_reverse_iterator(&start[-1]));
		}
		///////////////////////////////////////////////////
		//Capacity functions
		size_type	size() const {
			return _size;
		}

		size_type	max_size() const{
			if (sizeof(value_type) == 1)
				return static_cast<size_t>(powf(2, 64)) - 1;
			return ((static_cast<size_t>(powf(2, 64) / sizeof(value_type))) -1);
		}
		
		void	resize(size_type n, value_type val = value_type()){
			while (n < _size)
				pop_back();
			while (n > _size)
				push_back(val);
		}
		
		size_type capacity(void){
			return (_cap);
		}

		bool	empty(void) const{
			return _size ? false : true;
		}

		void reserve(size_type n)
		{
			if (n > _cap)
			{
				size_type i = -1;
				pointer tmp;
				tmp = _allocator.allocate(n);
				while (++i < _cap)
					_allocator.construct(&tmp[i], start[i]);
				for(size_type index = 0; index < _size; index++){
					_allocator.destroy(&start[index]);
				}
				_allocator.deallocate(start, _cap);
				start = tmp;
				_cap = n;
			}
		}
		//////////////////////////////////////////////////////
		//Element accessor functions
		reference	front(void)const{
			return start[0];
		}

		reference	back(void)const{
			return start[_cap - 1];
		}

		reference	operator[](size_type n){
			return start[n];
		}

		const_reference	operator[](size_type n) const{
			return start[n];
		}

		reference	at(size_type n)const{
			if (n >= _size)
				throw vector::OutOfRangeException();
			return start[n];
		}

		///////////////////////////////////////////////////////
		//Modifiers functions
		void	push_back(const value_type &x){
			reserve(_size + 1);
			_allocator.construct(&start[_size++], x);
		}

		void	pop_back(void){
			_allocator.destroy(&start[--_size]);
		}

		template<class InputIterator>
		void	assign(InputIterator first, InputIterator last,
		typename ft::enable_if<ft::is_integral<InputIterator>::value>::type* = 0){
			size_type i = static_cast<size_type>(last - first);
			clear();
			if(i > _cap){
				for (size_type index = 0; index < _size; index++){
					_allocator.destroy(&start[index]);
				}
				_allocator.deallocate(start, _cap);
				_cap = i;
				start = _allocator.allocate(_cap);
			}
			for (size_type j = 0; j < i; j++){
				_allocator.construct(&start[j], *first);
				first++;
			}
			_size = i;
		}

		void	assign(size_type n, const value_type &val){
			clear();
			if(n > _cap){
				for (size_type i = 0; i < _size; i++){
					_allocator.destroy(&start[i]);
				}
				_allocator.deallocate(start, _cap);
				_cap = n;
				start = _allocator.allocate(_cap);
			}
			for (size_type j = 0; j < n; j++){
				_allocator.construct(&start[j], val);
			}
			_size = n;
		}

		iterator insert(iterator position, const value_type &val){
			iterator beg = begin();
			iterator tmp = position;
			differerence_type x = tmp - beg;
			insert(position, 1, val);
			return &start[x];
		}

		void insert(iterator position, size_type n, const value_type &val){
			iterator beg = begin();
			size_type ret = static_cast<size_type>(position - beg);
			iterator tmp(&start[ret]);

			reserve(_size + n);
			size_type index = _cap - 1;
			//std::cout << "index = " << index << " n = " << n << " ret = " << ret << std::endl;
			if (tmp != end()){
				while (index - n >= ret && index >= n){
					_allocator.construct(&start[index], start[index - n]);
					_allocator.destroy(&start[index - n]);
					index--;
				}
			}
			for (size_type i = 0; i < n; i++){
				_allocator.construct(&start[index], val);
				index--;
				_size++;
			}
		}
		template<class InputIterator>
		void	insert(iterator position, InputIterator first, InputIterator last,
		typename ft::enable_if<ft::is_integral<InputIterator>::value>::type* = 0){
			iterator beg = begin();
			iterator tmp_last = last;
			size_type ret = static_cast<size_type>(position - beg);
			size_type n = static_cast<size_type>(last - first);
			iterator tmp(&start[ret]);

			reserve(_size + n);
			size_type index = _cap - 1;
			if (tmp != end()){
				while (index - n >= ret && index >= n){
					_allocator.construct(&start[index], start[index - n]);
					_allocator.destroy(&start[index - n]);
					index--;
				}
			}
			for (size_type i = 0; i < n; i++){
				_allocator.construct(&start[index], *(tmp_last - 1));
				index--;
				tmp_last--;
				_size++;
			}
		}

		void	clear(void){
			while (_size > 0)
				pop_back();
		}

		iterator	erase(iterator position){
			iterator beg = begin();
			iterator tmp = position;
			size_type index = static_cast<size_type>(position - beg);
			size_type ret = index;
			if (tmp == &start[_size]){
				_size--;
				return &start[_size];
			}
			while (&start[index] != &start[_size - 1]){
				_allocator.destroy(&start[index]);
				_allocator.construct(&start[index], start[index + 1]);
				index++;
			}
			_allocator.destroy(&start[index]);
			_size--;
			return &start[ret];
		}
		
		template<class InputIterator>
		iterator	erase(InputIterator first, InputIterator last){
			if (first == &start[_size] || first == last){
				return first;
			}
			size_type n = static_cast<size_type>(last - first);
			iterator ret = first;
			while (&(*(first + n)) < &start[_size]){
				_allocator.destroy(&(*first));
				if (&(*(first + n)) < &start[_size] && last != &start[_size])
					_allocator.construct(&(*first), *(first + n));
				first++;
			}
			// if (last != &start[_size]){
			// 	_allocator.destroy(&(*first));
			// 	first++;
			// }
			while (&(*first) != &start[_size]){
				_allocator.destroy(&(*first));
				first++;
			}
			if (last == &start[_size])
			{
				_size -= n;
				return &start[_size];
			}
			_size -= n;
			return ret;
		}

		void	swap(vector &x){
			swap(_allocator, x._allocator);
			swap(_size, x._size);
			swap(_cap, x._cap);
			swap(start, x.start);
		}

		///////////////////////////////////////////////////////
		//Allocator

		allocator_type get_allocator() const{
			return _allocator;
		}
		///////////////////////////////////////////////////////
		//Overloads
		vector&	operator=(const vector& x){
			for (size_type i = 0; i < _size; i++){
				_allocator.destroy(&start[i]);
			}
			_allocator.deallocate(start, _cap);
			_cap = 0;
			_size = 0;
			while (_cap < x._cap)
			{
				reserve(_cap + 1);
				_allocator.construct(&start[_size], x.start[_size]);
				_size++;
			}
			return *this;
		}
		friend void swap(vector &x, vector&y){
			x.swap(y);
		}

		friend bool operator==(const vector& lhs, const vector& rhs){
			if (lhs.size() != rhs.size())
				return false;
			vector tmpl = lhs;
			vector tmpr = rhs;
			return ft::equal(tmpl.begin(), tmpl.end(), tmpr.begin());
		}

		friend bool operator!=(const vector& lhs, const vector& rhs){
			if (lhs.size() != rhs.size())
				return true;
			vector tmpl = lhs;
			vector tmpr = rhs;
			return !(ft::equal(tmpl.begin(), tmpl.end(), tmpr.begin()));
		}

		friend bool operator<(const vector& lhs, const vector& rhs){
			if (lhs.size() < rhs.size()){
				return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());	
			}
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}

		friend bool operator<=(const vector& lhs, const vector& rhs){
			return !(rhs < lhs);
		}

		friend bool operator>(const vector& lhs, const vector& rhs){
			return (rhs < lhs);
		}
		
		friend bool operator>=(const vector& lhs, const vector& rhs){
			return !(lhs < rhs);
		}

		//////////////////////////////////////////////////////////
		//Private function
		private:
		template<typename U>
		void	swap(U &x, U &y){
			U tmp = x;
			x = y;
			y = tmp;
		}
		class OutOfRangeException : public std::exception
		{
		public:
	 	   char const* what() const throw(){
				return "Out Of Range error: vector::_M_range_check";
			}
		};
	};
}

#endif