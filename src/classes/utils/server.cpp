/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:00:29 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/13 19:32:36 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/globals.hpp"

std::vector<std::string> Server::_tokenizeStr(std::string const &str, std::string const &bounds)
{
  std::vector<std::string> myTokens;

  std::string::size_type startPos = 0;
  std::string::size_type foundPos;

    while ((foundPos = str.find_first_of(bounds, startPos)) != std::string::npos) {
        // ? Extract the token between startPos and foundPos
        std::string token = str.substr(startPos, foundPos - startPos);
        // ? Skip consecutive delimiters
        if (!token.empty()) {
            myTokens.push_back(token);
        }
        startPos = foundPos + 1; // ? Move to the next character after the delimiter
    }

    // ? Extract the last token after the last delimiter
    std::string lastToken = str.substr(startPos);
    if (!lastToken.empty()) {
        myTokens.push_back(lastToken);
    }
    return myTokens;   
}

std::vector<std::string> Server::_buildCommand(std::string str, char c)
{
  std::vector<std::string> command;

  std::stringstream ss(str);
  std::string token;
  while (std::getline(ss, token, c))
      command.push_back(token);

  return command;

}

void Server::_printVector(std::vector<std::string> vec, std::string msg)
{
  for (size_t i = 0; i < vec.size(); i++)
      std::cout << "[" << i << "] : " << msg << " -> " << vec[i] << std::endl;
}

