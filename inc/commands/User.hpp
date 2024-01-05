/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:31:14 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/28 20:31:52 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_HPP
# define USER_HPP

# include "../globals.hpp"

class User : public ACommand {
  public:
    User(int const &clientFd, std::vector<std::string> const &vec, Server *server);
    ~User(void);
};

#endif