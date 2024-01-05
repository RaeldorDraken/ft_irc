/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pass.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:49:59 by eros-gir          #+#    #+#             */
/*   Updated: 2024/01/01 13:35:03 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PASS_HPP
# define PASS_HPP

#include "../globals.hpp"

class Pass : public ACommand {
  public:
		Pass(int const &clientFd, std::vector<std::string> const &vec, Server *server);
		~Pass(void);
};

#endif