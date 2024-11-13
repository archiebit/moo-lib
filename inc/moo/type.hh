#ifndef MOO_TYPE_HH
#define MOO_TYPE_HH


#if defined _WIN64
namespace moo
{
    using uint08 = unsigned char;
    using uint16 = unsigned short int;
    using uint32 = unsigned int;
    using uint64 = unsigned long long int;

    using sint08 = signed char;
    using sint16 = signed short int;
    using sint32 = signed int;
    using sint64 = signed long long int;

    using real32 = float;
    using real64 = double;


    using  align = unsigned long long int;
    using  usize = unsigned long long int;
    using  ssize = signed long long int;

    using  uintp = unsigned long long int;
    using  sintp = signed long long int;
}
#endif


#endif