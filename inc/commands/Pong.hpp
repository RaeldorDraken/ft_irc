/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pong.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:41:11 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/28 18:50:10 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONG_HPP
# define PONG_HPP

# include "../globals.hpp"

class Pong : public ACommand {
  public:
    Pong(int const &clientFd, std::vector<std::string> const &vec, Server *server);
    ~Pong(void);
};

#endif