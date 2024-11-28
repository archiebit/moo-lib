#ifndef MOONMICE_EXCEPTION_HH
#define MOONMICE_EXCEPTION_HH

#include <moon-mice\type.hh>


namespace moonmice
{
    enum : uint32
    {
        FAIL_NOT_ENOUGH_MEMORY = 0x8000'0000
    };
}


namespace moonmice::ini::exception
{
    extern "C"
    {
        void moonmice_enter_exception_scope( );
        void moonmice_leave_exception_scope( );
        bool moonmice_check_exception_state( );

        [[noreturn]]
        void moonmice_throw_exception_code( uint32 code );
        void moonmice_throw_exceptopn_same( );
        bool moonmice_check_exception_code( uint32 code );
    }
}


#define moonmice_try                                                            \
    for                                                                         \
    (                                                                           \
        moonmice::ini::exception::moonmice_enter_exception_scope( );            \
        moonmice::ini::exception::moonmice_check_exception_state( );            \
        moonmice::ini::exception::moonmice_leave_exception_scope( )             \
    )                                                                           \
    if                                                                          \
    (                                                                           \
        moonmice::ini::exception::moonmice_check_exception_code( 0 )            \
    )


#define moonmice_throw( code )                                                  \
    moonmice::ini::exception::moonmice_throw_exception_code( code )


#define moonmice_rethrow                                                        \
    moonmice::ini::exception::moonmice_throw_exception_same( )


#define moonmice_catch( code )                                                  \
    else if                                                                     \
    (                                                                           \
        moonmice::ini::exception::moonmice_check_exception_code( code )         \
    )


#define moonmice_finally                                                        \
    else if                                                                     \
    (                                                                           \
        moonmice::ini::exception::moonmice_check_exception_code( 0xFFFF'FFFF )  \
    )


#endif