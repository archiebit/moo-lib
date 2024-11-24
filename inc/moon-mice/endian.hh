#ifndef MOONMICE_ENDIAN_HH
#define MOONMICE_ENDIAN_HH


namespace moonmice
{
    enum class endian
    {
        little = 0,
        big    = 1,
    #if defined __x86_64__
        native = little
    #else
    #   error Target architecture is unsupported!
    #endif
    };
}


#endif