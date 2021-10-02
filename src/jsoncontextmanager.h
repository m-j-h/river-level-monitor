#pragma once

#include <string>
#include <vector>
#include "jsoncontexthandler.h"

class JSONContextManager
{	
public:
	JSONContextManager(const JSONContextHandler::Ptr& rootHandler);

	void StartObject(const std::string& name);
	void StartArray(const std::string& name);	
	void EndObject();		
	void EndArray();	
	void String(const std::string& key, const std::string& value);
	
private:
	std::vector<JSONContextHandler::Ptr> m_contextStack;
};
