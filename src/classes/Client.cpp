/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:36:24 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/10 21:44:19 by rabril-h         ###   ########.fr       */
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
  std::cout << "New client with fd " << this->getClientFd() << std::endl;
}

Client::~Client(void)
{
  std::cout << "Client " << this->_clientFd << " destroyed" << std::endl;
  //close(this->_clientFd);
}

Client::Client(const Client &inst)
{
  *this = inst;
} // ? Copy constructor

Client &Client::operator=(Client const &inst)
{
  this->_clientFd = inst._clientFd;
  this->_isRegistered = inst._isRegistered;
  this->_name = inst._name;
  this->_realname = inst._realname;
  this->_nickname = inst._nickname;
  this->_buffer = inst._buffer;
  return (*this);
} // ? = operator assigment. We need to copy ALL private vars 

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