/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACommand.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:08:22 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/30 18:58:22 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/ACommand.hpp"

ACommand::ACommand(int const &clientFd, std::vector<std::string> const &vec, Server *server) :
  _clientFd (clientFd),
  _vec (vec),
  _type (vec[0]),
  _server (server)
  {
    const std::string commands[10] = {"JOIN", "USER", "NICK", "PRIVMSG",
                        "INVITE", "TOPIC", "NAMES", "MODE", "KICK", "PING"};
    bool match = false;
    
    for (ssize_t i = 0; i < 10; i++)
    {
      if (vec[0] == commands[i])
        match = true; 
    }

    if (!match)
      return;    
    
    std::cout << "Created " << this->_type << " with client id of " << this->_clientFd << " and the following params :" << std::endl;

    for (size_t i = 0; i < vec.size(); i++)
      std::cout << "[" << i << "] : -> " << vec[i] << std::endl;
    
    return ;
  }

  ACommand::~ACommand(void)
  {
    return ;
  }