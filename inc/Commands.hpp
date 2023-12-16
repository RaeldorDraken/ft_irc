/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Commands.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:45:12 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/16 19:37:59 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_HPP
# define COMMANDS_HPP

# include "globals.hpp"

class Server;

class Commands {

  public:
    static void JOIN(int const clientFd, std::vector<std::string> vec);
    static void USER(int const clientFd, std::vector<std::string> vec);
    static void NICK(int const clientFd, std::vector<std::string> vec);
    static void PRIVMSG(int const clientFd, std::vector<std::string> vec);
    static void INVITE(int const clientFd, std::vector<std::string> vec);
    static void TOPIC(int const clientFd, std::vector<std::string> vec);
    static void NAMES(int const clientFd, std::vector<std::string> vec);
    static void MODE(int const clientFd, std::vector<std::string> vec);
    static void KICK(int const clientFd, std::vector<std::string> vec);
    static void PING(int const clientFd, std::vector<std::string> vec);    

};

#endif