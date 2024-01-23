/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:21:19 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/23 19:18:29 by rabril-h         ###   ########.fr       */
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
  std::string reason; // ? Use a var to store the reason client leaves channel/s

  if (vec.size() > 2) // ? If we have an additional argument for reason
  {
    for (size_t i = 2; i < vec.size(); ++i) {
      // ? Concatenate each string to the result
      reason += vec[i];
      if (i < vec.size() - 1) {
          reason += ' '; // ? Add space between words except for the last one
      }
    }
  }    
  else // ? Otherwise set default reason
    reason = "no reason given..."; 

  if (multiple != std::string::npos)
  {
    std::vector<std::string> targets = Utils::tokenizeByChar(vec[1], ',');     
    for (unsigned long i = 0; i < targets.size(); i++)
      this->_partFromChannel(clientFd, targets[i], reason, server);      
  }
  else 
    this->_partFromChannel(clientFd, vec[1], reason, server);

  return ;
}

Part::~Part(void) {return ;}

void  Part::_partFromChannel(int const clientFd, std::string const &channel_name, std::string reason, Server *server)
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
	" PART " + channel->getChannelName() + " :" + reason; // ? Format message  

  channel->sendChannelMessage(0, output); // ? Send message to channel

  if (channel->clientIsOperator(*client))
    channel->removeOperator(*client); // ? If client i operator remove them from the _operators vector
  channel->removeClient(*client); // ? Remove client from channel

  

}