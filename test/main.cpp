#include <cstdlib>
#include <iostream>
#include "jsonprocessor.h"
#include "testjsonhandlers.h"

std::string GetDataFilePath(const std::string& fileName)
{
    const std::string rootDir(getenv("RIVER_LEVEL_ROOT"));    
    return rootDir + "/test/" + fileName;
}

int main()
{
    const std::string dataFile( GetDataFilePath("testdata.json") );
    JSONProcessor jsonProcessor;

    std::cout << "Opening file '" << dataFile << "'" << std::endl;
    DocumentHandler::Ptr document( new DocumentHandler() );
    jsonProcessor.Process(dataFile, document);
    std::cout << "MetaData_1 : " << document->m_document->m_metaData.m_valueOne << std::endl;
    std::cout << "MetaData_2 : " << document->m_document->m_metaData.m_valueTwo << std::endl;
    std::cout << "Items.size() : " << document->m_document->m_items.size() << std::endl;
    std::cout << "Items[0] : " << document->m_document->m_items[0].m_id << std::endl;
    std::cout << "Items[1] : " << document->m_document->m_items[1].m_id << std::endl;
    return EXIT_SUCCESS;
}
