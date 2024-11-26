#ifndef MOONMICE_TRAIT_HH
#define MOONMICE_TRAIT_HH


namespace moonmice
{
    /// @brief This class provide ability to remove type qualifiers
    ///        and definitions.
    class remove
    {
    private:
       ~remove( ) = delete;
        remove( ) = delete;

        struct ini
        {
            template <typename in>
            struct  constant;

            template <typename in>
            struct  unstable;

            template <typename in>
            struct  defenses;

            template <typename in>
            struct reference;

            template <typename in>
            struct     point;

            template <typename in>
            struct    member;

            template <typename in>
            struct     array;

            template <typename in>
            struct exception;

            template <typename in>
            struct    entire;
        };


    public:
        /// @brief  Removes 'const' qualifier.
        /// @tparam in source type
        template <typename in>
        using  constant = typename  ini::constant<in>::type;


        /// @brief  Removes 'volatile' qualifier.
        /// @tparam in source type
        template <typename in>
        using  unstable = typename  ini::unstable<in>::type;


        /// @brief  Removes 'const' and 'volatile' qualifiers.
        /// @tparam in source type
        template <typename in>
        using  defenses = typename  ini::defenses<in>::type;


        /// @brief  Removes reference definition.
        /// @tparam in source type
        template <typename in>
        using reference = typename ini::reference<in>::type;


        /// @brief  Removes pointer definition.
        /// @tparam in source type
        template <typename in>
        using     point = typename     ini::point<in>::type;


        /// @brief  Removes member pointer definition.
        /// @tparam in source type
        template <typename in>
        using    member = typename    ini::member<in>::type;


        /// @brief  Removes array definition.
        /// @tparam in source type
        template <typename in>
        using     array = typename     ini::array<in>::type;


        /// @brief  Removes 'noexcept' specifier.
        /// @tparam in source type
        template <typename in>
        using exception = typename ini::exception<in>::type;


        /// @brief  Removes all qualifiers and definitions.
        /// @tparam in source type
        template <typename in>
        using    entire = typename    ini::entire<in>::type;
    };




    template <typename in>
    struct remove::ini::constant
    {
        using type = in;
    };

    template <typename in>
    struct remove::ini::constant<in const>
    {
        using type = in;
    };

    template <typename in>
    struct remove::ini::constant<in const &>
    {
        using type = in &;
    };

    template <typename in>
    struct remove::ini::constant<in const &&>
    {
        using type = in &&;
    };




    template <typename in>
    struct remove::ini::unstable
    {
        using type = in;
    };

    template <typename in>
    struct remove::ini::unstable<in volatile>
    {
        using type = in;
    };

    template <typename in>
    struct remove::ini::unstable<in volatile &>
    {
        using type = in &;
    };

    template <typename in>
    struct remove::ini::unstable<in volatile &&>
    {
        using type = in &&;
    };




    template <typename in>
    struct remove::ini::defenses
    {
        using type = in;
    };

    template <typename in>
    struct remove::ini::defenses<in const>
    {
        using type = in;
    };

    template <typename in>
    struct remove::ini::defenses<in volatile>
    {
        using type = in;
    };

    template <typename in>
    struct remove::ini::defenses<in const volatile>
    {
        using type = in;
    };

    template <typename in>
    struct remove::ini::defenses<in const &>
    {
        using type = in &;
    };

    template <typename in>
    struct remove::ini::defenses<in volatile &>
    {
        using type = in &;
    };

    template <typename in>
    struct remove::ini::defenses<in const volatile &>
    {
        using type = in &;
    };

    template <typename in>
    struct remove::ini::defenses<in const &&>
    {
        using type = in &&;
    };

    template <typename in>
    struct remove::ini::defenses<in volatile &&>
    {
        using type = in &&;
    };

    template <typename in>
    struct remove::ini::defenses<in const volatile &&>
    {
        using type = in &&;
    };




    template <typename in>
    struct remove::ini::reference
    {
        using type = in;
    };

    template <typename in>
    struct remove::ini::reference<in &>
    {
        using type = in;
    };

    template <typename in>
    struct remove::ini::reference<in &&>
    {
        using type = in;
    };




    template <typename in>
    struct remove::ini::point
    {
        using type = in;
    };

