/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:36:24 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/05 18:34:27 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Client.hpp"

Client::Client(int fd) : 
  _clientFd (fd), 
  _isRegistered (false),
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
  //close(this->_clientFd);
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

void Client::setRegistered(bool isRegistered)
{
  this->_isRegistered = isRegistered;
}

const std::string &Client::getName() const
{
  return (this->_name);
}

const std::string &Client::getNickName() const
{
  return (this->_nickname);
}

const std::string &Client::getRealName() const
{
  return (this->_realname);
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

void Client::sendMessage(const std::string &msg) const
{
    std::string message = msg + "\r\n";
    send(this->_clientFd, message.c_str(), message.size(), 0);
}

bool Client::getRegistered() const
{
  return (this->_isRegistered);

}