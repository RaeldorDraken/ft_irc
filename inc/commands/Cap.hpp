/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cap.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:49:51 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/23 09:54:12 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAP_HPP
# define CAP_HPP

# include "../globals.hpp"

class Cap : public ACommand {
  public:
    Cap(int const &clientFd, std::vector<std::string> const &vec, Server *server);
    ~Cap(void);
};

#endif