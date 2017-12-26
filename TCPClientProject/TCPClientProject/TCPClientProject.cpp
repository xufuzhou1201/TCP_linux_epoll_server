#include <stdio.h>
#include <unistd.h>
#include "MyTCPClient.h"
#include "log.h"


///https://github.com/lihaitao8233/TCP_linux_epoll_server
///https://github.com/lihaitao8233/TCPServer_windows_iocp
///makeǰ��debug.mak�ļ������LIBRARY_DIRS����ΪlibTCPClient.a���õ�·��
int main(int argc, char* argv[])
{
    open_log_file("/home/lht/client", "client", 1);
    set_log_level(LOG_ERROR_LEVEL | LOG_NORMAL_LEVEL | LOG_DEBUG_LEVEL);

    MyTCPClient my_tcp_client;
    my_tcp_client.start("192.168.96.145", 5150);

    pause();
    my_tcp_client.stop();

    return 0;
}

