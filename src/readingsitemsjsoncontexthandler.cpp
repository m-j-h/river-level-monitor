#include "readingsitemsjsoncontexthandler.h"
#include "readingjsoncontexthandler.h"

ReadingsJSONItemsContextHandler::ReadingsJSONItemsContextHandler()
{}

ReadingsJSONItemsContextHandler::~ReadingsJSONItemsContextHandler()
{}
	
JSONContextHandler::Ptr ReadingsJSONItemsContextHandler::StartObject(const std::string& name)
{
	// We expect this object to have no name
	return JSONContextHandler::Ptr( new ReadingJSONContextHandler() );
}
