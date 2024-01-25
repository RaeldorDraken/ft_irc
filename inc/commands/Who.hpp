/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Who.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:59:07 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/24 19:59:28 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHO_HPP
# define WHO_HPP

# include "../globals.hpp"

class Who : public ACommand {
  public:
    Who(int const &clientFd, std::vector<std::string> const &vec, Server *server);
    ~Who(void);
};

#endif