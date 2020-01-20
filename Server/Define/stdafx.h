#pragma once

//-----
#define WONSY_PCH
//-----

// C++ Base
#include <iostream>
#include <chrono>
#include <string>

#define NDEBUG
#include <cassert>

// C++11
#include <mutex>
#include <atomic>
#include <thread>
#include <future>

// C++ 17
#include <shared_mutex>
#include <string_view>

// C++ STL
#include <unordered_set>
#include <array>
#include <vector>
#include <list>

// C++ PPL
#include <concurrent_vector.h>
#include <concurrent_queue.h>
#include <concurrent_priority_queue.h>
#include <concurrent_unordered_map.h>
#include <concurrent_unordered_set.h>

// Custom
#include "header_for_IOCP.h"

// Using
using namespace std;
using namespace std::chrono;
using namespace concurrency;

namespace ATOMIC_UTIL
{
	template <class TYPE> bool T_CAS(std::atomic<TYPE>* addr, TYPE oldValue, TYPE newValue) noexcept
	{
		return atomic_compare_exchange_strong(addr, &oldValue, newValue);
	};

	template <class TYPE> bool T_CAS(volatile TYPE* addr, TYPE oldValue, TYPE newValue) noexcept
	{
		return atomic_compare_exchange_strong(reinterpret_cast<volatile std::atomic<TYPE>*>(addr), &oldValue, newValue);
	};
}

namespace LOG_UTIL
{
#define __FUNCTION_NAME__ __FUNCTION__
#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#define SOURCE_LOCATION __FILENAME__, __LINE__, __FUNCTION_NAME__

	struct SourceLocation
	{
		const char* fileName;
		int fileLine;
		const char* functionName;

		SourceLocation(const char* fileName, int fileLine, const char* functionName);
		string operator()() const;
	};

#define MAKE_SOURCE_LOCATION LOG_UTIL::SourceLocation(SOURCE_LOCATION)

	SourceLocation::SourceLocation(const char* fileName, int fileLine, const char* functionName)
		: fileName(fileName), fileLine(fileLine), functionName(functionName)
	{
	}

	string SourceLocation::operator()() const
	{
		return
			'['
			+ std::string(fileName)
			+ ':'
			+ std::to_string(fileLine)
			+ "] "
			+ std::string(functionName);
	}
}

namespace ERROR_UTIL
{
	[[noreturn]] void Error(const LOG_UTIL::SourceLocation& sourceLocation, const string& printLog)
	{
		std::cout << "ERROR -> " << sourceLocation() << ", " << printLog << "\n";

		while (7)
		{
			// Infinite loop
		}
	};
}