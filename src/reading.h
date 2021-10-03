#pragma once

#include <memory>
#include <string>

class Reading
{
public:
    using Ptr = std::shared_ptr<Reading>;
    
	Reading( const std::string& id, 
			 const std::string& measure,
			 const std::string& timeStamp);
			 
	std::string ToString() const;

private:
	std::string m_id;
	std::string m_measure;
	std::string m_timeStamp;
};
