/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Join.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:18:40 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/08 20:56:12 by rabril-h         ###   ########.fr       */
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
    bool                        _joinChannel(int const clientFd, std::vector<std::string> const &vec, std::string &target, int pwdNum, Server *server);

    std::vector<std::string>    _getPwds(std::vector<std::string> &vec);
};

#endif