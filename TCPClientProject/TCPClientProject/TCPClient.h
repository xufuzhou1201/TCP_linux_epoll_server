#ifndef TCP_CLIENT_H_
#define TCP_CLIENT_H_

#include <pthread.h>


class TCPClient
{
public:
    TCPClient();
    ~TCPClient();
    int start(const char* ip, const unsigned short port);
    int stop();
    int send_data(const char* data, int len);
    int recv_data(char* data, int len);


protected:
    virtual int work();
    virtual int disconnection();

private:
    static void* thread_func(void* arg);
    int connect_to_server(const char* ip, const unsigned short port);

private:
    char m_server_ip[16];
    int m_socket;
    pthread_t m_thread_id;
    unsigned short m_port;
    bool m_sending;
    bool m_recving;
};

#endif
