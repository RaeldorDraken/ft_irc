/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ping.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:27:26 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/28 18:50:21 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PING_HPP
# define PING_HPP

# include "../globals.hpp"

class Pong;

class Ping : public ACommand {
  public:
    Ping(int const &clientFd, std::vector<std::string> const &vec, Server *server);
    ~Ping(void);
};

#endif