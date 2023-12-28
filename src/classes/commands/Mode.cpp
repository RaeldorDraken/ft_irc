/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mode.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:24:56 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/28 20:25:14 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/commands/Mode.hpp"

Mode::Mode(int const &clientFd, std::vector<std::string> const &vec, Server *server) : ACommand(clientFd, vec, server)
{
  (void)server;
  (void)vec;

  std::cout << "Mode command created with passed clientFd of " << clientFd << std::endl;
    
}

Mode::~Mode(void) {return ;}