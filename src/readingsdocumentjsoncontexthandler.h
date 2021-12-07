#pragma once

#include <memory>
#include "jsoncontexthandler.h"
#include "readingrepository.h"
#include "readingsitemsjsoncontexthandler.h"

class ReadingsDocumentJSONContextHandler : public JSONContextHandler
{
public:
    using Ptr = std::shared_ptr<ReadingsDocumentJSONContextHandler>;
    
    explicit ReadingsDocumentJSONContextHandler(const ReadingRepository::Ptr& readings);
    virtual ~ReadingsDocumentJSONContextHandler();

    virtual JSONContextHandler::Ptr StartArray(const std::string& name);

    unsigned long ReadingsAdded() const;

private:
    ReadingRepository::Ptr                  m_readings;
    ReadingsJSONItemsContextHandler::Ptr    m_itemsHandler;
};
