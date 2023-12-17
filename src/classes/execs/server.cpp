/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:07:51 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/17 19:41:01 by eros-gir         ###   ########.fr       */
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

  //std::cout << "input es " << input << std::endl;

  // TODO make case for PASS here so we can check if this is Client trying to get to server for the first time

  for (size_t i = 0; i < size; i++)
  {    
    
    if (input == commands[i])
    {
        if (input == "JOIN")
        {
         Join join = Join(clientFd, vec, this);  

        }
        else if (input == "USER")
        {
          std::cout << "handling USER on client [" << clientFd << "] with params :" << std::endl;

        }
        else if (input == "NICK")
        {
          std::cout << "handling NICK on client [" << clientFd << "] with params :" << std::endl;

        }
        else if (input == "PRIVMSG")
        {
          Privmsg privmsg = Privmsg(clientFd, vec, this);
          std::cout << "handling PRIVMSG on client [" << clientFd << "] with params :" << std::endl;

        }
        else if (input == "INVITE")
        {
          std::cout << "handling INVITEon client [" << clientFd << "] with params :" << std::endl;

        }
        else if (input == "TOPIC")
        {
          std::cout << "handling TOPIC on client [" << clientFd << "] with params :" << std::endl;

        }
        else if (input == "NAMES")
        {
          std::cout << "handling NAMES on client [" << clientFd << "] with params :" << std::endl;

        }
        else if (input == "MODE")
        {
          std::cout << "handling MODE on client [" << clientFd << "] with params :" << std::endl;

        }
        else if (input == "KICK")
        {
          std::cout << "handling KICK on client [" << clientFd << "] with params :" << std::endl;

        }
        else if (input == "PING")
        {

          std::cout << "handling PING on client [" << clientFd << "] with params :" << std::endl;
        }
        else
        {
          std::cout << input << " is an unhandled command" << std::endl;          
        }

        //this->_printVector(vec, "");
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