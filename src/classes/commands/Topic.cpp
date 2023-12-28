/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Topic.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:30:23 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/28 20:30:39 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/commands/Topic.hpp"

Topic::Topic(int const &clientFd, std::vector<std::string> const &vec, Server *server) : ACommand(clientFd, vec, server)
{
  (void)server;
  (void)vec;

  std::cout << "Topic command created with passed clientFd of " << clientFd << std::endl;
    
}

Topic::~Topic(void) {return ;}