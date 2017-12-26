#ifndef CLIENT_H_
#define CLIENT_H_
#include "CircularBuffer.h"

class Client
{
public:
    Client() {};
    ~Client() {};
    int work();

public:
    CircularBuffer m_send_deque;
    CircularBuffer m_recv_deque;
    char m_recv_data[4096];
    int m_recv_len;
};

#endif