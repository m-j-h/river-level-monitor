#pragma once

#include "jsoncontexthandler.h"

class ReadingsJSONItemsContextHandler : public JSONContextHandler
{
public:
	ReadingsJSONItemsContextHandler();
	virtual ~ReadingsJSONItemsContextHandler();
	
	virtual JSONContextHandler::Ptr StartObject(const std::string& name);
};
