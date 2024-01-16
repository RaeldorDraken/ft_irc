/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Kick.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:54:06 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/16 19:33:36 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KICK_HPP
# define KICK_HPP

# include "../globals.hpp"

class Kick : public ACommand {
  public:
    Kick(int const &clientFd, std::vector<std::string> const &vec, Server *server);
    ~Kick(void);

  private:

    Client *           _kickUser(int const clientFd, std::string const &target, Channel *channel, Server *server);
};

#endif