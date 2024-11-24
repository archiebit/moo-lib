#include <moon-mice\exception.hh>
#include <moon-mice\byte.hh>

#if defined _WIN32
#   include <windows.h>
#else
#   error Target OS is not supported!
#endif


namespace moonmice::ini::exception
{
    #if defined __x86_64__
    struct context
    {
    private:
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
    };
    #else
    #   error Target architecture is not supported!
    #endif


    struct context_node
    {
        context_node * next;
        context        data;
        uint32         code;
        uint32         done;
    };
}


namespace moonmice::ini::exception
{
    extern "C"
    {
        static constexpr usize context_free_limit = 16;

        static thread_local usize context_used_size = 0;
        static thread_local usize context_free_size = 0;

        static thread_local context_node * context_used = nullptr;
        static thread_local context_node * context_free = nullptr;
    }


#if defined _WIN32
    extern "C"
    {
        void * moonmice_create_exception_node( )
        {
            // Check for a free exception record in free-list.
            if( context_free_size != 0 )
            {
                auto node = context_free;
                auto next = context_free->next;

                node->next = context_used;
                node->code = 0;
                node->done = 0;

                context_free       = next;
                context_used       = node;
                context_free_size -= 1;
                context_used_size += 1;

                return node;
            }


            SIZE_T Size = sizeof( context_node );
            LPVOID Spot = HeapAlloc( GetProcessHeap( ), 0, Size );

            // Bruh moment?
            // If allocation fails, then everything breaks.
            if( Spot == NULL )
            {
                WCHAR Message[] = L"Can\'t allocate exception record.\n";
                HANDLE Output   = GetStdHandle( STD_ERROR_HANDLE );
                DWORD Written   = 0;   
                DWORD    Size   = sizeof( Message ) - sizeof( WCHAR );

                WriteFile( Output, Message, Size, & Written, NULL );
                ExitProcess( 1 );
            }


            auto node = static_cast<context_node *>( Spot );

            node->next = context_used;
            node->code = 0;
            node->done = 0;

            context_used       = node;
            context_used_size += 1;

            return node;
        }

        void   moonmice_remove_exception_node( )
        {
            if( context_used_size == 0 )
            {
                return;
            }


            auto node = context_used;
            auto next = context_used->next;

            // Put exception record to the free-list, if its size
            // in the limit.
            if( context_free_size < context_free_limit )
            {
                node->next = context_free;

                context_free = node;
                context_used = next;

                context_free_size += 1;
                context_used_size -= 1;
            }
            else
            {
                // Otherwise free it.
                HeapFree( GetProcessHeap( ), 0, node );

                context_used = next;
                context_used_size -= 1;
            }
        }

    #if defined __x86_64__
        [[gnu::naked, noreturn]]
        void   moonmice_create_exception_jump( context * record )
        {
            asm
            (
                // Load saved register values.
                "mov      rax,  [rcx +   0]                                 \n"
                "mov      rbx,  [rcx +   8]                                 \n"
                "mov      rdx,  [rcx +  24]                                 \n"
                "mov      rsi,  [rcx +  32]                                 \n"
                "mov      rdi,  [rcx +  40]                                 \n"
                "mov      rsp,  [rcx +  48]                                 \n"
                "mov      rbp,  [rcx +  56]                                 \n"
                "mov       r8,  [rcx +  64]                                 \n"
                "mov       r9,  [rcx +  72]                                 \n"
                "mov      r10,  [rcx +  80]                                 \n"
                "mov      r11,  [rcx +  88]                                 \n"
                "mov      r12,  [rcx +  96]                                 \n"
                "mov      r13,  [rcx + 104]                                 \n"
                "mov      r14,  [rcx + 112]                                 \n"
                "mov      r15,  [rcx + 120]                                 \n"

                // The same for XMM.
                "movdqu  xmm0,  [rcx + 136]                                 \n"
                "movdqu  xmm1,  [rcx + 152]                                 \n"
                "movdqu  xmm2,  [rcx + 168]                                 \n"
                "movdqu  xmm3,  [rcx + 184]                                 \n"
                "movdqu  xmm4,  [rcx + 200]                                 \n"
                "movdqu  xmm5,  [rcx + 216]                                 \n"
                "movdqu  xmm6,  [rcx + 232]                                 \n"
                "movdqu  xmm7,  [rcx + 248]                                 \n"
                "movdqu  xmm8,  [rcx + 264]                                 \n"
                "movdqu  xmm9,  [rcx + 280]                                 \n"
                "movdqu xmm10,  [rcx + 296]                                 \n"
                "movdqu xmm11,  [rcx + 312]                                 \n"
                "movdqu xmm12,  [rcx + 328]                                 \n"
                "movdqu xmm13,  [rcx + 344]                                 \n"
                "movdqu xmm14,  [rcx + 360]                                 \n"
                "movdqu xmm15,  [rcx + 376]                                 \n"

                // Jump to the return address.
                "mov      rcx,  [rcx + 128]                                 \n"
                "jmp      rcx                                               \n"
            );
        }
    #endif


    #if defined __x86_64__
        [[gnu::naked]]
        void moonmice_enter_exception_scope( )
        {
            asm
            (
                // Function prolog.
                "push   rbp                                                 \n"
                "mov    rbp, rsp                                            \n"
                "sub    rsp,  %0                                            \n"

                // Store general registers.
                "mov    [rsp +   0], rax                                    \n"
                "mov    [rsp +   8], rbx                                    \n"
                "mov    [rsp +  16], rcx                                    \n"
                "mov    [rsp +  24], rdx                                    \n"
                "mov    [rsp +  32], rsi                                    \n"
                "mov    [rsp +  40], rdi                                    \n"
                "mov    [rsp +  48], rsp                                    \n"
                "mov    [rsp +  56], rbp                                    \n"
                "mov    [rsp +  64],  r8                                    \n"
                "mov    [rsp +  72],  r9                                    \n"
                "mov    [rsp +  80], r10                                    \n"
                "mov    [rsp +  88], r11                                    \n"
                "mov    [rsp +  96], r12                                    \n"
                "mov    [rsp + 104], r13                                    \n"
                "mov    [rsp + 112], r14                                    \n"
                "mov    [rsp + 120], r15                                    \n"

                // Special case for RBP, RSP and RIP registers.
                "mov    rax, [rbp]                                          \n"
                "mov    rcx, [rbp +  8]                                     \n"
                "lea    rdx, [rbp + 16]                                     \n"
                "mov    [rsp +  56], rax                                    \n"
                "mov    [rsp + 128], rcx                                    \n"
                "mov    [rsp +  48], rdx                                    \n"

                // Store XMM registers.
                "movdqu [rsp + 136],  xmm0                                  \n"
                "movdqu [rsp + 152],  xmm1                                  \n"
                "movdqu [rsp + 168],  xmm2                                  \n"
                "movdqu [rsp + 184],  xmm3                                  \n"
                "movdqu [rsp + 200],  xmm4                                  \n"
                "movdqu [rsp + 216],  xmm5                                  \n"
                "movdqu [rsp + 232],  xmm6                                  \n"
                "movdqu [rsp + 248],  xmm7                                  \n"
                "movdqu [rsp + 264],  xmm8                                  \n"
                "movdqu [rsp + 280],  xmm9                                  \n"
                "movdqu [rsp + 296], xmm10                                  \n"
                "movdqu [rsp + 312], xmm11                                  \n"
                "movdqu [rsp + 328], xmm12                                  \n"
                "movdqu [rsp + 344], xmm13                                  \n"
                "movdqu [rsp + 360], xmm14                                  \n"
                "movdqu [rsp + 376], xmm15                                  \n"

                // Create new exception record and fill it's context
                // with stored values on stack.
                "call moonmice_create_exception_node                        \n"
                "add    rax,   8                                            \n"
                "mov    rsi, rsp                                            \n"
                "mov    rdi, rax                                            \n"
                "mov    rcx,  %0                                            \n"
                "rep movsb                                                  \n"

                // Get old values. Why not?
                "mov    rax, [rsp +   0]                                    \n"
                "mov    rcx, [rsp +  16]                                    \n"
                "mov    rdx, [rsp +  24]                                    \n"
                "mov    rsi, [rsp +  32]                                    \n"
                "mov    rdi, [rsp +  40]                                    \n"

                // Function epilogue.
                "mov    rsp, rbp                                            \n"
                "pop    rbp                                                 \n"
                "ret                                                        \n"
                :
                : "i"( sizeof( context ) )
            );
        }
    #endif

        bool moonmice_check_exception_state( )
        {
            // If list is empty just quit.
            // Maybe rework this state?
            if( not context_used )
            {
                return false;
            }

            // If there is no exception, or exception is handled,
            // then exception record will be removed
            // and program must quit from 'try-catch' block.
            if( context_used->done == 1 )
            {
                moonmice_remove_exception_node( );

                return false;
            }

            return true;
        }

        void moonmice_leave_exception_scope( )
        {
            // If no exception was called, then 'code' is still zero.
            // So mark it as done.
            if( context_used->code == 0 )
            {
                context_used->done = 1;
            }

            // If exception code is presented and there is no 'catch' block,
            // then just jump to previous 'try-catch' block.
            else if( context_used->done == 0 )
            {
                auto code = context_used->code;
                auto next = context_used->next;

                next->code = code;

                moonmice_remove_exception_node( );
                moonmice_create_exception_jump( & next->data );
            }
        }


        bool moonmice_check_exception_code( uint32 code )
        {
            // Special case for a 'finally' block.
            // After completion of 'finally' block,
            // go to next 'try-catch' block.
            if( code == 0xFFFF'FFFF )
            {
                return true;
            }

            // General case for exceptions.
            if( context_used->code == code and code != 0 )
            {
                context_used->done = 1;

                return true;
            }

            // Special case for a 'try' block.
            if( context_used->code == code )
            {
                return true;
            }

            return false;
        }

        void moonmice_throw_exception_same( )
        {
            // After 'catch' block mark it as not done.
            // Execution will go to the next 'try-catch' block.
            context_used->done = 0;
        }

        void moonmice_throw_exception_code( uint32 code )
        {
            // Set exception data and jump to 'try' block.
            context_used->code = code;
            context_used->done = 0;

            moonmice_create_exception_jump( & context_used->data );
        }
    }
#endif
}