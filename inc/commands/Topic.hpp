/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Topic.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:29:46 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/28 20:30:13 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOPIC_HPP
# define TOPIC_HPP

# include "../globals.hpp"

class Topic : public ACommand {
  public:
    Topic(int const &clientFd, std::vector<std::string> const &vec, Server *server);
    ~Topic(void);
};

#endif