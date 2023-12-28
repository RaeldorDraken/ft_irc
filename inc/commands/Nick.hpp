/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Nick.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:27:56 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/28 20:28:21 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NICK_HPP
# define NICK_HPP

# include "../globals.hpp"

class Nick : public ACommand {
  public:
    Nick(int const &clientFd, std::vector<std::string> const &vec, Server *server);
    ~Nick(void);
};

#endif