/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:49:42 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/16 19:38:36 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/Commands.hpp"

void Commands::JOIN(int const clientFd, std::vector<std::string> vec)
{
  std::cout << "Handling JOIN with client fd : [" << clientFd << "]" << " and the following commands :" << std::endl;


  for (size_t i = 0; i < vec.size(); i++)
    std::cout << "[" << i << "] : -> " << vec[i] << std::endl;
}

void Commands::USER(int const clientFd, std::vector<std::string> vec)
{
  std::cout << "Handling USER with client fd : [" << clientFd << "]" << " and the following commands :" << std::endl;

  for (size_t i = 0; i < vec.size(); i++)
    std::cout << "[" << i << "] : -> " << vec[i] << std::endl;
}

void Commands::NICK(int const clientFd, std::vector<std::string> vec)
{
  std::cout << "Handling NICK with client fd : [" << clientFd << "]" << " and the following commands :" << std::endl;

  for (size_t i = 0; i < vec.size(); i++)
    std::cout << "[" << i << "] : -> " << vec[i] << std::endl;
}

void Commands::PRIVMSG(int const clientFd, std::vector<std::string> vec)
{
  std::cout << "Handling PRIVMSG with client fd : [" << clientFd << "]" << " and the following commands :" << std::endl;

  for (size_t i = 0; i < vec.size(); i++)
    std::cout << "[" << i << "] : -> " << vec[i] << std::endl;
}

void Commands::INVITE(int const clientFd, std::vector<std::string> vec)
{
  std::cout << "Handling INVITE with client fd : [" << clientFd << "]" << " and the following commands :" << std::endl;

  for (size_t i = 0; i < vec.size(); i++)
    std::cout << "[" << i << "] : -> " << vec[i] << std::endl;
}

void Commands::TOPIC(int const clientFd, std::vector<std::string> vec)
{
  std::cout << "Handling TOPIC with client fd : [" << clientFd << "]" << " and the following commands :" << std::endl;

  for (size_t i = 0; i < vec.size(); i++)
    std::cout << "[" << i << "] : -> " << vec[i] << std::endl;
}

void Commands::NAMES(int const clientFd, std::vector<std::string> vec)
{
  std::cout << "Handling NAMES with client fd : [" << clientFd << "]" << " and the following commands :" << std::endl;

  for (size_t i = 0; i < vec.size(); i++)
    std::cout << "[" << i << "] : -> " << vec[i] << std::endl;
}

 void Commands::MODE(int const clientFd, std::vector<std::string> vec)
{
  std::cout << "Handling MODE with client fd : [" << clientFd << "]" << " and the following commands :" << std::endl;

  for (size_t i = 0; i < vec.size(); i++)
    std::cout << "[" << i << "] : -> " << vec[i] << std::endl;
}

void Commands::KICK(int const clientFd, std::vector<std::string> vec)
{
  std::cout << "Handling KICK with client fd : [" << clientFd << "]" << " and the following commands :" << std::endl;

  for (size_t i = 0; i < vec.size(); i++)
    std::cout << "[" << i << "] : -> " << vec[i] << std::endl;
}

void Commands::PING(int const clientFd, std::vector<std::string> vec)
{
  std::cout << "Handling PING with client fd : [" << clientFd << "]" << " and the following commands :" << std::endl;

  for (size_t i = 0; i < vec.size(); i++)
    std::cout << "[" << i << "] : -> " << vec[i] << std::endl;
}




  