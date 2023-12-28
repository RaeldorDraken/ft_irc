/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACommand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:05:22 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/28 10:09:47 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACOMMAND_HPP
# define ACOMMAND_HPP

# include <iostream>
# include <vector>
# include "ACommand.hpp"
# include "Server.hpp"

class Server;

class ACommand {

  public:    
    virtual ~ACommand(void);

  private:
    
  
  protected:

    ACommand(int const &clientFd, std::vector<std::string> const &vec, Server *server);
    
    int                         _clientFd;
    std::vector<std::string>    _vec;
    std::string                 _type;
    Server                      *_server;
};

#endif