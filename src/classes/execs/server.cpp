/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:07:51 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/13 21:08:12 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/globals.hpp"

void  Server::_runCommand(std::vector<std::string> vec, int const clientFd)
{
  const std::string commands[10] = {"JOIN", "USER", "NICK", "PRIVMSG",
                        "INVITE", "TOPIC", "NAMES", "MODE", "KICK", "PING"};


  (void)clientFd;
  
  // std::string cmds[10] = {"JOIN", "USER", "NICK", "PRIVMSG",\
	//  "INVITE", "TOPIC", "NAMES", "MODE", "KICK", "PING"};

  


	// void	(Server::*f[10])(int const client_fd, cmd &info) = \
	// {&Server::_join, &Server::_user, &Server::_nick, &Server::_privmsg,\
	//  &Server::_invite, &Server::_topic, &Server::_names,\
	//  &Server::_mode, &Server::_kick, &Server::_ping};

  // ? remove empty
  for (std::vector<std::string>::iterator it = vec.begin(); it != vec.end(); )
	{
		std::string value = *it;
    
    if (value.empty())
		    it = vec.erase(it);
		else
	    ++it;
	}

  size_t counter = 0;
  size_t size = sizeof(commands) / sizeof(commands[0]);

  std::string input = vec[0];

  std::cout << "input es " << vec[0] << std::endl;

  while (counter < size)
  {    
    if (input == "JOIN") {
        std::cout << "Handling JOIN case" << std::endl;
        break;
    } else if (input == "USER") {
        std::cout << "Handling USER case" << std::endl;
        break;
    } else if (input == "NICK") {
        std::cout << "Handling NICK case" << std::endl;
        break;
    } else if (input == "PRIVMSG") {
        std::cout << "Handling PRIVMSG case" << std::endl;
        break;
    } else if (input == "INVITE") {
        std::cout << "Handling INVITE case" << std::endl;
        break;
    } else if (input == "TOPIC") {
        std::cout << "Handling TOPIC case" << std::endl;
        break;
    } else if (input == "NAMES") {
        std::cout << "Handling NAMES case" << std::endl;
        break;
    } else if (input == "MODE") {
        std::cout << "Handling MODE case" << std::endl;
        break;
    } else if (input == "KICK") {
        std::cout << "Handling KICK case" << std::endl;
        break;
    } else if (input == "PING") {
        std::cout << "Handling PING case" << std::endl;
        break;
    } else {
        std::cout << "Unhanlded command !!! " << std::endl;
        break ;
    }
    counter++;
  }

  


	// if (checkInit(_clients[client_fd], c))
	// {
	// 	if (c.args[0] == "PASS")
	// 	{
	// 		_pass(client_fd, c);
	// 		return ;
	// 	}
	// }
	// else
	// {
	// 	for (int i = 0; i < 10; i++)
	// 		if (c.args[0] == cmds[i])
	// 		{
	// 			(this->*f[i])(client_fd, c);
	// 			return ;
	// 		}
	// }
}