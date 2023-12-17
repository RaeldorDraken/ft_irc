/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Join.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:18:40 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/17 18:21:39 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JOIN_HPP
# define JOIN_HPP

#include "../globals.hpp"

class Join : public ACommand {
  public:
    Join(int const &clientFd, std::vector<std::string> const &vec);
    ~Join(void);
};

#endif