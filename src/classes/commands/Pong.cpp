/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pong.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:44:10 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/28 19:38:19 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../inc/commands/Pong.hpp"

Pong::Pong(int const &clientFd, std::vector<std::string> const &vec, Server *server) : ACommand(clientFd, vec, server)
{
  std::map<int, Client *> _myClients = server->getClients();
  
  
    // std::map<int, Client *>::iterator it;
    // for (it = _myClients.begin(); it != _myClients.end(); ++it) {
    //     std::cout << "Key: " << it->first << ", Value: " << it->second->getName() << std::endl;
    // }
  
  
  Client *target = _myClients[clientFd];

  // std::cout << "my target has the following fd " << target->getClientFd() << std::endl;

  // ? Here our vec is a custom vector made of just the token send by PING command!!!

  if (vec.size() == 1)
  {
    // std::cout << "client " << clientFd  << " has to print a message with the following token: " << vec[0] << std::endl;

    target->sendMessage("PONG with token " + vec[0]);

  }

  
}

Pong::~Pong(void) {return ;}