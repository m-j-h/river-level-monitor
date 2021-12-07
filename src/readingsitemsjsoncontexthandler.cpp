#include "readingsitemsjsoncontexthandler.h"
#include <iostream>

ReadingsJSONItemsContextHandler::ReadingsJSONItemsContextHandler(const ReadingRepository::Ptr& readingRepository)
: m_id(),
  m_measure(),
  m_timeStamp(),
  m_readingRepository(readingRepository),
  m_readingsAdded(0L)
{}

ReadingsJSONItemsContextHandler::~ReadingsJSONItemsContextHandler()
{}

JSONContextHandler::Ptr ReadingsJSONItemsContextHandler::StartObject(const std::string& name)
{
    m_id.clear();
    m_measure.clear();
    m_timeStamp.clear();
    return shared_from_this();
}

void ReadingsJSONItemsContextHandler::EndObject()
{
    Reading::Ptr reading( new Reading(m_id, m_measure, m_timeStamp) );
    m_readingRepository->Add(reading);
    m_readingsAdded++;
}

void ReadingsJSONItemsContextHandler::String(const std::string& key, const std::string& value)
{
    if(key == "@id")
    {
        m_id = value;
    }
    else if(key == "dateTime")
    {
        m_timeStamp = value;
    }
    else if(key == "measure")
    {
        m_measure = value;
    }
}

unsigned long ReadingsJSONItemsContextHandler::ReadingsAdded() const
{
    return m_readingsAdded;
}
