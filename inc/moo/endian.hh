#ifndef MOO_ENDIAN_HH
#define MOO_ENDIAN_HH


namespace moo
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