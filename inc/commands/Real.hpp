/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Real.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 12:56:38 by eros-gir          #+#    #+#             */
/*   Updated: 2024/01/01 13:35:56 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REAL_HPP
# define REAL_HPP

# include "../globals.hpp"

class Real : public ACommand
{
  public:
	Real(int const &clientFd, std::vector<std::string> const &vec, Server *server);
	~Real(void);
};

#endif