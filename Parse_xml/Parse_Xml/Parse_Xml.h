
#ifndef parse_xml_h__
#define parse_xml_h__

#include <vector>
#include <map>
#include <ace/SString.h>
#include <ace/Log_Msg.h>
#include <ace/OS_NS_stdio.h>
#include <ace/OS.h>

#include "ace/Singleton.h"
#include "ace/Mutex.h"


using namespace std;


class Parse_Xml
{
public:
	Parse_Xml();
	~Parse_Xml();

	//<启动器配置文件

	ACE_TString get_module_name_l();

	int parse_lauch_server_from_buffer(char* xml_name, const string xml_file_buffer );

private:

	ACE_TString module_name_l_;
};

typedef ACE_Singleton<Parse_Xml, ACE_Mutex> Parse_Xml_;

#endif // parse_xml_h__
