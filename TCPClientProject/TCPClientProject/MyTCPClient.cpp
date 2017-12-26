#include "MyTCPClient.h"
#include <stdio.h>
#include <unistd.h>
#include "log.h"
#pragma warning(disable: 4996)


MyTCPClient::MyTCPClient()
{
}

MyTCPClient::~MyTCPClient()
{
}

int MyTCPClient::work()
{
    char data_to_send[1024];
    char data_to_recv[1024];
    int send_len = sprintf(data_to_send, "I am client %d\r\n", (unsigned int)getpid());
    send_len++;
    while (1)
    {
        usleep(1000 * 300);
        if (send_data(data_to_send, send_len) != send_len)
        {
            return -1;
        }

        if (recv_data(data_to_recv, send_len) != send_len)
        {
            return -2;
        }
        else
        {
            LOGN("%s", data_to_recv);
        }
    }

    return 0;
}

int MyTCPClient::disconnection()
{
    return 0;
}