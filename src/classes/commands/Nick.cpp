/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Nick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 12:56:58 by eros-gir          #+#    #+#             */
/*   Updated: 2024/01/05 18:30:46 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/commands/Nick.hpp"

Nick::Nick(int const &clientFd, std::vector<std::string> const &vec, Server *server) : ACommand(clientFd, vec, server)
{
  Client *client = this->_server->getClientByFd(this->_clientFd);
  if (client->getRegistered() == false)
  {
    std::cout << "Client [" << clientFd << "] is not registered yet" << std::endl;
    return ;
  }
  else if (vec.size() < 2)
  {
    std::cout << "Not enough params" << std::endl;
    return ;
  }
  else
  {
    if (vec.size() > 1)    
      client->setNickName(vec[1]);
    client->sendMessage("Your nick now is " + client->getNickName());
  }
  return ;
}

Nick::~Nick(void) {return ;}

