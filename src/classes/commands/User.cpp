/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:32:00 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/03 18:43:30 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/commands/User.hpp"

User::User(int const &clientFd, std::vector<std::string> const &vec, Server *server) : ACommand(clientFd, vec, server)
{
  (void)vec;

  // ? Get to know which client is executing the command
  //std::map<int, Client *> _myClients = server->getClients();
  Client *target = server->getClientByFd(clientFd);

  std::cout << "User command created with passed clientFd of " << clientFd << std::endl;

  //! Remove. this is a test

  if (target != nullptr) // ?  Safe to check if we had a match
  {
      target->sendMessage(Messages::getUserWelcome("nickdemierda", "networkname", "nickedemierda", "hostdemierda"));
      target->sendMessage(Messages::getCreatedAt("nickdemierda", server->getServerCreationTime()));
      target->sendMessage(Messages::getMyInfo("nickdemierda", "servername"));
  }
  
 
    
}

User::~User(void) {return ;}