/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mode.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:24:56 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/17 20:37:23 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/commands/Mode.hpp"

Mode::Mode(int const &clientFd, std::vector<std::string> const &vec, Server *server) : ACommand(clientFd, vec, server)
{
  // (void)server;
  // (void)vec;
  std::cout << "Mode command created with passed clientFd of " << clientFd << std::endl;

  Client		*client = server->getClientByFd(clientFd);

  std::vector<std::string> my_vec = vec; // ? Make a copy of vector so it is no longer const and can be modified further in the code 
  std::string pass; // ? Declare a var to hold the pass

  if (my_vec.size() == 1 || (my_vec[1][0] != '#' && my_vec[1][0] != '&')) // ? If we have only one argument OR the first character is NOT an # or &
  {
    if (my_vec.size() > 1) // ? If arguments has still more than one argument
      client->sendMessage(Messages::printNoSuchChannel(client->getNickName(),my_vec[1]));
    else // ? If not
      client->sendMessage(Messages::printNoSuchChannel(client->getNickName(),""));
    return ;
  }

  int my_channelFd = server->searchChannel(my_vec[1]); // ? Search for the channel to get send message to, to exist

  if (my_channelFd == -1) // ? If channel does noe exists
  {
    client->sendMessage(Messages::printNoSuchChannel(client->getNickName(),my_vec[1]));
    return ;
  }

  // ? If channel exists

  Channel *my_channel = server->getServerChannels()[my_channelFd]; // ? Get an instance for the channel

  if (my_vec.size() == 2 || (my_vec[2][0] != '+' && my_vec[2][0] != '-')) // ? If we are trying to set modes and client is not using + or - reply with available options and instructions
  {
    std::string channel_modes = my_channel->getModes(); // ? get the list
    std::string channel_args = my_channel->getModeArguments(); // ? get the mode arguments

    std::cout << "Channel modes are " << channel_modes << " and args are " << channel_args << std::endl;

    client->sendMessage(Messages::getChannelModeOptions(client->getNickName(), my_channel->getChannelName(), channel_modes, channel_args));
    return ;
  }
    
}

Mode::~Mode(void) {return ;}