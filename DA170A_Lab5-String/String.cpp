#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "String.h"

String::String() : size(0), capacity(0)
{
	letters = new char[capacity + 1] {'\0'};
}

String::String(const String &rhs) : size(rhs.size), capacity(rhs.capacity)
{
	letters = new char[rhs.capacity + 1];
	memcpy(letters, rhs.letters, rhs.size + 1);
}

String::String(const char *cstr) : size(0), capacity(0)
{
	int length = strlen(cstr);
	size = length;
	capacity = length;
	letters = new char[capacity + 1];
	memcpy(letters, cstr, length + 1);
}

String::String(String &&rhs) : size(std::move(rhs.size)), capacity(std::move(rhs.capacity)), letters(std::move(rhs.letters))
{
	rhs.size = 0;
	rhs.capacity = 0;
	rhs.letters = nullptr;
}

String& String::operator=(const String & rhs)
{
	char* temp = new char[rhs.capacity + 1];
	memcpy(temp, rhs.letters, rhs.size + 1);
	delete[] letters;
	letters = temp;
	capacity = rhs.capacity;
	size = rhs.size;

	return *this;
}

String& String::operator=(String &&rhs)
{
	if (this != &rhs)
	{
		delete[] letters;
		
		size = std::move(rhs.size);
		capacity = std::move(rhs.capacity);
		letters = std::move(rhs.letters);

		rhs.size = 0;
		rhs.capacity = 0;
		rhs.letters = nullptr;
	}

	return *this;
}

String::~String()
{
	delete[] letters;
}

String::operator bool()
{
	return capacity != 0;
}

char& String::At(const size_t i)
{
	if (i < 0 || capacity <= i)
	{
		throw std::out_of_range("Index out of bounds.");
	}
	else
	{
		return letters[i];
	}
}

const char& String::At(const size_t i) const
{
	if (i < 0 || capacity <= i)
	{
		throw std::out_of_range("Index out of bounds.");
	}
	else
	{
		return letters[i];
	}
}

char& String::operator[](const size_t i)
{
	return letters[i];
}

const char& String::operator[](const size_t i) const
{
	return letters[i];
}

const char* String::Data() const
{
	return letters;
}

int String::Size() const
{
	return size;
}

void String::Reserve(size_t newCapacity)
{
	if (newCapacity > capacity)
	{
		int oldSize = size;
		Resize(newCapacity);
		size = oldSize;
	}
}

int String::Capacity() const
{
	return capacity;
}

void String::Shrink_to_fit()
{
	Resize(size);
}

void String::Push_back(const char c)
{
	if (size >= capacity)
	{
		Reserve(capacity == 0 ? 10 : size * 2);
	}

	letters[size] = c;
	++size;
}

void String::Resize(size_t n)
{
	char *temp = new char[n + 1];
	capacity = n;
	memcpy(temp, letters, size);
	for (size_t i = size; i < n + 1; ++i) 
	{
		temp[i] = '\0';
	}
	size = n;
	delete[] letters;
	letters = temp;
}

String& String::operator+=(const String& rhs)
{
	Reserve(size + rhs.size);
	memcpy((letters + size), rhs.letters, rhs.size + 1);
	size += rhs.size;
	return *this;
}

String String::operator+(const String &rhs) const
{
	String temp = String(*this);
	temp += rhs;

	return temp;
}

bool operator==(const String &lhs, const String &rhs)
{
	if (lhs.size != rhs.size)
	{
		return false;
	}

	return 0 == memcmp(lhs.letters, rhs.letters, lhs.size);
}

bool operator!=(const String &lhs, const String &rhs)
{
	return !(lhs == rhs);
}
