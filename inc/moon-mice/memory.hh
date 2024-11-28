#ifndef MOONMICE_MEMORY_HH
#define MOONMICE_MEMORY_HH

#include <moon-mice\type.hh>


namespace moonmice
{
    enum nothrow_tag
    {
        nothrow
    };
}


void * operator new  ( moonmice::usize size );
void * operator new[]( moonmice::usize size );

void * operator new  ( moonmice::usize size, moonmice::align alignment );
void * operator new[]( moonmice::usize size, moonmice::align alignment );


void * operator new  ( moonmice::usize size, moonmice::nothrow_tag tag ) noexcept;
void * operator new[]( moonmice::usize size, moonmice::nothrow_tag tag ) noexcept;

void * operator new  ( moonmice::usize size, moonmice::align alignment, moonmice::nothrow_tag tag ) noexcept;
void * operator new[]( moonmice::usize size, moonmice::align alignment, moonmice::nothrow_tag tag ) noexcept;


void * operator new  ( moonmice::usize size, void * spot ) noexcept;
void * operator new[]( moonmice::usize size, void * spot ) noexcept;




void operator delete  ( void * spot ) noexcept;
void operator delete[]( void * spot ) noexcept;

void operator delete  ( void * spot, moonmice::usize size ) noexcept;
void operator delete[]( void * spot, moonmice::usize size ) noexcept;

void operator delete  ( void * spot, void * object ) noexcept;
void operator delete[]( void * spot, void * object ) noexcept;


#endif