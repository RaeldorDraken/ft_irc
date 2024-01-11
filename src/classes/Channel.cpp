/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:10:17 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/10 23:03:39 by eros-gir         ###   ########.fr       */
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
  _i = false; // ? inivite
  _t = false; // ? topic protection
  _k = false; // ? channel as key / password
  _o = false; // ? operator
  _l = false; // ? limit
  
  this->addNewClient(client); // ? Add the creator of the channel as first member of the channel
  
  this->addNewOperator(client); // ? insert the client creating the channel as first operator
  
  return ;
}

Channel::~Channel(void)
{
  // ? Do we need to empty all sets here ?

  // ? Remove members from channel
  std::set<int>::iterator it;
  std::set<int>::iterator it_end = _members.end();

  for (it = _members.begin(); it != it_end; it++)
  {
    _members.erase(it);
  }
    

  std::cout << "Channel " << this->getChannelName() << " destroyed" << std::endl;

  return ;
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


void Channel::sendChannelMessage(Client const &client, std::string const &message) const
{
  Client *target;

  std::set<int>::iterator it;
  std::set<int>::iterator it_end = this->_members.end();

  for (it = this->_members.begin(); it != it_end; it++)
  {
    target = this->_server->getClientByFd(*it);
    if (target->getNickName() != client.getNickName())
      target->sendMessage(message);
  }
}

bool Channel::clientIsMember(std::string const &nickname)
{
  Client *target;
  
  std::set<int>::iterator it;
  std::set<int>::iterator it_end = this->_members.end();

  for (it = this->_members.begin(); it != it_end; it++)
  {
    target = this->_server->getClientByFd(*it);
    if (target->getNickName() == nickname)
      return true;
  }
  return false;
}

void Channel::inviteClient(Client const &client)
{
  this->_invited.insert(client.getClientFd());
}

bool Channel::clientIsInvited(Client const &client) const
{
  int   target_fd = client.getClientFd();
  bool  isInvited = this->_invited.count(target_fd);

  return isInvited;
}

bool Channel::clientIsOperator(Client const &client) const
{
  int   target_fd = client.getClientFd();
  bool  isOperator = this->_operators.count(target_fd);

  return isOperator;
}

// ? Getters & Setters

const std::string &Channel::getChannelName() const
{
  return (this->_name);
}
const std::string &Channel::getChannelPass() const
{
  return (this->_channelPass);
}

void Channel::setChannelPass(std::string &key)
{
  this->_channelPass = key;
}

int Channel::getChannelLimit()
{
  return ((int)this->_limit);
}

void Channel::setChannelLimit(int limit)
{
  this->_limit = limit;
}

int Channel::getUserCount()
{
  return ((int)this->_members.size());
}

void Channel::setChannelTopic(std::string const &topic)
{
  this->_topic = topic;
}

const std::string Channel::getChannelTopic()
{
  return (this->_topic);
}

std::string Channel::getModes()
{
  std::string modes_list = "+";

  if (_i) modes_list.append("i");
  if (_t) modes_list.append("t");
  if (_k) modes_list.append("k");
  if (_o) modes_list.append("o");
  if (_l) modes_list.append("l");

  return modes_list; 
}
std::string Channel::getModeArguments()
{
  std::string args = "";

  if (_k && !_l) args.append(_channelPass);
  if (_l && !_k) args.append(intToString(_limit));
  if (_k && _l) args.append(_channelPass + " " + intToString(_limit));
  
  return args; 
}

void Channel::sendNames(Client const &client) const
{
  Client *my_client;

  client.sendMessage(Messages::printNamesReply(client.getNickName(), this->_name, "", "RoabhiDrakenBot"));
  std::set<int>::const_iterator it;
  for (it = this->_members.begin(); it != this->_members.end(); it++)
  {
    my_client = _server->getClientByFd(*it);
    std::string prefix = "";
    if (this->clientIsOperator(my_client->getClientFd()))
      prefix = "@";
    client.sendMessage(Messages::printNamesReply(client.getNickName(), this->_name, prefix, my_client->getNickName()));
  }
  client.sendMessage(Messages::printEndOfNames(client.getNickName(), this->_name));
}

// ? Getters and Setters for modes

bool Channel::getIMode()
{
  return (this->_i);
}

void Channel::setIMode(bool m)
{
  this->_i = m;
}

bool Channel::getTMode()
{
  return (this->_t);
}

void Channel::setTMode(bool m)
{
  this->_t = m;
}

bool Channel::getKMode()
{
  return (this->_k);
}

void Channel::setKMode(bool m)
{
  this->_k = m;
}

bool Channel::getOMode()
{
  return (this->_o);
}

void Channel::setOMode(bool m)
{
  this->_o = m;
}

bool Channel::getLMode()
{
  return (this->_l);
}

void Channel::setLMode(bool m)
{
  this->_l = m;
}

