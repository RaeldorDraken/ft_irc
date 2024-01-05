/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:10:17 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/03 20:59:15 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Channel.hpp"

Channel::Channel(std::string const &name, Client const &client, Server *server)  
{
  (void) _limit;
  
  _server = server;
  _name =  name;
  _topic = "";  
  _members = std::set<int>();
  _invited = std::set<int>();
  _operators = std::set<int>();
  _i = false;
  _t = false;
  _k = false;
  _o = false;
  _l = false;
  
  this->addNewClient(client); // ? Add the creator of the channel as first member of the channel
  
  this->addNewOperator(client); // ? insert the client creating the channel as first operator
  
  return ;
}

Channel::~Channel(void)
{
  // ? Do we need to empty all sets here ?
}

void  Channel::addNewClient(Client const &client)
{
  _members.insert(client.getClientFd());
}

void  Channel::addNewOperator(Client const &client)
{
  _operators.insert(client.getClientFd());
}

void Channel::removeClient(Client const &client)
{
  int target = client.getClientFd();
  
  _members.erase(target);
  _operators.erase(target);
}

void Channel::removeOperator(Client const &client)
{
  _operators.erase(client.getClientFd());
}

// ? Getters & Setters

const std::string &Channel::getName() const
{
  return (this->_name);
}
const std::string &Channel::getPass() const
{
  return (this->_channelPass);
}