/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:54:06 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/23 18:35:58 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PART_HPP
# define PART_HPP

# include "../globals.hpp"

class Part : public ACommand {
  public:
    Part(int const &clientFd, std::vector<std::string> const &vec, Server *server);
    ~Part(void);

  private:

    void                    _partFromChannel(int const clientFd, std::string const &channel_name, std::string reason, Server *server);
};

#endif