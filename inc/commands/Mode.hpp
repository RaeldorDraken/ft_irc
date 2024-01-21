/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mode.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:23:55 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/19 19:43:41 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODE_HPP
# define MODE_HPP

# include "../globals.hpp"

class Mode : public ACommand {
  public:
    Mode(int const &clientFd, std::vector<std::string> const &vec, Server *server);
    ~Mode(void);

  private:

    void                                    _addMode(std::map<std::string, std::string> &modes, std::vector<std::string> &vec, int const clientFd, Server *server);
    void                                    _removeMode(std::map<std::string, std::string> &modes, std::vector<std::string> &vec, int const clientFd, Server *server);
    bool                                    _enoughArgsForMode(std::vector<std::string> &vec, Client *client, std::string &modes, char c);
    std::string                             _getKeyFromString(std::map<std::string, std::string> &modes, std::vector<std::string> &vec, char c, Client *client);

    std::map<std::string, std::string>      _formatMode(std::string &input);
};

#endif