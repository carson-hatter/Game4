#pragma once

#include <exception>

class Exception : public std::exception
{
private: std::string String;
public: Exception(std::string String_) : std::exception()
	{
		String = String_;
	}
public: const char* what() const throw()
		{
			return String.c_str();
		}
};