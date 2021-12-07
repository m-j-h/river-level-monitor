#pragma once

#include <string>
#include "jsoncontexthandler.h"

class JSONProcessor
{
public:
    JSONProcessor();
    ~JSONProcessor();

    void Process(const std::string& fileName, const JSONContextHandler::Ptr& handler);
};
