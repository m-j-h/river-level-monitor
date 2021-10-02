#include "jsoncontexthandler.h"

JSONContextHandler::Ptr JSONContextHandler::StartObject(const std::string& name)
{
	return shared_from_this();
}

JSONContextHandler::Ptr JSONContextHandler::StartArray(const std::string& name)
{
	return shared_from_this();	
}

void JSONContextHandler::EndObject()
{}

void JSONContextHandler::EndArray()
{}

void JSONContextHandler::String(const std::string& key, const std::string& value)
{}
