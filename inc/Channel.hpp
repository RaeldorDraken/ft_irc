/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:27:20 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/08 19:15:50 by rabril-h         ###   ########.fr       */
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

    void                sendChannelMessage(Client const &client, std::string const &message) const;

    bool                clientIsMember(std::string const &nickname);
    void                inviteClient(Client const &client);
    bool                clientIsInvited(Client const &client) const;
    bool                clientIsOperator(Client const &client) const;

    std::string         getModes();
    std::string         getModeArguments();

    // ? Getters & Setters

    const std::string   &getChannelName() const;
    const std::string   &getChannelPass() const;

    bool                getIMode();
    void                setIMode(bool m);
    bool                getTMode();
    void                setTMode(bool m);
    bool                getKMode();
    void                setKMode(bool m);
    bool                getOMode();
    void                setOMode(bool m);
    bool                getLMode();
    void                setLMode(bool m);


    void                setChannelLimit(int limit);
    void                setChannelPass(std::string &key);

    int                 getUserCount();
    int                 getChannelLimit();

    void                setChannelTopic(std::string const &topic);
    const std::string   getChannelTopic();

    void                sendNames(Client const &client) const;


  private:

    Server              *_server;
    std::string         _name;

    std::string         _channelPass; // ? The pass for thhe channel

    uint64_t            _limit; // ? member limits controlled by +l MODE
    std::string         _topic; // ? topic of channel controlled by +t MODE

    // ? We use set here becasue
    // ? 1 -> set do now allow duplicates
    // ? 2 -> elements are sorted based on their values

    // ? Cons We will need to iterate sets since indexing is not supported...

    std::set<int>   _members; // ? fds of members in the channel
    std::set<int>   _invited; // ? fds of invites in the channel set by +i MODE
    std::set<int>   _operators; // ? fds of operators in the channel set by +o MODE

    // ? Boolean for MODES

    bool                _i; // ? bool for is the channel invite only?
    bool                _t; // ? bool for is the topic set?
    bool                _k; // ? bool for is the key channel set?
    bool                _o; // ? bool for has the channel operator?
    bool                _l; // ? bool for has the channel limit?


};


#endif