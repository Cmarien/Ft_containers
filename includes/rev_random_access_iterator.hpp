/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_random_access_iterator.hpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarien <cmarien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:59:08 by cmarien           #+#    #+#             */
/*   Updated: 2022/03/02 11:06:58 by cmarien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REV_RANDOM_ACCESS_ITERATOR_HPP
# define REV_RANDOM_ACCESS_ITERATOR_HPP

#include "random_access_iterator.hpp"

namespace ft{
	template<typename Iterator, typename Container>
	class rev_random_access_iterator
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

		
		rev_random_access_iterator() : current(Iterator()) { };
		rev_random_access_iterator(const Iterator& x) : current(x) { };

		reference operator*(){
			return *current;
		}

		pointer	operator->(){
			return current;
		}

		rev_random_access_iterator operator++(){
			return --current;
		}

		rev_random_access_iterator operator++(int){
			Iterator tmp = current--;
			return tmp;
		}

		rev_random_access_iterator operator--(){
			return ++current;
		}

		rev_random_access_iterator operator--(int){
			Iterator tmp = current++;
			return tmp;
		}
	};
}

#endif