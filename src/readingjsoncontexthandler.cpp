#include "readingjsoncontexthandler.h"
#include <iostream>

ReadingJSONContextHandler::ReadingJSONContextHandler()
{}

ReadingJSONContextHandler::~ReadingJSONContextHandler()
{}
	
void ReadingJSONContextHandler::String(const std::string& key, const std::string& value)
{
	std::cout << key << " : " << value << std::endl;
}
