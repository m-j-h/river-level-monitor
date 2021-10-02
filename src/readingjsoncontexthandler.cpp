#include "readingjsoncontexthandler.h"
#include <iostream>

ReadingJSONContextHandler::ReadingJSONContextHandler()
: m_id(),
  m_measure(),
  m_timeStamp()
{}

ReadingJSONContextHandler::~ReadingJSONContextHandler()
{}
	
void ReadingJSONContextHandler::String(const std::string& key, const std::string& value)
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

void ReadingJSONContextHandler::EndObject()
{
	std::cout << "id        : " << m_id << std::endl;
	std::cout << "measure   : " << m_measure << std::endl;
	std::cout << "timeStamp : " << m_timeStamp << std::endl;
	std::cout << "------------" << std::endl;
}
