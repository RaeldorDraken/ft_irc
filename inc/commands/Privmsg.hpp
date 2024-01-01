/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Privmsg.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:33:42 by eros-gir          #+#    #+#             */
/*   Updated: 2024/01/01 13:35:02 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVMSG_HPP
# define PRIVMSG_HPP

#include "../globals.hpp"

class Privmsg : public ACommand {
  public:
		Privmsg(int const &clientFd, std::vector<std::string> const &vec, Server *server);
		~Privmsg(void);
		void sendMsg(int const &sender, int const &receiver, std::string const &msg);
};

#endif