#include "reading.h"

Reading::Reading(   const std::string& id, 
                    const std::string& measure,
                    const std::string& timeStamp)
: m_id(id),
  m_measure(measure),
  m_timeStamp(timeStamp)
{}

std::string Reading::ToString() const
{
    return 
        "id        : " + m_id +
        "\nmeasure   : " + m_measure +
        "\ntimeStamp : " + m_timeStamp;
}
