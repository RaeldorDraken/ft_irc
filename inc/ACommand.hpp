/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACommand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:05:22 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/17 20:44:30 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACOMMAND_HPP
# define ACOMMAND_HPP

# include <iostream>
# include <vector>
# include "ACommand.hpp"

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