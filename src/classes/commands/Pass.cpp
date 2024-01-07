/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:50:32 by eros-gir          #+#    #+#             */
/*   Updated: 2024/01/07 20:30:27 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/commands/Pass.hpp"

Pass::Pass(int const &clientFd, std::vector<std::string> const &vec, Server *server) : ACommand(clientFd, vec, server)
{
	Client *client = this->_server->getClientByFd(this->_clientFd);

	if (this->_vec.size() != 2)
	{
		std::cout << "Error: Wrong number of arguments" << std::endl;
		return ;
	}
	else if (this->_vec[1] != _server->getPassword())
	{
		std::cout << "Error: Wrong password" << std::endl;
		client->sendMessage("Error: Wrong password\n");
		client->sendMessage("Closing connection\n");
		this->_server->removeClient(*client);
		return ;
	}
	else
	{
		std::cout << "Password correct" << std::endl;
		client->setRegistered(true);
		client->sendMessage("owo | Welcome to IRC chat! | uwu");
	}
	return ;
}

Pass::~Pass(void)
{
	return ;
}
