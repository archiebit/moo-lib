#include <moo\exception.hh>
#include <moo\byte.hh>

#if defined _WIN32
#   include <windows.h>
#else
#   error Target OS is not supported!
#endif


namespace moo::ini::exception
{
    #if defined __x86_64__
    struct context
    {
    private:
        using  reg16 = byte[  2 ];
        using  reg32 = byte[  4 ];
        using  reg64 = byte[  8 ];
        using reg128 = byte[ 16 ];


    public:
        reg64    rax;
        reg64    rbx;
        reg64    rcx;
        reg64    rdx;
        reg64    rsi;
        reg64    rdi;
        reg64    rsp;
        reg64    rbp;
        reg64     r8;
        reg64     r9;
        reg64    r10;
        reg64    r11;
        reg64    r12;
        reg64    r13;
        reg64    r14;
        reg64    r15;
        reg64    rip;

        reg128 xmm00;
        reg128 xmm01;
        reg128 xmm02;
        reg128 xmm03;
        reg128 xmm04;
        reg128 xmm05;
        reg128 xmm06;
        reg128 xmm07;
        reg128 xmm08;
        reg128 xmm09;
        reg128 xmm10;
        reg128 xmm11;
        reg128 xmm12;
        reg128 xmm13;
        reg128 xmm14;
        reg128 xmm15;

        reg64 rflags;
        reg32 xstate;
        reg16 fflags;
    };
    #else
    #   error Target architecture is not supported!
    #endif


    struct context_node
    {
        context_node * next;
        context        data;
        uint32         code;
    };
}


namespace moo::ini::exception
{
    extern "C"
    {
        static constexpr usize context_free_limit = 16;

        static thread_local usize context_used_size = 0;
        static thread_local usize context_free_size = 0;

        static thread_local context_node * context_used = nullptr;
        static thread_local context_node * context_free = nullptr;
    }
}