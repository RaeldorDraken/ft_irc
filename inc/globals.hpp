/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:06:49 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/03 20:22:47 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBALS_HPP
# define GLOBALS_HPP
# pragma once

# include <iostream> // ? standar std::
# include <limits> // TODO may not be needed
# include <ctime> // ? Standard C datetime library
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

# include <cerrno> // ? Linux specific 

# include "Server.hpp"
# include "Client.hpp"
# include "Channel.hpp"
# include "ACommand.hpp"
# include "Messages.hpp"
# include "commands/Join.hpp"
# include "commands/Privmsg.hpp"
# include "commands/Ping.hpp"
# include "commands/Invite.hpp"
# include "commands/Kick.hpp"
# include "commands/Mode.hpp"
# include "commands/Names.hpp"
# include "commands/Nick.hpp"
# include "commands/Topic.hpp"
# include "commands/User.hpp"
# include "commands/Pass.hpp"
# include "commands/Name.hpp"
# include "commands/Real.hpp"
# include "commands/Nick.hpp"



// TODO pong command is a bit different and weird to handle with ACommand. Maybe we should integrate it directly on the Server as method

# include "commands/Pong.hpp"

#endif
