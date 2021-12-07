#include <cstdlib>
#include <iostream>
#include "filemonitor.h"
#include "filehandler.h"

int main(int argc, char** argv)
{
    if( argc != 2 )
    {
        std::cout << "usage: river-level-monitor <filename>" << std::endl;
        return EXIT_FAILURE;
    }

    const std::string dataFile(argv[1]);
    FileMonitor monitor( dataFile );

    FileHandler::Ptr fileHandler( new FileHandler() );
    monitor.Start(fileHandler);

    return EXIT_SUCCESS;
}
