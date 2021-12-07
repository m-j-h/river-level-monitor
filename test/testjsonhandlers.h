#include "jsoncontexthandler.h"
#include <memory>
#include <vector>

struct Item
{
    std::string m_id;
};

struct MetaData
{
    std::string m_valueOne;
    std::string m_valueTwo;
};

struct Document
{
    using Ptr = std::shared_ptr<Document>;

    MetaData m_metaData;
    std::vector<Item> m_items;
};

struct MetaDataHandler : public JSONContextHandler
{
    MetaDataHandler(const Document::Ptr& document)
    : m_document(document)	
    {}

    virtual void String(const std::string& key, const std::string& value)
    {
        if( key == "meta-data-key-one")
        {
            m_document->m_metaData.m_valueOne = value;
        }
        else if( key == "meta-data-key-two")
        {
            m_document->m_metaData.m_valueTwo = value;
        }
    }
    Document::Ptr m_document;
};

struct SingleItemHandler : public JSONContextHandler
{
    SingleItemHandler(const Document::Ptr& document)
    : m_document(document)
    {
        m_document->m_items.push_back(Item());
    }

    virtual void String(const std::string& key, const std::string& value)
    {
        if( key == "id")
        {
            m_document->m_items.back().m_id = value;
        }
    }

    Document::Ptr m_document;
};

struct ItemsHandler : public JSONContextHandler
{
    ItemsHandler(const Document::Ptr& document)
    : m_document(document)
    {}

    virtual JSONContextHandler::Ptr StartObject(const std::string& name)
    {
        if( name == "" )
        {
            return JSONContextHandler::Ptr(new SingleItemHandler(m_document));
        }
        return shared_from_this();
    }

    Document::Ptr m_document;
};

struct DocumentHandler : public JSONContextHandler
{
    using Ptr = std::shared_ptr<DocumentHandler>;

    DocumentHandler()
    : m_document( new Document() )
    {}

    virtual JSONContextHandler::Ptr StartObject(const std::string& name)
    {
        if(name == "metadata")
        {
            return JSONContextHandler::Ptr( new MetaDataHandler(m_document) );
        }
        return shared_from_this();	
    }

    virtual JSONContextHandler::Ptr StartArray(const std::string& name)
    {
        if(name == "items")
        {
            return JSONContextHandler::Ptr( new ItemsHandler(m_document) );
        }
        return shared_from_this();
    }

    Document::Ptr m_document;
};
