#include <cstdlib>
#include <iostream>
#include "jsonprocessor.h"
#include "readingsdocumentjsoncontexthandler.h"
#include "readingrepository.h"

int main(int argc, char** argv)
{
    if( argc != 2 )
    {
        std::cout << "usage: river-level-monitor <filename>" << std::endl;
        return EXIT_FAILURE;
    }
    
    const std::string dataFile(argv[1]);
    ReadingRepository::Ptr readingRepository( new ReadingRepository() );
    JSONContextHandler::Ptr readings( new ReadingsDocumentJSONContextHandler(readingRepository) );
    JSONProcessor jsonProcessor;
    jsonProcessor.Process(dataFile, readings);
    readingRepository->Dump();
    return EXIT_SUCCESS;
}
