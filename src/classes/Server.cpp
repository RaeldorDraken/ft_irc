/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:23:50 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/23 22:39:38 by eros-gir         ###   ########.fr       */
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


// ? Constructor
Server::Server(int port, const std::string password){
  
  std::cout << "El puerto es " << port << " y el password es " << password << std::endl;
  
  // TODO init member vars
  this->_openConnections = 1; 
  this->_port = port;
  this->_host = "127.0.0.1"; // ? This is the host for the server. We can change it to whatever we want
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

  // ? Set Server Creation datetime
  
  std::time_t currentTime = std::time(NULL);
  //std::time_t currentTime = std::time(NULL);
  char timeString[100];
  std::strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", std::localtime(&currentTime));

  this->_serverCreationTime = timeString;
  
  return ;
}


//  ? Destructor
Server::~Server(){
  std::cout << "\nServer destoyed" << std::endl;  
  
  // ? destroy channels
  this->_channels.clear();
  
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


void Server::removeClient(Client const &client)
{
  std::vector<Channel *> my_channels = this->getServerChannels();

   for (size_t i = 0; i < my_channels.size(); i++)
   {
      // std::cout << "[" << i << "] : Canal es -> " << my_channels[i]->getChannelName() << std::endl;

      if (my_channels[i]->clientIsMember(client.getNickName()))
      {
        // std::cout << "El canal " << my_channels[i]->getChannelName() << " tiene al cliente " << client.getNickName() << std::endl;
        
        if (my_channels[i]->clientIsOperator(client))
          my_channels[i]->removeOperator(client);        
        my_channels[i]->removeClient(client);        
      }    
   }

  std::cout << "Entro en eliminar cliente" << std::endl;

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


// ? Entry point
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

// ? Server Public Methods

int Server::getOpenConnections() const
{
  return (this->_openConnections);
}

std::string Server::getPassword() const
{
  return this->_password;
}

std::string Server::getHost() const
{
  return this->_host;
}

Client *Server::getClientByFd(int fd)
{  
  
  // std::map<int, Client *>::iterator it; // ? Set iterator
  // std::map<int, Client *>::iterator it_end = _clients.end(); // ? set end of iterator

  // std::cout << "All clients from getclientFd are :" << std::endl << std::endl;

  // for (it = _clients.begin(); it != it_end; it++)
  // {
  //   std::cout << "El cliente con fd " << it->first << " tiene un referencia en memoria: " << it->second << std::endl; 
  // }
  
  
  std::map<int, Client *>::iterator it; // ? Set iterator
  std::map<int, Client *>::iterator it_end = _clients.end(); // ? set end of iterator

  for (it = _clients.begin(); it != it_end; it++) {
    if (it->first == fd)
      return (it->first == fd) ? it->second : NULL; // ?  return found client based on fd passed to function     
  }
  return NULL;  // ? Return NULL if not found
  // return NULL;
}

Client *Server::getClientByNickName(std::string const nickname)
{
  std::map<int, Client *>::iterator it; // ? Set iterator
  std::map<int, Client *>::iterator it_end = _clients.end(); // ? set end of iterator

  for (it = _clients.begin(); it != it_end; it++)
  {
    //if ((*it).second->getNickName() == nickname)
    if (it->second->getNickName() == nickname)    
      return (it->second);
  }

  return NULL;
}

bool  Server::clientNickNameExists(std::string const nickname)
{
  std::map<int, Client *>::iterator it; // ? Set iterator
  std::map<int, Client *>::iterator it_end = _clients.end(); // ? set end of iterator

  for (it = _clients.begin(); it != it_end; it++) 
  {
    if (it->second->getNickName() == nickname)
      return true;
  }

  return false;

}

std::string Server::getServerCreationTime() const
{
  return (this->_serverCreationTime);
}
std::string Server::getCurrentTime()
{
  time_t t = std::time(0);
  struct tm *now = std::localtime(&t);
  std::string time(asctime(now));
  time.erase(--time.end());
  return time;
}

std::vector<Channel *> Server::getServerChannels() const
{
  return (this->_channels);
}

int Server::searchChannel(std::string const &channelName)
{
  size_t count = 0;

  while (count < this->_channels.size())
  {
    if (!channelName.compare(this->_channels[count]->getChannelName())) // ? if the comparision is 0 means we have a match
      return (count);
    count++;
  }
  return (-1); // ? We return -1 for a mismatch in searching for a channel in channels list
}


void Server::addClientToChannel(Client const &client, std::string const &channelName)
{
  std::cout << "Channel name to join is " << channelName << std::endl;

  std::cout << "Current channels are " << std::endl;

  for (size_t i = 0; i < this->_channels.size(); i++)
      std::cout << "[" << i << "] : Channel -> " << this->_channels[i] << " with name " << this->_channels[i]->getChannelName() << std::endl;
  
  //Client *client = this->_clients[clientFd];

  for (size_t i = 0; i < this->_channels.size(); i++)
  {
    if (channelName == this->_channels[i]->getChannelName())
    {
        _channels[i]->addNewClient(client);
        return;
    }
  } 

  this->_channels.push_back(new Channel(channelName, client, this)); // ! This line create indirect leaks on linux. Need to read the following
  // ! https://stackoverflow.com/questions/46573427/what-is-the-difference-between-a-direct-and-indirect-leak
  // ! https://stackoverflow.com/questions/22185896/what-is-the-cyclic-dependency-issue-with-shared-ptr
}