#include "filehandler.h"
#include "jsonprocessor.h"
#include "readingsdocumentjsoncontexthandler.h"
#include "readingrepository.h"
#include <iostream>

FileHandler::FileHandler()
{}

FileHandler::~FileHandler()
{}

void FileHandler::HandleFile(const std::string& fileName)
{
    ReadingRepository::Ptr readingRepository( new ReadingRepository() );
    ReadingsDocumentJSONContextHandler::Ptr readings( new ReadingsDocumentJSONContextHandler(readingRepository) );
    JSONProcessor jsonProcessor;
    jsonProcessor.Process(fileName, readings);
    readingRepository->Dump();

    std::cout 
        << "Processed file: " << fileName << " "
        << "Added " << readings->ReadingsAdded() << " readings" 
        << std::endl;
}
