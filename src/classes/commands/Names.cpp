/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Names.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:27:10 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/28 20:27:28 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/commands/Names.hpp"

Names::Names(int const &clientFd, std::vector<std::string> const &vec, Server *server) : ACommand(clientFd, vec, server)
{
  (void)server;
  (void)vec;

  // std::cout << "Names command created with passed clientFd of " << clientFd << std::endl;

  Client *client = server->getClientByFd(clientFd);

  std::vector<std::string> targets;
  std::stringstream ss(vec[1]);
  std::string target;
  while (std::getline(ss, target, ','))
      targets.push_back(target);	

  for (unsigned long i = 0; i < targets.size(); i++)
  {
    int channel = server->searchChannel(targets[i]);
    if (channel != -1)
    {
      Channel *my_channel = server->getServerChannels()[channel];
      my_channel->sendNames(*client);
    }
  }
    
}

Names::~Names(void) {return ;}