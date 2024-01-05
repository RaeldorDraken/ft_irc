/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Real.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 12:56:58 by eros-gir          #+#    #+#             */
/*   Updated: 2024/01/01 13:34:53 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/commands/Real.hpp"

Real::Real(int const &clientFd, std::vector<std::string> const &vec, Server *server) : ACommand(clientFd, vec, server)
{
  Client *client = this->_server->getClients()[this->_clientFd];
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
  client->setRealName(vec[1]);
  std::cout << "Client [" << clientFd << "] real is now " << client->getRealName() << std::endl;
  }
  return ;
}

Real::~Real(void) {return ;}
