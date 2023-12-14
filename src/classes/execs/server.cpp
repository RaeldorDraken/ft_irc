/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:07:51 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/14 20:08:43 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/globals.hpp"

void  Server::_runCommand(std::vector<std::string> vec, int const clientFd)
{
  const std::string commands[10] = {"JOIN", "USER", "NICK", "PRIVMSG",
                        "INVITE", "TOPIC", "NAMES", "MODE", "KICK", "PING"};


  (void)clientFd;
  


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

    std::cout << "input es " << input << std::endl;

  for (size_t i = 0; i < size; i++)
  {    
    
    if (input == commands[i])
    {
        std::cout << "handling " << commands[i] << " which is " << input <<std::endl;
        return ;
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