/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Privmsg.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:33:28 by eros-gir          #+#    #+#             */
/*   Updated: 2024/01/01 13:34:55 by eros-gir         ###   ########.fr       */
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
		// ! stoi is not in c++98 need to change the function to use another type of conversion
		sendMsg(clientFd, ft_stoi(vec[1]), msg);
	}
  return ;
}

Privmsg::~Privmsg(void) {return ;}

void Privmsg::sendMsg(int const &sender, int const &receiver, std::string const &msg)
{
  // ! to_string is not in c++98, changed the function to use ostringstream
  std::ostringstream oss1;
  oss1 << sender;
  std::ostringstream oss2;
  oss2 << receiver;
  std::string msgtype = " PRIVMSG ";
  if (sender == receiver)
	return ;
  else if (sender == 3)
	msgtype = " NOTICE ";
  std::string toSend = ":" + oss1.str() + msgtype + oss2.str() + " :" + msg + "\r\n";
  std::cout << "Sending " << toSend << std::endl;
  send(receiver, toSend.c_str(), toSend.size(), 0);
}