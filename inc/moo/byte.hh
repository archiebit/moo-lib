#ifndef MOO_BYTE_HH
#define MOO_BYTE_HH


namespace moo
{
    enum class byte : unsigned char
    { };




    inline constexpr byte operator  ~( byte value ) noexcept
    {
        return static_cast<byte>( ~static_cast<unsigned char>( value ) );
    }


    inline constexpr byte operator  &( byte first, byte other ) noexcept
    {
        auto L = static_cast<unsigned char>( first );
        auto R = static_cast<unsigned char>( other );

        return static_cast<byte>( L & R );
    }

    inline constexpr byte operator  |( byte first, byte other ) noexcept
    {
        auto L = static_cast<unsigned char>( first );
        auto R = static_cast<unsigned char>( other );

        return static_cast<byte>( L | R );
    }

    inline constexpr byte operator  ^( byte first, byte other ) noexcept
    {
        auto L = static_cast<unsigned char>( first );
        auto R = static_cast<unsigned char>( other );

        return static_cast<byte>( L ^ R );
    }


    inline constexpr byte operator <<( byte value, unsigned int bits ) noexcept
    {
        return static_cast<byte>( static_cast<unsigned char>( value ) << bits );
    }

    inline constexpr byte operator >>( byte value, unsigned int bits ) noexcept
    {
        return static_cast<byte>( static_cast<unsigned char>( value ) >> bits );
    }




    inline constexpr byte & operator  &=( byte & first, byte other ) noexcept
    {
        return first = first & other;
    }

    inline constexpr byte & operator  |=( byte & first, byte other ) noexcept
    {
        return first = first | other;
    }

    inline constexpr byte & operator  ^=( byte & first, byte other ) noexcept
    {
        return first = first ^ other;
    }


    inline constexpr byte & operator <<=( byte & value, unsigned int bits ) noexcept
    {
        return value = value << bits;
    }

    inline constexpr byte & operator >>=( byte & value, unsigned int bits ) noexcept
    {
        return value = value >> bits;
    }
}


#endif