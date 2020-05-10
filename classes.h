#include <iostream>

using namespace std;

class Printable
{
public:
		Printable(){}
		virtual std::string ToString() = 0; 
		friend std::ostream& operator<<( std::ostream &s, Printable const &obj );
};

std::ostream& operator<<( std::ostream &s, Printable &obj )
{
	std::string strout = obj.ToString();
    s << strout; 
    return s;
}

class Named: public virtual Printable
{
public:
		Named( std::string const &name ) 
		{ 
			m_name = name; 
		}

protected:
		std::string m_name;
};

class Shape : public virtual Printable

{
public:
		int GetCount()
		{ 
			return shapesCount; 
		}

		Shape() 
		{ 
			shapesCount++;
		}

		~Shape()
		{ 
			shapesCount--;
		}

protected:
		static int shapesCount;
};

int Shape::shapesCount = 0;

class Point : public Shape, Named
{
 static std::string statName;

public:
		Point(): Named(statName + std::to_string( GetCount() ) ){ X = Y = 0; }
		Point( float x, float y ): Named(statName + std::to_string( GetCount() ) ){ X = x;Y = y; }
   
 		virtual std::string ToString(); 

 		float get_x() 
		{ 
			return X; 
		}

 		float get_y() 
		{
			return Y; 
		}

		friend Point operator-( Point const &p1, Point const &p2 );
		float distance(Point &p);
protected:
		float X,Y;
};

 std::string Point::statName = "POINT";
 
std::string Point::ToString()
{ 
   std::stringstream out;
   out << m_name << '(' << X << ',' << Y << ')';
   return out.str();
}

float Point::distance( Point  &pt )
{
   float distX = X-pt.get_x();
   float distY = Y-pt.get_y();
   return sqrt( distX * distX + distY * distY );
}

Point operator-( Point  const &pt1, Point   const &pt2 )
{
	return Point( pt1.X - pt2.X, pt1.Y - pt2.Y );
}
 
class Circle : public Shape, Named
{
 public:
		 Circle( float x, float y, float radius): Named( "CIRCLE" ), Shape()
		 {
			 m_center = Point(x, y);
			 m_radius = radius;
		 }
 		virtual std::string ToString(); 

		float Area()
		{ 
			float PI = std::atan(1.0) * 4;
			return m_radius * m_radius * PI; 
		}

protected:
		Point m_center;
		float m_radius;
};

std::string Circle::ToString()
{ 
   std::stringstream out;
   out << m_name <<'('<< '(' << m_center.get_x() <<","<< m_center.get_y() <<')'<<",Radius:" << m_radius << ",Area:" << Area() << ')';
   return out.str();
}


class Rect : public Shape, Named
{
 public:
		 Rect( float left, float bottom, float width, float height ): Named("RECT"), Shape()
		{ 
			m_leftbot = Point( left, bottom ); 
			m_righttop = Point( left + width, bottom + height ); 
		}
		virtual std::string ToString(); 
		float Area(); 

protected:
		Point m_leftbot;
		Point m_righttop;
};

std::string Rect::ToString()
{
   std::stringstream out;
   out << m_name <<'('<<'('<< m_leftbot.get_x() << "," << m_leftbot.get_y() << ')' << ","<< '('<<m_righttop.get_x()<< ','<< m_righttop.get_y() << ')' << ",Area:" << Area() << ')';
   return out.str();
}

 float Rect::Area()
{ 
  Point d = m_righttop - m_leftbot; 

  return d.get_x() * d.get_y();
} 

class Square :public Shape, Named
{
 public:
 		Square( float left, float bottom, float width): Named( "SQUARE" ), Shape()
		{
			m_leftbottom = Point( left, bottom );
			m_width = width;
		}
		virtual std::string ToString(); 
protected:
		Point m_leftbottom;
		float m_width;

		float Area()
		{ 
			return m_width * m_width;
		}
};

std::string Square::ToString()
{
	std::stringstream out;
	out << m_name << '(' << '(' << m_leftbottom.get_x() << ',' << m_leftbottom.get_y() << ')';
	out << ',' << m_width << ",Area:"<< Area() << ')';
   	return out.str();
}


class Polyline : public Shape, Named
{
public:
		Polyline():Named( "POLYLINE" ), Shape() {}

		void AddPoint(Point const &point)
		{
			line.pushBack(point);
		}

		virtual std::string ToString(); 
		float Length(); 
protected:
		Container <Point> line; 
};


float Polyline::Length()
{
 	float leng = 0;
 	if( line.lenght() > 1 )
 	{
		for( unsigned int i = 0; i < line.lenght() - 1 ; i++ )
		{
	 		Point p1 = line[ i ];
	 		Point p2 = line[ i + 1 ];
			leng += p1.distance( p2 );
		}
	}
	 return leng;
 }

std::string Polyline::ToString()
{
	std::stringstream out;

	Point p;
	out << m_name << '(';
	for( unsigned int i = 0; i < line.lenght(); i++ )
	{
		p = line[ i ];
		out << p.ToString();
	}
	out << "Length:"<< Length() << ')';
   	return out.str();
}
 

class Polygon : public Shape, Named
{
 public:
 		Polygon():Named ("POLYGON" ), Shape(){}
 		void AddPoint(Point const &point);
 		virtual std::string ToString(); 
		float Perimeter();
protected:
		Container <Point> verts;
};

 void Polygon::AddPoint( Point const &point )
 {
 	verts.pushBack( point );
 }
 
std::string Polygon::ToString()
{
	std::stringstream out;
	Point p;
	out << m_name << '(';
	for( int i = 0; i < verts.lenght(); i++ )
	{
	    p = verts[ i ];
		out << p.ToString();
	}
	out << "Perimeter:" << Perimeter() << ')';
   	return out.str();
}

float Polygon::Perimeter()
{
 	float p = 0;
 	Point p1, p2;
 	int num = verts.lenght();
 	
 	if( num > 2 )
 	{
		for( int i = 0; i < num ; i++ )
		{
	 		p1 = verts[ i ];
	 		p2 = verts[ ( i+1 ) %num ];
			p += p1.distance( p2 );
		}
	}
	return p;
}
