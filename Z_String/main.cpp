#include <iostream>

#include "Z_String.h"
#include <cassert>

int main() {
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

	//Constructors.
	Z_String string1( "hello world how are you? I'm fine" );
	Z_String string2( 'c' );
	Z_String string3( "newString" );
	Z_String string4( string3 );

	const char *cStr = "hej pa dig min van";

	Z_String string5( cStr, 4, 5 );

	Z_String string6( cStr + 15, 3 );

	Z_String string7( 10, 'c' );

	//operator =.
	string3 = string1;
	string1 = cStr;
	string1 = 'j';

	//operator +=
	string1 = "f";
	string1 += string3;
	string1 += cStr;
	string1 += 'g';

	//operator []
	string3 = "newString";
	const char first = string3[0];
	const char last = string3[9];

	Z_String string10 = "";
	std::cin >> string10;
	std::cout << string10;

	system( "pause" );
	return 0;
}