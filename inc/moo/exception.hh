#ifndef MOO_EXCEPTION_HH
#define MOO_EXCEPTION_HH

#include <moo\type.hh>


namespace moo::ini::exception
{
    extern "C"
    {
        void moo_enter_exception_scope( );
        void moo_leave_exception_scope( );
        bool moo_check_exception_state( );

        [[noreturn]]
        void moo_throw_exception_code( uint32 code );
        void moo_throw_exceptopn_same( );
        bool moo_check_exception_code( uint32 code );
    }
}


#define moo_try                                                         \
    for                                                                 \
    (                                                                   \
        moo::ini::exception::moo_enter_exception_scope( );              \
        moo::ini::exception::moo_check_exception_state( );              \
        moo::ini::exception::moo_leave_exception_scope( )               \
    )                                                                   \
    if                                                                  \
    (                                                                   \
        moo::ini::exception::moo_check_exception_code( 0 )              \
    )


#define moo_throw( code )                                               \
    moo::ini::exception::moo_throw_exception_code( code )


#define moo_rethrow                                                     \
    moo::ini::exception::moo_throw_exception_same( )


#define moo_catch( code )                                               \
    else if                                                             \
    (                                                                   \
        moo::ini::exception::moo_check_exception_code( code )           \
    )


#define moo_finally                                                     \
    else if                                                             \
    (                                                                   \
        moo::ini::exception::moo_check_exception_code( 0xFFFF'FFFF )    \
    )


#endif