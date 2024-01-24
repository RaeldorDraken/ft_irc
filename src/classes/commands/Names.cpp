/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Names.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:27:10 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/23 20:08:48 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/commands/Names.hpp"

Names::Names(int const &clientFd, std::vector<std::string> const &vec, Server *server) : ACommand(clientFd, vec, server)
{
  Client *client = server->getClientByFd(clientFd);

  if (vec.size() < 2)
  {
    return ;
  } // ? If not enogh args, just return. 

  std::vector<std::string> targets = Utils::tokenizeByChar(vec[1],','); // ? Get the channels we need to send the names to parsing the args from vec[1]
 

  for (unsigned long i = 0; i < targets.size(); i++)
  {
    int channel = server->searchChannel(targets[i]);
    if (channel != -1) // ? If channel exists
    {
      Channel *my_channel = server->getServerChannels()[channel];
      my_channel->sendNames(*client);
    }
  }
    
}

Names::~Names(void) {return ;}