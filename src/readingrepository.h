#pragma once

#include "reading.h"
#include <memory>
#include <vector>

class ReadingRepository
{
public:
    using Ptr = std::shared_ptr<ReadingRepository>;

    ReadingRepository();
    ~ReadingRepository();

    void Add(const Reading::Ptr& reading);
    void Dump();

private:
    std::vector<Reading::Ptr> m_readings;
};
