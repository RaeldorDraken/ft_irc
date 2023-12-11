/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:32:23 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/11 18:53:39 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

# include "globals.hpp"

class Client {

  public:
    Client(int fd);
    ~Client();

    Client(Client const &inst);
    Client &operator=(Client const &inst);

  private:

    int             _clientFd;
    //std::string     _password;


};

#endif