#pragma once

#include "jsoncontexthandler.h"

class ReadingJSONContextHandler : public JSONContextHandler
{
public:
	ReadingJSONContextHandler();
	virtual ~ReadingJSONContextHandler();
	
	virtual void String(const std::string& key, const std::string& value);
};
