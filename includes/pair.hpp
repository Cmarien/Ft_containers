/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:11:04 by user42            #+#    #+#             */
/*   Updated: 2022/03/04 14:18:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft{

    template<class T1, class T2>
    struct pair{
        public:
        typedef T1  first_type;
        typedef T2  second_type;
        first_type  first;
        second_type second;

        pair(){}
        pair(const T1& x, const T2& y) : first(x), second(y){ }
        pair(const pair<T1, T2>& newone) {
            *this = newone;
        }
        template<class T3, class T4>
        pair&   operator=(const pair<T3, T4>& rhs){
            this->first = rhs.first;
            this->second = rhs.second;
            return *this;
        }
    };
    template<class T1, class T2>
    pair<T1, T2>    make_pair(T1 x, T2 y){
        return pair<T1, T2>(x, y);
    }
}


#endif