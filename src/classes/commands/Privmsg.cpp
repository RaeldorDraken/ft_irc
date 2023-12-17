/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Privmsg.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:33:28 by eros-gir          #+#    #+#             */
/*   Updated: 2023/12/17 19:46:25 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/commands/Privmsg.hpp"

Privmsg::Privmsg(int const &clientFd, std::vector<std::string> const &vec, Server *server) : ACommand(clientFd, vec, server)
{
	//PRIVMSG user msg
	if (vec.size() < 3)
		std::cout << "Not enough params" << std::endl;
	else
	{
		std::string msg = "";
		for (size_t i = 2; i < vec.size(); i++)
			msg += vec[i] + " ";
		std::cout << "Sending msg to " << vec[1] << " : " << msg << std::endl;
		sendMsg(clientFd, std::stoi(vec[1]), msg);
	}
  return ;
}

Privmsg::~Privmsg(void) {return ;}

void Privmsg::sendMsg(int const &sender, int const &receiver, std::string const &msg)
{
  std::string toSend = ":" + std::to_string(sender) + " PRIVMSG " + std::to_string(receiver) + " :" + msg + "\r\n";
  std::cout << "Sending " << toSend << std::endl;
  send(receiver, toSend.c_str(), toSend.size(), 0);
}