#pragma once

#include <string>
#include "jsoncontexthandler.h"
#include "readingrepository.h"

class ReadingsJSONItemsContextHandler : public JSONContextHandler
{
public:
    explicit ReadingsJSONItemsContextHandler(const ReadingRepository::Ptr& readingRepository);
    virtual ~ReadingsJSONItemsContextHandler();

    virtual JSONContextHandler::Ptr StartObject(const std::string& name);
    virtual void EndObject();
    virtual void String(const std::string& key, const std::string& value);

private:
    std::string m_id;
    std::string m_measure;
    std::string m_timeStamp;
    ReadingRepository::Ptr m_readingRepository;
};
