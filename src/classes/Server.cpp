/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:23:50 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/12 20:44:42 by rabril-h         ###   ########.fr       */
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

  std::map<int, Client *>::iterator it;
  std::map<int, Client *>::iterator it_end = this->_clients.end();

  for (it = this->_clients.begin(); it != it_end; it++)
      delete (it->second);
  this->_clients.clear();

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
		} // ? if error

    c = 0; // ? Reset counter everytime
    
    while (c < this->_openConnections)
    {
      if (this->_pollsfd[c].revents & POLLIN)
			{
				if (this->_pollsfd[c].fd == this->_serverfd.fd) // ? If the incoming connection has the same mapping that our server
        {
					//_newClient();	
          //std::cout << "new client needed with" << std::endl;

          // TODO we can abstract this into a function

          struct sockaddr_storage	remotaddr; // ? store the address information of the remote client (IPv4 / IPv6)
          socklen_t				addrlen; // ? store the size of the address structure.
          int newfd; // ? file descriptor for the new connection

          addrlen = sizeof remotaddr; // ? store the actual size

          /**
           * * int     accept(int, struct sockaddr * __restrict, socklen_t * __restrict)
           * @param int -> The fd for the listening socket
           * @param struct_sockaddr -> content of the remoteaddr stored in a struct
           * @param socklen_t -> size of the address structure, which will be updated by accept to indicate the actual size
           * 
           * ? The accept() method from socket library returns an int that we store as the newfd to get an unique id of the client we're about to create
          */
          newfd = accept(this->_serverfd.fd, (struct sockaddr*)&remotaddr, &addrlen); // ? Accept connection to listening server socket, 

          // ? If error on accepting a nbew client
          if (newfd == -1)
            std::cerr << "accept() error: " << std::strerror(errno) << std::endl;
          else // ? Exit accepting a new client
          {
                struct pollfd p; // ? New struct pollfd to store info for new Client
                this->_pollsfd.push_back(p); // ? Add the new client info to our existing _pollsfd vector
                this->_pollsfd[this->_openConnections].fd = newfd; // ? with the current count on the polls vector (first time will be 1) asign the new fd to the current poll structure
                this->_pollsfd[this->_openConnections].events = POLLIN; // ? Listen for incoming coneections on this client
                this->_clients.insert(std::pair<int, Client *>(newfd, new Client(newfd))); // ? Insert the new Client into our map using the id / fd created y accept() and a pointer to the actual Client class
                this->_openConnections++; // ? Increment our openConnection by 1
          }

        }
				else // ? request for communication
        {
					//_request(c);
          //std::cout << "request needed" << std::endl;


          // TODO we can abstract this into a function

          char buffer[1024]; // ? store the data received from the client

          /**
           * * ssize_t recv(int, void *, size_t, int) __DARWIN_ALIAS_C(recv);
           * @param int -> id /fd reading from
           * @param void -> where to store the info recieved
           * @param size_t -> maximum number of bytes to receive = 1024
           * @param int -> default behaviour
          */


          ssize_t bytesRead = recv(this->_pollsfd[c].fd, buffer, sizeof(buffer), 0);
          if (bytesRead == -1)
          {
              std::cerr << "recv() error: " << std::strerror(errno) << std::endl;
              break ;
              //return;
          }
          if (bytesRead == 0)
          {
              this->_removeClient(*_clients[this->_pollsfd[c].fd]);              
              break ;             
              //return;
          }
          std::string request(buffer, bytesRead); // ? Make a string out of the current request based on content and length of the request
          
          
          
          
          // TODO below start with implementing Client methods and getBufer() specially
          // ? concatenate any previously received but unprocessed data with the newly received data
          request = _clients[this->_pollsfd[c].fd]->getBuffer() + request; 
          std::vector<std::string> tokens = _tokenizeStr(request, "\r\n");

          // // ! snippet for printing tokens - remove on production          
          // this->_printVector(tokens, "Content is "); 

          std::cout << "tokens size is " << tokens.size() << std::endl;      

          if (tokens.size() == 0)
          {
              std::cout << "llego aqui" << std::endl;
              break ;
              //return ;
          }

          /**
           * ! EMPEZAR POR AQUI. PORQUE tokens.size -1 ???? preguntar joan
          */
          
          
          for (size_t j = 0; j < tokens.size() - 1; ++j)
          {
            //_runCmd(_parse(aux[j].c_str(), ' '), this->_pollsfd[i].fd);

            std::cout << "entro aqui" << std::endl;

            // ! temporary vector to get parsed command

            this->_printVector(this->_buildCommand(tokens[j].c_str(), ' '), " Parsed command is ");
          }
              
          // if (request.size() >= 2 && request.substr(request.size() - 2, request.size()) == "\r\n")
          // {
          //     _clients[this->_pollsfd[c].fd]->setBuffer("");
          //     //_runCmd(_parse(aux[aux.size() - 1].c_str(), ' '), this->_pollsfd[i].fd);    
          // }
          // else
          //     _clients[this->_pollsfd[c].fd]->setBuffer(tokens[tokens.size() - 1]);
          

        }
			}
      c++;
    }
  }  
}