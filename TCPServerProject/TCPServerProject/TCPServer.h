#ifndef TCP_SERVER_H_
#define TCP_SERVER_H_
#include <pthread.h>
#include <vector>
#include "Client.h"


class TCPServer
{
public:
    typedef struct _ServerThreadPool
    {
        pthread_t thread_id;
        int fd[2];
        int epoll_fd;

    } ServerThreadPool;

    typedef struct _ThreadArg
    {
        int thread_num;
        void* p_this;

    } ThreadArg;

public:
    TCPServer();
    ~TCPServer();

    //如果IP等于NULL，表示INADDR_ANY
    int start(const char* ip, const unsigned short port, unsigned int thread_cnt);
    int stop();

private:
    int read_from_client(int fd, Client& client);
    int write_to_client(int fd, Client& client);
    int create_thread_pool(unsigned int thread_cnt);
    int get_listen_socket(const char* ip, const unsigned short port, const int backlog = 100);
    static void* client_thread(void*);
    static void* accept_thread(void*);

    ServerThreadPool* m_thread_pool;
    unsigned int m_thread_cnt;
    pthread_t m_accept_thread_id;
    int m_listen_socket;
    int m_epoll_fd;
    std::vector<unsigned char> m_client_cnt;
    bool m_run_flag;
};

#endif