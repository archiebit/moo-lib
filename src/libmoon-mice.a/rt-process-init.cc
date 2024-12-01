#include <moon-mice-runtime\init.hh>

#if defined _WIN32
#   include <windows.h>
#endif


// I warn you! When I tested this piece of 'work', I ran into a problem.
// All that beautifull global gibberish with constructors and destructors
// DIDN'T WORK AT ALL!
//
// But I found a solution: add a 'thread_local' variable to your executable
// and use it somehow.
//
// Example:
// -----------------------------------------------------------------------------
//  static thread_local int volatile force_tls;
//
//  void init_this_precious_executable( )
//  {
//      force_tls = 0;
//
//      do_stuff( ... );
//      do_exit( ... );
//  }
//
// -----------------------------------------------------------------------------
#if defined _WIN32

namespace moonmice::runtime
{
    CRITICAL_SECTION ThreadSection;


    // This function and the following one are in the TLS callback list.
    // The purpose of this one is to call constructors of all static
    // and 'thread_local' variables.
    [[gnu::used]]
    VOID NTAPI StaticInit( PVOID Module, DWORD Reason, PVOID Reserved )
    {
        UNREFERENCED_PARAMETER( Reserved );


        HMODULE Binary = GetModuleHandleW( NULL );

        switch( Reason )
        {
            case DLL_PROCESS_ATTACH:
            {
                if( Module == Binary )
                {
                    InitializeCriticalSection( & ThreadSection );

                    __cxa_initialize( );
                }

                __cxa_thread_initialize( );

                break;
            }

            case DLL_THREAD_ATTACH:
            {
                __cxa_thread_initialize( );

                break;
            }
        }
    }


    // This function calls static and 'thread_local' destructors,
    // works with the 'atexit' list of process and all of it threads.
    [[gnu::used]]
    VOID NTAPI StaticExit( PVOID Module, DWORD Reason, PVOID Reserved )
    {
        UNREFERENCED_PARAMETER( Reserved );


        HMODULE Binary = GetModuleHandleW( NULL );

        switch( Reason )
        {
            case DLL_PROCESS_DETACH:
            {
                __cxa_thread_finalize( );

                if( Module == Binary )
                {
                    __cxa_finalize( nullptr );

                    DeleteCriticalSection( & ThreadSection );
                }
                else
                {
                    __cxa_finalize( Module );
                }

                break;
            }

            case DLL_THREAD_DETACH:
            {
                __cxa_thread_finalize( );

                break;
            }
        }
    }
}

#endif


namespace moonmice::runtime
{
    // 'atexit' list of the process.
    static exit_node * list;


#if defined _WIN32
    extern "C" void __cxa_allocate_exit_node( )
    {
        HANDLE Heap = GetProcessHeap( );
        LPVOID Data = HeapAlloc( Heap, HEAP_ZERO_MEMORY, sizeof( exit_node ) );

        if( Data != NULL )
        {
            exit_node * head = list;
            exit_node * next = static_cast<exit_node *>( Data );

            next->next = head;
            list = next;
        }
    }


    extern "C" void __cxa_deallocate_exit_node( )
    {
        exit_node * head = list;
        exit_node * next = list->next;

        HeapFree( GetProcessHeap( ), 0, head );

        list = next;
    }


    extern "C" void __cxa_thread_enter( )
    {
        EnterCriticalSection( & ThreadSection );
    }


    extern "C" void __cxa_thread_leave( )
    {
        LeaveCriticalSection( & ThreadSection );
    }
#endif

    // Executes global constructors.
    extern "C" void __cxa_initialize( )
    {
        list = nullptr;

        extern void( * __CTOR_LIST__[] )( );


        for( usize i = 1; __CTOR_LIST__[ i ]; ++i )
        {
            ( * __CTOR_LIST__[ i ] )( );
        }
    }


    // Executes 'atexit' list and global destructors.
    extern "C" void __cxa_finalize( lib binary )
    {
        __cxa_thread_enter( );

        exit_node * curr = list;
        exit_node * next = nullptr;

        while( curr )
        {
            for( usize i = curr->size - 1; i < exit_node::MAX; --i )
            {
                exit_data & data = curr->data[ i ];


                if( not data.function )
                {
                    continue;
                }

                if( not binary or binary == data.binary )
                {
                    if( data.object ) ( * data.method   )( data.object );
                    else              ( * data.function )( );

                    data.function = nullptr;
                    data.object   = nullptr;
                }
            }


            next = curr->next;
            curr = next;

            if( not binary )
            {
                __cxa_deallocate_exit_node( );
            }
        }


        if( not binary )
        {
            list = nullptr;

            extern void( * __DTOR_LIST__[] )( );


            for( usize i = 1; __DTOR_LIST__[ i ]; ++i )
            {
                ( * __DTOR_LIST__[ i ] )( );
            }
        }

        __cxa_thread_leave( );
    }


    extern "C" int  __cxa_atexit( func function, obj object, lib binary )
    {
        __cxa_thread_enter( );

        if( not list or list->size == exit_node::MAX )
        {
            exit_node * prev = list;
            exit_node * curr;

            __cxa_allocate_exit_node( ), curr = list;

            if( prev == curr )
            {
                __cxa_thread_leave( );

                return 1;
            }
        }


        usize &     size = list->size;
        exit_data & data = list->data[ size ];

        data.function = function;
        data.object   = object;
        data.binary   = binary;

        size += 1;

        __cxa_thread_leave( );

        return 0;
    }
}