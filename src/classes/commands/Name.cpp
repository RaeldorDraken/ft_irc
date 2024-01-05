/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Name.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 12:56:58 by eros-gir          #+#    #+#             */
/*   Updated: 2024/01/05 18:29:39 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/commands/Name.hpp"

Name::Name(int const &clientFd, std::vector<std::string> const &vec, Server *server) : ACommand(clientFd, vec, server)
{
  Client *client = this->_server->getClientByFd(this->_clientFd);
  if (client->getRegistered() == false)
  {
	std::cout << "Client [" << clientFd << "] is not registered yet" << std::endl;
	return ;
  }
  else if (vec.size() < 1)
  {
	std::cout << "Not enough params" << std::endl;
	return ;
  }
  else
  {
	client->setName(vec[1]);
	std::cout << "Client [" << clientFd << "] name is now " << client->getName() << std::endl;
  }
  return ;
}

Name::~Name(void) {return ;}