/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Privmsg.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:33:28 by eros-gir          #+#    #+#             */
/*   Updated: 2024/01/16 21:06:48 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/commands/Privmsg.hpp"

Privmsg::Privmsg(int const &clientFd, std::vector<std::string> const &vec, Server *server) : ACommand(clientFd, vec, server)
{
	std::vector<std::string> my_vec = vec; // ? Make a copy of vector so it is no longer const and can be modified further in the code (_sendMsgToUser and _sendMsgToChannel)

	if (my_vec.size() > 1)
	{
		size_t has_multiple = my_vec[1].find(',');		

		if (has_multiple != std::string::npos)
		{
			std::vector<std::string> targets;
			std::stringstream ss(my_vec[1]);
			std::string token;
			while (std::getline(ss, token, ','))
					targets.push_back(token);  

			for (unsigned long i = 0; i < targets.size(); i++)
			{
				if (targets[i][0] == '#' || targets[i][0] == '&' )
					this->_sendMessageToChannel(clientFd, my_vec, targets[i], server); // ? send messages to channel
				else
					this->_sendMsgToUser(clientFd, my_vec, targets[i], server); // ? send messages to users
			}
		}
		else
		{
			if (my_vec[1][0] == '#' || my_vec[1][0] == '&')
				this->_sendMessageToChannel(clientFd, my_vec, my_vec[1], server); // ? send message to channel
			else
				this->_sendMsgToUser(clientFd, my_vec, my_vec[1], server); // ? send messages to users

		}
	}
	else
	{
		Client *client = server->getClientByFd(clientFd);
		client->sendMessage(Messages::printNoRecipient(client->getNickName(), "PRIVMSG"));
	}
  return ;
}

Privmsg::~Privmsg(void) {return ;}


void Privmsg::_sendMessageToChannel(int const clientFd, std::vector<std::string> &vec, std::string const &target, Server *server)
{
	Client *client = server->getClientByFd(clientFd);

	int my_channelFd = server->searchChannel(target); // ? Search for the channel to get send message to, to exist

	if (my_channelFd == -1)
	{
		client->sendMessage(Messages::printNoSuchNick(client->getNickName(), target));
		return ;
	} // ? If channel does not exist

	if (vec.size() < 3)
	{
		client->sendMessage(Messages::printNoTextToSend(client->getNickName()));
		return ;
	} // ? if not enough arguments

	// TODO this may be solved in other commands maybe MODES. Do not allow message to a channel if client is not in that channel

	if (!server->getServerChannels()[my_channelFd]->clientIsMember(client->getNickName()))
	{
		client->sendMessage(Messages::printNotOnChannel(client->getNickName(), server->getServerChannels()[my_channelFd]->getChannelName()));
		return; 
	}

	// TODO end of TODO

	std::string output = ":" + client->getNickName() + " PRIVMSG " + server->getServerChannels()[my_channelFd]->getChannelName(); // ? Format the beginning of the message as IRC standards
	if (vec[2][0] != ':')
		vec[2] = ":" + vec[2]; // ? if not present append :
	
	for (unsigned long i = 2; i < vec.size(); i++)
		output.append(" " + vec[i]); // ? Append the text to the message to send

	server->getServerChannels()[my_channelFd]->sendChannelMessage(*client, output); // ? send message to channel
	
}

void Privmsg::_sendMsgToUser(int const clientFd, std::vector<std::string> &vec, std::string const &target, Server *server)
{
	Client *client = server->getClientByFd(clientFd);

	if (vec.size() < 2 || target[0] == ':')
	{
		client->sendMessage(Messages::printNoRecipient(client->getNickName(), "PRIVMSG"));
		return ;
	} // ? if not enough argmuments or second argument is just ":"

	if (!server->clientNickNameExists(target) && target != "RoabhiDrakenBot")
	{
		client->sendMessage(Messages::printNoSuchNick(client->getNickName(), target));
		return ;
	} // ? If no nickname is found on the server

	if (vec.size() < 3 && target != "RoabhiDrakenBot")
	{
		client->sendMessage(Messages::printNoTextToSend(client->getNickName()));
		return ;
	} // ? If there is no arguments associated with the message

	if (target == "RoabhiDrakenBot")
	{
		client->sendMessage(":RoabhiDrakenBot PRIVMSG " + client->getNickName() + " :You are messaging the bot. Do not do that again");
		return ;
	} // ? If messages go the the bot/server

	Client *targetClient = server->getClientByNickName(target); // ? Get the Client to get invited based on its nickname

	if (targetClient != NULL) // ? If client exists
	{
		if (vec[2][0] != ':')
			vec[2] = ":" + vec[2]; // ? if not present append :
		std::string output = ":" + client->getNickName() + "!" + client->getHostName() + " PRIVMSG " + targetClient->getNickName(); // ? format the beginning of the message as IRC standards
		for (unsigned long i = 2; i < vec.size(); i++)
			output.append(" " + vec[i]); // ? Concatenate the text to message to send
		targetClient->sendMessage(output); // ? Send it			
	}
}

