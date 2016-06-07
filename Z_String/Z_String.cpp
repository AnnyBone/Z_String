#include "Z_String.h"

#include <string>

const size_t npos = -1;

//******
//Constructor
//Default
//******
Z_String::Z_String() {}

//******
//Constructor
//Copy (Shallow copy)
//******
Z_String::Z_String( const INT8 &c ) {
	char arr[2];
	arr[0] = c;
	arr[1] = '\0';

	Concat( arr, 1 );
}

//******
//Constructor
//from c-string
//******
Z_String::Z_String( const INT8 *cStr ) {
	const size_t l = strlen( cStr );
	if ( l > 0 ) {
		Concat( cStr, l);
	}
}

//******
//Constructor
//Copy (deep copy)
//Observe that no memory is not deleted, size will not be same as Z_String size parameter.
//******
Z_String::Z_String( const Z_String &str )  {
	if ( str.length > 0 ) {
		Concat( str.string, str.length );
	}
	else {
		throw std::out_of_range( "from c-string" );
	}
}

//******
//Constructor
//Substring
//******
Z_String::Z_String( const Z_String& str, const size_t pos, const size_t len ) {
	if ( len > 0 && len <= str.length &&
		 pos >= 0 && 
		 pos + len <= str.length ) {

		Concat( str.string + pos, len );
	}
	else {
		throw std::out_of_range( "substring");
	}
}

//******
//Constructor
//From buffer
//******
Z_String::Z_String( const INT8 *cStr, size_t len ) {
	if ( len > 0 && len <= strlen(cStr) ) {
		Concat( cStr, len );
	}
	else {
		throw std::out_of_range( "From buffer" );
	}
}

//******
//Constructor
//Fill
//******
Z_String::Z_String( const size_t n, const INT8 c ) {
	if ( n > 0 ) {
		Concat( "c", n );

		memset( this->string, c, n );
		this->string[length] = '\0';
	}
	else {
		throw std::out_of_range( "Fill constructor" );
	}
}

//******
//Constructor
//Move 
//******
Z_String::Z_String( const Z_String &&string ) {
	// TODO!!!!
}

//******
//Destructor
//******
Z_String::~Z_String() {
	if ( size > 0 ) {
		delete []string;
	}
}

//******
//oprator=
//Z_string
//Observe that no memory is not deleted, size will not be same as Z_String size parameter.
//******
Z_String& Z_String::operator=( const Z_String &str ) {
	this->length = 0;
	Concat( str.string, str.length );
	return *this;
}

//******
//oprator=
//c-string
//Observe that no memory is not deleted, size will not be same as cStr size.
//******
Z_String& Z_String::operator=( const INT8* cStr ) {
	if ( cStr[0] != '\0' ) {
		this->length = 0;
		Concat( cStr, strlen( cStr ) );
	}
	return *this;
}

//******
//oprator=
//character
//Observe that no memory is not deleted, size will not be same as c size.
//******
Z_String& Z_String::operator=( const INT8 &c ) {
	this->length = 0;

	char arr[2];
	arr[0] = c;
	arr[1] = '\0';

	Concat( arr, 1 );
	return *this;
}

//******
//oprator+=
//character
//******
Z_String& Z_String::operator += ( const Z_String &str ) {
	Concat( str.string, str.length );
	return *this;
}

//******
//oprator+=
//character
//******
Z_String& Z_String::operator += ( const INT8 *cStr ) {
	Concat(cStr, strlen(cStr));
	return *this;
}

//******
//oprator+=
//character
//******
Z_String& Z_String::operator += ( const INT8 &c ) {
	char arr[2];
	arr[0] = c;
	arr[1] = '\0';

	Concat( arr, 1 );
	return *this;
}

//******
//oprator[]
//******
char& Z_String::operator[] ( size_t pos ) {
	return this->string[pos];
}

//******
//oprator[]
//const
//******
const char& Z_String::operator[] ( size_t pos ) const {
	return this->string[pos];
}

