// Final Project Milestone 2
// Version 1.0
// Date	
// Author	
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "ErrorMessage.h"
using namespace std;
namespace sict {
	ErrorMessage::ErrorMessage(const char* errorMessage ) {
		if (errorMessage == nullptr) {
			mess = new char[1];
			mess[0] = '\0';
		}
		else {
			int len = strlen(errorMessage);
			mess = new char[len+1];
			strcpy(mess, errorMessage);
		}
	}
	ErrorMessage::~ErrorMessage() {
		delete[] mess;
		mess = nullptr;
	}
	void ErrorMessage::clear() {
		mess[0] = '\0';
	}
	bool ErrorMessage::isClear() const {
		if (mess[0] == '\0')
			return true;
		else
			return false;
	}
	void ErrorMessage::message(const char* str) {
		delete[] mess;
		mess = new char[strlen(str)+1];
		strcpy(mess, str);
	}
	const char* ErrorMessage::message() const {
		return mess;
	}
	std::ostream& operator<<(std::ostream& os, ErrorMessage& er) {
		if (er.isClear())
			return os;
		else {
			os << er.message();
			return os;
		}

	}

}