    template <typename in>
    struct remove::ini::point<in *>
    {
        using type = in;
    };

    template <typename in>
    struct remove::ini::point<in * const>
    {
        using type = in;
    };

    template <typename in>
    struct remove::ini::point<in * volatile>
    {
        using type = in;
    };

    template <typename in>
    struct remove::ini::point<in * const volatile>
    {
        using type = in;
    };




    template <typename in>
    struct remove::ini::member
    {
        using type = in;
    };

    template <typename in, typename structure>
    struct remove::ini::member<in structure::*>
    {
        using type = in;
    };




    template <typename in>
    struct remove::ini::array
    {
        using type = in;
    };

    template <typename in>
    struct remove::ini::array<in[]>
    {
        using type = in;
    };

    template <typename in, unsigned long long int count>
    struct remove::ini::array<in[ count ]>
    {
        using type = in;
    };




    template <typename in>
    struct remove::ini::exception
    {
        using type = in;
    };




    template <typename in>
    struct remove::ini::entire
    {
        using type = in;
    };

    template <typename in>
    struct remove::ini::entire<in const>
    {
        using type = typename entire<in>::type;
    };

    template <typename in>
    struct remove::ini::entire<in volatile>
    {
        using type = typename entire<in>::type;
    };

    template <typename in>
    struct remove::ini::entire<in &>
    {
        using type = typename entire<in>::type;
    };

    template <typename in>
    struct remove::ini::entire<in &&>
    {
        using type = typename entire<in>::type;
    };

    template <typename in>
    struct remove::ini::entire<in *>
    {
        using type = typename entire<in>::type;
    };

    template <typename in, typename structure>
    struct remove::ini::entire<in structure::*>
    {
        using type = typename entire<in>::type;
    };

    template <typename in>
    struct remove::ini::entire<in[]>
    {
        using type = typename entire<in>::type;
    };

    template <typename in, unsigned long long int count>
    struct remove::ini::entire<in[ count ]>
    {
        using type = typename entire<in>::type;
    };




    template <typename back, typename... args>
    struct remove::ini::constant<back( args... )>
    {
        using type = back( args... );
    };

    template <typename back, typename... args>
    struct remove::ini::constant<back( args... ) const>
    {
        using type = back( args... );
    };

    template <typename back, typename... args>
    struct remove::ini::constant<back( args... ) volatile>
    {
        using type = back( args... ) volatile;
    };

    template <typename back, typename... args>
    struct remove::ini::constant<back( args... ) const volatile>
    {
        using type = back( args... ) volatile;
    };

