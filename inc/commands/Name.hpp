/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Name.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 12:56:38 by eros-gir          #+#    #+#             */
/*   Updated: 2024/01/01 13:35:59 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAME_HPP
# define NAME_HPP

# include "../globals.hpp"

class Name : public ACommand
{
  public:
	Name(int const &clientFd, std::vector<std::string> const &vec, Server *server);
	~Name(void);
};

#endif