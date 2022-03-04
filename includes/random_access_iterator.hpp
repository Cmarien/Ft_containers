/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:34:19 by cmarien           #+#    #+#             */
/*   Updated: 2022/03/04 17:00:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include <iostream>
#include <iterator>
#include "iterators.hpp"

namespace ft
{
	template<typename Iterator, typename Container>
	class random_access_iterator
	{
		private:
		protected:
			Iterator current;
		public:
			typedef iterator_traits<Iterator> traits_type;
			typedef Iterator									iterator_type;
			typedef typename traits_type::value_type			value_type;
			typedef typename traits_type::difference_type		difference_type;
			typedef typename traits_type::reference			reference;
			typedef typename traits_type::pointer				pointer;
			typedef typename traits_type::iterator_category	iterator_category;

		random_access_iterator() : current(Iterator())
		{ }

		random_access_iterator(const Iterator& x) : current(x)
		{ }

		random_access_iterator base(){
			return current;
		}
		
		bool operator!=(const random_access_iterator& it) const {return (it.current != current);};

		reference operator*(){
			return *current;
		}

		pointer	operator->(){
			return current;
		}

		random_access_iterator operator++(){
			return ++current;
		}

		random_access_iterator operator++(int){
			Iterator tmp = current++;
			return tmp;
		}

		random_access_iterator operator--(){
			return --current;
		}

		random_access_iterator operator--(int){
			Iterator tmp = current--;
			return tmp;
		}

		difference_type operator-(random_access_iterator &sub){
			difference_type i = 0;
			while(*this != sub)
			{
				i++;
				current--;
			}
			return i;
		}
	};
}

#endif