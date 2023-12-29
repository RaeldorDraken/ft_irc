/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:50:32 by eros-gir          #+#    #+#             */
/*   Updated: 2023/12/28 10:24:52 by eros-gir         ###   ########.fr       */
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
	// TODO if password is correct, set client as registered
	}
	return ;
}

Pass::~Pass(void)
{
	return ;
}
