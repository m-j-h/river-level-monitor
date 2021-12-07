#pragma once

#include <memory>
#include <string>

class JSONContextHandler : public std::enable_shared_from_this<JSONContextHandler>
{
public:
    using Ptr = std::shared_ptr<JSONContextHandler>;

    virtual JSONContextHandler::Ptr StartObject(const std::string& name);
    virtual JSONContextHandler::Ptr StartArray(const std::string& name);
    virtual void EndObject();
    virtual void EndArray();
    virtual void String(const std::string& key, const std::string& value);
};
