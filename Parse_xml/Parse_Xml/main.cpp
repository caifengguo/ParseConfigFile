#include <iostream>

#include "ace/OS.h"
#include <ace/ARGV.h>
#include <ace/Argv_Type_Converter.h>
#include <ace/Get_Opt.h>

#include <fstream>
#include <sstream>

using namespace std;
#include "Parse_Xml.h"

#include "Xml_Str.h"

int ACE_TMAIN(int argc, ACE_TCHAR * argv[])
{
	try
	{
		XMLPlatformUtils::Initialize();
	}
	catch(const XMLException& toCatch)
	{
		char *pMsg = XMLString::transcode(toCatch.getMessage());
		XERCES_STD_QUALIFIER cerr << "Error during Xerces-c Initialization.\n"
			<< "  Exception message:"
			<< pMsg;
		XMLString::release(&pMsg);
	}

	Parse_Xml Parse_Xml_;
	string xml_file_buffer;
	char file_path_name[MAX_PATH] = {0};
	ACE_OS::getcwd(file_path_name,MAX_PATH);
	char xml_name[MAX_PATH] ={0};
	ACE_OS::sprintf(xml_name,"%s/Launch_Monitor.xml",file_path_name);

	ACE_DEBUG((LM_DEBUG,ACE_TEXT("(%t|%T)read configure file :%s!\n"),xml_name));
	std::ifstream ifs(xml_name,ios::in|ios::binary) ;
	if (ifs)
	{
		ostringstream os;
		os << ifs.rdbuf();
		xml_file_buffer = os.str();
	}
	int ret_val = Parse_Xml_.parse_lauch_server_from_buffer(xml_name,xml_file_buffer);

	cout << Parse_Xml_.get_module_name_l().c_str()<<endl;
	return 0;
}