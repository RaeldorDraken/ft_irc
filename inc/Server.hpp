/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:20:57 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/09 20:34:10 by rabril-h         ###   ########.fr       */
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

    bool            _isServerRunning;
    std::string     _password;
    int             _port;

    

};

#endif