/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Who.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:59:37 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/27 18:25:07 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/commands/Who.hpp"

Who::Who(int const &clientFd, std::vector<std::string> const &vec, Server *server) : ACommand(clientFd, vec, server)
{
  std::cout << "Who command created with passed clientFd of " << clientFd << std::endl;

  Client		              *client = server->getClientByFd(clientFd);
  std::string             response;
  std::set<int>           my_clients;

  if (vec.size() < 2) // ? If not enough params 
  {
    client->sendMessage(Messages::printMoreParamsMsg(client->getNickName(), vec[0]));
    return ;
  }

  if (vec[1][0] != '&' && vec[1][0] != '#') // ? If channel name does not start with # or &
	{
		client->sendMessage(Messages::printBadChannelMask(client->getNickName()));
		return ;
	}

  int channelExists = server->searchChannel(vec[1]);

  if (channelExists == -1) // ? If channel does not exists just return an empty list 
  {
    response = ":127.0.0.1 315 #";
		response += vec[1];
		response += " :End of /WHO list.\r\n";
  }

  Channel *channel = server->getServerChannels()[channelExists]; // ? If channel exists get the channel



  //BUCLE AROUND ALL USES IN CHANNEL (OPERATORS AND NORMAL USERS)
	for(int i = 0; i < 2; i++)
	{
		if(i == 0)
			my_clients = channel->getChannelOperators();
		else
			my_clients = channel->getChannelMembers();

		for(std::set<int>::iterator it = my_clients.begin(); it != my_clients.end(); ++it)
		{
			response = ":127.0.0.1 352 #";
			response += vec[1];
			response += " ~";
			response += server->getClientByFd(*it)->getRealName();
			response += " B125170E.C0ED857D.425D16";
			response += "0E.IP * ";
			response += server->getClientByFd(*it)->getNickName();
			response += " H 0 ";
			response += server->getClientByFd(*it)->getName();
			response += "\r\n";
		  client->sendMessage(response);
		}
	}

  //END WHO MESAJE
	response = ":127.0.0.1 315 #";
	response += vec[1];
	response += " :End of /WHO list.\r\n";
	client->sendMessage(response);


  Utils::printVector(vec, " arg is ");
}

Who::~Who(void){return ;}