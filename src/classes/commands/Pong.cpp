/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pong.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:44:10 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/10 23:04:06 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../inc/commands/Pong.hpp"

Pong::Pong(int const &clientFd, std::vector<std::string> const &vec, Server *server) : ACommand(clientFd, vec, server)
{
  // ? get the right client executing the command
  Client *target = server->getClientByFd(clientFd);

  // ? Here our vec is a custom vector made of just the token send by PING command not the arguments passed via normal execution!!!

  if (vec.size() == 1 && target != NULL)
  // if (vec.size() == 1 && target != NULL)
    target->sendMessage("PONG with token " + vec[0]);  
}

Pong::~Pong(void) {return ;}