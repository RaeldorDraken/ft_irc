/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Invite.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:51:15 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/20 18:40:18 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/commands/Invite.hpp"

Invite::Invite(int const &clientFd, std::vector<std::string> const &vec, Server *server) : ACommand(clientFd, vec, server)
{
  std::cout << "Invite command created with passed clientFd of " << clientFd << std::endl;

  Client		*client = server->getClientByFd(clientFd); 

  if (vec.size() < 3)
  {
    client->sendMessage(Messages::printMoreParamsMsg(client->getNickName(), vec[0]));
		return ;
  } // ? If not enough arguments INVITE <nickname> <channel>

  std::string invitedClient = vec[1];
  std::string inviteChannel = vec[2];

  std::cout << "Cliente es " <<  invitedClient << " y canal a ingresar es " << inviteChannel << std::endl;

  int my_channelFd = server->searchChannel(inviteChannel); // ? Search for the channel to get invited to, to exist

  if (my_channelFd == -1)
  {
    client->sendMessage(Messages::printNoSuchChannel(client->getNickName
    (), inviteChannel));
    return ;
  }

  Channel *my_channel = server->getServerChannels()[my_channelFd]; // ? Get a reference to the channel instance *Channel

  if (!my_channel->clientIsMember(client->getNickName()))
  {
    client->sendMessage(Messages::printNotOnChannel(client->getNickName(), inviteChannel));
    return ;
  } // ? If client trying to invite to another is not on the channel itself

  if (my_channel->clientIsMember(invitedClient))
  {
    client->sendMessage(Messages::printUserAlreadyInChannel(client->getNickName(), invitedClient, inviteChannel));
    return ;
  } // ? If client to get invited is already on the channel 

  if (my_channel->getIMode() && !my_channel->clientIsOperator(*client))
  {
    client->sendMessage(Messages::printUserNotOperator(client->getNickName(), inviteChannel));
    return ;
  } // ? if the client trying to invite another has no privileges to do so.

  Client *targetClient = server->getClientByNickName(invitedClient); // ? Get the Client to get invited based on its nickname
  if (targetClient != NULL) // ? If client exists
  {
    //int targetFd = targetClient->getClientFd(); // ? Get their FD
    my_channel->inviteClient(*targetClient); // ? Invite the Client by adding their fd to the members on channel

    // ? Send both messages for invited client and client inviting
    targetClient->sendMessage(":" + client->getNickName() + " INVITE " + targetClient->getNickName() + " " + inviteChannel); 
    client->sendMessage(Messages::getInviteReply(client->getNickName(), targetClient->getNickName(), inviteChannel));
  }

  return ;  
    
}

Invite::~Invite(void) {return ;}