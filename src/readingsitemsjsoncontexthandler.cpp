#include "readingsitemsjsoncontexthandler.h"
#include <iostream>

ReadingsJSONItemsContextHandler::ReadingsJSONItemsContextHandler()
: m_id(),
  m_measure(),
  m_timeStamp()
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
	std::cout << "id        : " << m_id << std::endl;
	std::cout << "measure   : " << m_measure << std::endl;
	std::cout << "timeStamp : " << m_timeStamp << std::endl;
	std::cout << "------------" << std::endl;	
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
