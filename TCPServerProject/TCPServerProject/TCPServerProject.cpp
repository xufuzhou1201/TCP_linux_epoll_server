#include <stdio.h>
#include <unistd.h>
#include "TCPServer.h"
#include "log.h"


///https://github.com/lihaitao8233/TCP_linux_epoll_server
///https://github.com/lihaitao8233/TCPServer_windows_iocp
///makeǰ��debug.mak�ļ������LIBRARY_DIRS����ΪlibTCPServer.a���õ�·��
///epollʵ�ֵĸ߲�����������
///������ֻ��Ҫ��Client���Client.cpp�������ÿ���ͻ��˵�ҵ���߼�������Ҫ��������ϸ��
int main(int argc, char *argv[])
{
    open_log_file("/home/lht/server", "server", 0);
    set_log_level(LOG_ERROR_LEVEL | LOG_NORMAL_LEVEL | LOG_DEBUG_LEVEL);

    TCPServer tcp_server;
    tcp_server.start(NULL, 5150, 5);

    pause();
    tcp_server.stop();
    return 0;
}