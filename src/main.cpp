/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:05:49 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/09 20:28:31 by rabril-h         ###   ########.fr       */
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

  Server server(atoi(argv[1]), argv[2]);

  try {
    
    server.run();
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  

  return (0);

}