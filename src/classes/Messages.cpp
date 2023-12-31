/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Messages.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:08:34 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/31 19:20:16 by rabril-h         ###   ########.fr       */
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

std::string Messages::printNoSuchChannel(std::string client, std::string channel)
{
  return(std::string("403 ") + client + " " +  channel + " :No such channel");
}

std::string Messages::printNotOnChannel(std::string client, std::string channel)
{
  return(std::string("442 ") + client + " " +  channel + " :You're not on that channel");
}

std::string Messages::printUserAlreadyInChannel(std::string client, std::string nickname, std::string channel)
{
  return (std::string("443 ") + client + " " +  nickname + " " + channel + " :is already on channel");
}

std::string Messages::printMoreParamsMsg(std::string client, std::string command)
{
  return(std::string("461 ") + client + " " + command + std::string(" :Not enough parameters"));
}

std::string Messages::printUserNotOperator(std::string client, std::string channel)
{
  return (std::string("482 ") + client + " " +  channel + " :You're not channel operator");
}

// * PASS

std::string Messages::printAlreadyRegistered(std::string client)
{
  return (std::string("462 ") + client + " :You may not reregister");
}

std::string Messages::printPassMisMatch(std::string client)
{
  return (std::string("464 ") + client + " :Password incorrect");
}

// * KICK

std::string Messages::printUserNotInChannel(std::string client, std::string nickname, std::string channel)
{
  return (std::string("441 ") + client + " " + nickname + " " + channel + " :They aren't on that channel");
}

// * TOPIC

std::string Messages::getNoTopic(std::string client, std::string channel)
{
  return(std::string("331 ") + client + " " + channel + " :No topic is set");
}

std::string Messages::getTopic(std::string client, std::string channel, std::string topic)
{
  return (std::string("332 ") + client + " " + channel + " " + topic);
}

std::string Messages::getTopicWhoWhen(std::string client, std::string channel, std::string nickname, std::string timedate)
{
  return (std::string("333 ") + client + " " + channel + " " + nickname + " " + timedate);
}

// * JOIN

std::string Messages::printUserInTooManyChannels(std::string client, std::string channel)
{
  return (std::string("405 ") + client + " " + channel + " :You have joined too many channels");
}

std::string Messages::printBadChannelKey(std::string client, std::string channel)
{
  return (std::string("475 ") + client + " " + channel + " :Cannot join channel (+k)");
}

std::string Messages::printUserBannedFromChannel(std::string client, std::string channel)
{
  return (std::string("474 ") + client + channel + " :Cannot join channel (+b)");
}

std::string Messages::printChannelIsFull(std::string client, std::string channel)
{
  return (std::string("471 ") + client + " " + channel + " :Cannot join channel (+l)");
}

std::string Messages::printBadChannelMask(std::string client)
{
  return (std::string("476 ") + client + " :Bad Channel Mask");
}

std::string Messages::printNamesReply(std::string client, std::string channel, std::string prefix, std::string nickname)
{
  return (std::string("353 ") + client + " = " + channel + " :" + prefix  + nickname); // TODO This may be incorrect
}

std::string Messages::printEndOfNames(std::string client, std::string channel)
{
  return (std::string("366 ") + client + " " + channel + " :End of /NAMES list");
}

// * NICK

std::string Messages::printNoNickNameGiven(std::string client)
{
  return (std::string("431 ") + client + " :No nickname given");
}

std::string Messages::printNickHasBadChars(std::string client, std::string nickname)
{
  return (std::string("432 ") + client + " " +  nickname + " :Erroneus nickname");
}

std::string Messages::printNickNameInUse(std::string client, std::string nickname)
{
  return (std::string("433 ") + client + " " + nickname + " :Nickname is already in use");
}

std::string Messages::printNickCollision(std::string client, std::string nickname, std::string user, std::string hostname)
{
  return (std::string("436 ") + client + " " +  nickname + " :Nickname collision KILL from " + user + "@" + hostname);
}

// * PRIVMSG

std::string Messages::printNoSuchNick(std::string client, std::string nickname)
{
  return (std::string("401 ") + client + " " + nickname + " :No suck nick/channel");
}

std::string Messages::printCannotSendToChannel(std::string client, std::string channel)
{
  return (std::string("404 ") + client + " " + channel + " :Cannot send to channel");
}

std::string Messages::printNoRecipient(std::string client, std::string command)
{
  return (std::string("411 ") + client + " :No recipient given " + command);
}

std::string Messages::printNoTextToSend(std::string client)
{
  return (std::string("412 ") + client + " :No text to send");
}

std::string Messages::getUserAwayMessage(std::string client, std::string nickname, std::string message)
{
  return (std::string("301 ") + client + " " + nickname + " :" + message);
}