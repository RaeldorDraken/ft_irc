/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Messages.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:08:34 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/30 20:51:44 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Messages.hpp"

// ? Cannonical - This is a STATIC CLASS !!!
Messages::Messages(void){ return ;}
Messages::~Messages(void){ return ;}


// ? Public Message Specific Methods

// * WELCOME

std::string Messages::getUserWelcome(std::string client, std::string networkname, std::string nickname, std::string userhost)
{
  return (std::string("001 ") + client + " :Welcome to the " + networkname + " Network, " + nickname + "!" + userhost);
}

std::string Messages::getYourHost(std::string client, std::string servername)
{
  return (std::string("002 ") + client + " :Your host is " + servername + ", running version 1.0");
}

std::string Messages::getCreatedAt(std::string client, std::string datetime)
{
  return (std::string("003 ") + client + " :This server was created " + datetime);
}

std::string Messages::getMyInfo(std::string client, std::string servername)
{
  return (std::string("004 ") + client + " " + servername +  " 1.0 itkol");
}

// * INVITE

std::string Messages::getInviteReply(std::string client, std::string nickname, std::string channel)
{
  return (std::string("341 ") + client + " " + nickname + " " + channel);
}

