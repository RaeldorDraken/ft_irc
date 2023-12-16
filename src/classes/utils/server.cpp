/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:00:29 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/16 17:52:17 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/globals.hpp"

std::vector<std::string> Server::_tokenizeStr(std::string const &str, std::string const &bounds)
{
  std::vector<std::string> myTokens; // ? Tokens to return

  // std::string::size_type startPos = 0; // ? start pos
  // std::string::size_type foundPos = 0; // ? end pos

  //  while (startPos < str.length()) {
  //     // ? position of the first character in the input that is NOT th characters incleded in bouds
  //     startPos = str.find_first_not_of(bounds, foundPos); 
  //     if (startPos == std::string::npos) {
  //         break;
  //     } // ? no more characters in the input string that are not in the set of characters specified by bounds. Break here


  //     // ? If there are more characters to process. 
      
  //     //? Returns the position of the first character that matches any character in bounds. If no such character is found, foundPos is set to std::string::npos
  //     foundPos = str.find_first_of(bounds, startPos);


  //     // ? If there are no more characters in the input string that are in the set of characters specified by bounds the remaining substring from startPos to the end of the string is added to the vector myTokens
  //     if (foundPos == std::string::npos) {
  //         myTokens.push_back(str.substr(startPos));
  //         break;
  //     } else {

  //         // ? If there are more characters to process, a substring from startPos to foundPos - 1 is added to the vector myTokens. This substring represents the token found in the input string.
  //         myTokens.push_back(str.substr(startPos, foundPos - startPos));
  //     }
  //   } // ? loop through input

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

