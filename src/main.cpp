#include <cstdlib>
#include <iostream>
#include "jsonprocessor.h"
#include "readingsdocumentjsoncontexthandler.h"

int main(int argc, char** argv)
{
    if( argc != 2 )
    {
        std::cout << "usage: river-level-monitor <filename>" << std::endl;
        return EXIT_FAILURE;
    }
    
    const std::string dataFile(argv[1]);
    JSONContextHandler::Ptr readings( new ReadingsDocumentJSONContextHandler() );
    JSONProcessor jsonProcessor;
    jsonProcessor.Process(dataFile, readings);    
    return EXIT_SUCCESS;
}
