/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:20:57 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/27 16:06:11 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include "globals.hpp"

class Client;
class Channel;
class ACommand;

class Server {

  public:
    Server(int port, const std::string password);
    ~Server();
    int                     getOpenConnections() const;

    Client *                getClientByFd(int fd); // ? New function. Now we only return the client based on passed fd

    Client *                getClientByNickName(std::string const nickname); // ? New function. This returns a client based on a string referring to their nickname

    std::string             getServerCreationTime() const;
    std::string             getCurrentTime();
    std::string             getHost() const;
    std::string             getHostName() const;
    std::string             getPassword() const;
    void                    removeClient(Client const &client);

    std::vector<Channel *>  getServerChannels() const;

    void                    addClientToChannel(Client const &client, std::string const &channelName);

    int                     searchChannel(std::string const &channelName);    

    bool                    clientNickNameExists(std::string const nickname);

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
    std::string               _host; // ? our host for the server
    std::string               _hostname; // ? our hostname -> "RoabhiDrakenBot"
    int                       _port; // ? our port for the server
    struct pollfd             _serverfd; // ? description avobe
    int                       _openConnections; // ? open connections
    std::vector<pollfd>       _pollsfd; // ? Vector to store all connections via polls
    std::map<int, Client *>   _clients; // ? Map to store a int/fd AND Client * key/pair values

    std::vector<Channel *>    _channels; // ? vector to include any channels 

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
 std::string               intToString(int number);
