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
#if defined __clang__
#   define MOON_MICE_SECTION( name ) [[gnu::used, gnu::section( name )]]
#else
#   error Current compiler is unsupported!
#endif

    extern "C"
    {
        MOON_MICE_SECTION( ".CRT$XLA" )
        PIMAGE_TLS_CALLBACK __xl_a = NULL;

        MOON_MICE_SECTION( ".CRT$XLZ" )
        PIMAGE_TLS_CALLBACK __xl_z = NULL;


        MOON_MICE_SECTION( ".CRT$XDA" )
        PROC                __xd_a = NULL;

        MOON_MICE_SECTION( ".CRT$XDZ" )
        PROC                __xd_z = NULL;


        MOON_MICE_SECTION( ".tls" )
        BYTE            _tls_start = 0;

        MOON_MICE_SECTION( ".tls$ZZZ" )
        BYTE              _tls_end = 0;

        UINT            _tls_index = 0;
        LPVOID        __dso_handle = NULL;




        MOON_MICE_SECTION( ".rdata$T" )
        IMAGE_TLS_DIRECTORY64 _tls_used
        {
            .StartAddressOfRawData = reinterpret_cast<ULONGLONG>( & _tls_start ),
            .EndAddressOfRawData   = reinterpret_cast<ULONGLONG>( & _tls_end   ),
            .AddressOfIndex        = reinterpret_cast<ULONGLONG>( & _tls_index ),
            .AddressOfCallBacks    = reinterpret_cast<ULONGLONG>( & __xl_a + 1 ),
            .SizeOfZeroFill        = 0,
            .Characteristics       = 0
        };
    }
}

#endif




// That's the TLS callback list. Need an entry? Add it!
#if defined _WIN32

namespace moonmice::runtime
{
    extern VOID NTAPI StaticInit( PVOID, DWORD, PVOID );
    extern VOID NTAPI StaticExit( PVOID, DWORD, PVOID );


    MOON_MICE_SECTION( ".CRT$XLB" )
    PIMAGE_TLS_CALLBACK __xl_b = & StaticInit;

    MOON_MICE_SECTION( ".CRT$XLC" )
    PIMAGE_TLS_CALLBACK __xl_c = & StaticExit;
}

#endif




namespace moonmice::runtime
{
#if defined __clang__
    // 'atexit' list of the thread.
    static __thread exit_node * list;
#else
#   error Current compiler is unsupported!
#endif



#if defined _WIN32
    extern "C" void __cxa_allocate_thread_exit_node( )
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


    extern "C" void __cxa_deallocate_thread_exit_node( )
    {
        exit_node * head = list;
        exit_node * next = list->next;

        HeapFree( GetProcessHeap( ), 0, head );

        list = next;
    }


    extern "C" void __cxa_thread_initialize( )
    {
        using function_addr = void( *  )( );
        using function_list = void( ** )( );

        list = nullptr;

        function_list starts = reinterpret_cast<function_list>( & __xd_a + 1 );
        function_list ending = reinterpret_cast<function_list>( & __xd_z );

        while( starts != ending )
        {
            function_addr function = * starts;

            if( function ) ( * function )( );

            starts += 1;
        }
    }
#endif

    extern "C" void __cxa_thread_finalize( )
    {
        exit_node * curr = list;
        exit_node * next;

        while( curr )
        {
            for( usize i = curr->size - 1; i < exit_node::MAX; --i )
            {
                exit_data & data = curr->data[ i ];


                if( not data.function )
                {
                    continue;
                }

                if( data.object ) ( * data.method   )( data.object );
                else              ( * data.function )( );

                data.object   = nullptr;
                data.function = nullptr;
            }

            next = curr->next;
            curr = next;

            __cxa_deallocate_thread_exit_node( );
        }

        list = nullptr;
    }


    extern "C" int  __cxa_thread_atexit( func function, obj object, lib binary )
    {
        if( not list or list->size == exit_node::MAX )
        {
            exit_node * prev = list;
            exit_node * curr;

            __cxa_allocate_thread_exit_node( ), curr = list;

            if( prev == curr )
            {
                return 1;
            }
        }


        usize &     size = list->size;
        exit_data & data = list->data[ size ];

        data.function = function;
        data.object   = object;
        data.binary   = binary;

        size += 1;

        return 0;
    }
}