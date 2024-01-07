/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:07:51 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/07 19:07:57 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/globals.hpp"

void  Server::_runCommand(std::vector<std::string> vec, int const clientFd)
{
  const std::string commands[10] = {"JOIN", "USER", "NICK", "PRIVMSG",
                        "INVITE", "TOPIC", "NAMES", "MODE", "KICK", "PING"};
  
  const std::string logincmds[4] = {"USER", "NICK", "PASS", "CAP"};

  size_t icomm = 0;
  
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

  if (_clients[clientFd]->getName() == ""
  && _clients[clientFd]->getNickName() == "" 
  && _clients[clientFd]->getRealName() == ""
  && !_clients[clientFd]->getRegistered())
  {
    while (icomm < logincmds->size())
    {
      if (input == logincmds[icomm])
          break;
      icomm++;
    }
    switch (icomm)
    {
      case 0: { // USER
        User name = User(clientFd, vec, this);  
      }  break;
      case 1: { // NICK
        Nick nick = Nick(clientFd, vec, this);
      } break;
      case 2: { // PASS
        Pass pass = Pass(clientFd, vec, this);
      } break;
      case 3: { // CAP
        std::cout << "handling CAP on client [" << clientFd << "] with params :" << std::endl;
        _clients[clientFd]->sendMessage("CAP * ACK :cap1 cap2 - END");
      } break;
      default: {
        std::cout << input << " is an unhandled command" << std::endl;
      } break;
    }
    std::cout << "Client [" << clientFd << "] has yet not been set up" << std::endl;
    return ;
  }

  icomm = 0;

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
        // std::cout << "handling USER on client [" << clientFd << "] with params :" << std::endl;
      User user = User(clientFd, vec, this);
    } break;
    case 2: { // NICK
        // std::cout << "handling NICK on client [" << clientFd << "] with params :" << std::endl;
        Nick nick = Nick(clientFd, vec, this);
    } break;
    case 3: { // PRIVMSG
        Privmsg privmsg = Privmsg(clientFd, vec, this);
        // std::cout << "handling PRIVMSG on client [" << clientFd << "] with params :" << std::endl;
    } break;
    case 4: { // INVITE
        // std::cout << "handling INVITE on client [" << clientFd << "] with params :" << std::endl;
        Invite invite = Invite(clientFd, vec, this);
    } break;
    case 5: { // TOPIC
        // std::cout << "handling TOPIC on client [" << clientFd << "] with params :" << std::endl;
        Topic topic = Topic(clientFd, vec, this);
    } break;
    case 6: { // NAMES
        // std::cout << "handling NAMES on client [" << clientFd << "] with params :" << std::endl;
        Names names = Names(clientFd, vec, this);
    } break;
    case 7: { // MODE
        // std::cout << "handling MODE on client [" << clientFd << "] with params :" << std::endl;
        Mode mode = Mode(clientFd, vec, this);
    } break;
    case 8: { // KICK
        // std::cout << "handling KICK on client [" << clientFd << "] with params :" << std::endl;
        Kick kick = Kick(clientFd, vec, this);
    } break;
    case 9: { // PING
        Ping ping = Ping(clientFd, vec, this);
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