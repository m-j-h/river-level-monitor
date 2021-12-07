#include "filehandler.h"
#include "jsonprocessor.h"
#include "readingsdocumentjsoncontexthandler.h"
#include "readingrepository.h"

FileHandler::FileHandler()
{}

FileHandler::~FileHandler()
{}

void FileHandler::HandleFile(const std::string& fileName)
{
    ReadingRepository::Ptr readingRepository( new ReadingRepository() );
    JSONContextHandler::Ptr readings( new ReadingsDocumentJSONContextHandler(readingRepository) );
    JSONProcessor jsonProcessor;
    jsonProcessor.Process(fileName, readings);
    readingRepository->Dump();
}
