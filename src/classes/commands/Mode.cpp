/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mode.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:24:56 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/18 21:12:41 by rabril-h         ###   ########.fr       */
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

  std::map<std::string, std::string> modes = this->_formatMode(my_vec[2]);

  // TODO temporary code, print result from formatMode

  std::map<std::string, std::string>::iterator it;
  for (it = modes.begin(); it != modes.end(); ++it) {
      std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
  }
  
  if (modes["+"].size() > 1)
  {
    this->_addMode(modes, my_vec, clientFd, server);
  }
  

}

Mode::~Mode(void) {return ;}

// ? ADD 

void Mode::_addMode(std::map<std::string, std::string> &modes, std::vector<std::string> &vec, int const clientFd, Server *server)
{
  
  // TODO need to find a way that only operators can set modes such as +t. Currently no operators can set +t on the channel...
  
  
  (void) clientFd;
  //Client  *client = server->getClientByFd(clientFd); // ? Get the client
  Channel *channel = server->getServerChannels()[server->searchChannel(vec[1])]; // ? Get the channel 

  std::string pass = ""; // ? Var to hold the pass for k

  // ? Simple modes with no arguments
  
  if (Utils::isCharInString(modes["+"], 'i')) // ? If we are setting just invite only channel mode
    channel->setIMode(true);
  if (Utils::isCharInString(modes["+"], 't')) // ? If we are setting just topic protected mode
    channel->setTMode(true);

  // ? Rest of modes 

  // ? K mode - Channel is passord protected - This is well implemented

  // if (Utils::isCharInString(modes["+"], 'k') && this->_enoughArgsForMode(vec, client, modes["+"], 'k'))
  // {
  //   pass = this->_getKeyFromString(modes, vec, 'k', client); // ? Get the pass from the arguments
	// 	if (Utils::isCharInString(modes["+"], 'k'))
	// 	{
	// 		channel->setKMode(true);
	// 		channel->setChannelPass(pass);
	// 	}
  // }

  // // ? o mode - Add operator - Needs work

  // if (Utils::isCharInString(modes["+"], 'o') && this->_enoughArgsForMode(vec, client, modes["+"], 'o'))
  // {
  //   pass = this->_getKeyFromString(modes, vec, 'k', client); // ? Get the nick from the arguments
  //   if (Utils::isCharInString(modes["+"], 'o'))
  //   {
  //     // TODO continue with the following commands. Maybe password can be named key since it is used in all commands for different purposes
  //   }

  // }





}

// ? Utils functions

std::map <std::string, std::string> Mode::_formatMode(std::string &input)
{
  std::map<std::string, std::string> my_modes;
  bool                               already;
  char                               c;

  c = input[0]; // ? get the first letter from input

  my_modes["+"] = "+";
	my_modes["-"] = "-";
	for (unsigned long i = 0; i < input.length(); i++)
	{
		already = 0;
		if (std::isalpha(input[i]) && Utils::isCharInString("itkol", input[i]))
		{
			for (unsigned long j = i + 1; j < input.length(); j++)
				if (i != j && input[i] == input[j])
					already = 1;
			if (already == 0 && c == '+')
				my_modes["+"] = my_modes["+"] + input[i];
			if (already == 0 && c == '-')
				my_modes["-"] = my_modes["-"] + input[i];
		}
		if (input[i] == '+' || input[i] == '-')
			c = input[i];
	}
	my_modes["order"] = "";
	if (input.length() == 0)
		return my_modes;
	for (long long i = input.length() - 1; i >= 0; i--)
	{
		if (Utils::isCharInString("kol", input[i]) && !Utils::isCharInString(my_modes["order"] + "+-", input[i]))
			my_modes["order"] = input[i] + my_modes["order"];
	}
	if (Utils::isCharInString(my_modes["-"], 'l') && Utils::isCharInString(my_modes["order"], 'l'))
		Utils::deleteCharFromString(my_modes["order"], 'l');

  
  // std::map<std::string, std::string> my_modes;
  // std::string currentMode;
  // std::string order;

  // for (size_t i = 0; i < input.length(); ++i) {
  //     char c = input[i];

  //     if (c == '+' || c == '-') {
  //         currentMode = c;
  //     } else if (std::isalpha(c) && Utils::isCharInString("itkol", c)) {
  //         if (currentMode == "+") {
  //             if (my_modes["+"].find(c) == std::string::npos) {
  //                 my_modes["+"] += c;
  //             }
  //         } else if (currentMode == "-") {
  //             if (my_modes["-"].find(c) == std::string::npos) {
  //                 my_modes["-"] += c;
  //             }
  //         }
  //     }
  // }

  // for (int i = static_cast<int>(input.length()) - 1; i >= 0; --i) {
  //     char c = input[static_cast<size_t>(i)];
  //     if (Utils::isCharInString("kol", c) && order.find(c) == std::string::npos) {
  //         order = c + order;
  //     }
  // }

  // if (my_modes["-"].find('l') != std::string::npos && order.find('l') != std::string::npos) {
  //     Utils::deleteCharFromString(order, 'l');
  // }

  // my_modes["order"] = order;

  return my_modes;

}

bool  Mode::_enoughArgsForMode(std::vector<std::string> &vec, Client *client, std::string &modes, char c)
{
  if (vec.size() < 4)
	{
		client->sendMessage(Messages::printMoreParamsMsg(client->getNickName(), vec[0] + " " + c));
		Utils::deleteCharFromString(modes, c);
		return false;
	}
	return true;
}

std::string Mode::_getKeyFromString(std::map<std::string, std::string> &modes, std::vector<std::string> &vec, char c, Client *client)
{
  std::string key = ""; // ? var to hold the returned key

  int index = Utils::getCharPosFromString(modes["order"], c); // ? get the index for the char representing the mode for which we are looking for an arg

  switch (index)
	{
		case 0:
		{
			key = vec[3];
			break ;
		}
		case 1:
		{
			if (vec.size() >= 5)
				key = vec[4];
			else 
			{
				client->sendMessage(Messages::printMoreParamsMsg(client->getNickName(), vec[0] + " +" + c));
				Utils::deleteCharFromString(modes["+"], c);
			}
			break ;
		}
		case 2:
		{
			if (vec.size() >= 6)
				key = vec[5];
			else
			{
				client->sendMessage(Messages::printMoreParamsMsg(client->getNickName(), vec[0] + " +" + c));
				Utils::deleteCharFromString(modes["+"], c);
			}
			break ;
		}
	};
	return key;
}