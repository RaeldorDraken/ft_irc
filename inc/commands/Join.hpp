/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Join.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:18:40 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/28 10:28:41 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JOIN_HPP
# define JOIN_HPP

#include "../globals.hpp"

class Join : public ACommand {
  public:
    Join(int const &clientFd, std::vector<std::string> const &vec, Server *server);
    ~Join(void);
};

#endif