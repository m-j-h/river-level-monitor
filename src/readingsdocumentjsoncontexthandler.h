#pragma once

#include "jsoncontexthandler.h"

class ReadingsDocumentJSONContextHandler : public JSONContextHandler
{
public:
	ReadingsDocumentJSONContextHandler();
	virtual ~ReadingsDocumentJSONContextHandler();

	virtual JSONContextHandler::Ptr StartArray(const std::string& name);
};
