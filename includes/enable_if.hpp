/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:35:27 by user42            #+#    #+#             */
/*   Updated: 2022/03/31 17:02:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

namespace   ft{
    template<bool B>
    struct enable_if {};

    template<>
    struct enable_if<true>{typedef int type;};

    template<typename T>
    struct is_integral{static const bool value = false;};

    template<>
    struct is_integral<bool>{static const bool value = true;};

    template<>
    struct is_integral<int>{static const bool value = true;};

    template<>
    struct is_integral<char>{static const bool value = true;};

    template<>
    struct is_integral<short>{static const bool value = true;};

    template<>
    struct is_integral<long>{static const bool value = true;};

    template<>
    struct is_integral<long long>{static const bool value = true;};

    template<>
    struct is_integral<unsigned char>{static const bool value = true;};

    template<>
    struct is_integral<unsigned int>{static const bool value = true;};

    template<>
    struct is_integral<unsigned long>{static const bool value = true;};

    template<>
    struct is_integral<unsigned long long>{static const bool value = true;};

    template<>
    struct is_integral<unsigned short>{static const bool value = false;};
}

#endif