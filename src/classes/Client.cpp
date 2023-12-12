/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:36:24 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/12 19:20:40 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Client.hpp"

Client::Client(int fd) : 
  _clientFd (fd), 
  _name (""),
  _realname (""),
  _nickname (""),
  _buffer ("")

{
  std::cout << "New client with fd " << this->_clientFd << std::endl;
}

Client::~Client(void)
{
  std::cout << "Client " << this->_clientFd << " destroyed" << std::endl;
}

void Client::setName(std::string name)
{
  this->_name = name; 
}

void Client::setRealName(std::string realname)
{
  this->_realname = realname; 
}

void Client::setNickName(std::string nickname)
{
  this->_nickname = nickname; 
}

void Client::setHostName(std::string hostname)
{
  this->_hostname = hostname; 
}

void Client::setBuffer(std::string buff)
{
  this->_buffer = buff; 
}

const std::string &Client::getName() const
{
  return (this->_name);
}

const std::string &Client::getNickName() const
{
  return (this->_nickname);
}

const std::string &Client::getHostName() const
{
  return (this->_hostname);
}

const std::string &Client::getBuffer() const
{
  return (this->_buffer);
}

int Client::getClientFd() const
{
  return (this->_clientFd);
}
    
