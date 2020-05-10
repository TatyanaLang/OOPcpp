#include <iostream>

template <typename T>
class Container
{
public:
	Container();
	Container( unsigned int );
	void pushBack( const T& );
	void popBack();
	T& operator[] ( int i );
	int lenght();
	bool is_empty();
	void clear();
	T *m_data;
	unsigned int m_size;
	int m_last;
	unsigned int m_pr_size;
	unsigned int m_capacity;
protected:
	void allocate();
protected:
};

template <typename T>
Container<T>::Container()
{
	m_data = NULL;
	m_size = 0;
	m_last = -1;
	m_pr_size = 5;
	m_capacity = 0;
}

template <typename T>
Container<T>::Container( unsigned int k )
{
	m_data = new T[k]();
	m_last = k - 1;
	m_size = k;
}

template <typename T>
void Container <T>::pushBack( T const &data )
{
	if (( m_last + 1 ) >= m_size )
	{
		allocate();
	}
	m_data[ ++m_last ] = data;
}

template <typename T>
void Container <T>::popBack()
{
	if ( m_last >= 0 ) m_last--;
}

template <typename T>
T& Container <T>::operator[] ( int index )
{
	if ( index < 0 || index > m_last )
		throw std::runtime_error( "error index: " + std::to_string( index ) );
	return m_data[ index ];
}

template <typename T>
void Container <T>::allocate()
{
	T *ptr = new T[ m_size + m_pr_size ];

	for ( int i = 0; i < m_size; i++ )
		ptr[ i ] = m_data[ i ];

	delete[] m_data;

	m_size += m_pr_size;

	m_data = ptr;
}

template <typename T>
int  Container <T>::lenght()
{
	return ( m_last + 1 );
}

template <typename T>
bool Container <T>::is_empty()
{
	return ( m_last < 0 );
}

template <typename T>
void Container <T>::clear()
{
	m_last = -1;
}
