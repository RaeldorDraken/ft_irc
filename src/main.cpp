/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:05:49 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/09 17:11:59 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/globals.hpp"

int main(int argc, char **argv)
{
  if (argc != 3)
  {
    std::cout << "Usage: ./ircserv <port> <password>" << std::endl;
    return (-1);
  }

  std::cout << "El puerto es " << argv[1] << " y el password es " << argv[2] << std::endl;

  return (0);

}