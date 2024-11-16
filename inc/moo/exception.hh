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
        bool moo_check_exception_code( uint32 code );
    }
}


#endif