/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:21:19 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/22 21:40:31 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/commands/Part.hpp"

Part::Part(int const &clientFd, std::vector<std::string> const &vec, Server *server) : ACommand(clientFd, vec, server)
{
  std::cout << "PART command created with passed clientFd of " << clientFd << std::endl;

  Client		*client = server->getClientByFd(clientFd);
  
  if (vec.size() < 2)
  {
    client->sendMessage(Messages::printMoreParamsMsg(client->getNickName(), vec[0]));
    return ;
  } // ? If not enough params
 

  size_t multiple = vec[1].find(','); // ? get to know if we are parting from more than one channel

  if (multiple != std::string::npos)
  {
    std::vector<std::string> targets = Utils::tokenizeByChar(vec[1], ',');     
    for (unsigned long i = 0; i < targets.size(); i++)
      this->_partFromChannel(clientFd, targets[i], server);      
  }
  else 
    this->_partFromChannel(clientFd, vec[1], server);

  return ;
}

Part::~Part(void) {return ;}

void  Part::_partFromChannel(int const clientFd, std::string const &channel_name, Server *server)
{
  Client		*client = server->getClientByFd(clientFd);

  int my_channelPos = server->searchChannel(channel_name); // ? Get the index of the channel we want to part from from the vector of existing channels

  if (my_channelPos == -1)
  {
    client->sendMessage(Messages::printNoSuchChannel(client->getNickName(), channel_name));
    return ;
  } // ? If channel does not exist
 

  Channel *channel = server->getServerChannels()[my_channelPos]; 

  if (!channel->clientIsMember(client->getNickName()))
  {
     client->sendMessage(Messages::printNotOnChannel(client->getNickName(), channel_name));
     return ;
  } // ? If client to part is not on that channel

  // ? We are good to part

  std::string output = ":" + client->getNickName() + "!" + client->getHostName() +\
	" PART " + channel->getChannelName(); // ? Format message  

  channel->sendChannelMessage(NULL, output); // ? Send message to channel

  if (channel->clientIsOperator(*client))
    channel->removeOperator(*client); // ? If client i operator remove them from the _operators vector
  channel->removeClient(*client); // ? Remove client from channel

  

}