

#include "Parse_Xml.h"


#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/OutOfMemoryException.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/framework/MemBufInputSource.hpp>
#include <xercesc/framework/Wrapper4InputSource.hpp>

#include "Xml_Str.h"

Parse_Xml::Parse_Xml()
{
}

Parse_Xml::~Parse_Xml()
{

}

ACE_VERSIONED_NAMESPACE_NAME::ACE_TString Parse_Xml::get_module_name_l()
{
	return module_name_l_;
}


int Parse_Xml::parse_lauch_server_from_buffer( char* xml_name, const string xml_file_buffer )
{
	int ret_value = 0;
	try
	{
		//MemBufInputSource * memBufIS = 
		//	new MemBufInputSource((const XMLByte*)(xml_file_buffer.c_str()),
		//	xml_file_buffer.size() ,"lanuch_monitor", false); 

		XercesDOMParser *parser = new XercesDOMParser;
		parser-> setValidationScheme(XercesDOMParser::Val_Auto);
		parser-> setDoNamespaces(false);
		parser-> setDoSchema(false);
		parser-> setLoadExternalDTD(false);

		parser->parse(xml_name);
		xercesc::DOMDocument* xmlDoc = parser->getDocument();
		DOMElement * pRootElement = xmlDoc->getDocumentElement();
		if (0 == pRootElement)
		{
			ACE_ERROR_RETURN((LM_ERROR, 
				ACE_TEXT("(%t|%T) Empty xml file! \n")), -1);
		}
		//校验根节点是否正常
		const XMLCh * pNodeName = pRootElement->getTagName();
		if (!strcmp((const char*)pNodeName, "Configure"))
		{
			ACE_ERROR_RETURN((LM_ERROR, 
				ACE_TEXT("(%t|%T) invalid xml format \n")), -1);
		}

		DOMNodeList * extract_unit_nodes = 
			pRootElement->getElementsByTagName(X("module_name"));
		if (extract_unit_nodes->getLength() > 0)
		{
			const XMLCh * xml_value = ((DOMElement *)extract_unit_nodes->item(0))->getAttribute(X("value"));
			module_name_l_ = XMLString::transcode(xml_value);
			
			
			//module_name_l_ = ACE_TEXT_WCHAR_TO_TCHAR((wchar_t*)xml_value);
		}
	}
	catch (const OutOfMemoryException&)
	{
		ACE_ERROR_RETURN((LM_ERROR, 
			ACE_TEXT("(%t|%T) OutOfMemoryException in parse_xml_config\n")), 
			-1);
	}
	catch (const DOMException& e)
	{
		ACE_ERROR_RETURN((LM_ERROR, 
			ACE_TEXT("(%t|%T) DOMException in parse_xml_config, code is %d\n"),
			e.code),-1);
	}
	catch (...)
	{
		ACE_ERROR_RETURN((LM_ERROR, 
			ACE_TEXT("(%t|%T) Unknown Exception in parse_xml_config\n")),
			-1);
	}
	return ret_value;
}
