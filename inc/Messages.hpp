/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Messages.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:04:19 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/24 19:44:35 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef MESSAGES_HPP
# define MESSAGES_HPP

# include "globals.hpp"

// ? get<NameOfFunction> = RPL_CODE
// ? print<NameOfFunction> = ERR_CODE

class Messages {
  public :
  
    // * WELCOME CODES
    
    // ? CODE 01
    static std::string      getUserWelcome(std::string client, std::string networkname, std::string nickname, std::string userhost);

    // ? CODE 02
    static std::string      getYourHost(std::string client, std::string servername);

    // ? CODE 03 
    static std::string      getCreatedAt(std::string client, std::string datetime);

    // ? CODE 04 
    static std::string      getMyInfo(std::string client, std::string servername);


    // * INVITE CODES

    // ? CODE 341
    static std::string      getInviteReply(std::string client, std::string nickname, std::string channel);

     // ? CODE 403

    static std::string      printNoSuchChannel(std::string client, std::string channel); // ? channel does not exists

    // ? CODE 442

    static std::string      printNotOnChannel(std::string client, std::string channel);

    // ? CODE 443

    static std::string      printUserAlreadyInChannel(std::string client, std::string nickname, std::string channel);

    // ? CODE 461

    static std::string      printMoreParamsMsg(std::string client, std::string command);

    // ? CODE 482

    static std::string      printUserNotOperator(std::string client, std::string channel);

    // * PASS CODES

    // ? CODE 461 already set

    // ? CODE 462

    static std::string      printAlreadyRegistered(std::string client);

    // ? CODE 464

    static std::string      printPassMisMatch(std::string client);

    // * KICK CODES

    // ? CODE 403,442,461,482 Already set

    // ? CODE 441

    static std::string      printUserNotInChannel(std::string client, std::string nickname, std::string channel);

    // * TOPIC CODES

    // ? CODE 403,442,461,482 Already set

    // ? CODE 331

    static std::string      getNoTopic(std::string client, std::string channel);

    // ? CODE 332

    static std::string      getTopic(std::string client, std::string channel, std::string topic);

    // ? CODE 333

    static std::string      getTopicWhoWhen(std::string client, std::string channel, std::string nickname, std::string timedate);

    // * JOIN CODES

    // ? CODE 461,403,473,332,333 Already set

    // ? CODE 405

    static std::string      printUserInTooManyChannels(std::string client, std::string channel);

    // ? CODE 475

    static std::string      printBadChannelKey(std::string client, std::string channel);

    // ? CODE 474

    static std::string      printUserBannedFromChannel(std::string client, std::string channel);

    // ? CODE 471

    static std::string      printChannelIsFull(std::string client, std::string channel); // ? This is for 

    // ? CODE 476

    static std::string      printBadChannelMask(std::string client); // ? The channel does not have a valid name but may exist

    // ? CODE 353

    static std::string      printNamesReply(std::string client, std::string channel, std::string prefix, std::string nickname); // ? https://modern.ircdocs.horse/#rplnamreply-353

    // ? CODE 366

    static std::string      printEndOfNames(std::string client, std::string channel);

    // * NICK CODES

    // ? CODE 431

    static std::string      printNoNickNameGiven(std::string client);

    // ? CODE 432

    static std::string      printNickHasBadChars(std::string client, std::string nickname);

    // ? CODE 433

    static std::string      printNickNameInUse(std::string client, std::string nickname);

    // ? CODE 436

    static std::string      printNickCollision(std::string client, std::string nickname, std::string user, std::string hostname); // ? Nick exists in another server

    // * PRIVMSG CODES

    // ? CODE 407,412,414 Already set

    // ? CODE 401

    static std::string      printNoSuchNick(std::string client, std::string nickname);

    // ? CODE 404

    static std::string      printCannotSendToChannel(std::string client, std::string channel);

    // ? CODE 411

    static std::string      printNoRecipient(std::string client, std::string command); // ? Message without target

    // ? CODE 412

    static std::string      printNoTextToSend(std::string client);

    // ? CODE 301

    static std::string      getUserAwayMessage(std::string client, std::string nickname, std::string message);

    // * MODE CODES

     // ? CODE 368

    static std::string      getEndOfBanList(std::string channel); // ? end of ban list when recieving MODES b


    // ? CODE 472

    static std::string      getUnknownModeChar(std::string client, std::string modechar); // ? channel modes not recognized by server
    
    
    // ? CODE 473

    static std::string      getInviteOnlyChannel(std::string client, std::string channel);

    // ? CODE 501

    static std::string      getUnknownModeFlag(std::string client); // ? user mode flag not recognized by server

    // ? CODE 324

    static std::string      getChannelModeOptions(std::string client, std::string channel, std::string modes, std::string args);
    
    static std::string      printInvalidModeParam(std::string client, std::string target, std::string mode, std::string arg, std::string info);
 

  private :

    // ? This is a Static Class. We do not instantiate it. We only use its methods

    Messages(void);
    ~Messages(void);
    
    
};

#endif