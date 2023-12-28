/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:32:23 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/28 09:29:57 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

# include "globals.hpp"

class Server;

class Client {

  public:
    Client(int fd);
    ~Client();

    Client(Client const &inst);
    Client &operator=(Client const &inst);

    void                setName(std::string name);
    void                setRealName(std::string realname);
    void                setNickName(std::string nickname);
    void                setHostName(std::string hostname);
    void                setBuffer(std::string buff); 
    void                setRegistered(bool isRegistered);
    
    
    const std::string   &getName(void) const;
    const std::string   &getNickName(void) const;
    const std::string   &getHostName(void) const;
    const std::string   &getBuffer(void) const;
    int                 getClientFd() const;
    bool                getRegistered() const;

  private:

    int                   _clientFd;
    bool                  _isRegistered;
    std::string           _name;
    std::string           _realname;
    std::string           _nickname;
    std::string           _hostname;
    std::string           _buffer;

    //std::string     _password;

   



};

#endif