/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cap.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:49:58 by eros-gir          #+#    #+#             */
/*   Updated: 2024/01/24 22:47:01 by eros-gir         ###   ########.fr       */
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
	  client->sendMessage(":127.0.0.1 CAP * LS :unrealircd.org/link-security=2 unrealircd.org/plaintext-policy=user=allow,oper=deny,server=deny unrealircd.org/history-storage=memory extended-join chghost cap-notify userhost-in-names multi-prefix away-notify sasl=EXTERNAL,PLAIN tls account-notify message-tags batch server-time account-tag echo-message labeled-response draft/chathistory\r\n");  
	  break;
	}
	case 1: { // REQ
	  client->sendMessage(":127.0.0.1 CAP * ACK extended-join chghost cap-notify userhost-in-names multi-prefix away-notify tls account-notify server-time account-tag echo-message \r\n");
	  break;
	}
	case 2: { // END
	  //client->sendMessage("CAP * END"); //creo que no hace flata
	  client->sendMessage(Messages::getUserWelcome(client->getName(), server->getHost(), client->getNickName(), client->getHostName()));
	  client->sendMessage(Messages::getYourHost(client->getNickName(), server->getHost()));
	  client->sendMessage(Messages::getCreatedAt(client->getNickName(), server->getServerCreationTime()));
	  client->sendMessage(Messages::getMyInfo(client->getNickName(), server->getHost()));
	  break;
	}
  }
}

Cap::~Cap(void)
{}
