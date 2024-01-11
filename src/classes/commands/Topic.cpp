/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Topic.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:30:23 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/09 21:00:13 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/commands/Topic.hpp"

Topic::Topic(int const &clientFd, std::vector<std::string> const &vec, Server *server) : ACommand(clientFd, vec, server)
{
  // (void)server;
  // (void)vec;

  std::cout << "Topic command created with passed clientFd of " << clientFd << std::endl;

  Client *client = server->getClientByFd(clientFd); 

  if (vec.size() < 2) // ? If no channel is provided
  {
    client->sendMessage(Messages::printMoreParamsMsg(client->getNickName(), vec[0]));
    return ;
  } 

  int channel = server->searchChannel(vec[1]);
  if (channel == -1) // ? if channel is not found
  {
    client->sendMessage(Messages::printNoSuchChannel(client->getNickName(),vec[1]));
    return ;
  }

  std::cout << "Llego aqui" << std::endl;

  Channel *my_channel = server->getServerChannels()[channel];

  if (!my_channel->clientIsMember(client->getNickName())) // ? If client is not in the channel topic cannot be set
  {
    client->sendMessage(Messages::printNotOnChannel(client->getNickName(), my_channel->getChannelName()));
    return ;
  }

  if (vec.size() > 2 && my_channel->getTMode() && !my_channel->clientIsOperator(clientFd)) // ? If there is more than just TOPIC, meaninf args are enough long to have a string for topic BUT the channel is topic protected (+k) and client is NOT an operator of the channel
  {
    client->sendMessage(Messages::printUserNotOperator(client->getNickName(), my_channel->getChannelName()));
  }

  if (vec.size() > 2 && vec[2] == ":") // ? If there are enough args to set a topic BUT the topic is just  ":"
  {
    my_channel->setChannelTopic("");
    std::string new_topic = "TOPIC " + my_channel->getChannelName() + " :" + my_channel->getChannelTopic();
    my_channel->sendChannelMessage(0, new_topic);
    return ;
  }

  if (vec.size() > 2) // ? If we just have enough args to set a topic. Set it and send proper messages
  {
    std::string new_topic = vec[2];
    for (unsigned long i = 3; i < vec.size(); i++)
      new_topic.append(" " + vec[i]);
    my_channel->setChannelTopic(new_topic);
    my_channel->sendChannelMessage(0, Messages::getTopic(client->getNickName(), my_channel->getChannelName(), my_channel->getChannelTopic()));
    my_channel->sendChannelMessage(0, Messages::getTopicWhoWhen(client->getNickName(), my_channel->getChannelName(), my_channel->getChannelTopic(), server->getCurrentTime()));
    
  }
  else // ? Otherwise
  {
    if (my_channel->getChannelTopic() == "") // ? send message to client
    {
      client->sendMessage(Messages::getTopic(client->getNickName(), my_channel->getChannelName(), my_channel->getChannelTopic()));
      client->sendMessage(Messages::getTopicWhoWhen(client->getNickName(), my_channel->getChannelName(), my_channel->getChannelTopic(), server->getCurrentTime())); 
    }
    else
      client->sendMessage(Messages::getNoTopic(client->getNickName(), my_channel->getChannelName()));
  }  
    
}

Topic::~Topic(void) {return ;}