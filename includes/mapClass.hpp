/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapClass.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:14:22 by user42            #+#    #+#             */
/*   Updated: 2022/03/16 13:27:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPCLASS_HPP
# define MAPCLASS_HPP

#include <iostream>
#include <cstdio>
#include <memory>
#include "pair.hpp"

namespace ft
{
    //std::less --> ft::less
    template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
    class map
    {
    public:
        typedef Key     key_type;
        typedef T       mapped_type;
        typedef Compare key_compare;
        typedef Alloc   allocator_type;

        typedef pair<const key_type, T>		value_type;
		typedef value_type					&reference;
		typedef const value_type			&const_reference;
		typedef value_type					*pointer;
		typedef const value_type			*const_pointer;
		typedef std::size_t					size_type;
		typedef	ptrdiff_t					difference_type;
        map();
        ~map();
    private:
		allocator_type	_allocator;
		
	public:
    };
}


#endif