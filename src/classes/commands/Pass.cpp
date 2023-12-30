/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:50:32 by eros-gir          #+#    #+#             */
/*   Updated: 2023/12/30 12:31:13 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/commands/Pass.hpp"

Pass::Pass(int const &clientFd, std::vector<std::string> const &vec, Server *server) : ACommand(clientFd, vec, server)
{
	Client *client = this->_server->getClients()[this->_clientFd];

	(void) client;

	if (this->_vec.size() != 2)
	{
	std::cout << "Error: Wrong number of arguments" << std::endl;
	return ;
	}
	else if (this->_vec[1] != _server->getPassword())
	{
	std::cout << "Error: Wrong password" << std::endl;
	// TODO if password is incorrect, close connection
	return ;
	}
	else
	{
	std::cout << "Password correct" << std::endl;
	server->getClients()[this->_clientFd]->setRegistered(true);
	// TODO if password is correct, send welcome message
	std::vector<std::string> vec;
	std::ostringstream oss2;
  	oss2 << this->_clientFd;
	vec.push_back("PRIVMSG");
	vec.push_back(oss2.str());
	vec.push_back("Welcome to irc chat!");
	Privmsg *privmsg = new Privmsg(3, vec, this->_server);
	delete privmsg;
	}
	return ;
}

Pass::~Pass(void)
{
	return ;
}
