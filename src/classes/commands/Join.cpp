/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:08:16 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/30 20:58:29 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../inc/commands/Join.hpp"

Join::Join(int const &clientFd, std::vector<std::string> const &vec, Server *server) : ACommand(clientFd, vec, server)
{
  
  
  
  std::cout << server->getOpenConnections() << std::endl;
  return ;
}

Join::~Join(void) {return ;}