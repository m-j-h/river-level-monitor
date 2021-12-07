#pragma once

#include "jsoncontexthandler.h"
#include "readingrepository.h"

class ReadingsDocumentJSONContextHandler : public JSONContextHandler
{
public:
    explicit ReadingsDocumentJSONContextHandler(const ReadingRepository::Ptr& readings);
    virtual ~ReadingsDocumentJSONContextHandler();

    virtual JSONContextHandler::Ptr StartArray(const std::string& name);

private:
    ReadingRepository::Ptr m_readings;
};
