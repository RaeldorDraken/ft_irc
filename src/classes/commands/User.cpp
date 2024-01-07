/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:32:00 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/07 17:12:01 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/commands/User.hpp"

User::User(int const &clientFd, std::vector<std::string> const &vec, Server *server) : ACommand(clientFd, vec, server)
{

  Client *client = server->getClientByFd(clientFd);

  if (client == nullptr)
  {
    std::cout << "Client is null" << std::endl;
    return ;
  }

  if (client->getName() != "")
  {
    std::ostringstream oss;
    oss << "name: " << client->getName() << "\nrealname: " << client->getRealName();
    client->sendMessage("You are already registered with:\n" + oss.str() + "\n");
    std::cout << clientFd << ": User already registered" << std::endl;
    return ;
  }

  if (vec.size() < 5)
  {
    client->sendMessage("Not enough arguments\n");
    std::cout << clientFd << ": Not enough params" << std::endl;
    return ;
  }
  else if (vec.size() > 5)
  {
    client->sendMessage("Too many arguments\n");
    std::cout << clientFd << ": Too many params" << std::endl;
    return ;
  }
  else if (vec.size() == 5)
  {
    client->setName(vec[1]);
    client->setRealName(vec[4]);
    client->sendMessage("You are now registered");
    std::cout << clientFd << ": User registered" << std::endl;
    return ;
  }    
}

User::~User(void) {return ;}