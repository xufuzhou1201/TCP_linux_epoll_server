///#include "stdafx.h"
#include "Client.h"


int Client::work()
{
    m_recv_len = sizeof(m_recv_data);
    while (1)
    {
        if (m_recv_deque.size() == 0)
        {
            break;
        }

        if (m_recv_len > m_recv_deque.size())
        {
            m_recv_len = m_recv_deque.size();
        }

        if (m_recv_len > m_send_deque.left())
        {
            break;
        }

        m_recv_deque.front(m_recv_data, m_recv_len);
        m_send_deque.push(m_recv_data, m_recv_len);
        m_recv_deque.pop(m_recv_len);
    }

    return 0;
}