/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:23:50 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/23 20:17:07 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Server.hpp"

bool _isServerRunning = true; 

void handler(int signal) {
    (void) signal; 
    _isServerRunning = false;

    

    // TODO this we need to also destroy anything the destructor will do as well
    // TODO Such as channels or anything else


    // ! We need to find a way to make this function part of the class as well as _isServerRunning at the same time it works with signals

    


} // ? handler function for exiting program via signal (keyboard) 



Server::Server(int port, const std::string password){
  
  std::cout << "El puerto es " << port << " y el password es " << password << std::endl;
  
  // TODO init member vars
  this->_openConnections = 1; 
  this->_port = port;
  this->_password = password;

  this->_pollsfd = std::vector<pollfd>(1); // ?  To be filled by struct pollfd as we add more connections to the pollfd struct
 
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

  
  // TODO we need to close all fd for all clients here

  std::map<int, Client *>::iterator it;
  std::map<int, Client *>::iterator it_end = this->_clients.end();

  for (it = this->_clients.begin(); it != it_end; it++)
  {
      close(it->first);
      delete (it->second);
      this->_openConnections--;

  }
  this->_clients.clear();  
  std::cout << "open connections are " << this->_openConnections << std::endl;
  return ;
}


void Server::_removeClient(Client const &client)
{
  // TODO remove Client from any channel!!

  size_t counter = 0;

  while (counter < _pollsfd.size())
  {
    if (client.getClientFd() == _pollsfd[counter].fd)
    {
        _pollsfd.erase(_pollsfd.begin() + counter);
        this->_openConnections--;
        break;
    }
    counter++;
  }

  int targetFd = client.getClientFd();
  close(targetFd);
  delete _clients[targetFd];
  _clients.erase(targetFd);  
}

void Server::run()
{
  int c; // ? Counter for _openConnections
  
  std::signal(SIGINT, handler); // ? Signal when killing server from keyboard
  while (_isServerRunning)
  {
    // ? number of file descriptors for which events have occurred
    // ? If poll is interrupted by a signal or encounters an error, poll_count may be set to -1
    int poll_count = poll(this->_pollsfd.data(), this->_openConnections, -1);
    if (poll_count == -1)
		{
      std::cerr << "poll() error: " << std::strerror(errno) << std::endl;
      break ;
		} // ? if error

    c = 0; // ? Reset counter everytime
    
    while (c < this->_openConnections)
    {
      if (this->_pollsfd[c].revents & POLLIN)
			{
				if (this->_pollsfd[c].fd == this->_serverfd.fd) // ? If the incoming connection has the same mapping that our server   
        {
					this->_createClient();
        }
				else // ? request for communication
        {
					this->_processClientRequest(c);
        }
			}
      c++;
    }
  }  

}

int Server::getOpenConnections() const
{
  return (this->_openConnections);
}