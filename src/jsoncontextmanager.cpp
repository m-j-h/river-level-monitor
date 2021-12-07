
#include "jsoncontextmanager.h"

JSONContextManager::JSONContextManager(const JSONContextHandler::Ptr& rootHandler)
{
    m_contextStack.push_back(rootHandler);
}

void JSONContextManager::StartObject(const std::string& name)
{
    auto currentContext = m_contextStack.back();
    auto newContext = currentContext->StartObject(name);
    m_contextStack.push_back(newContext);
}

void JSONContextManager::StartArray(const std::string& name)
{
    auto currentContext = m_contextStack.back();		
    auto newContext = currentContext->StartArray(name);
    m_contextStack.push_back(newContext);
}

void JSONContextManager::EndObject()
{
    auto currentContext = m_contextStack.back();
    currentContext->EndObject();
    m_contextStack.pop_back();
}

void JSONContextManager::EndArray()
{
    auto currentContext = m_contextStack.back();
    currentContext->EndArray();
    m_contextStack.pop_back();
}

void JSONContextManager::String(const std::string& key, const std::string& value)
{
    m_contextStack.back()->String(key,value);
}