////******
////oprator+
////string
////******
//Z_String& Z_String::operator + ( const Z_String &rhs ){
//	Concat( rhs.string, rhs.len );
//	return *this;
//}
//
////******
////oprator+
////string
////******
//Z_String& Z_String::operator + ( Z_String &&rhs ) {
//	// TODO!!!!
//}
//
////******
////oprator+
////string
////******
//Z_String& Z_String::operator + ( const Z_String &rhs ) {
//	Concat( rhs.string, rhs.len );
//	return *this;
//}
//
////******
////oprator+
////string
////******
//Z_String& Z_String::operator + ( Z_String &&rhs ) {
//	// TODO!!!!
//}
//
////******
////oprator+
////c-string
////******
//Z_String& Z_String::operator + ( const char *rhs ) {
//	Concat( rhs, strlen(rhs) );
//	return *this;
//}
//
////******
////oprator+
////c-string
////******
//Z_String& Z_String::operator + ( const char *rhs ) {
//	Concat( rhs, strlen( rhs ) );
//	return *this;
//}
//
////******
////oprator+
////c-string
////******
//Z_String& Z_String::operator + ( const Z_String &rhs ) {
//
//}
//
////******
////oprator+
////c-string
////******
//Z_String& Z_String::operator + ( Z_String &&rhs ) {
//	// TODO!!!!
//}
//
////******
////oprator+
////character
////******
//Z_String& Z_String::operator + ( char rhs ) {
//	char arr[2];
//	arr[0] = rhs;
//	arr[1] = '\0';
//
//	Concat( arr, 1 );
//	return *this;
//}
//
////******
////oprator+
////character
////******
//Z_String& Z_String::operator + ( char rhs ) {
//
//}
//
////******
////oprator+
////character
////******
//Z_String& Z_String::operator + ( const Z_String &rhs ) {
//
//}
//
////******
////oprator+
////character
////******
//Z_String& Z_String::operator + ( Z_String &&rhs ) {
//	// TODO!!!!
//}

//******
//operator ostream (<<)
//friend function to Z_String
//****** 
std::ostream &operator <<( std::ostream &output, const Z_String &string ) {
		return output << string.string;
}

//******
//GetInput
//****** 
void Z_String::GetInput( std::istream &input, Z_String &string ) {
	string = ""; //Empty string

	INT8 buffer[4];
	INT8 c;
	int i = 0;
	while ( input.get( c ) ) {
		buffer[i] = c;
		++i;
		if ( c == '\n' ) { 
			break;

		} else if ( i == 3 ) {
			buffer[3] = '\0';
			Concat( buffer, i );

			i = 0;
		}
	}

	buffer[i -1] = '\0';
	Concat( buffer, i );
}

//******
//operator istream (>>)
//friend function to Z_String
//******
std::istream &operator >>( std::istream  &input, Z_String &string ) {
	string.GetInput( input, string );
	return input;
}

//bool Z_String::operator == ( const Z_String &rhs ) _NOEXCEPT {
//	return compare( rhs ) == 0;
//}
//
//bool Z_String::operator == ( const Z_String &rhs ) {
//	//TODO!
//}
//
//bool Z_String::operator == ( const INT8 *rhs ) {
//	return compare( rhs ) == 0;
//}
//
//bool Z_String::operator != ( const Z_String &rhs ) _NOEXCEPT {
//	return compare( rhs.string ) > 0 && compare(rhs.string) < 0;
//}
//
//bool Z_String::operator != ( const Z_String &rhs ) {
//	//TODO!
//}
//
//bool Z_String::operator != ( const INT8 *rhs ) {
//	return compare( rhs ) > 0 && compare( rhs ) < 0;
//}
//
//bool Z_String::operator <  ( const Z_String &rhs ) _NOEXCEPT {
//	return rhs.string < 0;
//}
//
//bool Z_String::operator <  ( const Z_String &rhs ) {
//	//TODO!
//}
//
//bool Z_String::operator <  ( const INT8 *rhs ) {
//	return rhs < 0;
//}
//
//bool Z_String::operator <= ( const Z_String &rhs ) _NOEXCEPT {
//
//}
//
//bool Z_String::operator <= ( const Z_String &rhs ) {
//	//TODO!
//}
//
//bool Z_String::operator <= ( const char* rhs ) {
//
//}
//
//bool Z_String::operator >  ( const Z_String &rhs ) _NOEXCEPT {
//	return rhs.string > 0;
//}
//
//bool Z_String::operator >  ( const Z_String &rhs ) {
//	//TODO!
//}
//
//bool Z_String::operator >  ( const char *rhs ) {
//	return rhs > 0;
//}
//
//bool Z_String::operator >= ( const Z_String& rhs ) _NOEXCEPT {
//
//}
//
//bool Z_String::operator >= ( const Z_String& rhs ) {
//	//TODO!
//}
//
//bool Z_String::operator >= ( const char* rhs ) {
//
//}

