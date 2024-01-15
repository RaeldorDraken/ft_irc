/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Privmsg.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:33:28 by eros-gir          #+#    #+#             */
/*   Updated: 2024/01/15 20:58:53 by rabril-h         ###   ########.fr       */
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


	if (vec.size() > 1)
	{
		size_t has_multiple = vec[1].find(',');		

		if (has_multiple != std::string::npos)
		{
			std::vector<std::string> targets;
			std::stringstream ss(vec[1]);
			std::string token;
			while (std::getline(ss, token, ','))
					targets.push_back(token);  

			for (unsigned long i = 0; i < targets.size(); i++)
			{
				if (targets[i][0] == '#' || targets[i][0] == '&' )
					std::cout << "Send messages to channel " << std::endl; // ? send messages to channel
				else
					this->_sendMsgToUser(clientFd, vec, targets[i], server); // ? send messages to users
			}
		}
		else
		{
			if (vec[1][0] == '#' || vec[1][0] == '&')
				std::cout << "Send messages to channel " << std::endl; // ? send message to channel
			else
				this->_sendMsgToUser(clientFd, vec, vec[1], server); // ? send messages to users

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

void Privmsg::_sendMsgToUser(int const clientFd, std::vector<std::string> const &vec, std::string const &target, Server *server)
{
	Client *client = server->getClientByFd(clientFd);
	//std::string	client_nickname = client->getNickName();

	if (vec.size() < 2 || target[0] == ':')
	{
		client->sendMessage(Messages::printNoRecipient(client->getNickName(), "PRIVMSG"));
		return ;
	} // ? if not enough argmuments or second argument is just ":"

	// TODO need to create a method in server to find a match over a client based on its nickname, which will need a connection to NICK

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
		std::string msg;
		//int targetFd = targetClient->getClientFd(); // ? Get their FD
		// if (vec[2][0] != ':')
		// {
		// 	// ? Prepend ":" if not present
		// 	msg = ':' + vec[2];
		// }
		std::string output = ":" + client->getNickName() + "!" + client->getHostName() + " PRIVMSG " + targetClient->getNickName();
		for (unsigned long i = 2; i < vec.size(); i++)
			output.append(" " + vec[i]);
		targetClient->sendMessage(output);			
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