/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:20:57 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/07 20:28:18 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include "globals.hpp"

class Client;
class ACommand;

class Server {

  public:
    Server(int port, const std::string password);
    ~Server();
    int                     getOpenConnections() const;

    // ? This function is needed from Pong command
    Client *                getClientByFd(int fd); // ? New function. Now we only return the client based on passed fd
    std::string             getServerCreationTime() const;

    std::string             getPassword() const;
    void                    removeClient(Client const &client);



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

    // std::vector<ACommand *>    _commands; // ? vector to include any commands including servers

    std::string               _serverCreationTime;

    
    // * Private Member functions

    // ? comms classes/comms  
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
 int                       ft_stoi(std::string str);
