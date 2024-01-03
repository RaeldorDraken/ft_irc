/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:27:20 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/03 20:59:09 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include "globals.hpp"

class Server;

class Channel {

  public:
    Channel(std::string const &name, Client const &client, Server *server);
    ~Channel(void);


    // ? Class public methods

    void                addNewClient(Client const &client);

    void                addNewOperator(Client const &client);

    void                removeClient(Client const &client);
    void                removeOperator(Client const &client);


    // ? Getters & Setters

    const std::string   &getName() const;
    const std::string   &getPass() const;

  private:

    Server              *_server;
    std::string         _name;

    std::string         _channelPass; // ? The pass for thhe channel

    uint64_t             _limit; // ? member limits controlled by +l MODE
    std::string         _topic; // ? topic of channel controlled by +t MODE

    // ? We use set here becasue
    // ? 1 -> set do now allow duplicates
    // ? 2 -> elements are sorted based on their values

    // ? Cons We will need to iterate sets since indexing is not supported...

    std::set<int>   _members; // ? number of members in the channel
    std::set<int>   _invited; // ? number of invites in the channel set by +i MODE
    std::set<int>   _operators; // ? number of operators in the channel set by +o MODE

    // ? Boolean for MODES

    bool                _i; // ? bool for is the channel invite only?
    bool                _t; // ? bool for is the topic set?
    bool                _k; // ? bool for is the key channel set?
    bool                _o; // ? bool for has the channel operator?
    bool                _l; // ? bool for has the channel limit?


};


#endif