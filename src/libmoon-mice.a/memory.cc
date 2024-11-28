#include <moon-mice\exception.hh>
#include <moon-mice\memory.hh>
#include <moon-mice\byte.hh>

#if defined _WIN32
#   include <windows.h>
#endif


#if defined _WIN32
namespace moonmice::ini
{
    byte * reserve( usize  size ) noexcept
    {
        return static_cast<byte *>( HeapAlloc( GetProcessHeap( ), 0, size ) );
    }

    byte * dispose( byte * spot ) noexcept
    {
        HeapFree( GetProcessHeap( ), 0, spot );

        return nullptr;
    }


    byte * reserve_aligned( usize  size, align alignment ) noexcept
    {
        size += alignment - 1;
        size += sizeof( void * );

        uintp address = 0;
        uintp  origin = reinterpret_cast<uintp>( HeapAlloc( GetProcessHeap( ), 0, size ) );
        uintp    mask = ~( alignment - 1 );


        if( origin != 0 )
        {
            address += origin + alignment - 1;
            address &= mask;

            reinterpret_cast<uintp *>( address - sizeof( void * ) )[ 0 ] = origin;
        }

        return reinterpret_cast<byte *>( address );
    }

    byte * dispose_aligned( byte * spot ) noexcept
    {
        uintp origin = reinterpret_cast<uintp *>( spot - sizeof( void * ) )[ 0 ];

        HeapFree( GetProcessHeap( ), 0, reinterpret_cast<LPVOID>( origin ) );

        return nullptr;
    }
}
#endif


using namespace moonmice;


void * operator new  ( usize size )
{
    auto point = ini::reserve( size );

    if( not point )
    {
        moonmice_throw( FAIL_NOT_ENOUGH_MEMORY );
    }

    return point;
}
void * operator new[]( usize size )
{
    auto point = ini::reserve( size );

    if( not point )
    {
        moonmice_throw( FAIL_NOT_ENOUGH_MEMORY );
    }

    return point;
}


void * operator new  ( usize size, align alignment )
{
    auto point = ini::reserve_aligned( size, alignment );

    if( not point )
    {
        moonmice_throw( FAIL_NOT_ENOUGH_MEMORY );
    }

    return point;
}
void * operator new[]( usize size, align alignment )
{
    auto point = ini::reserve_aligned( size, alignment );

    if( not point )
    {
        moonmice_throw( FAIL_NOT_ENOUGH_MEMORY );
    }

    return point;
}


void * operator new  ( usize size, nothrow_tag tag ) noexcept
{
    static_cast<void>( tag );


    auto point = ini::reserve( size );

    return point;
}
void * operator new[]( usize size, nothrow_tag tag ) noexcept
{
    static_cast<void>( tag );


    auto point = ini::reserve( size );

    return point;
}


void * operator new  ( usize size, align alignment, nothrow_tag tag ) noexcept
{
    static_cast<void>( tag );


    auto point = ini::reserve_aligned( size, alignment );

    return point;
}
void * operator new[]( usize size, align alignment, nothrow_tag tag ) noexcept
{
    static_cast<void>( tag );


    auto point = ini::reserve_aligned( size, alignment );

    return point;
}


void * operator new  ( usize size, void * spot ) noexcept
{
    static_cast<void>( size );


    return spot;
}
void * operator new[]( usize size, void * spot ) noexcept
{
    static_cast<void>( size );


    return spot;
}




void operator delete  ( void * spot ) noexcept
{
    ini::dispose( static_cast<moonmice::byte *>( spot ) );
}
void operator delete[]( void * spot ) noexcept
{
    ini::dispose( static_cast<moonmice::byte *>( spot ) );
}


void operator delete  ( void * spot, usize size ) noexcept
{
    static_cast<void>( size );


    ini::dispose( static_cast<moonmice::byte *>( spot ) );
}
void operator delete[]( void * spot, usize size ) noexcept
{
    static_cast<void>( size );


    ini::dispose( static_cast<moonmice::byte *>( spot ) );
}


void operator delete  ( void * spot, void * object ) noexcept
{
    static_cast<void>(   spot );
    static_cast<void>( object );
}
void operator delete[]( void * spot, void * object ) noexcept
{
    static_cast<void>(   spot );
    static_cast<void>( object );
}