/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:23:50 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/09 20:42:35 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Server.hpp"

Server::Server(int port, const std::string password){
  
  std::cout << "El puerto es " << port << " y el password es " << password << std::endl;
  
  // TODO init member vars
  this->_isServerRunning = true;  
  this->_port = port;
  this->_password = password;

  // this->_isServerRunning = false; // ? exit program
  
  return ;
}

Server::~Server(){
  std::cout << "Server destoyed" << std::endl;
  return ;
}

void Server::run()
{
    
  while (this->_isServerRunning)
  {
    // std::cout << "looping" << std::endl;
  }

  
  
}