// Final Project Milestone 2
// Version 1.0
// Date	
// Author	
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
#ifndef SICT_ERRORMESSAGE_H_
#define SICT_ERRORMESSAGE_H_
#include <iostream>
namespace sict{
	class ErrorMessage {
		char* mess;
	public:
		explicit ErrorMessage(const char* errorMessage = nullptr);
		ErrorMessage(const ErrorMessage& em) = delete;
		ErrorMessage& operator=(const ErrorMessage& em) = delete;
		virtual ~ErrorMessage();
		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message()const;
	};
	std::ostream& operator<<(std::ostream& os, ErrorMessage& er);
}



#endif 
