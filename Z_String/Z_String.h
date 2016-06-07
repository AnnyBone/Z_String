#pragma once

#include "Defs.h"

#include <iostream>
#include <yvals.h>

typedef char INT8;
typedef char INT32[4];

class Z_String {
public:
	//Constructors
	Z_String();
	Z_String( const INT8 &c );
	Z_String( const INT8 *cStr );
	Z_String( const Z_String &string );
	Z_String( const Z_String& str, size_t pos, size_t len );
	Z_String( const INT8 *cStr, size_t len );
	Z_String( size_t n, INT8 c );
	Z_String( const Z_String &&string );

	//Destructor
	~Z_String();

	//operator =
	Z_String& operator = ( const Z_String &str );
	Z_String& operator = ( const INT8* cStr );
	Z_String& operator = ( const INT8 &c );

	//operator +=
	Z_String& operator += ( const Z_String &str );
	Z_String& operator += ( const INT8 *cStr );
	Z_String& operator += ( const INT8 &c );

	//operator []
	INT8& operator[] ( size_t pos );
	const INT8& operator[] ( size_t pos ) const;

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

	////operator ==
	//bool operator== ( const Z_String &rhs ) _NOEXCEPT;
	//bool operator== ( const Z_String  &rhs );
	//bool operator== ( const INT8 *rhs );
	//
	////operator !=
	//bool operator!= ( const Z_String &rhs ) _NOEXCEPT;
	//bool operator!= ( const Z_String &rhs );
	//bool operator!= ( const INT8 *rhs );

	////operator <
	//bool operator<  ( const Z_String &rhs ) _NOEXCEPT;
	//bool operator<  ( const Z_String &rhs );
	//bool operator<  ( const INT8 *rhs );

	////operator <=
	//bool operator<= ( const Z_String  &rhs ) _NOEXCEPT;
	//bool operator<= ( const Z_String &rhs );
	//bool operator<= ( const INT8 *rhs );

	////operator >
	//bool operator>  ( const Z_String &rhs ) _NOEXCEPT;
	//bool operator>  ( const Z_String &rhs );
	//bool operator>  ( const INT8* rhs );

	////operator >=
	//bool operator>= ( const Z_String &rhs ) _NOEXCEPT;
	//bool operator>= ( const Z_String &rhs );
	//bool operator>= ( const INT8* rhs );

	//Compare (string)
	int compare( const Z_String& str ) const _NOEXCEPT;

	//Compare (substrings)
	int compare( size_t pos, size_t len, const Z_String &str ) const;
	int compare( size_t pos, size_t len, const Z_String &str, size_t subpos, size_t sublen = npos ) const;

	//Compare (c-string)
	int compare( const char* s ) const;
	int compare( size_t pos, size_t len, const INT8 *cStr ) const;

	//Compare (buffer)
	int compare( size_t pos, size_t len, const INT8 *cStr, size_t n ) const;

	const static size_t npos;

	//Append (string)
	Z_String& Append( const Z_String& str );

	//Append (substring)
	Z_String& Append( const Z_String& str, const size_t &subpos, const size_t &sublen = npos );

	//Append (c-string)
	Z_String& Append( const char *cStr );

	//Append (buffer)
	Z_String& Append( const char *cStr, const size_t &n );

	//Append (fill)
	Z_String& Append( const size_t &n, const char &c );

	//Append (range)
	//template <class InputIterator>
	//string& Append( InputIterator first, InputIterator last );

	//Append (initializer-list)
	//Z_String& Append( initializer_list<char> il );


	//Assign (string)
	Z_String& Assign( const Z_String &str );

	//Assign (substring)
	Z_String& Assign( const Z_String &str, const size_t subpos, const size_t sublen = npos );

	//Assign (c-string)
	Z_String& Assign( const INT8 *cStr );

	//Assign (buffer)
	Z_String& Assign( const INT8 *cStr, const size_t n );

	//Assign (fill)
	Z_String& Assign( size_t n, const INT8 &c );

	//Assign (range)
	//template<class InputIterator>
	//Z_String& Assign( InputIterator first, InputIterator last );

	//Assign (initializer list)
	//Z_String& Assign( Initializer_list<INT8> il );

	//Assign (move)
	Z_String& Assign( Z_String&& str ) _NOEXCEPT;

	//compare

	size_t Length() const;

	char& At( const size_t pos );
	const char& At( const size_t pos ) const;

	INT8 Back();
	const INT8 Back() const;

	size_t Capacity() const _NOEXCEPT;

	void Clear() _NOEXCEPT;

	size_t Copy( INT8* cStr, const size_t &len, const size_t &pos ) const;

	const INT8* C_Str() const _NOEXCEPT;

	const INT8* Data() const _NOEXCEPT;

protected:
	void Z_String::GetInput( std::istream &input, Z_String &string );

private:
	char *string;
	size_t length = 0;
	size_t size = 0;
	const int multiplier = 3;

	size_t Strlen( const INT8 *cStr ) const ;
	void Concat( const char *cStr, const size_t &len );
};

