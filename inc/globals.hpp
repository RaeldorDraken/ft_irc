/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:06:49 by rabril-h          #+#    #+#             */
/*   Updated: 2023/12/10 16:26:35 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBALS_HPP
# define GLOBALS_HPP

# include <iostream> // ? standar std::
# include <limits> // TODO may not be needed
# include <sstream> // ? string stream classes
# include <cstring> // ? legacy abstract base class used for bidirectional I/O
# include <csignal> // ? signals cpp
# include <unistd.h> // ? functionlities for write, etc, from C
# include <sys/socket.h> // ? main sockets functionality
# include <sys/types.h> // ? a collection of typedef symbols and structures
# include <netinet/in.h> // ? sockaddr_x functionality
# include <poll.h> // ? pollfd structure fd, events, revents
# include <string> // ? support for squences of chars
# include <vector> // ? vector container
# include <map> // ? map container
# include <set> // ? set container
# include <algorithm> // ? functions to be used on ranges of elements (all_of. search, fill, swap, sort, etc...)

# include "Server.hpp"

#endif