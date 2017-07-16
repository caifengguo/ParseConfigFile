#pragma once

#include <windows.h>

//Author:    TengChunGuang
//Date:        2008-07-14
//Function:
//    操作INI文件

#include <stdexcept>
using namespace std;

const int MAX_LEN_CONFIG_KEY_VALUE = 100;        //配置文件键值最大长度

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
    //    取得INI文件中的键值
    //Parameter:
    //    appName:    扇区应用名称
    //    keyName:    键名
    //Return:
    //    键值
	std::string GetKeyValue(const char* appName, const char* keyName);

    //Author:    TengChunGuang
    //Date:        2008-07-14
    //Function:
    //    设置INI文件中的键值
    //Parameter:
    //    appName:    扇区应用名称
    //    keyName:    键值
    //    Value:        
    //Return:
    //    S_OK/S_FALSE 成功/失败
    HRESULT SetKeyValue(const char* appName, const char* keyName, const char* Value);

    //Author:    TengChunGuang
    //Date:        2009-05-07
    //Function:
    //    取得INI文件中的键值
    //Parameter:
    //    appName:    扇区应用名称
    //    keyName:    键名
    //Return:
    //    键值
    int GetIntKeyValue(const char* appName, const char* keyName);
};