/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:20:57 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/17 19:14:52 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include "globals.hpp"

class Client;

class Server {

  public:
    Server(int port, const std::string password);
    ~Server();
    int getOpenConnections() const;

    void run();

  private:

    // ? struct pollfd {
    // ? int   fd;         // File descriptor to be monitored
    // ? short events;     // Events of interest (input, output, etc.)
    // ? short revents;    // Events that occurred (set by the system)
    // ? };



    // * Member private vars    

    //bool                      _isServerRunning;
    std::string               _password; // ? our pass for the server
    int                       _port; // ? our port for the server
    struct pollfd             _serverfd; // ? description avobe
    int                       _openConnections; // ? open connections
    std::vector<pollfd>       _pollsfd; // ? Vector to store all connections via polls
    std::map<int, Client *>   _clients; // ? Map to store a int/fd AND Client * key/pair values

    
    // * Private Member functions

    // ? comms classes/comms
    void                      _removeClient(Client const &client);
    void                      _createClient(void);
    void                      _processClientRequest(int c);
    
    
    // ? execs classes/execs
    void                      _runCommand(std::vector<std::string> vec, int const clientFd);

    // * Utils 

    std::vector<std::string> _tokenizeStr(std::string const &str, std::string const &bounds); // ? Tokenizes a string based on delimeters such as \n\r to get a clean Client input message so it waits for a proper \r char
    
    void                     _printVector(std::vector<std::string> vec, std::string msg); // ? Prints a vector with on each position with a custom msg

    std::vector<std::string> _buildCommand(std::string str, char c); // ? Build a command based on input and a char which acts as delimiter. We will use space " "



                       

    
    

    

};



#endif

 void                      handler(int signal);
