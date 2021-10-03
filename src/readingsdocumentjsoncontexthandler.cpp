#include "readingsdocumentjsoncontexthandler.h"
#include "readingsitemsjsoncontexthandler.h"

ReadingsDocumentJSONContextHandler::ReadingsDocumentJSONContextHandler(const ReadingRepository::Ptr& readings)
: JSONContextHandler(),
  m_readings(readings)
{}

ReadingsDocumentJSONContextHandler::~ReadingsDocumentJSONContextHandler()
{}

JSONContextHandler::Ptr ReadingsDocumentJSONContextHandler::StartArray(const std::string& name)
{
	if( name == "items" )
	{
		return JSONContextHandler::Ptr( new ReadingsJSONItemsContextHandler(m_readings) );
	}
	return shared_from_this();
}
