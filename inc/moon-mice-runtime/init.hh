#ifndef MOON_MICE_RUNTIME_INIT_HH
#define MOON_MICE_RUNTIME_INIT_HH

#include <moon-mice\type.hh>


// This is needed for a 'atexit' stuff and some startup initialization.
namespace moonmice::runtime
{
    extern "C" using  obj = void *;
    extern "C" using  lib = void *;
    extern "C" using func = void( * )( );
    extern "C" using dest = void( * )( void * );


    extern "C" struct exit_data
    {
        obj object;
        lib binary;

        union
        {
            func function;
            dest   method;
        };
    };


    extern "C" struct exit_node
    {
        static constexpr usize MAX = 170;


        exit_node * next;
        usize       size;
        exit_data   data[ MAX ];
    };

    static_assert( sizeof( exit_node ) == 4096 );




    // Removes concurency problem.
    extern "C" void __cxa_thread_enter( );
    extern "C" void __cxa_thread_leave( );

    extern "C" int  __cxa_thread_atexit( func function, obj object, lib binary );
    extern "C" void __cxa_thread_finalize( );
    extern "C" void __cxa_thread_initialize( );

    extern "C" int  __cxa_atexit( func function, obj object, lib binary );
    extern "C" void __cxa_finalize( lib binary );
    extern "C" void __cxa_initialize( );


    extern "C" void __cxa_allocate_exit_node( );
    extern "C" void __cxa_deallocate_exit_node( );

    extern "C" void __cxa_allocate_thread_exit_node( );
    extern "C" void __cxa_deallocate_thread_exit_node( );
}


#endif