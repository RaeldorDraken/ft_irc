/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Kick.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:54:06 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/28 19:54:40 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KICK_HPP
# define KICK_HPP

# include "../globals.hpp"

class Kick : public ACommand {
  public:
    Kick(int const &clientFd, std::vector<std::string> const &vec, Server *server);
    ~Kick(void);
};

#endif