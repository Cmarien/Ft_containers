/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_random_access_iterator.hpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarien <cmarien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:59:08 by cmarien           #+#    #+#             */
/*   Updated: 2022/03/23 10:46:28 by cmarien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REV_RANDOM_ACCESS_ITERATOR_HPP
# define REV_RANDOM_ACCESS_ITERATOR_HPP

#include "random_access_iterator.hpp"

namespace ft{
	template<typename T>
	class rev_random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T>
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
		
		rev_random_access_iterator() : current(pointer()) {}

		rev_random_access_iterator(pointer p) : current(p) {
		}

		rev_random_access_iterator(const rev_random_access_iterator& x) : current(x.current)
		{ }

		bool operator!=(const rev_random_access_iterator& it) const {return (current != it.current);};
		bool operator==(const rev_random_access_iterator& it) const {return (current == it.current);};
		bool operator>(const rev_random_access_iterator& it) const {return (current > it.current);};
		bool operator<(const rev_random_access_iterator& it) const {return (current < it.current);};
		bool operator<=(const rev_random_access_iterator& it) const {return (current <= it.current);};
		bool operator>=(const rev_random_access_iterator& it) const {return (current >= it.current);};

		reference operator*() const{
			return *current;
		}

		pointer	operator->() const{
			return current;
		}

		rev_random_access_iterator	&operator=(const rev_random_access_iterator &rhs) {
			if (this != &rhs)
				current = rhs.current;
			return *this;
		}

		rev_random_access_iterator operator++(){
			return --current;
		}

		rev_random_access_iterator operator++(int){
			pointer tmp = current--;
			return tmp;
		}

		rev_random_access_iterator operator--(){
			return ++current;
		}

		rev_random_access_iterator operator--(int){
			pointer tmp = current++;
			return tmp;
		}

		difference_type operator-(rev_random_access_iterator &sub){
			difference_type i = 0;
			pointer tmp = current;
			while(tmp != sub.current)
			{
				i++;
				tmp--;
			}
			return i;
		}

		rev_random_access_iterator	operator-(difference_type n){
			pointer tmp = current;
			for (difference_type i = 0; i < n; i++){
				tmp++;
			}
			return tmp;
		}

		rev_random_access_iterator	operator+(difference_type n){
			pointer tmp = current;
			for (difference_type i = 0; i < n; i++){
				tmp--;
			}
			return tmp;
		}

		rev_random_access_iterator	operator+=(difference_type n){
			for (difference_type i = 0; i < n; i++){
				current--;
			}
			return current;
		}

		rev_random_access_iterator	operator-=(difference_type n){
			for (difference_type i = 0; i < n; i++){
				current++;
			}
			return current;
		}

		reference	operator[](int n){
			return *(current - n);
		}
	};
}

#endif