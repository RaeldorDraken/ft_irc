/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NullPtrType.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:01:55 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/09 19:07:17 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// ? Class needed to compile in any other computer other than the fucking MacOS at 42 which DO NOT apply c98++ flags properly. 

class NullPtrType
{
public:
    template<class T>
    operator T*() const
    {
        return 0;
    }

    template<class C, class T>
    operator T C::*() const
    {
        return 0;
    }

private:
    void operator&() const;
};

#define nullptrtype NullPtrType()
