#ifndef MOONMICE_MEMORY_HH
#define MOONMICE_MEMORY_HH

#include <moon-mice\type.hh>


namespace moonmice
{
    enum nothrow_tag
    {
        // Pass this flag if you want non-throwing allocation.
        nothrow
    };
}




/// @brief Allocates memory block.
/// @param size size of memory block in bytes
/// @throw FAIL_NOT_ENOUGH_MEMORY
/// @return pointer to the memory block.
void * operator new  ( moonmice::usize size );


/// @brief Allocates memory.
/// @param size size of memory block in bytes.
/// @throw FAIL_NOT_ENOUGH_MEMORY
/// @return pointer to the memory block.
void * operator new[]( moonmice::usize size );


/// @brief Allocates aligned memory block.
/// @param size size of memory block in bytes
/// @param alignment address alignment
/// @throw FAIL_NOT_ENOUGH_MEMORY
/// @return aligned pointer to the memory block.
void * operator new  ( moonmice::usize size, moonmice::align alignment );


/// @brief Allocates aligned memory block.
/// @param size size of memory block in bytes
/// @param alignment address alignment
/// @throw FAIL_NOT_ENOUGH_MEMORY
/// @return aligned pointer to the memory block.
void * operator new[]( moonmice::usize size, moonmice::align alignment );


/// @brief Allocates memory block.
/// @param size size of memory block in bytes
/// @param tag flag for non-throwing allocation
/// @return pointer to the memory block or 'nullptr'.
void * operator new  ( moonmice::usize size, moonmice::nothrow_tag tag ) noexcept;


/// @brief Allocates memory block.
/// @param size size of memory block in bytes
/// @param tag flag for non-throwing allocation
/// @return pointer to the memory block or 'nullptr'.
void * operator new[]( moonmice::usize size, moonmice::nothrow_tag tag ) noexcept;


/// @brief Allocates aligned memory block.
/// @param size size of memory block in bytes
/// @param alignment address alignment
/// @param tag flag for non-throwing allocation
/// @return aligned pointer to the memory block or 'nullptr'.
void * operator new  ( moonmice::usize size, moonmice::align alignment, moonmice::nothrow_tag tag ) noexcept;


/// @brief Allocates aligned memory block.
/// @param size size of memory block in bytes
/// @param alignment address alignment
/// @param tag flag for non-throwing allocation
/// @return aligned pointer to the memory block or 'nullptr'.
void * operator new[]( moonmice::usize size, moonmice::align alignment, moonmice::nothrow_tag tag ) noexcept;


/// @brief Constructs object right at the place.
/// @param size size of memory block in bytes
/// @param spot object location
/// @return pointer to the input location
void * operator new  ( moonmice::usize size, void * spot ) noexcept;


/// @brief Constructs object right at the place.
/// @param size size of memory block in bytes
/// @param spot object location
/// @return pointer to the input location
void * operator new[]( moonmice::usize size, void * spot ) noexcept;




/// @brief Frees memory.
/// @param spot pointer to the memory block, from operator 'new'
void operator delete  ( void * spot ) noexcept;


/// @brief Frees memory.
/// @param spot pointer to the memory block, from operator 'new[]'
void operator delete[]( void * spot ) noexcept;


/// @brief Frees memory.
/// @param spot pointer to the memory block, from operator 'new'
/// @param size size argument that was passed to the operator 'new' 
void operator delete  ( void * spot, moonmice::usize size ) noexcept;


/// @brief Frees memory.
/// @param spot pointer to the memory block, from operator 'new[]'
/// @param size size argument that was passed to the operator 'new[]'
void operator delete[]( void * spot, moonmice::usize size ) noexcept;


/// @brief Destroys object at the specific location.
/// @param spot Just for consistency with operator 'new'?
/// @param object pointer that was passed to the operator 'new'
void operator delete  ( void * spot, void * object ) noexcept;


/// @brief Destroys object at the specific location.
/// @param spot Just for consistency with operator 'new[]'?
/// @param object pointer that was passed to the operator 'new[]'
void operator delete[]( void * spot, void * object ) noexcept;


#endif