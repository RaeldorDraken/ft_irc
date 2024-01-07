/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Join.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:18:40 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/07 20:08:52 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JOIN_HPP
# define JOIN_HPP

#include "../globals.hpp"

class Join : public ACommand {
  public:
    Join(int const &clientFd, std::vector<std::string> const &vec, Server *server);
    ~Join(void);

  private:
    //_joinChannel(int const client_fd, std::vector<std::string> &vec, std::string &target, int pwdNum);
};

#endif