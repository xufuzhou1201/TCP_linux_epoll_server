#ifndef MY_TCP_CIENT_H_
#define MY_TCP_CIENT_H_

#include "TCPClient.h"

class MyTCPClient : public TCPClient
{
public:
    MyTCPClient();
    ~MyTCPClient();

protected:
    virtual int work();
    virtual int disconnection();
};

#endif
