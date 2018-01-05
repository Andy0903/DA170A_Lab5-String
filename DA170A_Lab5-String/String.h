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
	char& At(size_t i);
	const char& String::At(const size_t i) const;
	char& operator[](size_t i);
	const char& operator[](size_t i) const;
	const char* Data() const;

	int Size() const;
	void Reserve(size_t);
	int Capacity() const;
	void Shrink_to_fit();

	void Push_back(char c);
	void Resize(size_t n);

	String& operator +=(const String& rhs);
	String String::operator+(const String &rhs) const;

	friend bool operator==(const String &lhs, const String &rhs);
	friend bool operator !=(const String &lhs, const String &rhs);

	friend std::ostream& operator<<(std::ostream& cout, String& rhs)
	{
		for (size_t i = 0; i < rhs.size; ++i)
		{
			cout << rhs[i];
		}
		return cout;
	}

private:
	char *letters;
	int size;
	int capacity;
};