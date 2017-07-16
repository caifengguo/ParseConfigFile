#include "INIFile.h"
#include <shlwapi.h>

CINIFile::CINIFile(void)
{
    m_strFileName = "";
}

CINIFile::CINIFile(const char* fileName)
{
    SetINIFileName(fileName);
}
CINIFile::~CINIFile(void)
{
}

void CINIFile::SetINIFileName(const char* fileName)
{
    if(!PathFileExists(fileName))
    {
		std::string strErrMsg = "INI文件没有找到！\n文件位置：";
        strErrMsg += fileName;

		throw(logic_error(strErrMsg.c_str()));
    }
    m_strFileName = fileName;
}

std::string CINIFile::GetKeyValue(const char* appName, const char* keyName)
{
    char chValue[MAX_LEN_CONFIG_KEY_VALUE];
    ::GetPrivateProfileStringA(appName,
                                keyName,
                                "",
                                chValue,
                                MAX_LEN_CONFIG_KEY_VALUE,
                                m_strFileName.c_str());
    return (const char*)chValue;
}

HRESULT CINIFile::SetKeyValue(const char* appName, const char* keyName, const char* Value)
{
    BOOL bFlag = ::WritePrivateProfileStringA(appName,
                                keyName,
                                Value,
                                m_strFileName.c_str());

    if(bFlag)
        return S_OK;
    else
        return S_FALSE;
}

int CINIFile::GetIntKeyValue(const char* appName, const char* keyName)
{
    return ::GetPrivateProfileInt(appName,
                                keyName,
                                0,
                                m_strFileName.c_str());
}