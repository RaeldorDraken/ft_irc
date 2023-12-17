/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACommand.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:08:22 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/17 19:53:51 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/ACommand.hpp"

ACommand::ACommand(int const &clientFd, std::vector<std::string> const &vec, Server *server) :
  _clientFd (clientFd),
  _vec (vec),
  _type (vec[0]),
  _server (server)
  {
    std::cout << "Created " << this->_type << " with client id of " << this->_clientFd << " and the following params :" << std::endl;

    for (size_t i = 0; i < vec.size(); i++)
      std::cout << "[" << i << "] : -> " << vec[i] << std::endl;
    
    return ;
  }

  ACommand::~ACommand(void)
  {
    return ;
  }