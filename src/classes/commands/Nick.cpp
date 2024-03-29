/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Nick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 12:56:58 by eros-gir          #+#    #+#             */
/*   Updated: 2024/01/28 15:42:23 by eros-gir         ###   ########.fr       */
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
    if (vec.size() > 1 && !server->clientNickNameExists(vec[1]))
      client->setNickName(vec[1]);
    else
      return ;
    // client->sendMessage("Your nick now is " + client->getNickName());
    client->sendMessage(Messages::getUserWelcome(client->getNickName(), server->getHostName(), client->getNickName(), client->getHostName()));
	  client->sendMessage(Messages::getYourHost(client->getNickName(), server->getHostName()));
	  client->sendMessage(Messages::getCreatedAt(client->getNickName(), server->getServerCreationTime()));
	  client->sendMessage(Messages::getMyInfo(client->getNickName(), server->getHostName()));
  }
  return ;
}

Nick::~Nick(void) {return ;}