//******
// C_Str
//****** 
const char* Z_String::C_Str() const _NOEXCEPT {
	return string;
}

//******
// Data
//****** 
const char* Z_String::Data() const _NOEXCEPT {
	return string;
}

//******
// Copy
//****** 
size_t Z_String::Copy( INT8 *cStr, const size_t &len, const size_t &pos ) const {
	if ( (pos + len) <= this->length ) {
		memcpy( cStr, this->string + pos, len );
		return len;
	}
	return 0;
}

//******
// Clear
//****** 
void Z_String::Clear() _NOEXCEPT {
	if ( size > 0 ) {
		this->string[0] = '\0';
		this->length = 0;
	}
}

//******
// Capacity
//****** 
size_t Z_String::Capacity() const _NOEXCEPT {
	return this->size;
}

//******
// Back
//****** 
INT8 Z_String::Back() {
	if ( size > 0 && length > 0 ) {
		return string[length -1];
	}
}

//******
// Back
//****** 
const INT8 Z_String::Back() const {
	if ( size > 0 && length > 0 ) {
		return string[length -1];
	}
}

char& Z_String::At( const size_t pos ) {
	if ( pos > this->length ) {
		throw std::out_of_range( "AT" );
	}
	return this->string[pos];
}

const char& Z_String::At( const size_t pos ) const {
	if ( pos > this->length ) {
		throw std::out_of_range( "AT" );
	}
	return this->string[pos];
}


//******
//Append
//******
size_t Z_String::Length() const {
	return this->length;
}

//******
//Append
// string
//******
Z_String& Z_String::Append( const Z_String &str ) {
	if ( str.length > 0 ) {
		Concat( str.string, str.length );
	}
	return *this;
}

//******
//Append
// substring
//******
Z_String& Z_String::Append( const Z_String &str, const size_t &subpos, const size_t &sublen ) {
	if ( str.length > 0  && (subpos + sublen) <= str.length) {
		Concat( str.string + subpos, sublen );
	}
	return *this;
}

//******
//Append
// c-string
//******
Z_String& Z_String::Append( const char *cStr ) {
	if ( Strlen( cStr ) > 0 ) {
		Concat( cStr, Strlen( cStr ) );
	}
	return *this;
}

//******
//Append
// buffer
//******
Z_String& Z_String::Append( const char *cStr, const size_t &n ) {
	if ( Strlen( cStr ) > 0 ) {
		Concat( cStr, n );
	}
	return *this;
}

//******
//Append
// fill
//******
Z_String& Z_String::Append( const size_t &n, const char &c ) {
	if ( n > 0 ) {
		Concat( "c", n );

		memset( this->string, c, n );
		this->string[length] = '\0';
	} 
	return *this;
}

//******
//Assign (string)
//******
Z_String& Z_String::Assign( const Z_String &str ) {

}

//******
//Assign (substring)
//******
Z_String& Z_String::Assign( const Z_String &str, const size_t subpos, const size_t sublen = npos ) {

}

//******
//Assign (c-string)
//******
Z_String& Z_String::Assign( const INT8 *cStr ) {

}

//******
//Assign (buffer)
//******
Z_String& Z_String::Assign( const INT8 *cStr, const size_t n ) {

}

//******
//Assign (fill)
//******
Z_String& Z_String::Assign( size_t n, const INT8 &c ) {

}

//******
// Concat
//****** 
void Z_String::Concat( const INT8 *cStr, const size_t &len ) {
	if ( this->size == 0 ) {
		this->size += len * this->multiplier;
		this->string = DBG_NEW char[this->size];

	}
	else if ( this->size < this->length + len +1) {
		const INT8 *tmp = this->string;

		this->size += len * this->multiplier;
		this->string = DBG_NEW char[this->size];

		memcpy( this->string, tmp, this->length );

		delete tmp;
	}

	memcpy( string + this->length, cStr, len );
	this->length += len;
	string[this->length] = '\0';
}

//******
// Strlen
//****** 
size_t Z_String::Strlen( const INT8 *cStr ) const {
	size_t len = 0;
	while ( cStr[len] != '\0' ) {
		++len;
	}
	return len;
}
