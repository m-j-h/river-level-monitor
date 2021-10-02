#include "readingsdocumentjsoncontexthandler.h"
#include "readingsitemsjsoncontexthandler.h"

ReadingsDocumentJSONContextHandler::ReadingsDocumentJSONContextHandler()
: JSONContextHandler()
{}

ReadingsDocumentJSONContextHandler::~ReadingsDocumentJSONContextHandler()
{}

JSONContextHandler::Ptr ReadingsDocumentJSONContextHandler::StartArray(const std::string& name)
{
	if( name == "items" )
	{
		return JSONContextHandler::Ptr( new ReadingsJSONItemsContextHandler() );
	}
	return shared_from_this();
}
