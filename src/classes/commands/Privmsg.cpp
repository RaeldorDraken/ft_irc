/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Privmsg.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:33:28 by eros-gir          #+#    #+#             */
/*   Updated: 2024/01/16 19:03:17 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/commands/Privmsg.hpp"

Privmsg::Privmsg(int const &clientFd, std::vector<std::string> const &vec, Server *server) : ACommand(clientFd, vec, server)
{
	// //PRIVMSG user msg
	// if (vec.size() < 3)
	// 	std::cout << "Not enough params" << std::endl;
	// else
	// {
	// 	std::string msg = "";
	// 	for (size_t i = 2; i < vec.size(); i++)
	// 		msg += vec[i] + " ";
	// 	std::cout << "Sending msg to " << vec[1] << " : " << msg << std::endl;
	// 	// ! stoi is not in c++98 need to change the function to use another type of conversion
	// 	sendMsg(clientFd, ft_stoi(vec[1]), msg);
	// }

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

// void Privmsg::sendMsg(int const &sender, int const &receiver, std::string const &msg)
// {
//   // ! to_string is not in c++98, changed the function to use ostringstream
//   std::ostringstream oss1;
//   oss1 << sender;
//   std::ostringstream oss2;
//   oss2 << receiver;
//   std::string msgtype = " PRIVMSG ";
//   if (sender == receiver)
// 	return ;
//   else if (sender == 3)
// 	msgtype = " NOTICE ";
//   std::string toSend = ":" + oss1.str() + msgtype + oss2.str() + " :" + msg + "\r\n";
//   std::cout << "Sending " << toSend << std::endl;
//   send(receiver, toSend.c_str(), toSend.size(), 0);
// }