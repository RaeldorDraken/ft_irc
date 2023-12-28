/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mode.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:23:55 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/28 20:24:28 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODE_HPP
# define MODE_HPP

# include "../globals.hpp"

class Mode : public ACommand {
  public:
    Mode(int const &clientFd, std::vector<std::string> const &vec, Server *server);
    ~Mode(void);
};

#endif