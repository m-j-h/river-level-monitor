#pragma once

#include <memory>
#include <string>

class FileHandler
{
public:
    using Ptr = std::shared_ptr<FileHandler>;

    FileHandler();
    ~FileHandler();

    void HandleFile(const std::string& fileName);
};
