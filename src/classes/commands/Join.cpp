/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:08:16 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/17 19:28:01 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../inc/commands/Join.hpp"

Join::Join(int const &clientFd, std::vector<std::string> const &vec, Server *server) : ACommand(clientFd, vec, server)
{
  std::cout << server->getOpenConnections() << std::endl;
  return ;
}

Join::~Join(void) {return ;}