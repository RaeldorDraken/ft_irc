/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:08:16 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/07 20:31:26 by rabril-h         ###   ########.fr       */
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

  size_t found = vec[1].find(',');
	if (found != std::string::npos)
	{
		std::cout << "Joining more than one channel" << std::endl;
    
    std::vector<std::string> targets;
    std::stringstream ss(vec[1]);
    std::string token;
    while (std::getline(ss, token, ','))
        targets.push_back(token);    

    for (size_t i = 0; i < targets.size(); i++)
      std::cout << "Channel " << i << " : to join is " << "-> " << targets[i] << std::endl;

    // int pwdNum = 0;
		// for (unsigned long i = 0; i < targets.size(); i++)
		// {	
		// 	pwdNum += _joinChannel(clientFd, vec, targets[i], pwdNum);
		// }
	}
	else
		// _joinChannel(clientFd, vec, vec[1], 0);
    std::cout << "Join a single channel" << std::endl;

  
  return ;
}

Join::~Join(void) {return ;}