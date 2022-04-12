#pragma once
#include <iostream>
#include <cstring>

namespace mystd
{
	class ostream
	{
	public:
		ostream& operator<< (char* str);

		ostream& operator<< (const char* str);

		ostream& operator<< (char str);

		ostream& operator<< (ostream& (*fp)(ostream& ostm));
	};

	ostream& endl(ostream& ostm);

	class istream
	{
	public:
		istream& operator>> (char str[]);
	};
}


namespace my
{
	class string
	{
	private:
		char* str;
		int strLen;

	public:
		string(); 
		string(const char* str);
		string(const string& ref);

		string operator+ (const string& substr);
		string& operator= (const string& substr);
		string& operator+= (const string& substr);
		bool operator== (const string substr);

		friend mystd::ostream& operator<< (mystd::ostream& os, const string& string);
		friend mystd::istream& operator>> (mystd::istream& is, string& string);

		~string();
	};
}

mystd::ostream& my::operator<< (mystd::ostream& os, const my::string& string);
mystd::istream& my::operator>> (mystd::istream& is, my::string& string);