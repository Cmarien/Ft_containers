/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:34:19 by cmarien           #+#    #+#             */
/*   Updated: 2022/03/11 19:56:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include <iostream>
#include <iterator>
#include <limits>
#include "iterators.hpp"

namespace ft
{
	template<typename T>
	class random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T>
	{
		private:
		public:
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type			value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type		difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference			reference;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer				pointer;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;
		protected:
			pointer current;
		public:
		random_access_iterator() : current(pointer()) {}

		random_access_iterator(pointer p) : current(p) {
		}

		random_access_iterator(const random_access_iterator& x) : current(x.current)
		{ }

		random_access_iterator base(){
			return current;
		}
		
		bool operator!=(const random_access_iterator& it) const {return (it.current != current);};
		bool operator==(const random_access_iterator& it) const {return (it.current == current);};

		reference operator*() const{
			return *current;
		}

		pointer	operator->() const{
			return current;
		}

		random_access_iterator	&operator=(const random_access_iterator &rhs) {
			if (this != &rhs)
				current = rhs.current;
			return *this;
		}

		random_access_iterator operator++(){
			return ++current;
		}

		random_access_iterator operator++(int){
			pointer tmp = current++;
			return tmp;
		}

		random_access_iterator operator--(){
			return --current;
		}

		random_access_iterator operator--(int){
			pointer tmp = current--;
			return tmp;
		}

		difference_type operator-(random_access_iterator &sub){
			difference_type i = 0;
			pointer tmp = current;
			while(tmp != sub.current)
			{
				i++;
				tmp--;
			}
			return i;
		}

		random_access_iterator	operator-(difference_type n){
			pointer tmp = current;
			for (difference_type i = 0; i < n; i++){
				tmp--;
			}
			return tmp;
		}

		random_access_iterator	operator+(difference_type n){
			pointer tmp = current;
			for (difference_type i = 0; i < n; i++){
				tmp++;
			}
			return tmp;
		}

		random_access_iterator	operator+=(difference_type n){
			for (difference_type i = 0; i < n; i++){
				current++;
			}
			return current;
		}

		random_access_iterator	operator-=(difference_type n){
			for (difference_type i = 0; i < n; i++){
				current--;
			}
			return current;
		}

		reference	operator[](int n){
			return current[n];
		}
	};
}

#endif