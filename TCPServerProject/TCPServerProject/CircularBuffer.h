#ifndef CIRCULARBUFFER_H_
#define CIRCULARBUFFER_H_

class CircularBuffer
{
public:
    CircularBuffer();
    ~CircularBuffer();
    int set_capacity(int capacity);
    int capacity();
    inline int size()
    {
        return m_size;
    }
    bool full();
    //���ܴ洢�����ֽ�
    inline int left()
    {
        return m_capacity - m_size;
    }
    //ѹ�����ݣ�����ǰ��Ҫͨ��left()�ж��Ƿ����㹻�Ŀռ䣬������������
    int push(const char* data, int len);
    //ȡ���ݣ�����ǰ��Ҫͨ��size()�ж��Ƿ����㹻��Ԫ��
    int front(char* data, int len);
    //�������ݣ�����ǰ��Ҫͨ��size()�ж��Ƿ����㹻��Ԫ��
    int pop(int len);
    void reset();
    void free_buffer();


private:
    int     m_capacity;         //����
    int     m_begin;            //ȡ�����ݵ�λ��
    int     m_end;              //ѹ�����ݵ�λ��
    int     m_size;
    char*   m_buffer;
};

#endif