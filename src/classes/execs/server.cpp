/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:07:51 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/16 19:37:06 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/globals.hpp"

void  Server::_runCommand(std::vector<std::string> vec, int const clientFd)
{
  const std::string commands[10] = {"JOIN", "USER", "NICK", "PRIVMSG",
                        "INVITE", "TOPIC", "NAMES", "MODE", "KICK", "PING"};

  


  //(void)clientFd;
  


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
            it++;
    }
    
  std::string input = vec[0];
  size_t size = sizeof(commands) / sizeof(commands[0]);

  //std::cout << "input es " << input << std::endl;

  for (size_t i = 0; i < size; i++)
  {    
    
    if (input == commands[i])
    {
        if (input == "JOIN")
          Commands::JOIN(clientFd, vec);
        else if (input == "USER")
          Commands::USER(clientFd, vec);
        else if (input == "NICK")
          Commands::NICK(clientFd, vec);
        else if (input == "INVITE")
          Commands::INVITE(clientFd, vec);
        else if (input == "TOPIC")
          Commands::TOPIC(clientFd, vec);
        else if (input == "NAMES")
          Commands::NAMES(clientFd, vec);
        else if (input == "MODE")
          Commands::MODE(clientFd, vec);
        else if (input == "KICK")
          Commands::KICK(clientFd, vec);
        else if (input == "PING")
          Commands::PING(clientFd, vec);
        else
          std::cout << input << " is an unhandled command" << std::endl;
    }

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