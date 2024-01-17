/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:05:31 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/17 18:43:56 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/Utils.hpp"

Utils::Utils(void) {return ;}
Utils::~Utils(void) {return ;}

// ? Utils to parse strings
std::vector<std::string> Utils::tokenizeByStr(std::string const &str, std::string const &bounds)
{
  std::vector<std::string> myTokens; // ? Tokens to return

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

std::vector<std::string> Utils::tokenizeByChar(std::string str, char c)
{
  std::vector<std::string> command;

  std::stringstream ss(str);
  std::string token;
  while (std::getline(ss, token, c))
      command.push_back(token);
  return command;

}

int Utils::getCharPosFromString(std::string &str, char c)
{
  int i = 0;

	while (str[i])
	{
		if (str[i] == c)
			return i;
		i++;
	}
	return i;
}

bool Utils::isCharInString(std::string &str, char c)
{
  if (str == "")
		return false;
	for (unsigned long i = 0; i < str.length(); i++)
		if (str[i] == c)
			return true;
	return false;
}

void Utils::deleteCharFromString(std::string &str, char c)
{
  for (std::string::iterator it = str.begin(); it != str.end(); )
  {
    if (*it == c) {
        it = str.erase(it);
    } else {
        ++it;
    }
	}
}

// ? General utilities

void Utils::printVector(std::vector<std::string> vec, std::string msg)
{
  for (size_t i = 0; i < vec.size(); i++)
      std::cout << "[" << i << "] : " << msg << " -> " << vec[i] << std::endl;
}

int Utils::ft_stoi(std::string str)
{
  int num = 0;
  int sign = 1;
  int i = 0;

  if (str[i] == '-')
  {
    sign = -1;
    i++;
  }
  while (str[i] != '\0')
  {
    num = num * 10 + str[i] - '0';
    i++;
  }
  return (sign * num);
}

std::string Utils::intToString(int number) {
    std::ostringstream oss;
    oss << number;
    return oss.str();
}
