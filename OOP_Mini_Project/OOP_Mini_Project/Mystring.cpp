#include "Mystring.h"

//ostream
mystd::ostream& mystd::ostream::operator<< (char* str)
{
	printf("%s", str);
	return *this;
}

mystd::ostream& mystd::ostream::operator<< (const char* str)
{
	printf("%s", str);
	return *this;
}

mystd::ostream& mystd::ostream::operator<< (char str)
{
	printf("%c", str);
	return *this;
}

mystd::ostream& mystd::ostream::operator<< (ostream& (*fp)(ostream& ostm))
{
	return fp(*this);
}

mystd::ostream& mystd::endl(ostream& ostm)
{
	ostm << '\n';
	fflush(stdout);
	return ostm;
}

mystd::ostream& my::operator<< (mystd::ostream& os, const my::string& string)
{
	os << string.str;
	return os;
}

//istream
mystd::istream& mystd::istream::operator>> (char str[])
{
	scanf_s("%s", str, (int)sizeof(str));
	return *this;
}

mystd::istream& my::operator>> (mystd::istream& is, my::string& string)
{
	if (string.str != nullptr)
	{
		delete[] string.str;
	}

	char* temp = new char[100];
	scanf_s("%s", temp, 100);

	string.strLen = (int)strlen(temp) + 1;
	string.str = new char[string.strLen];
	strncpy_s(string.str, string.strLen, temp, string.strLen);

	delete[] temp;

	return is;
}

//string
my::string::string() : str(nullptr), strLen(0)
{
}

my::string::string(const char* str)
{
	strLen = (int)strlen(str) + 1;	
	this->str = new char[strLen];
	strcpy_s(this->str, strLen, str);
}

my::string::string(const string& ref)
{
	strLen = ref.strLen;
	str = new char[strLen];
	strcpy_s(str, strLen, ref.str);
}

my::string my::string::operator+ (const string& substr)
{
	char* temp = new char[strLen + substr.strLen - 1];
	strcpy_s(temp, strLen + substr.strLen - 1, str);
	strcat_s(temp, strLen + substr.strLen - 1, substr.str);
	
	string stemp(temp);

	delete[] temp;

	return stemp;
}

my::string& my::string::operator= (const string& substr)
{
	if (str != nullptr)
	{
		delete[] str;
	}

	strLen = substr.strLen;
	str = new char[strLen];
	strcpy_s(str, strLen, substr.str);
	return *this;
}

my::string& my::string::operator+= (const string& substr)
{
	*this = *this + substr;
	return *this;
}

bool my::string::operator== (const string substr)
{
	return strcmp(this->str, substr.str) == 0;
}

my::string::~string()
{
	if (str != nullptr)
	{
		delete[] str;
	}
}