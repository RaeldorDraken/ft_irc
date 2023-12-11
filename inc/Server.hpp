/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:20:57 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/11 19:31:40 by rabril-h         ###   ########.fr       */
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
    
    // ? Member private vars

    //bool                      _isServerRunning;
    std::string              _password;
    int                       _port;
    struct pollfd             _serverfd;
    int                       _openConnections;
    // ? struct pollfd {
    // ? int   fd;         // File descriptor to be monitored
    // ? short events;     // Events of interest (input, output, etc.)
    // ? short revents;    // Events that occurred (set by the system)
    // ? };
    std::vector<pollfd>       _pollsfd; // ? Vector to store all connections via polls

    std::map<int, Client *>   _clients; // ? Map to store a int/fd AND Client * key/pair values



    protected :

    void                      _destroyClients(void);                     

    
    

    

};



#endif

 void                      handler(int signal);
