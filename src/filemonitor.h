#pragma once

#include <string>
#include "filehandler.h"

class FileMonitor
{
public:
    explicit FileMonitor(const std::string& fileName);
    ~FileMonitor();

    void Start(const FileHandler::Ptr& handler);

private:
    std::string m_fileName;
};
