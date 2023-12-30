/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:32:00 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/30 20:59:33 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/commands/User.hpp"

User::User(int const &clientFd, std::vector<std::string> const &vec, Server *server) : ACommand(clientFd, vec, server)
{
  (void)vec;

  // ? Get to know which client is executing the command
  std::map<int, Client *> _myClients = server->getClients();
  Client *target = _myClients[clientFd];

  std::cout << "User command created with passed clientFd of " << clientFd << std::endl;

  //! Remove. this is a test
  
  target->sendMessage(Messages::getUserWelcome("nickdemierda", "networkname", "nickedemierda", "hostdemierda"));

  target->sendMessage(Messages::getCreatedAt("nickdemierda", server->getServerCreationTime()));

  target->sendMessage(Messages::getMyInfo("nickdemierda", "servername"));
    
}

User::~User(void) {return ;}