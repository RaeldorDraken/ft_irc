/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Messages.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:04:19 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/30 20:50:18 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef MESSAGES_HPP
# define MESSAGES_HPP

# include "globals.hpp"

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
    static std::string     getInviteReply(std::string client, std::string nickname, std::string channel);

  private :

    // ? This is a Static Class. We do not instantiate it. We only use its methods

    Messages(void);
    ~Messages(void);
    
    
};

#endif