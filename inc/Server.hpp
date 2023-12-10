/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:20:57 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/10 17:56:08 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include "globals.hpp"

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
    std::vector<pollfd>       _pollsfd;


    
    

    

};



#endif

 void                      handler(int signal);