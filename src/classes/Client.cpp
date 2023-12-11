/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:36:24 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/11 19:34:31 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Client.hpp"

Client::Client(int fd) : _clientFd (fd)
{
  std::cout << "New client with fd " << this->_clientFd << std::endl;
}

Client::~Client(void)
{
  std::cout << "Client " << this->_clientFd << " destroyed" << std::endl;
}