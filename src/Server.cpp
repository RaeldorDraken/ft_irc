/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:23:50 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/10 17:59:26 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Server.hpp"

bool _isServerRunning = true; 

void handler(int signal) {
    (void) signal; 
    _isServerRunning = false;

    // TODO this we need to also destroy anything the destructor will do as well
    // TODO Such as channels or anything else

} // ? handler function for exiting program via signal (keyboard)

Server::Server(int port, const std::string password){
  
  std::cout << "El puerto es " << port << " y el password es " << password << std::endl;
  
  // TODO init member vars
  this->_openConnections = 1; 
  this->_port = port;
  this->_password = password;

  this->_pollsfd = std::vector<pollfd>(1); // ?  To be filled by struct pollfd as we add more connections to the pollfd struct
 
  // this->_isServerRunning = false; // ? exit program

  /* 
  ? ======================================
  ? TCP sockets creation
  ? ======================================  
  */

  int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (serverSocket == -1) {
      std::cerr << "socket() error: " << std::strerror(errno) << std::endl;
  }

  sockaddr_in serverAddr;
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(port);
  serverAddr.sin_addr.s_addr = INADDR_ANY;

  if (bind(serverSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) == -1) {
      std::cerr << "bind() error: " << std::strerror(errno) << std::endl;
  }

  if (listen(serverSocket, 5) == -1) {
      std::cerr << "listen() error: " << std::strerror(errno) << std::endl;
  }

  _serverfd.fd = serverSocket; // ? Asign the serverSocket to the _serverfd pollfd structure so we can listen for events on that fd / id

  _pollsfd[0].fd = serverSocket; // ? Assing first slot of vector to the server. This will increase as we add more connections
  _pollsfd[0].events = POLLIN; // ? Listen for incoming requests
  
  return ;
}

Server::~Server(){
  std::cout << "\nServer destoyed" << std::endl;
  return ;
}



void Server::run()
{
  std::signal(SIGINT, handler); // ? Signal when killing server from keyboard
  while (_isServerRunning)
  {
    // std::cout << "looping" << std::endl;
  }

  
  
}