    template <typename back, typename... args>
    struct remove::ini::constant<back( args... ) noexcept>
    {
        using type = back( args... ) noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::constant<back( args... ) const noexcept>
    {
        using type = back( args... ) noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::constant<back( args... ) volatile noexcept>
    {
        using type = back( args... ) volatile noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::constant<back( args... ) const volatile noexcept>
    {
        using type = back( args... ) volatile noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::constant<back( args... ) &>
    {
        using type = back( args... ) &;
    };

    template <typename back, typename... args>
    struct remove::ini::constant<back( args... ) const &>
    {
        using type = back( args... ) &;
    };

    template <typename back, typename... args>
    struct remove::ini::constant<back( args... ) volatile &>
    {
        using type = back( args... ) volatile &;
    };

    template <typename back, typename... args>
    struct remove::ini::constant<back( args... ) const volatile &>
    {
        using type = back( args... ) volatile &;
    };

    template <typename back, typename... args>
    struct remove::ini::constant<back( args... ) & noexcept>
    {
        using type = back( args... ) & noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::constant<back( args... ) const & noexcept>
    {
        using type = back( args... ) & noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::constant<back( args... ) volatile & noexcept>
    {
        using type = back( args... ) volatile & noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::constant<back( args... ) const volatile & noexcept>
    {
        using type = back( args... ) volatile & noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::constant<back( args... ) &&>
    {
        using type = back( args... ) &&;
    };

    template <typename back, typename... args>
    struct remove::ini::constant<back( args... ) const &&>
    {
        using type = back( args... ) &&;
    };

    template <typename back, typename... args>
    struct remove::ini::constant<back( args... ) volatile &&>
    {
        using type = back( args... ) volatile &&;
    };

    template <typename back, typename... args>
    struct remove::ini::constant<back( args... ) const volatile &&>
    {
        using type = back( args... ) volatile &&;
    };

    template <typename back, typename... args>
    struct remove::ini::constant<back( args... ) && noexcept>
    {
        using type = back( args... ) && noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::constant<back( args... ) const && noexcept>
    {
        using type = back( args... ) && noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::constant<back( args... ) volatile && noexcept>
    {
        using type = back( args... ) volatile && noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::constant<back( args... ) const volatile && noexcept>
    {
        using type = back( args... ) volatile && noexcept;
    };




    template <typename back, typename... args>
    struct remove::ini::unstable<back( args... )>
    {
        using type = back( args... );
    };

    template <typename back, typename... args>
    struct remove::ini::unstable<back( args... ) const>
    {
        using type = back( args... ) const;
    };

    template <typename back, typename... args>
    struct remove::ini::unstable<back( args... ) volatile>
    {
        using type = back( args... );
    };

    template <typename back, typename... args>
    struct remove::ini::unstable<back( args... ) const volatile>
    {
        using type = back( args... ) const;
    };

    template <typename back, typename... args>
    struct remove::ini::unstable<back( args... ) noexcept>
    {
        using type = back( args... ) noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::unstable<back( args... ) const noexcept>
    {
        using type = back( args... ) const noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::unstable<back( args... ) volatile noexcept>
    {
        using type = back( args... ) noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::unstable<back( args... ) const volatile noexcept>
    {
        using type = back( args... ) const noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::unstable<back( args... ) &>
    {
        using type = back( args... ) &;
    };

    template <typename back, typename... args>
    struct remove::ini::unstable<back( args... ) const &>
    {
        using type = back( args... ) const &;
    };

    template <typename back, typename... args>
    struct remove::ini::unstable<back( args... ) volatile &>
    {
        using type = back( args... ) &;
    };

    template <typename back, typename... args>
    struct remove::ini::unstable<back( args... ) const volatile &>
    {
        using type = back( args... ) const &;
    };

    template <typename back, typename... args>
    struct remove::ini::unstable<back( args... ) & noexcept>
    {
        using type = back( args... ) & noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::unstable<back( args... ) const & noexcept>
    {
        using type = back( args... ) const & noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::unstable<back( args... ) volatile & noexcept>
    {
        using type = back( args... ) & noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::unstable<back( args... ) const volatile & noexcept>
    {
        using type = back( args... ) const & noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::unstable<back( args... ) &&>
    {
        using type = back( args... ) &&;
    };

    template <typename back, typename... args>
    struct remove::ini::unstable<back( args... ) const &&>
    {
        using type = back( args... ) const &&;
    };

    template <typename back, typename... args>
    struct remove::ini::unstable<back( args... ) volatile &&>
    {
        using type = back( args... ) &&;
    };

    template <typename back, typename... args>
    struct remove::ini::unstable<back( args... ) const volatile &&>
    {
        using type = back( args... ) const &&;
    };

    template <typename back, typename... args>
    struct remove::ini::unstable<back( args... ) && noexcept>
    {
        using type = back( args... ) && noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::unstable<back( args... ) const && noexcept>
    {
        using type = back( args... ) const && noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::unstable<back( args... ) volatile && noexcept>
    {
        using type = back( args... ) && noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::unstable<back( args... ) const volatile && noexcept>
    {
        using type = back( args... ) const && noexcept;
    };




    template <typename back, typename... args>
    struct remove::ini::defenses<back( args... )>
    {
        using type = back( args... );
    };

    template <typename back, typename... args>
    struct remove::ini::defenses<back( args... ) const>
    {
        using type = back( args... );
    };

    template <typename back, typename... args>
    struct remove::ini::defenses<back( args... ) volatile>
    {
        using type = back( args... );
    };

    template <typename back, typename... args>
    struct remove::ini::defenses<back( args... ) const volatile>
    {
        using type = back( args... );
    };

    template <typename back, typename... args>
    struct remove::ini::defenses<back( args... ) noexcept>
    {
        using type = back( args... ) noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::defenses<back( args... ) const noexcept>
    {
        using type = back( args... ) noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::defenses<back( args... ) volatile noexcept>
    {
        using type = back( args... ) noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::defenses<back( args... ) const volatile noexcept>
    {
        using type = back( args... ) noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::defenses<back( args... ) &>
    {
        using type = back( args... ) &;
    };

    template <typename back, typename... args>
    struct remove::ini::defenses<back( args... ) const &>
    {
        using type = back( args... ) &;
    };

    template <typename back, typename... args>
    struct remove::ini::defenses<back( args... ) volatile &>
    {
        using type = back( args... ) &;
    };

    template <typename back, typename... args>
    struct remove::ini::defenses<back( args... ) const volatile &>
    {
        using type = back( args... ) &;
    };

    template <typename back, typename... args>
    struct remove::ini::defenses<back( args... ) & noexcept>
    {
        using type = back( args... ) & noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::defenses<back( args... ) const & noexcept>
    {
        using type = back( args... ) & noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::defenses<back( args... ) volatile & noexcept>
    {
        using type = back( args... ) & noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::defenses<back( args... ) const volatile & noexcept>
    {
        using type = back( args... ) & noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::defenses<back( args... ) &&>
    {
        using type = back( args... ) &&;
    };

    template <typename back, typename... args>
    struct remove::ini::defenses<back( args... ) const &&>
    {
        using type = back( args... ) &&;
    };

    template <typename back, typename... args>
    struct remove::ini::defenses<back( args... ) volatile &&>
    {
        using type = back( args... ) &&;
    };

    template <typename back, typename... args>
    struct remove::ini::defenses<back( args... ) const volatile &&>
    {
        using type = back( args... ) &&;
    };

    template <typename back, typename... args>
    struct remove::ini::defenses<back( args... ) && noexcept>
    {
        using type = back( args... ) && noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::defenses<back( args... ) const && noexcept>
    {
        using type = back( args... ) && noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::defenses<back( args... ) volatile && noexcept>
    {
        using type = back( args... ) && noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::defenses<back( args... ) const volatile && noexcept>
    {
        using type = back( args... ) && noexcept;
    };




    template <typename back, typename... args>
    struct remove::ini::reference<back( args... )>
    {
        using type = back( args... );
    };

    template <typename back, typename... args>
    struct remove::ini::reference<back( args... ) const>
    {
        using type = back( args... ) const;
    };

    template <typename back, typename... args>
    struct remove::ini::reference<back( args... ) volatile>
    {
        using type = back( args... ) volatile;
    };

    template <typename back, typename... args>
    struct remove::ini::reference<back( args... ) const volatile>
    {
        using type = back( args... ) const volatile;
    };

    template <typename back, typename... args>
    struct remove::ini::reference<back( args... ) noexcept>
    {
        using type = back( args... ) noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::reference<back( args... ) const noexcept>
    {
        using type = back( args... ) const noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::reference<back( args... ) volatile noexcept>
    {
        using type = back( args... ) volatile noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::reference<back( args... ) const volatile noexcept>
    {
        using type = back( args... ) const volatile noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::reference<back( args... ) &>
    {
        using type = back( args... );
    };

    template <typename back, typename... args>
    struct remove::ini::reference<back( args... ) const &>
    {
        using type = back( args... ) const;
    };

    template <typename back, typename... args>
    struct remove::ini::reference<back( args... ) volatile &>
    {
        using type = back( args... ) volatile;
    };

    template <typename back, typename... args>
    struct remove::ini::reference<back( args... ) const volatile &>
    {
        using type = back( args... ) const volatile;
    };

    template <typename back, typename... args>
    struct remove::ini::reference<back( args... ) & noexcept>
    {
        using type = back( args... ) noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::reference<back( args... ) const & noexcept>
    {
        using type = back( args... ) const noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::reference<back( args... ) volatile & noexcept>
    {
        using type = back( args... ) volatile noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::reference<back( args... ) const volatile & noexcept>
    {
        using type = back( args... ) const volatile noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::reference<back( args... ) &&>
    {
        using type = back( args... );
    };

    template <typename back, typename... args>
    struct remove::ini::reference<back( args... ) const &&>
    {
        using type = back( args... ) const;
    };

    template <typename back, typename... args>
    struct remove::ini::reference<back( args... ) volatile &&>
    {
        using type = back( args... ) volatile;
    };

    template <typename back, typename... args>
    struct remove::ini::reference<back( args... ) const volatile &&>
    {
        using type = back( args... ) const volatile;
    };

    template <typename back, typename... args>
    struct remove::ini::reference<back( args... ) && noexcept>
    {
        using type = back( args... ) noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::reference<back( args... ) const && noexcept>
    {
        using type = back( args... ) const noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::reference<back( args... ) volatile && noexcept>
    {
        using type = back( args... ) volatile noexcept;
    };

    template <typename back, typename... args>
    struct remove::ini::reference<back( args... ) const volatile && noexcept>
    {
        using type = back( args... ) const volatile noexcept;
    };




    template <typename back, typename... args>
    struct remove::ini::exception<back( args... )>
    {
        using type = back( args... );
    };

    template <typename back, typename... args>
    struct remove::ini::exception<back( args... ) const>
    {
        using type = back( args... ) const;
    };

    template <typename back, typename... args>
    struct remove::ini::exception<back( args... ) volatile>
    {
        using type = back( args... ) volatile;
    };

    template <typename back, typename... args>
    struct remove::ini::exception<back( args... ) const volatile>
    {
        using type = back( args... ) const volatile;
    };

    template <typename back, typename... args>
    struct remove::ini::exception<back( args... ) noexcept>
    {
        using type = back( args... );
    };

    template <typename back, typename... args>
    struct remove::ini::exception<back( args... ) const noexcept>
    {
        using type = back( args... ) const;
    };

    template <typename back, typename... args>
    struct remove::ini::exception<back( args... ) volatile noexcept>
    {
        using type = back( args... ) volatile;
    };

    template <typename back, typename... args>
    struct remove::ini::exception<back( args... ) const volatile noexcept>
    {
        using type = back( args... ) const volatile;
    };

    template <typename back, typename... args>
    struct remove::ini::exception<back( args... ) &>
    {
        using type = back( args... ) &;
    };

    template <typename back, typename... args>
    struct remove::ini::exception<back( args... ) const &>
    {
        using type = back( args... ) const &;
    };

    template <typename back, typename... args>
    struct remove::ini::exception<back( args... ) volatile &>
    {
        using type = back( args... ) volatile &;
    };

    template <typename back, typename... args>
    struct remove::ini::exception<back( args... ) const volatile &>
    {
        using type = back( args... ) const volatile &;
    };

    template <typename back, typename... args>
    struct remove::ini::exception<back( args... ) & noexcept>
    {
        using type = back( args... ) &;
    };

    template <typename back, typename... args>
    struct remove::ini::exception<back( args... ) const & noexcept>
    {
        using type = back( args... ) const &;
    };

    template <typename back, typename... args>
    struct remove::ini::exception<back( args... ) volatile & noexcept>
    {
        using type = back( args... ) volatile &;
    };

    template <typename back, typename... args>
    struct remove::ini::exception<back( args... ) const volatile & noexcept>
    {
        using type = back( args... ) const volatile &;
    };

    template <typename back, typename... args>
    struct remove::ini::exception<back( args... ) &&>
    {
        using type = back( args... ) &&;
    };

    template <typename back, typename... args>
    struct remove::ini::exception<back( args... ) const &&>
    {
        using type = back( args... ) const &&;
    };

    template <typename back, typename... args>
    struct remove::ini::exception<back( args... ) volatile &&>
    {
        using type = back( args... ) volatile &&;
    };

    template <typename back, typename... args>
    struct remove::ini::exception<back( args... ) const volatile &&>
    {
        using type = back( args... ) const volatile &&;
    };

    template <typename back, typename... args>
    struct remove::ini::exception<back( args... ) && noexcept>
    {
        using type = back( args... ) &&;
    };

    template <typename back, typename... args>
    struct remove::ini::exception<back( args... ) const && noexcept>
    {
        using type = back( args... ) const &&;
    };

    template <typename back, typename... args>
    struct remove::ini::exception<back( args... ) volatile && noexcept>
    {
        using type = back( args... ) volatile &&;
    };

    template <typename back, typename... args>
    struct remove::ini::exception<back( args... ) const volatile && noexcept>
    {
        using type = back( args... ) const volatile &&;
    };
}


#endif