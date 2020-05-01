using namespace std;

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "container.h"

int main()
{
	Container <int> vectorInteger;	    
	Container <double> vectorDouble( 10 );
	Container <string> vectorString;

	try
	{
		cout << "INT:" << '\n';
		
		vectorInteger.pushBack( -1 );
		vectorInteger.pushBack( 5 );
		vectorInteger.pushBack( 4 );
		vectorInteger.pushBack( 23 );
		vectorInteger.pushBack( -6 );
		vectorInteger.pushBack( -2 );
		vectorInteger.pushBack( 3 );
		vectorInteger.pushBack( 6 );
		vectorInteger.pushBack( 3 );
		vectorInteger.pushBack( -6 );

		cout << "Container of integers:";
		for ( int i = 0; i < vectorInteger.lenght(); i++ )
			std::cout << vectorInteger[ i ] << ' ';
		cout << endl;

		vectorInteger.popBack();
		vectorInteger.popBack();

		cout << "Delete last element from container:";
		for ( int i = 0; i < vectorInteger.lenght(); i++ )
			std::cout << vectorInteger[ i ] << ' ';
		cout << endl;

		cout << "Get element by index: " << vectorInteger.operator[]( 1 ) << endl;

		cout << "Row container size: " << vectorInteger.lenght() << endl;

		cout << "The row container is empty" << endl;
		vectorInteger.clear();

		cout << "Check for empty rows: " << vectorInteger.is_empty() << endl;
		vectorInteger.is_empty();

//--------------------------------------------------------------------------------------
		cout << "DOUBLE:" << '\n';
		
		double z = 0.1;

		for ( int i = 0; i < vectorDouble.lenght(); i++ )
		{
			vectorDouble[ i ] = z; z += z;
		}

		cout << "Container of double numbers:";
		for ( int i = 0; i < vectorDouble.lenght(); i++ ) 
			cout << vectorDouble[ i ] << ' ';

		cout << std::endl;

		vectorDouble.popBack();

		cout << "Delete last element:";
		for ( int i = 0; i < vectorDouble.lenght(); i++ )
			std::cout << vectorDouble[ i ] << ' ';
		cout << endl;

		cout << " Get element by index: " << vectorDouble.operator[](1) << endl;

		cout << "Row container size: " << vectorDouble.lenght() << endl;

		cout << "The row container is empty" << endl;
		vectorDouble.clear();

		cout << "Check for empty rows: " << vectorDouble.is_empty() << endl;
		vectorInteger.is_empty();
//------------------------------------------------------------------------------------------
		cout << "ROWS:" << '\n';
		
		 std::string str1 = "784"; 
		 std::string str2 = "361";
		 std::string str3 = "943";
		 std::string str4 = "183";
		 std::string str5 = "523";
		 std::string str6 = "254";
		 std::string str7 = "591";
		
		vectorString.pushBack(str1);
		vectorString.pushBack(str2);
		vectorString.pushBack(str3);
		vectorString.pushBack(str4);
		vectorString.pushBack(str5);
		vectorString.pushBack(str6);
		vectorString.pushBack(str7);

		cout << "Row container:";
		for ( int i = 0; i < vectorString.lenght(); i++ )
			cout << vectorString[ i ] << ',';
		cout << endl;

		vectorString.popBack();
		cout << "Delete last element:";

		for ( int i = 0; i < vectorString.lenght(); i++ )
			std::cout << vectorString[ i ] << ' ';
		cout << endl;

		cout << "Get element by index: " << vectorString.operator[](1) << endl;

		cout << "Row container size: " << vectorString.lenght() << endl;

		cout << "The row container is empty" << endl;
		vectorString.clear();

		cout << "Check for empty rows: " << vectorString.is_empty() << endl;
		vectorString.is_empty();
	}
	catch ( const std::string &msg )
	{
		std::cerr << msg << endl;
	}

	cout << endl;

	system( "pause" );

	return 0;
}