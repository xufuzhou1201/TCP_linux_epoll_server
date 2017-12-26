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
    //还能存储多少字节
    inline int left()
    {
        return m_capacity - m_size;
    }
    //压入数据，调用前需要通过left()判断是否有足够的空间，不覆盖老数据
    int push(const char* data, int len);
    //取数据，调用前需要通过size()判断是否有足够的元素
    int front(char* data, int len);
    //弹出数据，调用前需要通过size()判断是否有足够的元素
    int pop(int len);
    void reset();
    void free_buffer();


private:
    int     m_capacity;         //容量
    int     m_begin;            //取出数据的位置
    int     m_end;              //压入数据的位置
    int     m_size;
    char*   m_buffer;
};

#endif