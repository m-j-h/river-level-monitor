
#include "jsonprocessor.h"

#include <fstream>
#include "jsonhandler.h"
#include <rapidjson/istreamwrapper.h>

JSONProcessor::JSONProcessor()
{}

JSONProcessor::~JSONProcessor()
{}
	
void JSONProcessor::Process(const std::string& 				fileName, 
							const JSONContextHandler::Ptr& 	handler)
{
    JSONHandler jsonHandler(handler);
    Reader reader;
    
    std::ifstream ifs(fileName);
    IStreamWrapper isw(ifs);
    reader.Parse(isw, jsonHandler);
}
