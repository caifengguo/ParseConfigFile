#pragma once

#include <windows.h>

//Author:    TengChunGuang
//Date:        2008-07-14
//Function:
//    ����INI�ļ�

#include <stdexcept>
using namespace std;

const int MAX_LEN_CONFIG_KEY_VALUE = 100;        //�����ļ���ֵ��󳤶�

class CINIFile
{
public:
    CINIFile(void);
    CINIFile(const char* fileName);
public:
    ~CINIFile(void);
private:
	std::string m_strFileName;
public:
    void SetINIFileName(const char* fileName);

    //Author:    TengChunGuang
    //Date:        2008-07-14
    //Function:
    //    ȡ��INI�ļ��еļ�ֵ
    //Parameter:
    //    appName:    ����Ӧ������
    //    keyName:    ����
    //Return:
    //    ��ֵ
	std::string GetKeyValue(const char* appName, const char* keyName);

    //Author:    TengChunGuang
    //Date:        2008-07-14
    //Function:
    //    ����INI�ļ��еļ�ֵ
    //Parameter:
    //    appName:    ����Ӧ������
    //    keyName:    ��ֵ
    //    Value:        
    //Return:
    //    S_OK/S_FALSE �ɹ�/ʧ��
    HRESULT SetKeyValue(const char* appName, const char* keyName, const char* Value);

    //Author:    TengChunGuang
    //Date:        2009-05-07
    //Function:
    //    ȡ��INI�ļ��еļ�ֵ
    //Parameter:
    //    appName:    ����Ӧ������
    //    keyName:    ����
    //Return:
    //    ��ֵ
    int GetIntKeyValue(const char* appName, const char* keyName);
};