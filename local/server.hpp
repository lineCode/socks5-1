/*******************************************************************************
 *
 * socks5
 * A C++11 socks5 proxy server based on Libevent 
 *
 * Copyright 2018 Senlin Zhan. All rights reserved.
 *
 ******************************************************************************/

#ifndef SERVER_H
#define SERVER_H

#include "address.hpp"
#include "base.hpp"

#include <memory>
#include <string>

class Server
{
public:
    Server(const Address &address, const Address &remoteAddress,
           const std::string &key);
    
    // disable the copy operations    
    Server(const Server &) = delete;
    Server &operator=(const Server &) = delete;

    // create tunnel between the client and the proxy server
    void createTunnel(int inConnFd);
    
    // run the event loop
    void run();
    
private:
    std::shared_ptr<ServerBase>   base_;
    Address                       remoteAddress_;  // address of the proxy server    
    std::string                   key_;            // secret key
};

#endif /* SERVER_H */
