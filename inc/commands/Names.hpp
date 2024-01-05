/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Names.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:26:40 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/28 20:27:02 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAMES_HPP
# define NAMES_HPP

# include "../globals.hpp"

class Names : public ACommand {
  public:
    Names(int const &clientFd, std::vector<std::string> const &vec, Server *server);
    ~Names(void);
};

#endif