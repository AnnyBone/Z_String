#pragma once

#include "Defs.h"

#include <iostream>
#include <yvals.h>

typedef char INT8;
typedef char INT32[4];

class Z_String {
public:
	//Constructors
	Z_String(); //(default)
	Z_String( const INT8 &c ); //(character)
	Z_String(const INT8 *cStr); //(c-string)
	Z_String( const Z_String &string ); //(string)
	Z_String( const Z_String& str, const size_t &pos, const size_t &len ); //(substring)
	Z_String( const INT8 *cStr, const size_t &len ); //(buffer)
	Z_String( const size_t &n, const INT8 &c ); //(fill)
	Z_String( const Z_String &&string ); //(move)


	//Destructor
	~Z_String();


	//operator =
	Z_String& operator = ( const Z_String &str ); //(string)
	Z_String& operator = ( const INT8 *cStr ); //(c-string)
	Z_String& operator = ( const INT8 &c ); //(character)


	//operator +=
	Z_String& operator += ( const Z_String &str ); //(string)
	Z_String& operator += ( const INT8* cStr );//(c-string)
	Z_String& operator += ( const INT8 &c );//(character)


	//operator []
	INT8& operator[] ( const size_t &pos );
	const INT8& operator[] ( const size_t &pos ) const;

	//operator + (string)
	//Z_String& operator + ( const Z_String& rhs );
	//Z_String& operator + ( Z_String&& rhs );
	//Z_String& operator + ( const Z_String& rhs );
	//Z_String& operator + ( Z_String&& rhs );

	////operator + (c-string)
	//Z_String& operator + ( const INT8* rhs );
	//Z_String& operator + ( const INT8* rhs );
	//Z_String& operator + ( const Z_String& rhs );
	//Z_String& operator + ( Z_String&& rhs );

	////operator + (character)
	//Z_String& operator + ( INT8 rhs );
	//Z_String& operator + ( INT8 rhs );
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


	//Compare 
	size_t Compare( const Z_String &str ) const _NOEXCEPT; //(string)

	size_t Compare( const size_t &pos, const size_t &len, const Z_String &str ) const; // (substring)
	size_t Compare( const size_t &lhsPos, const size_t &lhsLen, const Z_String &rhsStr, const size_t &rhsPos, const size_t &rhsLen = npos ) const; // (substring)

	size_t Compare( const INT8 *cStr ) const; //(c-string)
	size_t Compare( const size_t &pos, const size_t &len, const INT8 *cStr ) const; //(c-string)

	size_t Compare( const size_t &pos, const size_t &len, const INT8 *cStr, const size_t &n ) const; // (buffer)


	//Append
	Z_String& Append( const Z_String &str ); //(string)
	Z_String& Append( const Z_String &str, const size_t &subpos, const size_t &sublen = npos ); // (substring)
	Z_String& Append( const INT8 *cStr ); //(c-string)
	Z_String& Append( const INT8 *cStr, const size_t &n ); //(buffer)
	Z_String& Append( const size_t &n, const INT8 &c ); //(fill)
	//template <class InputIterator>
	//string& Append( InputIterator first, InputIterator last ); //(range)
	//Z_String& Append( initializer_list<INT8> il ); //(initializer-list)


	//Assign
	Z_String& Assign( const Z_String &str ); // (string)
	Z_String& Assign( const Z_String &str, const size_t &subpos, const size_t &sublen = npos ); //(substring)
	Z_String& Assign( const INT8 *cStr ); //(c-string)
	Z_String& Assign( const INT8 *cStr, const size_t &n ); // (buffer)
	Z_String& Assign( const size_t &n, const INT8 &c ); //(fill)
	//template<class InputIterator>
	//Z_String& Assign( InputIterator first, InputIterator last ); // (range)
	//Z_String& Assign( Initializer_list<INT8> il ); // (initializer list)
	//Z_String& Assign( Z_String&& str ) _NOEXCEPT; // (move)


	size_t Length() const;

	INT8& At( const size_t &pos );
	const INT8& At( const size_t &pos ) const;

	INT8 Back();
	const INT8 Back() const;

	size_t Capacity() const _NOEXCEPT;

	void Clear() _NOEXCEPT;

	size_t Copy( INT8* cStr, const size_t &len, const size_t &pos ) const;

	const INT8* C_Str() const _NOEXCEPT;

	const INT8* Data() const _NOEXCEPT;

	void Swap( Z_String &str );

	Z_String SubStr( const size_t pos = 0, const size_t len = npos ) const;

	size_t Size() const;

	void Shrink_To_Fit();

	//Find
	size_t Find( const Z_String &str ) const _NOEXCEPT; //(string)
	size_t Find( const INT8 *cStr ) const; //(c-string)
	size_t Find( const INT8 *cStr, const size_t &pos, const size_t &n ) const; //(buffer)
	size_t Find( const INT8 &c ) const _NOEXCEPT; //(character)

	//TODO!!!
	//rfind
	//Resize
	//Reserve
	//Replace
	//Push_Back
	//Pop_Back
	//Max_Size
	//Insert
	//Get_Allocator
	//Front
	//Find_Last_Of
	//Find_Last_Not_Of
	//Find_First_of
	//Find_First_Not_of
	//Erase

	const static int npos;

protected:
	void Z_String::GetInput( std::istream &input, Z_String &string );

private:
	INT8 *string;
	size_t length = 0;
	size_t size = 0;
	const size_t multiplier = 3;

	inline size_t Strlen( const INT8 *cStr ) const;
	inline size_t StrCmp( const INT8 *cStr1, const INT8 *cStr2 ) const;
	inline void Concat( const INT8 *cStr, const size_t &len );
	inline size_t Abs( const int &value ) const;
	inline INT8 Internal_Back() const;
	inline INT8& Internal_At( const size_t &pos ) const;
	inline Z_String& Internal_Append( const INT8 *cStr, const size_t &len );
	inline Z_String& Internal_Assign( const INT8 *cStr, const size_t &len );
	inline size_t Internal_Find( const INT8 *cStr, const size_t &len ) const;
	inline size_t Internal_RFind( const INT8 *cStr, const size_t &len ) const;

};