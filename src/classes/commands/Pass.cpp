/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:50:32 by eros-gir          #+#    #+#             */
/*   Updated: 2024/01/27 17:33:49 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/commands/Pass.hpp"

Pass::Pass(int const &clientFd, std::vector<std::string> const &vec, Server *server) : ACommand(clientFd, vec, server)
{
	Client *client = server->getClientByFd(clientFd);	

	if (this->_vec.size() != 2)
	{
		std::cout << "Error: Wrong number of arguments" << std::endl;
		return ;
	}
	else if (this->_vec[1] != server->getPassword())
	{
		std::cout << "Error: Wrong password" << std::endl;
		// TODO if password is incorrect, close connection
		return ;
	}
	else
	{
		std::cout << "Password correct" << std::endl;
		client->setRegistered(true);
		// TODO if password is correct, send welcome message
		//client->sendMessage("Welcome to irc chat!");		
		client = NULL;
	}
	return ;
}

Pass::~Pass(void)
{
	return ;
}
