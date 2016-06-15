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
	int len = string1.Copy( buffer, 2, 3 );
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

	//function Compare
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

	//function Swap
	string1 = "hello world";
	string2 = "babar";
	string1.Swap( string2 );
	Assert_String( string1.Data(), "babar", "function Swap" );
	Assert_String( string2.Data(), "hello world", "function Swap" );

	string1 = "hello world";
	string2.Clear();
	string1.Swap( string2 );
	Assert_String( string1.Data(), "", "function Swap" );
	Assert_String( string2.Data(), "hello world", "function Swap" );


	//function SubStr
	string1 = "hello babar";
	string2 = string1.SubStr( 4, 6 );
	Assert_String( string2.Data(), "o baba", "function SubStr" );

	string2 = string1.SubStr( 11, 6 );
	Assert_String( string2.Data(), "", "function SubStr" );

	//Uncomment to test!
	//string2 = string1.SubStr( 12, 6 );
	//Assert_String( string2.Data(), "", "function SubStr(throws out_of_range)" );

	//function Shrink_To _Fit and function Size().
	string1 = "babar is home in bed, he is to lazy to get out of bed :)";
	string1.Shrink_To_Fit();
	Assert_String( string1.Size(), 57, "function Shrink_To_Fit" );

	//function Find
	string1 = "lazy";
	string2 = "babar is home in bed, he is to lazy to get out of bed :)";
	Assert_String( string2.Find(string1), 31, "function Find(string)" );

	Assert_String( string2.Find( "home" ), 9, "function Find(c-string)" );

	Assert_String( string2.Find( "he is to lazy to", 9, 4 ), 31, "function Find(buffer)" );

	Assert_String( string2.Find( 'e' ), 12, "function Find(character)" );

	//function RFind
	string1 = "lazy";
	string2 = "babar is home in bed, he is to lazy to get out of bed :)";
	Assert_String( string2.RFind( string1 ), 35, "function Find(string)" );

	Assert_String( string2.RFind( "home" ), 13, "function Find(c-string)" );

	Assert_String( string2.RFind( "he is to lazy to", 9, 4 ), 35, "function Find(buffer)" );

	Assert_String( string2.RFind( 'e' ), 13, "function Find(character)" );

	//function Resize
	string2 = "babar is home in bed, he is to lazy to get out of bed :)";
	string2.Resize( 5 );
	Assert_String( string2.Data(), "babar", "function Resize(n)" );
	
	string2.Resize( 10, 'c' );
	Assert_String( string2.Data(), "babarccccc", "function Resize(n, c)" );

	string2 = "babar is home in bed, he is to lazy to get out of bed :)";
	string2.Reserve( 10 );
	Assert_String( string2.Capacity(), 11, "function Reserve" );

	int cap = string2.Capacity() * 4; //this->size += len * this->multiplier;
	string2.Reserve( cap );
	Assert_String( string2.Capacity(), 44 , "function Reserve" );

	//function Replace
	string1 = "kalle is in his car, he is trying to get out";
	string2 = "house";
	string1.Shrink_To_Fit();
	string1.Replace( 16, 3, string2 );
	Assert_String( string1.Data(), "kalle is in his house, he is trying to get out", "funiction Replace string" );

	string1 = "kalle is in his car, he is trying to get out";
	string2 = "house";
	string1.Replace( 16, 3, string2, 0, 5 );
	Assert_String( string1.Data(), "kalle is in his house, he is trying to get out", "funiction Replace substring" );

	string1 = "kalle is in his car, he is trying to get out";
	string2 = "house";
	string1.Replace( 16, 3, string2.C_Str() );
	Assert_String( string1.Data(), "kalle is in his house, he is trying to get out", "funiction Replace c-string" );

	string1 = "kalle is in his car, he is trying to get out";
	string2 = "house";
	string1.Replace( 16, 3, string2.C_Str(), 5 );
	Assert_String( string1.Data(), "kalle is in his house, he is trying to get out", "funiction Replace buffer" );

	string1 = "kalle is in his car, he is trying to get out";
	string2 = "house";
	string1.Replace( 16, 3, string2.C_Str(), 5 );
	Assert_String( string1.Data(), "kalle is in his house, he is trying to get out", "funiction Replace fill" );

	//function Max_size
	Assert_String( string1.Max_Size(), INT_MAX / 2, "function Max_Size" );

	//function Push_Back
	string1 = "kalle";
	string1.Push_Back( 's' );
	Assert_String( string1.Data(), "kalles", "function Push_Back" );

	//function Pop_Back
	string1 = "kalles";
	string1.Pop_Back();
	Assert_String( string1.C_Str(), "kalle", "function Pop_Back" );

	//Front
	string1 = "nisse";
	Assert_String( string1.Front(), 'n', "function Front" );

	string1.Front() = 'p';
	Assert_String( string1.C_Str(), "pisse", "function Front" );

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