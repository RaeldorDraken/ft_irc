/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Privmsg.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:33:42 by eros-gir          #+#    #+#             */
/*   Updated: 2024/01/16 18:53:16 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVMSG_HPP
# define PRIVMSG_HPP

#include "../globals.hpp"

class Privmsg : public ACommand {
  public:
		Privmsg(int const &clientFd, std::vector<std::string> const &vec, Server *server);
		~Privmsg(void);
		//void sendMsg(int const &sender, int const &receiver, std::string const &msg);

	private:

		void 										_sendMsgToUser(int const clientFd, std::vector<std::string> &vec, std::string const &target, Server *server);

		void 										_sendMessageToChannel(int const clientFd, std::vector<std::string> &vec, std::string const &target, Server *server);

};

#endif