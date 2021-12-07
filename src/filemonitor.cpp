#include "filemonitor.h"

FileMonitor::FileMonitor(const std::string& fileName)
: m_fileName(fileName)
{}

FileMonitor::~FileMonitor()
{}

void FileMonitor::Start(const FileHandler::Ptr& handler)
{
    handler->HandleFile(m_fileName);
}
