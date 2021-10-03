#pragma once

#include <string>
#include "jsoncontexthandler.h"

class ReadingsJSONItemsContextHandler : public JSONContextHandler
{
public:
	ReadingsJSONItemsContextHandler();
	virtual ~ReadingsJSONItemsContextHandler();
	
	virtual JSONContextHandler::Ptr StartObject(const std::string& name);
	virtual void EndObject();
	virtual void String(const std::string& key, const std::string& value);
	
private:
	std::string m_id;
	std::string m_measure;
	std::string m_timeStamp;
};
