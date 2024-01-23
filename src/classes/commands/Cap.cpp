/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cap.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:49:58 by eros-gir          #+#    #+#             */
/*   Updated: 2024/01/23 10:44:16 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/commands/Cap.hpp"


Cap::Cap(int const &clientFd, std::vector<std::string> const &vec, Server *server) : ACommand(clientFd, vec, server)
{
  std::cout << "Cap command created with passed clientFd of " << clientFd << std::endl;

  Client		*client = server->getClientByFd(clientFd);
  const std::string commands[3] = {"LS", "REQ", "END"};
  size_t icomm = 0;

  while(icomm < 3)
  {
	if (vec[1] == commands[icomm])
	  break;
	icomm++;
  }
  switch(icomm)
  {
	case 0: { // LS
	  client->sendMessage("CAP * LS :multi-prefix");  
	  break;
	}
	case 1: { // REQ
	  client->sendMessage("CAP * ACK :multi-prefix");
	  break;
	}
	case 2: { // END
	  client->sendMessage("CAP * END");
	  client->sendMessage(Messages::getUserWelcome(client->getName(), "127.0.0.1", client->getNickName(), client->getHostName()));
	  client->sendMessage(Messages::getYourHost(client->getNickName(), "127.0.0.1"));
	  client->sendMessage(Messages::getCreatedAt(client->getNickName(), server->getServerCreationTime()));
	  client->sendMessage(Messages::getMyInfo(client->getNickName(), "127.0.0.1"));
	  break;
	}
  }
}

Cap::~Cap(void)
{}
