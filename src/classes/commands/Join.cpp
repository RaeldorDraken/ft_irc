/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:08:16 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/07 19:45:59 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../inc/commands/Join.hpp"

Join::Join(int const &clientFd, std::vector<std::string> const &vec, Server *server) : ACommand(clientFd, vec, server)
{  
  // std::cout << server->getOpenConnections() << std::endl;

  Client		*client = server->getClientByFd(clientFd); 

	if (vec.size() < 2)
	{
		client->sendMessage(Messages::printMoreParamsMsg(client->getNickName(), vec[0]));
		return ;
	}

  
  return ;
}

Join::~Join(void) {return ;}