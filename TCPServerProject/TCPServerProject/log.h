#ifndef LOG_H_
#define LOG_H_

#define LOG_ERROR_LEVEL     1
#define LOG_NORMAL_LEVEL    2
#define LOG_DEBUG_LEVEL     4
#define LOG_ALL_LEVEL       7
#define LOGE(...)        _log1(LOG_ERROR_LEVEL, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__)
#define LOGN(...)        _log1(LOG_NORMAL_LEVEL, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__)
#define LOGD(...)        _log1(LOG_DEBUG_LEVEL, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__)

#ifdef __cplusplus
extern "C" {
#endif

//file_name_key��־�ļ����ƵĹؼ��֣���������-�����ַ��� ����������־���ܻ����
//��־�ļ�·���������£�ÿ�θ��ݳ�������ʱ�������µ���־�ļ���test��Ϊfile_name_key
//dir\test-2017-03-09-09-06-03.log
int open_log_file(const char* dir, const char* file_name_key, const int days = -1);

//������ϵͳ���ر�IO�� ���������ĵ��÷�����ϵͳ����IOǰ�� �����ڴ����֮��
//��ֹд��־��ʱ���Ѿ����ر�
int close_log_file();

//�������ָ����������־��open_log_file֮�����
int clear_log(const int days);
void set_log_level(int level = 1);
int get_log_level();

//����log����  ����� [��-��-��-ʱ-��-��]�ļ�-�к�-��������:
//ϵͳ��������
//�û�����
int _log1(int type, const char* file_name, int line, const char* func_name, const char *fmt, ...);

#ifdef __cplusplus
}
#endif

#endif
