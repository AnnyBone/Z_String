#pragma once

#include "Defs.h"

#include <iostream>

class Z_String {
public:
	//Constructors
	Z_String();
	Z_String( const char &c );
	Z_String( const char *cStr );
	Z_String( const Z_String &string );
	Z_String( const Z_String& str, size_t pos, size_t len );
	Z_String( const char *cStr, size_t len );
	Z_String( size_t n, char c );
	Z_String( const Z_String &&string );

	//Destructor
	~Z_String();

	//operator =
	Z_String& operator = ( const Z_String &str );
	Z_String& operator = ( const char* cStr );
	Z_String& operator = ( const char &c );

	//operator +=
	Z_String& operator += ( const Z_String &str );
	Z_String& operator += ( const char *cStr );
	Z_String& operator += ( const char &c );

	//operator []
	char& operator[] ( size_t pos );
	const char& operator[] ( size_t pos ) const;

	//operator + (string)
	//Z_String& operator + ( const Z_String& rhs );
	//Z_String& operator + ( Z_String&& rhs );
	//Z_String& operator + ( const Z_String& rhs );
	//Z_String& operator + ( Z_String&& rhs );

	////operator + (c-string)
	//Z_String& operator + ( const char* rhs );
	//Z_String& operator + ( const char* rhs );
	//Z_String& operator + ( const Z_String& rhs );
	//Z_String& operator + ( Z_String&& rhs );

	////operator + (character)
	//Z_String& operator + ( char rhs );
	//Z_String& operator + ( char rhs );
	//Z_String& operator + ( const Z_String& rhs );
	//Z_String& operator + ( Z_String&& rhs );

	//operator ostream (<<)
	friend std::ostream &operator <<( std::ostream &output, const Z_String &string );
	//operator istream (>>)
	friend std::istream &operator >>( std::istream  &input, Z_String &string );

	//operator ==
	bool operator== ( const Z_String& rhs ) noexcept;
	bool operator== ( const Z_String& rhs );
	bool operator== ( const char* rhs );
	
	//operator !=
	bool operator!= ( const Z_String& rhs ) noexcept;
	bool operator!= ( const Z_String& rhs );
	bool operator!= ( const char* rhs );

	//operator <
	bool operator<  ( const Z_String& rhs ) noexcept;
	bool operator<  ( const Z_String& rhs );
	bool operator<  ( const char* rhs );

	//operator <=
	bool operator<= ( const Z_String& rhs ) noexcept;
	bool operator<= ( const Z_String& rhs );
	bool operator<= ( const char* rhs );

	//operator >
	bool operator>  ( const Z_String& rhs ) noexcept;
	bool operator>  ( const Z_String& rhs );
	bool operator>  ( const char* rhs );

	//operator >=
	bool operator>= ( const Z_String& rhs ) noexcept;
	bool operator>= ( const Z_String& rhs );
	bool operator>= ( const char* rhs );

	//Compare (string)
	int compare( const Z_String& str ) const noexcept;

	//Compare (substrings)
	int compare( size_t pos, size_t len, const Z_String& str ) const;
	int compare( size_t pos, size_t len, const Z_String& str, size_t subpos, size_t sublen = npos ) const;

	//Compare (c-string)
	int compare( const char* s ) const;
	int compare( size_t pos, size_t len, const char* s ) const;

	//Compare (buffer)
	int compare( size_t pos, size_t len, const char* s, size_t n ) const;

	const static size_t npos;

	//TODO TOMORROW Implement:
	//append.

	//assign.

	//at'
	
	//back

	//capacity

	//clear

	//compare

	//copy

	//c_str

	//data

protected:
	void Z_String::GetInput( std::istream &input, Z_String &string );

private:
	char *string;
	size_t length = 0;
	size_t size = 0;
	const int multiplier = 3;

	size_t strlen( const char *cStr );
	void Concat( const char *cStr, const size_t &len );
};

