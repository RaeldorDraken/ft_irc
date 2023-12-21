/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:07:51 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/21 10:03:03 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/globals.hpp"

void  Server::_runCommand(std::vector<std::string> vec, int const clientFd)
{
  const std::string commands[10] = {"JOIN", "USER", "NICK", "PRIVMSG",
                        "INVITE", "TOPIC", "NAMES", "MODE", "KICK", "PING"};

  size_t icomm = 0;

  (void)clientFd;
  
	// void	(Server::*f[10])(int const client_fd, cmd &info) = 
	// {&Server::_join, &Server::_user, &Server::_nick, &Server::_privmsg,
	//  &Server::_invite, &Server::_topic, &Server::_names,
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

  // TODO make case for PASS here so we can check if this is Client trying to get to server for the first time

  while (icomm < size)
  {
    if (input == commands[icomm])
        break;
    icomm++;
  }
  switch (icomm)
  {
    case 0: { // JOIN
      Join join = Join(clientFd, vec, this);  
    }  break;
    case 1: { // USER
        std::cout << "handling USER on client [" << clientFd << "] with params :" << std::endl;
    } break;
    case 2: { // NICK
        std::cout << "handling NICK on client [" << clientFd << "] with params :" << std::endl;
    } break;
    case 3: { // PRIVMSG
        Privmsg privmsg = Privmsg(clientFd, vec, this);
        std::cout << "handling PRIVMSG on client [" << clientFd << "] with params :" << std::endl;
    } break;
    case 4: { // INVITE
        std::cout << "handling INVITE on client [" << clientFd << "] with params :" << std::endl;
    } break;
    case 5: { // TOPIC
        std::cout << "handling TOPIC on client [" << clientFd << "] with params :" << std::endl;
    } break;
    case 6: { // NAMES
        std::cout << "handling NAMES on client [" << clientFd << "] with params :" << std::endl;
    } break;
    case 7: { // MODE
        std::cout << "handling MODE on client [" << clientFd << "] with params :" << std::endl;
    } break;
    case 8: { // KICK
        std::cout << "handling KICK on client [" << clientFd << "] with params :" << std::endl;
    } break;
    case 9: { // PING
        std::cout << "handling PING on client [" << clientFd << "] with params :" << std::endl;
    } break;
    default: {
        std::cout << input << " is an unhandled command" << std::endl;
    } break;
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