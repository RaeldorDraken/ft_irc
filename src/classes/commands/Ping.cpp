/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ping.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:26:58 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/28 19:56:19 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/commands/Ping.hpp"

Ping::Ping(int const &clientFd, std::vector<std::string> const &vec, Server *server) : ACommand(clientFd, vec, server)
{
  // (void)clientFd;
  // (void)server;

  std::vector<std::string> token;

  // ? If there is no token found in the PING command or there are too many arguments
  if (vec.size() == 2)
  {
    std::cout << "token send is " << vec[1] << std::endl;
    token.push_back(vec[1]);
    Pong pong = Pong(clientFd, token, server); 
  }
    
}

Ping::~Ping(void) {return ;}