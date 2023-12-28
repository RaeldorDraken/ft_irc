/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Names.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:27:10 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/28 20:27:28 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/commands/Names.hpp"

Names::Names(int const &clientFd, std::vector<std::string> const &vec, Server *server) : ACommand(clientFd, vec, server)
{
  (void)server;
  (void)vec;

  std::cout << "Names command created with passed clientFd of " << clientFd << std::endl;
    
}

Names::~Names(void) {return ;}