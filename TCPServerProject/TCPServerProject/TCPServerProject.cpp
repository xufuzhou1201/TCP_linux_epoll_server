#include <stdio.h>
#include <unistd.h>
#include "TCPServer.h"
#include "log.h"


///https://github.com/lihaitao8233/TCP_linux_epoll_server
///https://github.com/lihaitao8233/TCPServer_windows_iocp
///make前把debug.mak文件里面的LIBRARY_DIRS设置为libTCPServer.a放置的路径
///epoll实现的高并发网络服务端
///调用者只需要在Client类里（Client.cpp）添加与每个客户端的业务逻辑，不需要关心网络细节
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