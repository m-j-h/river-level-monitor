#include "readingrepository.h"
#include <algorithm>
#include <iostream>

ReadingRepository::ReadingRepository()
: m_readings()
{}
	
ReadingRepository::~ReadingRepository()
{}

void ReadingRepository::Add(const Reading::Ptr& reading)
{
	m_readings.push_back(reading);
}

void ReadingRepository::Dump()
{
	std::for_each( 	m_readings.begin(), 
					m_readings.end(),
					[](const auto& reading) 
					{
						std::cout << reading->ToString() << std::endl;
						std::cout << "--------" << std::endl;
					});
}
