#ifndef MOONMICE_MOVEMENT_HH
#define MOONMICE_MOVEMENT_HH


#include <moon-mice\trait.hh>


// 'forward' for forwarding, 'provide' for moving.
//
// Why 'provide'?
//      Well, for the same name length.
//
// Why does 'provide' have two overrides?
//      To be consistent with 'forward'.
//
// Are two overrides for 'provide' bloat?
//      Yeah, I don't care.
namespace moonmice
{
    template <typename in>
    inline constexpr auto && forward( remove::reference<in> && value ) noexcept
    {
        return static_cast<decltype( value ) &&>( value );
    }

    template <typename in>
    inline constexpr auto && forward( remove::reference<in> &  value ) noexcept
    {
        return static_cast<decltype( value ) &&>( value );
    }


    template <typename in>
    inline constexpr auto && provide( remove::reference<in> && value ) noexcept
    {
        return static_cast<remove::reference<in> &&>( value );
    }

    template <typename in>
    inline constexpr auto && provide( remove::reference<in> &  value ) noexcept
    {
        return static_cast<remove::reference<in> &&>( value );
    }
}


#endif