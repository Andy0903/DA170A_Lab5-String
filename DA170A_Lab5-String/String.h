#pragma once
#include <iostream>

class String
{
public:
	String();
	String(const String &rhs);
	String(String &&rhs);
	String(const char *cstr);
	String& operator=(const String &rhs);
	String& operator=(String &&rhs);
	~String();

	explicit operator bool();
	char& at(size_t i);
	char& operator[](size_t i);
	const char* data() const;

	int size() const;
	void reserve(size_t);
	int capacity() const;
	void shrink_to_fit();

	void push_back(char c);
	void resize(size_t n);

	String& operator +=(const String& rhs);
	String& operator+();

	friend bool operator==(const String &lhs, const String &rhs);
	friend bool operator !=(const String &lhs, const String &rhs);

	friend std::ostream& operator<<(std::ostream& cout, String& rhs)
	{
		for (size_t i = 0; i < rhs. ? ? ? ? ; ++i)
			cout << rhs. ? ? ? ? [i];
		return cout;
	}
};