/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:08:16 by rabril-h          #+#    #+#             */
/*   Updated: 2024/01/10 21:44:38 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../inc/commands/Join.hpp"

Join::Join(int const &clientFd, std::vector<std::string> const &vec, Server *server) : ACommand(clientFd, vec, server)
{   

  Client		*client = server->getClientByFd(clientFd); 

	if (vec.size() < 2)
	{
		client->sendMessage(Messages::printMoreParamsMsg(client->getNickName(), vec[0]));
		return ;
	}

  size_t found = vec[1].find(',');
	if (found != std::string::npos)
	{
		//std::cout << "Joining more than one channel" << std::endl;
    
    std::vector<std::string> targets;
    std::stringstream ss(vec[1]);
    std::string token;
    while (std::getline(ss, token, ','))
        targets.push_back(token);    

    // for (size_t i = 0; i < targets.size(); i++)
    //   std::cout << "Channel " << i << " : to join is " << "-> " << targets[i] << std::endl;

    int pwdNum = 0;
		for (unsigned long i = 0; i < targets.size(); i++)
			pwdNum += this->_joinChannel(clientFd, vec, targets[i], pwdNum, server);
	}
	else
	{
		std::string	channelToJoin = vec[1];
		this->_joinChannel(clientFd, vec, channelToJoin, 0, server);
    //std::cout << "Join a single channel with " << channelToJoin << std::endl;
	}
		

  
  return ;
}

Join::~Join(void) {return ;}

std::vector<std::string> Join::_getPwds(std::vector<std::string> &vec)
{
	std::vector<std::string>	pwds;
	if (vec.size() > 2)
	{
		std::stringstream ss(vec[2]);
    std::string pwd;
    while (std::getline(ss, pwd, ','))
        pwds.push_back(pwd);			
		return pwds;
	}
	return pwds;
}

// TODO This seems to create a new client. Try to pass a reference to a pointer

bool Join::_joinChannel(int const clientFd, std::vector<std::string> const &vec, std::string &target, int pwdNum, Server *server)
{
	// (void) clientFd;
	(void)	vec;
	// // (void) target;
	(void) pwdNum;

	Client		*client = this->_server->getClientByFd(clientFd);

	if (target[0] != '&' && target[0] != '#')
	{
		client->sendMessage(Messages::printBadChannelMask(client->getNickName()));
		return false;
	}

	int channelExists = server->searchChannel(target);

	if (channelExists != -1) // ? If channel exists
	{
		std::cout << "Channel " << target << " exists" << std::endl;

		// Channel *channel = server->getServerChannels()[channelExists];

		// std::vector<std::string> myVec = vec;
		// std::vector<std::string> pwds = this->_getPwds(myVec);

		// TODO continue adding to existing channnels

	}
	// ? If channel does not exist

	server->addClientToChannel(clientFd, target);
	channelExists = server->searchChannel(target);

	Channel *channel = server->getServerChannels()[channelExists];
	if (channel->getChannelTopic() != "")
	{	
		client->sendMessage(Messages::getTopic(client->getNickName(), channel->getChannelName(), channel->getChannelTopic()));
		client->sendMessage(Messages::getTopicWhoWhen(client->getNickName(), channel->getChannelName(), channel->getChannelTopic(), server->getCurrentTime()));
	}
	else
		client->sendMessage(Messages::getNoTopic(client->getNickName(), channel->getChannelName()));

	std::string	joinmsg = client->getNickName() + "!" + client->getHostName() + " JOIN " + channel->getChannelName();

	channel->sendChannelMessage(NULL, joinmsg); // ! this thwrows a compiling error in linux...need to find a way to implement nullptr in c++98
	channel->sendNames(*client);
	if (channel->getKMode())
		return true;
	return false;

}