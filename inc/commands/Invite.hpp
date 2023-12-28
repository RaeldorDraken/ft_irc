/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Invite.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:49:51 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/28 19:51:02 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INVITE_HPP
# define INVITE_HPP

# include "../globals.hpp"

class Invite : public ACommand {
  public:
    Invite(int const &clientFd, std::vector<std::string> const &vec, Server *server);
    ~Invite(void);
};

#endif