/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pass.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:49:59 by eros-gir          #+#    #+#             */
/*   Updated: 2023/12/28 10:07:58 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PASS_HPP
# define PASS_HPP

# include "../../inc/ACommand.hpp"

class Pass : public ACommand
{
  public:
	Pass(int const &clientFd, std::vector<std::string> const &vec, Server *server);
	~Pass(void);
	void runCmd();
  private:
	Pass(void);
	Pass(Pass const &src);
	Pass &operator=(Pass const &rhs);
};

#endif