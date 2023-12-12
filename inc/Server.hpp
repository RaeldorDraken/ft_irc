/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:20:57 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/12 19:16:57 by rabril-h         ###   ########.fr       */
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

    void run();

  private:
    

    // ? struct pollfd {
    // ? int   fd;         // File descriptor to be monitored
    // ? short events;     // Events of interest (input, output, etc.)
    // ? short revents;    // Events that occurred (set by the system)
    // ? };



    // ? Member private vars    

    //bool                      _isServerRunning;
    std::string               _password; // ? our pass for the server
    int                       _port; // ? our port for the server
    struct pollfd             _serverfd; // ? description avobe
    int                       _openConnections; // ? open connections
    std::vector<pollfd>       _pollsfd; // ? Vector to store all connections via polls
    std::map<int, Client *>   _clients; // ? Map to store a int/fd AND Client * key/pair values

    
    // ? Private Member functions

    void                      _removeClient(Client const &client);


    // * Utils

    std::vector<std::string> _tokenizeStr(std::string const &str, std::string const &bounds); // ? Tokenizes a string based on delimeters such as \n\r to get a clean Client input message so it waits for a proper \r char
    
    void                     _printVector(std::vector<std::string> vec, std::string msg); // ? Prints a vector with on each position with a custom msg



                       

    
    

    

};



#endif

 void                      handler(int signal);
