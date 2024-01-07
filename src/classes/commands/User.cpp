/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:32:00 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/07 19:47:15 by eros-gir         ###   ########.fr       */
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
  else
  {
    client->setName(vec[1]);
    std::string realName = vec[4];
    if (vec.size() > 5)
    {
      for (size_t i = 5; i < vec.size(); i++)
        realName += " " + vec[i];
      client->setRealName(realName);
    }
    if (realName[0] == ':')
      realName = realName.substr(1, realName.size() - 1);
    client->setRealName(realName);
    std::cout << clientFd << ": User registered" << std::endl;
    return ;
  }    
}

User::~User(void) {return ;}