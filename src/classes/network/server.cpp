/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:21:08 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/07 20:28:40 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/globals.hpp"

void  Server::_createClient(void)
{
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

void Server::_processClientRequest(int c)
{
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
        return;
    }
    if (bytesRead == 0)
    {
        this->removeClient(*_clients[this->_pollsfd[c].fd]);              
        return;
    }
    std::string request(buffer, bytesRead); // ? Make a string out of the current request based on content and length of the request    
    
    // ? concatenate any previously received but unprocessed data with the newly received data. This first tokenization is useful when recieving more than one line at the same time such as when a client joins the irc or a channel. Otherwise it will be printed all in the same line.
    request = _clients[this->_pollsfd[c].fd]->getBuffer() + request;   

    std::vector<std::string> tokens = _tokenizeStr(request, "\r\n");

    // ! snippet for printing tokens - remove on production          
    //this->_printVector(tokens, "Content of tokenized request is ");           

    if (tokens.size() == 0)
        return ;

    //std::cout << "tokens size for line is " << tokens.size() << std::endl;

    // ? Here we tokenize again for every line
    for (size_t j = 0; j < tokens.size(); ++j) 
    {
      std::vector<std::string> myCommands = this->_buildCommand(tokens[j].c_str(), ' ');

      // ! temporary vector to get parsed command

      // std::cout << " Token -> { " << j << " }" << std::endl;

      // this->_printVector(myCommands, " Parsed command is ");
      
      this->_runCommand(myCommands, this->_pollsfd[c].fd);

     
    }


    // TODO create code to add to buffer in case commands are not properly formated

    if (request.size() >= 2 && request.substr(request.size() - 2, request.size()) == "\r\n")
    {
      std::cout << "Handling cleaning buffer " << std::endl;
    }
    else
    {
      std::cout << "Handling setting buffer" << std::endl;
    }

        
    // if (request.size() >= 2 && request.substr(request.size() - 2, request.size()) == "\r\n")
    // {
    //     _clients[this->_pollsfd[c].fd]->setBuffer("");
    //      std::vector<std::string> myCommands = this->_buildCommand(tokens[c].c_str(), ' ');
    //     this->_runCommand(myCommands, this->_pollsfd[c].fd);    
    // }
    // else
    //     _clients[this->_pollsfd[c].fd]->setBuffer(tokens[tokens.size()]);
}