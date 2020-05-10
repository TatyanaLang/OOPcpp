#include <sstream>
#include "container.h"
#include "classes.h"
#include <time.h>
#include <iostream>

using namespace std;

Container <Shape*> Factory;

int random( int n = 50 )
{ 
	return rand() % ( n + 1 ); 
}

int SelectElem( int n )
{
	int id;
	while( true ) 
	{
		cin >> id;
		if( ( id > 0 && id <= n  ) && ( cin.peek() == '\n' ) )
		{ 
			cin.get();
			break; 
		}
	else
		{
		cout << "Error. Enter a number(from 1 to " << n << "):" << endl;
		cin.clear();
		while( cin.get() != '\n' ){}; 
		}
	}
	return id;
}

void ListOfShapes()
{
	int n = Factory.lenght();
	cout << endl << "List of shapes: " << endl << " " << endl;

if( n > 0 )
{
		for( int i = 0; i < n; i++ )
	{
		cout << *(Factory[ i ] ) << endl;;
	}
		cout << " " << endl;
		cout << "Number of all shapes: "<< Factory[ 0 ]->GetCount() << endl << endl << "------------------------" << endl;
}
else 
		cout << "The list is empty" << endl << "------------------------" << endl;
		cout << " " << endl;
}


void AddShape( void )
{ 
 	int id;
 	Shape *fShape; 
  	float x, y, wight, height, radius;
	unsigned int n;
	Polyline *pl;
	Polygon *pg;
	
		cout << endl << "Select shape:" << endl;
		cout << "1) Point" << endl;
		cout << "2) Circle" << endl;
		cout << "3) Rectangle" << endl;
		cout << "4) Square" << endl;
		cout << "5) Polyline" << endl;
		cout << "6) Polygon" << endl << "------------------------" << endl;
		id = SelectElem( 6 );
	
		switch( id )
		{
			case 1: 
					x = random();
					y = random();
					fShape = new Point( x, y ); 
					break;
			case 2: 
					x = random();
					y = random();
					radius = random();
					fShape = new Circle( x, y, radius);
					break;
			case 3:  
					x = random();
					y = random();
					wight = random();
					height = random();
					fShape = new Rect( x, y, x + wight, y + height);
					break;
			case 4: 
					x = random();
					y = random();
					wight = random();
					 fShape = new Square( 0, 0, wight);
					 break;
			case 5: 
					pl = new Polyline(); 
					n = rand() % 8 + 2;
					for( int i = 0; i < n; i++ )
					{ 
						x = random();
						y = random();
						pl->AddPoint( Point( x, y ) ); 
					}
					fShape = pl; 
					break; 
			case 6: 
					pg = new Polygon();
					n = rand() % 10 + 3;
					for( int i = 0; i < n; i++ )
					{
						x = random();
						y = random();
						pg->AddPoint( Point( x, y ) ); 
					}
					fShape = pg;
					break;
			default:
			{
				cout << "Impossible case" << endl;
			}
				return;
		}
		
		cout << *fShape << endl << "------------------------" << endl;
		Factory.pushBack( fShape );
}

int main()
{
	bool bQuit;
	int k;
	bQuit = false;
	srand( time( NULL ) ); 
	while( !bQuit )
	{
		cout << "1) List of added shapes" << endl;
		cout << endl << "2) Add shape" << endl;
		cout << endl << "3) Complete the program" << endl << "------------------------" << endl;

		k = SelectElem( 3 );
		switch(k)
		{
			case 1: ListOfShapes();
				break;
			case 2: AddShape();
				break;
			case 3: bQuit = true; 
				break;
		}
	}
return 0;
}