/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:50:32 by eros-gir          #+#    #+#             */
/*   Updated: 2023/12/28 10:15:17 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/commands/Pass.hpp"

Pass::Pass(int const &clientFd, std::vector<std::string> const &vec, Server *server) : ACommand(clientFd, vec, server)
{
  runCmd();
  return ;
}

Pass::~Pass(void) {return ;}

void Pass::runCmd()
{
  Client *client = this->_server->getClients()[this->_clientFd];

  if (this->_vec.size() != 2)
  {
	std::cout << "Error: Wrong number of arguments" << std::endl;
	return ;
  }
  else if (this->_vec[1] != _server->getPassword())
  {
	std::cout << "Error: Wrong password" << std::endl;
	return ;
  }
  else
  {
  // TODO check if password is correct
  // TODO if password is correct, set client as registered
  // TODO if password is incorrect, close connection
  return ;
}
