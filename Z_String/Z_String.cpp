#include "Z_String.h"

#include <string>
#include <cmath>

const int Z_String::npos = -1;

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
	INT8 arr[2];
	arr[0] = c;
	arr[1] = '\0';

	Concat( arr, 1 );
}

//******
//Constructor
//from c-string
//******
Z_String::Z_String( const INT8 *cStr ) {
	const int l = Strlen( cStr );
	if ( l > 0 ) {
		Concat( cStr, l );
	}
}

//******
//Constructor
//Copy (deep copy)
//Observe that no memory is not deleted, size will not be same as Z_String size parameter.
//******
Z_String::Z_String( const Z_String &str ) {
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
Z_String::Z_String( const Z_String& str, const size_t &pos, const size_t &len ) {
	if ( len > 0 && len <= str.length &&
		 pos >= 0 &&
		 pos + len <= str.length ) {

		Concat( str.string + pos, len );
	}
	else {
		throw std::out_of_range( "substring" );
	}
}

//******
//Constructor
//From buffer
//******
Z_String::Z_String( const INT8 *cStr, const size_t &len ) {
	if ( len > 0 && len <= Strlen( cStr ) ) {
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
Z_String::Z_String( const size_t &n, const INT8 &c ) {
	if ( n > 0 ) {
		INT8 arr[2];
		arr[0] = c;
		arr[1] = '\0';

		Concat( arr, n );

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
		delete[]string;
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
		Concat( cStr, Strlen( cStr ) );
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

	INT8 arr[2];
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
	Concat( cStr, Strlen( cStr ) );
	return *this;
}

//******
//oprator+=
//character
//******
Z_String& Z_String::operator += ( const INT8 &c ) {
	INT8 arr[2];
	arr[0] = c;
	arr[1] = '\0';

	Concat( arr, 1 );
	return *this;
}

//******
//oprator[]
//******
INT8& Z_String::operator[] ( const size_t &pos ) {
	return this->string[pos];
}

//******
//oprator[]
//const
//******
const INT8& Z_String::operator[] ( const size_t &pos ) const {
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
//Z_String& Z_String::operator + ( const INT8 *rhs ) {
//	Concat( rhs, Strlen(rhs) );
//	return *this;
//}
//
////******
////oprator+
////c-string
////******
//Z_String& Z_String::operator + ( const INT8 *rhs ) {
//	Concat( rhs, Strlen( rhs ) );
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
//Z_String& Z_String::operator + ( INT8 rhs ) {
//	INT8 arr[2];
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
//Z_String& Z_String::operator + ( INT8 rhs ) {
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
////INT8acter
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

		}
		else if ( i == 3 ) {
			buffer[3] = '\0';
			Concat( buffer, i );

			i = 0;
		}
	}

	buffer[i - 1] = '\0';
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
//bool Z_String::operator <= ( const INT8* rhs ) {
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
//bool Z_String::operator >  ( const INT8 *rhs ) {
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
//bool Z_String::operator >= ( const INT8* rhs ) {
//
//}

//******
//C_Str
//****** 
const INT8* Z_String::C_Str() const _NOEXCEPT {
	return this->string;
}

//******
//Data
//****** 
const INT8* Z_String::Data() const _NOEXCEPT {
	return this->string;
}

//******
//Copy
//****** 
size_t Z_String::Copy( INT8 *cStr, const size_t &len, const size_t &pos ) const {
	if ( Strlen( cStr ) > 0 && ( pos + len ) <= this->length ) {
		memcpy( cStr, this->string + pos, len );
		return len;
	}
	return 0;
}

//******
//Clear
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
//Back
//****** 
INT8 Z_String::Back() {
	return Internal_Back();
}

//******
//Back
//****** 
const INT8 Z_String::Back() const {
	return Internal_Back();
}

//******
//Front
//****** 
INT8& Z_String::Front() {
	if ( this->length > 0 ) {
		return this->string[0];
	}
}

//******
//Front
//****** 
const INT8& Z_String::Front() const {
	if ( this->length > 0 ) {
		return this->string[0];
	}
}

INT8& Z_String::At( const size_t &pos ) {
	return Internal_At( pos );
}

const INT8& Z_String::At( const size_t &pos ) const {
	return Internal_At( pos );
}

//******
//Compare 
//string
//this->string == rhs.string return 0;
//this->string <= rhs.string return -1;
//this->string >= rhs.string return 1;
//******
size_t Z_String::Compare( const Z_String &str ) const _NOEXCEPT {
	return StrCmp( this->string, str.string );
}

//******
//Compare
//substring
//obj.string == str.string return 0;
//obj.string <= str.string return -1;
//obj.string >= str.string return 1;
//******
size_t Z_String::Compare( const size_t &pos, const size_t &len, const Z_String &str ) const {
	Z_String tmp( str.string + pos, len );
	return StrCmp( this->string, tmp.string );
}

//******
//Compare 
//substring
//obj.string == str.string return 0;
//obj.string <= str.string return -1;
//obj.string >= str.string return 1;
//******
size_t Z_String::Compare( const size_t &lhsPos, const size_t &lhsLen, const Z_String &rhsStr, const size_t &rhsPos, const size_t &rhsLen ) const {
	Z_String tmpRhs( rhsStr.string + rhsPos, rhsLen );
	Z_String tmpLhs( this->string + lhsPos, lhsLen );
	return StrCmp( tmpLhs.string, tmpRhs.string );
}

//******
//Compare 
//c-string
//obj.string == str.string return 0;
//obj.string <= str.string return -1;
//obj.string >= str.string return 1;
//******
size_t Z_String::Compare( const INT8* cStr ) const {
	return StrCmp( this->string, cStr );
}

//******
//Compare 
//c-string
//obj.string == str.string return 0;
//obj.string <= str.string return -1;
//obj.string >= str.string return 1;
//******
size_t Z_String::Compare( const size_t &pos, const size_t &len, const INT8 *cStr ) const {
	Z_String tmp( cStr + pos, len );
	return StrCmp( this->string, tmp.string );
}

//******
//Compare 
//buffer
//obj.string == str.string return 0;
//obj.string <= str.string return -1;
//obj.string >= str.string return 1;
//******
size_t Z_String::Compare( const size_t &pos, const size_t &len, const INT8 *cStr, const size_t &n ) const {
	throw std::out_of_range( "Function is not implemented!!!" );
	return 0; //This function makes no sence, both len and n as parameters in functionhead, why? We already has Compare for c-string!
}

//******
//Length
//******
size_t Z_String::Length() const {
	return this->length;
}

//******
//Append
//string
//******
Z_String& Z_String::Append( const Z_String &str ) {
	return Internal_Append( str.string, str.length );
}

//******
//Append
//substring
//******
Z_String& Z_String::Append( const Z_String &str, const size_t &subpos, const size_t &sublen ) {
	if ( ( subpos + sublen ) <= str.length ) {
		return Internal_Append( str.string + subpos, sublen );
	}
	return *this;
}

//******
//Append
//c-string
//******
Z_String& Z_String::Append( const INT8 *cStr ) {
	return Internal_Append( cStr, strlen(cStr) );
}

//******
//Append
//buffer
//******
Z_String& Z_String::Append( const INT8 *cStr, const size_t &n ) {
	if ( n >= 0 && n <= Strlen( cStr ) ) {
		return Internal_Append( cStr, n );
	}
	return *this;
}

//******
//Append
//fill
//******
Z_String& Z_String::Append( const size_t &n, const INT8 &c ) {
	if ( n >= 0 ) {
		INT8 arr[2];
		arr[0] = c;
		arr[1] = '\0';

		Concat( arr, n );

		const int len = Abs( this->length - n );

		memset( this->string + len, c, n );
		this->string[length] = '\0';
	}
	return *this;
}

//******
//Assign 
//string
//Assigns a new value to the string, replacing its current contents.
//******
Z_String& Z_String::Assign( const Z_String &str ) {
	return Internal_Assign( str.string, str.length );
}

//******
//Assign 
//substring
//Assigns a new value to the string, replacing its current contents.
//******
Z_String& Z_String::Assign( const Z_String &str, const size_t &subpos, const size_t &sublen ) {
	if ( ( subpos + sublen ) <= str.length ) {
		return Internal_Assign( str.string + subpos, sublen );
	}
	return *this;
}

//******
//Assign 
//c-string
//Assigns a new value to the string, replacing its current contents.
//******
Z_String& Z_String::Assign( const INT8 *cStr ) {
	return Internal_Assign( cStr, strlen( cStr ) );
}

//******
//Assign
//buffer
//Assigns a new value to the string, replacing its current contents.
//******
Z_String& Z_String::Assign( const INT8 *cStr, const size_t &n ) {
	return Internal_Assign( cStr, n );
}

//******
//Assign
//fill
//Assigns a new value to the string, replacing its current contents.
//******
Z_String& Z_String::Assign( const size_t &n, const INT8 &c ) {
	if ( n >= 0 ) {
		INT8 arr[2];
		arr[0] = c;
		arr[1] = '\0';

		Concat( arr, n );

		memset( this->string, c, n );
		this->string[length] = '\0';
	}
	return *this;
}

//******
//Swap
//****** 
void Z_String::Swap( Z_String &str ) {
	Z_String tmp( *this );
	*this = str;
	str = tmp;
}

//******
//SubStr
//****** 
Z_String Z_String::SubStr( const size_t pos, const size_t len ) const {
	int newLen = len;

	if ( pos == this->length ) {
		return Z_String( "" );

	}
	else if ( ( pos + len ) > this->length ) {
		newLen = pos - this->length;

		if ( -newLen ) {
			throw std::out_of_range( "Substr, pos is greater then string length" );
		}
	}

	return Z_String( this->string, pos, newLen );
}

//******
//Size
//****** 
size_t Z_String::Size() const {
	return this->size;
}

//******
//Shrink_To_fit
//Decreases the size and make it eqaul to length.
//******
void Z_String::Shrink_To_Fit() {
	Internal_Shrink_To_Fit(this->length);
}

//******
//Find
//string
//****** 
size_t Z_String::Find( const Z_String &str ) const _NOEXCEPT {
	return Internal_Find( str.string, 0 );
}

//******
//Find
//c-string
//****** 
size_t Z_String::Find( const INT8 *cStr ) const {
	return Internal_Find( cStr, 0 );
}

//******
//Find
//buffer
//****** 
size_t Z_String::Find( const INT8 *cStr, const size_t &pos, const size_t &n ) const {
	Z_String tmp( cStr, pos, n );
	return Internal_Find( tmp.string, 0 );
}

//******
//Find
//character
//****** 
size_t Z_String::Find( const INT8 &c ) const _NOEXCEPT {
	INT8 arr[2];
	arr[0] = c;
	arr[1] = '\0';

	return Internal_Find( arr, 0 );
}

//******
//RFind
//string
//****** 
size_t Z_String::RFind( const Z_String &str ) const _NOEXCEPT {
	return Internal_Find( str.string, str.length );
}

//******
//RFind
//c-string
//****** 
size_t Z_String::RFind( const INT8 *cStr ) const {
	return Internal_Find( cStr, Strlen( cStr ) );
}

//******
//RFind
//buffer
//****** 
size_t Z_String::RFind( const INT8 *cStr, const size_t &pos, const size_t &n ) const {
	Z_String tmp( cStr, pos, n );
	return Internal_Find( tmp.string, tmp.length );
}

//******
//RFind
//character
//****** 
size_t Z_String::RFind( const INT8 &c ) const _NOEXCEPT {
	INT8 arr[2];
	arr[0] = c;
	arr[1] = '\0';

	return Internal_Find( arr, 1 );
}

//******
//Resize
//****** 
void Z_String::Resize( const size_t &n ) {
	Internal_Resize( n, 'c' );
}

//******
//Resize
//****** 
void Z_String::Resize( const size_t &n, const char &c ) {
	Internal_Resize( n, c );
}

//******
//Reserve
//******
void Z_String::Reserve( const size_t &n ) {
	if ( n > this->length ) {
		const INT8 *tmp = this->string;

		this->size = n;
		this->string = DBG_NEW INT8[this->size];

		memcpy( this->string, tmp, this->length );
		this->string[this->length] = '\0';

		delete tmp;
	}
	else {
		Internal_Shrink_To_Fit(n);
	}
}

//******
//Replace
//String
//****** 
Z_String& Z_String::Replace( const size_t &pos, const size_t &len, const Z_String &str ) {
	return Internal_Replace( pos, len, str.string, str.length, 0 );
}

//******
//Replace
//substring
//****** 
Z_String& Z_String::Replace( const size_t &pos, const size_t &len, const Z_String &subStr, const size_t &subPos, const size_t &subLen ) {
	return Internal_Replace(pos, len, subStr.string, subLen, subPos);
}

//******
//Replace
//c-string
//****** 
Z_String& Z_String::Replace( const size_t &pos, const size_t &len, const char *subStr ) {
	return Internal_Replace( pos, len, subStr, Strlen(subStr ), 0 );
}

//******
//Replace
//buffer
//****** 
Z_String& Z_String::Replace( const size_t &pos, const size_t &len, const char *subStr, const size_t &n ) {
	return Internal_Replace( pos, len, subStr, n, 0 );
}

//******
//Replace
//fill
//****** 
Z_String& Z_String::Replace( const size_t &pos, const size_t &len, const char &subC, const size_t &n ) {
	char arr[1];
	arr[0] = subC;
	arr[1] = '\0';

	return Internal_Replace( pos, len, arr, n, 0 );
}

//******
//Push_Back
//****** 
void Z_String::Push_Back( const char &c ) {
	char arr[2];
	arr[0] = c;
	arr[1] = '\0';
	Concat( arr, 1 );
}

//******
//Pop_Back
//****** 
void Z_String::Pop_Back() {
	this->length -= 1;
	this->string[this->length] = '\0';
}

//******
//Max_size
//******
size_t Z_String::Max_Size() const _NOEXCEPT {
	return maxSize;
}

//******
//Concat
//****** 
void Z_String::Concat( const INT8 *cStr, const size_t &len ) {
	if ( this->size == 0 ) {
		this->size += len * this->multiplier;
		this->string = DBG_NEW INT8[this->size];

	}
	else if ( this->size < this->length + len + 1 ) {
		const INT8 *tmp = this->string;

		this->size += len * this->multiplier;
		this->string = DBG_NEW INT8[this->size];

		memcpy( this->string, tmp, this->length );

		delete tmp;
	}

	memcpy( string + this->length, cStr, len );
	this->length += len;
	this->string[this->length] = '\0';
}

//******
//Strlen
//****** 
size_t Z_String::Strlen( const INT8 *cStr ) const {
	int len = 0;
	while ( cStr[len] != '\0' ) {
		++len;
	}
	return len;
}

//******
//Abs
//****** 
size_t Z_String::Abs( const int  &value ) const {
	if ( value < 0 ) {
		return -value;
	}
	return value;
}

//******
//StrCmp
//lhs == rhs return 0;
//lhs <= rhs return -1;
//lhs >= rhs return 1;
//****** 
size_t Z_String::StrCmp( const INT8 *cStr1, const INT8 *cStr2 ) const {
	int s1;
	int s2;
	do {
		s1 = *cStr1++;
		s2 = *cStr2++;
		if ( s1 == 0 )
			break;
	} while ( s1 == s2 );
	int i = ( s1 < s2 ) ? -1 : ( s1 > s2 );
	return i;
}

//******
//Internal_At
//******
INT8& Z_String::Internal_At( const size_t &pos ) const {
	if ( pos > this->length ) {
		throw std::out_of_range( "AT" );
	}
	return this->string[pos];
}

//******
//Internal_Back
//******
INT8 Z_String::Internal_Back() const {
	if ( this->size > 0 && this->length > 0 ) {
		return this->string[this->length - 1];
	}
	throw std::out_of_range( "String is empty!" );
}

//******
//Internal_Assign
//******
Z_String& Z_String::Internal_Assign( const INT8 *cStr, const size_t &len ) {
	if ( len > 0 ) {
		this->length = 0;
		Concat( cStr, len );
	}
	return *this;
}

//******
//Internal_Find
//******
size_t Z_String::Internal_Find( const char *cStr, const size_t &offset ) const {
	if (cStr && this->string > 0 ) {
		const char *isFound = strstr( this->string, cStr );
		if ( isFound ) {
			return Abs( this->string - (isFound + offset) );
		}
	}

	return npos;
}

//******
//Internal_Append
//******
Z_String& Z_String::Internal_Append( const INT8 *cStr, const size_t &len ) {
	if ( len > 0 ) {
		Concat( cStr, len );
	}
	return *this;
}

//******
//Internal_Resize
//******
void Z_String::Internal_Resize( const size_t n, const char &c ) {
	if ( n > this->length ) {
		INT8 arr[2];
		arr[0] = c;
		arr[1] = '\0';

		Concat( arr, n );

		const int len = Strlen( this->string );
		memset( this->string + len, c, n - len );
		
		this->length = n;
		this->string[length] = '\0';
	}
	else {
		this->length = n;
		this->string[n] = '\0';
	}
}

//******
//Internal_Shrink_To_Fit
//******
void Z_String::Internal_Shrink_To_Fit(const size_t &n) {
	if ( this->size > 1 ) {
		const INT8 *tmp = this->string;

		this->size = n + 1;
		this->length = this->size -1;
		this->string = DBG_NEW INT8[this->size];

		memcpy( this->string, tmp, this->length );
		this->string[this->length] = '\0';

		delete tmp;
	}
}

Z_String& Z_String::Internal_Replace( const size_t &startPos, const size_t &len, const char *subStr, const size_t &subLen, const size_t &subStartPos ) {
	if ( subStr && this->length > 0 ) {
		if ( startPos > this->length || subStartPos > subLen ) {
			throw std::out_of_range( "Internal_Replace" );
		}
		else {
			Z_String str;
			str.Append( this->string, startPos );
			str.Append( subStr + subStartPos, subLen );
			str.Append( this->string + startPos + len );

			*this = str;
		}
	}
	return *this;
}
