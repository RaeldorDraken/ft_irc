/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:06:14 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/17 18:54:46 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include "globals.hpp"

class Utils {

  public :

    static std::vector<std::string>      tokenizeByStr(std::string const &str, std::string const &bound);

    static std::vector<std::string>      tokenizeByChar(std::string str, char c);

    void                          printVector(std::vector<std::string> vec, std::string msg);

    static int                           ft_stoi(std::string str);
    static std::string                   intToString(int number);
    static int                           getCharPosFromString(std::string &str, char c);
    static bool                          isCharInString(std::string &str, char c);
    void                                 deleteCharFromString(std::string &str, char c);


  private :

    // ? This is a Static Class. We do not instantiate it. We only use its methods

    Utils(void);
    ~Utils(void);

};

#endif