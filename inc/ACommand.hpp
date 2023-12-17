/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACommand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:05:22 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/17 18:27:16 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACOMMAND_HPP
# define ACOMMAND_HPP

# include <iostream>
# include <vector>

class ACommand {

  public:    
    virtual ~ACommand(void);

  private:
    
  
  protected:

    ACommand(int const &clientFd, std::vector<std::string> const &vec);
    
    int                         _clientFd;
    std::vector<std::string>    _vec;
    std::string                 _type;
};

#endif