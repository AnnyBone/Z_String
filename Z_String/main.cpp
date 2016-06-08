#include <iostream>

#include "Z_String.h"

void Assert_String( const INT8 *cStr1, const INT8 *cStr2, const INT8 *errMsg );
void Assert_String( const int val1, const int val2, const INT8 *errMsg );
void Assert_String( const INT8 &c1, const INT8 c2, const INT8 *errMsg );

int main() {
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

	//Constructor
	Z_String string2( "hello world how are you? I'm fine" );
	Assert_String( string2.Data(), "hello world how are you? I'm fine", "constructor c-string" );

	Z_String string3( 'c' );
	Assert_String( string3.Data(), "c", "constructor INT8" );

	Z_String string4( string2 );
	Assert_String( string4.Data(), "hello world how are you? I'm fine", "constructor copy" );

	const INT8 *cStr = "hej pa dig min van";
	Z_String string5( cStr, 4, 5 );
	Assert_String( string5.Data(), "pa di", "constructor substring" );

	Z_String string6( cStr + 9, 3 );
	Assert_String( string6.Data(), "g m", "constructor sequence" );
	
	Z_String string7( 10, 'c' );
	Assert_String( string7.Data(), "cccccccccc", "constructor fill" );

	Z_String();
	Z_String string1;
	string1 = "string";
	Assert_String( string1.Data(), "string", "function Data();" );
	Assert_String( string1.C_Str(), "string", "function C_Str();" );

	//function Copy()
	INT8 buffer[20];
	size_t len = string1.Copy( buffer, 2, 3 );
	buffer[len] = '\0';
	Assert_String( buffer, "in", "function Copy();" );
	
	Assert_String( string1.Back(), 'g', "function Back();" );

	Assert_String( string1.Capacity(), 18, "function Capacity()");

	//function Clear()
	string1.Clear();
	Assert_String( string1.C_Str(), "", "function Clear();" );

	//function At()
	string1 = "test string";
	Assert_String( string1.At( 3 ), 't', "function At();" );

	//function Append()
	string2 = " for testing!";
	string1.Append( string2 );
	Assert_String( string1.Data(), "test string for testing!", "function Append(string);" );
	string1.Clear();

	string1.Append( string2, 5, 7 );
	Assert_String( string1.C_Str(), "testing", "function Append(substring)" );
	string1.Clear();

	string1.Append( "hello World" );
	Assert_String( string1.Data(), "hello World", "function Append(c-string" );
	string1.Clear();

	string1.Append( "hello world", 5 );
	Assert_String( string1.Data(), "hello", "function Append(buffer" );

	string1.Append( 5, 'v' );
	Assert_String( string1.Data(), "hellovvvvv", "function Append(fill)" );

	//function Assign()
	string2 = "hello world";
	string1.Assign( string2 );
	Assert_String( string1.Data(), "hello world", "function Assign(string)" );

	string2 = "hello world";
	string1.Assign( string2, 4, 5 );
	Assert_String( string1.Data(), "o wor", "function Assign(substring)" );

	string1.Assign( "hello world" );
	Assert_String( string1.Data(), "hello world", "function Assign(c-string)" );

	string1.Assign( "hello world", 6 );
	Assert_String( string1.Data(), "hello ", "function Assign(buffer)" );

	string1.Assign( 6, 'g' );
	Assert_String( string1.Data(), "ggggggg", "function Assign(fill)" );

	string1 = "hello world";
	string2 = "hello world";
	Assert_String( string1.Compare( string2 ), 0, "function Compare(string) = 0" );

	//Compare
	string1.Clear();
	string2.Clear();
	Assert_String( string1.Compare( string2 ), 0, "function Compare(string) = 0" );

	string1 = "hello world";
	string2 = "";
	Assert_String( string1.Compare( string2 ), 1, "function Compare(string) = -1" );

	string1 = "hello worldd";
	string2 = "hello world";
	Assert_String( string1.Compare( string2 ), 1, "function Compare(string) = 1" );

	string1 = "hello worl";
	string2 = "hello world";
	Assert_String( string1.Compare( string2 ), -1, "function Compare(string) = -1" );

	string1 = "";
	string2 = "hello world";
	Assert_String( string1.Compare( string2 ), -1, "function Compare(string) = 1" );

	string1 = "world";
	string2 = "hello world";
	Assert_String( string1.Compare( 6, 5, string2 ), 0, "function Compare(substring) = 0" );

	string1 = "world hello";
	string2 = "hello world";
	Assert_String( string1.Compare( 0, 5, string2, 6, 5 ), 0, "function Compare(substring) = 0" );

	string1 = "hello world";
	Assert_String(string1.Compare("hello world"), 0, "function Compare(c-string) = 0");

	string1 = " world";
	Assert_String( string1.Compare( 5, 6, "hello world" ), 0, "function Compare(c-string) = 0" );




	//operator =.
	string2 = cStr; //"hej pa dig min van"
	Assert_String( string2.Data(), "hej pa dig min van", "operator = (c-string)" );

	string1 = string2;
	Assert_String( string1.Data(), "hej pa dig min van", "operator = (string)" );

	string1 = 'j';
	Assert_String( string1.Data(), "j", "operator = (character)" );

	//operator +=
	string2 = "rue";
	string1 = "t";
	string1 += string2;
	Assert_String( string1.Data(), "true", "operator += (string)" );

	string1 += ", is it? ";
	Assert_String( string1.Data(), "true, is it? ", "operator += (c-string)" );

	string1 += 'y';
	Assert_String( string1.Data(), "true, is it? y", "operator += (character)" );

	//operator []
	string1 = "new string";
	Assert_String( string1[0], 'n', "operator [] (character) first" );
	Assert_String( string1[9], 'g', "operator [] (character) last" );


	//Input/output console window (uncomment to test).
	//string1.Clear();
	//std::cin >> string1;
	//std::cout << string1;

	system( "pause" );
	return 0;
}

void Assert_String( const INT8 *cStr1, const INT8 *cStr2, const INT8 *errMsg ) {
	if ( strcmp( cStr1, cStr2 ) == 0 ) {
		//They are the same.
		return;
	} 
	throw std::out_of_range( errMsg );
}

void Assert_String( const int val1, const int val2, const INT8 *errMsg ) {
	if ( val1 == val2 ) {
		//They are the same.
		return;
	}
	throw std::out_of_range( errMsg );
}

void Assert_String( const INT8 &c1, const INT8 c2, const INT8 *errMsg ) {
	if ( c1 == c2 ) {
		//They are the same.
		return;
	}
	throw std::out_of_range( errMsg );
}