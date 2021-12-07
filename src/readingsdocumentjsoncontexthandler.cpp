#include "readingsdocumentjsoncontexthandler.h"
#include "readingsitemsjsoncontexthandler.h"

ReadingsDocumentJSONContextHandler::ReadingsDocumentJSONContextHandler(const ReadingRepository::Ptr& readings)
: JSONContextHandler(),
  m_readings(readings),
  m_itemsHandler( new ReadingsJSONItemsContextHandler(m_readings) )
{}

ReadingsDocumentJSONContextHandler::~ReadingsDocumentJSONContextHandler()
{}

JSONContextHandler::Ptr ReadingsDocumentJSONContextHandler::StartArray(const std::string& name)
{
    if( name == "items" )
    {
        return m_itemsHandler;
    }
    return shared_from_this();
}

unsigned long ReadingsDocumentJSONContextHandler::ReadingsAdded() const
{
    return m_itemsHandler->ReadingsAdded();
}
