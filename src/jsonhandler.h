#pragma once

#include <string>
#include "rapidjson/reader.h"
#include "jsoncontextmanager.h"

using namespace rapidjson;

class KeyValue
{
public:
    KeyValue() : m_key()
    {}
    
    void Set(const std::string& key)
    {
        m_key = key;
    }
    
    std::string Use()
    {
        auto key = m_key;
        m_key.clear();
        return key;
    }
    
private:
    std::string m_key;
};

struct JSONHandler : public BaseReaderHandler<UTF8<>, JSONHandler> 
{
    KeyValue m_key;
    JSONContextManager m_contextManager;
    
    JSONHandler(const JSONContextHandler::Ptr& handler) 
    : m_contextManager( handler )
    {}

    bool Null() 
    { 
        return true; 
    }
    
    bool Bool(bool b) 
    { 
        return true; 
    }
    
    bool Int(int i) 
    { 
        return true; 
    }
    
    bool Uint(unsigned u) 
    { 
        return true; 
    }
    
    bool Int64(int64_t i) 
    { 
        return true; 
    }
    
    bool Uint64(uint64_t u) 
    { 
        return true; 
    }
    
    bool Double(double d) 
    { 
        return true; 
    }
    
    bool String(const char* str, SizeType length, bool copy) 
    { 
        auto key = m_key.Use();
        m_contextManager.String(key,str);
        return true;
    }
    
    bool StartObject() 
    {
        auto key = m_key.Use();
        m_contextManager.StartObject(key);
        return true; 
    }
    
    bool Key(const char* str, SizeType length, bool copy) 
    {
        m_key.Set(str);
        return true;
    }
    
    bool EndObject(SizeType memberCount) 
    {
        m_contextManager.EndObject();
        return true; 
    }
    
    bool StartArray() 
    { 
        auto key = m_key.Use();
        m_contextManager.StartArray(key);
        return true; 
    }
    
    bool EndArray(SizeType elementCount) 
    {
        m_contextManager.EndArray();
        return true; 
    }
};
