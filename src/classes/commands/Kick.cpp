/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Kick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:55:24 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/23 19:49:28 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/commands/Kick.hpp"

Kick::Kick(int const &clientFd, std::vector<std::string> const &vec, Server *server) : ACommand(clientFd, vec, server)
{
  std::cout << "Kick command created with passed clientFd of " << clientFd << std::endl;

  Client		*client = server->getClientByFd(clientFd);

  if (vec.size() < 3)
  {
    client->sendMessage(Messages::printMoreParamsMsg(client->getNickName(), vec[0]));
    return ;
  } // ? If not enough params

  int my_channelFd = server->searchChannel(vec[1]); // ? Search for the channel to kick an user out of
  
  if (my_channelFd == -1)
  {
    client->sendMessage(Messages::printNoSuchChannel(client->getNickName(), vec[1]));
    return ;
  } // ? If channel does not exist

  Channel *my_channel = server->getServerChannels()[my_channelFd]; // ? Get an instance for our channel

  if (!my_channel->clientIsOperator(*client))
  {
    client->sendMessage(Messages::printUserNotOperator(client->getNickName(), my_channel->getChannelName()));
    return ;
  }

  size_t multiple = vec[2].find(','); // ? get to know if we are kicking more than one user

  if (multiple != std::string::npos)
  {
    std::vector<std::string> targets = Utils::tokenizeByChar(vec[2], ',');
    // std::stringstream ss(vec[2]);
    // std::string token;
    // while (std::getline(ss, token, ','))
    //     targets.push_back(token);

    for (unsigned long i = 0; i < targets.size(); i++)
      this->_kickUser(clientFd, targets[i], my_channel, server);
  }
  else
    this->_kickUser(clientFd, vec[2], my_channel, server);

}

Kick::~Kick(void) {return ;}

Client *Kick::_kickUser(int const clientFd, std::string const &target, Channel *channel, Server *server)
{
  Client		*client = server->getClientByFd(clientFd);

  if (!channel->clientIsMember(target))
  {
    client->sendMessage(Messages::printUserNotInChannel(client->getNickName(), target, channel->getChannelName()));
    return NULL;
  } // ? If client to kick out is not in the channel

  if (!channel->clientIsMember(client->getNickName()))
  {
    client->sendMessage(Messages::printNotOnChannel(client->getNickName(), channel->getChannelName()));
    return NULL;
  }// ? If client trying to kick out another is not on the channel

  int my_target_fd = server->getClientByNickName(target)->getClientFd();

  if (my_target_fd == -1 || my_target_fd == clientFd)
    return NULL; // ? If target does not exist or we are kicking ourselfs

  Client *toKick = server->getClientByFd(my_target_fd); // ? Get an instance of the kicked client

  std::string output = ":" + client->getNickName() + "!" + client->getHostName() +\
	" KICK " + channel->getChannelName() + " " + toKick->getNickName() + " Kicked from channel";

  channel->sendChannelMessage(0, output);

  // std::cout << "Members on channel " << channel->getChannelName() << " are: " << std::endl;

  // std::vector<Channel *> my_channels = server->getServerChannels();


  
  // for (size_t i = 0; i < server->getServerChannels(); i++)
  //     std::cout << "[" << i << "] : " << msg << " -> " << vec[i] << std::endl;

  channel->removeClient(*toKick);

  return (toKick);
   
}