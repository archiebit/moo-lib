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




namespace moonmice
{
    namespace ini
    {
        template <typename target, typename... list>
        inline constexpr auto same
        {
            ( same<target, list> or ... )
        };

        template <typename target, typename other>
        inline constexpr auto same<target, other>
        {
            false
        };

        template <typename target>
        inline constexpr auto same<target, target>
        {
            true
        };

        template <typename target>
        inline constexpr auto same<target>
        {
            false
        };
    }


    /// @brief  Checks if the target type is in the list.
    /// @tparam target the type you want to find
    /// @tparam list... list of types
    template <typename target, typename... list>
    concept same = ini::same<target, list...>;
}


namespace moonmice
{
    namespace ini
    {
        template <typename in>
        inline constexpr auto constant
        {
            false
        };

        template <typename in>
        inline constexpr auto constant<in const>
        {
            true
        };
    }


    /// @brief  Checks if the target type has the 'const' qualifier.
    /// @tparam in target type for testing
    template <typename in>
    concept constant = ini::constant<in>;
}


namespace moonmice
{
    namespace ini
    {
        template <typename in>
        inline constexpr auto unstable
        {
            false
        };

        template <typename in>
        inline constexpr auto unstable<in volatile>
        {
            true
        };
    }


    /// @brief  Checks if the target type has the 'volatile' qualifier.
    /// @tparam in target type for testing
    template <typename in>
    concept unstable = ini::unstable<in>;
}


namespace moonmice
{
    namespace ini
    {
        template <typename in>
        inline constexpr auto defenses
        {
            false
        };

        template <typename in>
        inline constexpr auto defenses<in const>
        {
            true
        };

        template <typename in>
        inline constexpr auto defenses<in volatile>
        {
            true
        };

        template <typename in>
        inline constexpr auto defenses<in const volatile>
        {
            true
        };
    }


    /// @brief  Checks whether the target type has
    ///         the 'const' or 'volatile' qualifiers.
    /// @tparam in target type for testing
    template <typename in>
    concept defenses = ini::defenses<in>;
}


namespace moonmice
{
    namespace ini
    {
        template <typename in>
        inline constexpr auto reference
        {
            false
        };

        template <typename in>
        inline constexpr auto reference<in &>
        {
            true
        };

        template <typename in>
        inline constexpr auto reference<in &&>
        {
            true
        };
    }


    /// @brief  Checks if the target type is a reference.
    /// @tparam in taget type for testing
    template <typename in>
    concept reference = ini::reference<in>;
}


namespace moonmice
{
    namespace ini
    {
        template <typename in>
        inline constexpr auto point
        {
            false
        };

        template <typename in>
        inline constexpr auto point<in *>
        {
            true
        };

        template <typename in>
        inline constexpr auto point<in * const>
        {
            true
        };

        template <typename in>
        inline constexpr auto point<in * volatile>
        {
            true
        };

        template <typename in>
        inline constexpr auto point<in * const volatile>
        {
            true
        };
    }


    /// @brief  Checks if the target type is a pointer.
    /// @tparam in taget type for testing
    template <typename in>
    concept point = ini::point<in>;
}


namespace moonmice
{
    namespace ini
    {
        template <typename in>
        inline constexpr auto member
        {
            false
        };

        template <typename in, typename structure>
        inline constexpr auto member<in structure::*>
        {
            true
        };
    }


    /// @brief  Checks if the target type is a member pointer.
    /// @tparam in taget type for testing
    template <typename in>
    concept member = ini::member<in>;
}


namespace moonmice
{
    namespace ini
    {
        template <typename in>
        inline constexpr auto series
        {
            false
        };

        template <typename in>
        inline constexpr auto series<in[]>
        {
            true
        };

        template <typename in, unsigned long long int count>
        inline constexpr auto series<in[ count ]>
        {
            true
        };
    }


    /// @brief  Checks if the target type is an array.
    /// @tparam in taget type for testing
    template <typename in>
    concept series = ini::series<in>;
}


namespace moonmice
{
    namespace ini
    {
        template <typename in>
        inline constexpr auto function
        {
            false
        };

        template <typename back, typename... args>
        inline constexpr auto function<back( args... )>
        {
            true
        };

        template <typename back, typename... args>
        inline constexpr auto function<back( args... ) const>
        {
            true
        };

        template <typename back, typename... args>
        inline constexpr auto function<back( args... ) volatile>
        {
            true
        };

        template <typename back, typename... args>
        inline constexpr auto function<back( args... ) const volatile>
        {
            true
        };

        template <typename back, typename... args>
        inline constexpr auto function<back( args... ) noexcept>
        {
            true
        };

        template <typename back, typename... args>
        inline constexpr auto function<back( args... ) const noexcept>
        {
            true
        };

        template <typename back, typename... args>
        inline constexpr auto function<back( args... ) volatile noexcept>
        {
            true
        };

        template <typename back, typename... args>
        inline constexpr auto function<back( args... ) const volatile noexcept>
        {
            true
        };

        template <typename back, typename... args>
        inline constexpr auto function<back( args... ) &>
        {
            true
        };

        template <typename back, typename... args>
        inline constexpr auto function<back( args... ) const &>
        {
            true
        };

        template <typename back, typename... args>
        inline constexpr auto function<back( args... ) volatile &>
        {
            true
        };

        template <typename back, typename... args>
        inline constexpr auto function<back( args... ) const volatile &>
        {
            true
        };

        template <typename back, typename... args>
        inline constexpr auto function<back( args... ) & noexcept>
        {
            true
        };

        template <typename back, typename... args>
        inline constexpr auto function<back( args... ) const & noexcept>
        {
            true
        };

        template <typename back, typename... args>
        inline constexpr auto function<back( args... ) volatile & noexcept>
        {
            true
        };

        template <typename back, typename... args>
        inline constexpr auto function<back( args... ) const volatile & noexcept>
        {
            true
        };

        template <typename back, typename... args>
        inline constexpr auto function<back( args... ) &&>
        {
            true
        };

        template <typename back, typename... args>
        inline constexpr auto function<back( args... ) const &&>
        {
            true
        };

        template <typename back, typename... args>
        inline constexpr auto function<back( args... ) volatile &&>
        {
            true
        };

        template <typename back, typename... args>
        inline constexpr auto function<back( args... ) const volatile &&>
        {
            true
        };

        template <typename back, typename... args>
        inline constexpr auto function<back( args... ) && noexcept>
        {
            true
        };

        template <typename back, typename... args>
        inline constexpr auto function<back( args... ) const && noexcept>
        {
            true
        };

        template <typename back, typename... args>
        inline constexpr auto function<back( args... ) volatile && noexcept>
        {
            true
        };

        template <typename back, typename... args>
        inline constexpr auto function<back( args... ) const volatile && noexcept>
        {
            true
        };
    }


    /// @brief  Checks if the target type is a function.
    /// @tparam in taget type for testing
    template <typename in>
    concept function = ini::function<in>;
}


namespace moonmice
{
    namespace ini
    {
        template <typename in>
        inline constexpr auto method
        {
            false
        };

        template <typename structure, typename back, typename... args>
        inline constexpr auto method<back ( structure::* )( args... )>
        {
            true
        };

        template <typename structure, typename back, typename... args>
        inline constexpr auto method<back ( structure::* )( args... ) const>
        {
            true
        };

        template <typename structure, typename back, typename... args>
        inline constexpr auto method<back ( structure::* )( args... ) volatile>
        {
            true
        };

        template <typename structure, typename back, typename... args>
        inline constexpr auto method<back ( structure::* )( args... ) const volatile>
        {
            true
        };

        template <typename structure, typename back, typename... args>
        inline constexpr auto method<back ( structure::* )( args... ) noexcept>
        {
            true
        };

        template <typename structure, typename back, typename... args>
        inline constexpr auto method<back ( structure::* )( args... ) const noexcept>
        {
            true
        };

        template <typename structure, typename back, typename... args>
        inline constexpr auto method<back ( structure::* )( args... ) volatile noexcept>
        {
            true
        };

        template <typename structure, typename back, typename... args>
        inline constexpr auto method<back ( structure::* )( args... ) const volatile noexcept>
        {
            true
        };

        template <typename structure, typename back, typename... args>
        inline constexpr auto method<back ( structure::* )( args... ) &>
        {
            true
        };

        template <typename structure, typename back, typename... args>
        inline constexpr auto method<back ( structure::* )( args... ) const &>
        {
            true
        };

        template <typename structure, typename back, typename... args>
        inline constexpr auto method<back ( structure::* )( args... ) volatile &>
        {
            true
        };

        template <typename structure, typename back, typename... args>
        inline constexpr auto method<back ( structure::* )( args... ) const volatile &>
        {
            true
        };

        template <typename structure, typename back, typename... args>
        inline constexpr auto method<back ( structure::* )( args... ) & noexcept>
        {
            true
        };

        template <typename structure, typename back, typename... args>
        inline constexpr auto method<back ( structure::* )( args... ) const & noexcept>
        {
            true
        };

        template <typename structure, typename back, typename... args>
        inline constexpr auto method<back ( structure::* )( args... ) volatile & noexcept>
        {
            true
        };

        template <typename structure, typename back, typename... args>
        inline constexpr auto method<back ( structure::* )( args... ) const volatile & noexcept>
        {
            true
        };

        template <typename structure, typename back, typename... args>
        inline constexpr auto method<back ( structure::* )( args... ) &&>
        {
            true
        };

        template <typename structure, typename back, typename... args>
        inline constexpr auto method<back ( structure::* )( args... ) const &&>
        {
            true
        };

        template <typename structure, typename back, typename... args>
        inline constexpr auto method<back ( structure::* )( args... ) volatile &&>
        {
            true
        };

        template <typename structure, typename back, typename... args>
        inline constexpr auto method<back ( structure::* )( args... ) const volatile &&>
        {
            true
        };

        template <typename structure, typename back, typename... args>
        inline constexpr auto method<back ( structure::* )( args... ) && noexcept>
        {
            true
        };

        template <typename structure, typename back, typename... args>
        inline constexpr auto method<back ( structure::* )( args... ) const && noexcept>
        {
            true
        };

        template <typename structure, typename back, typename... args>
        inline constexpr auto method<back ( structure::* )( args... ) volatile && noexcept>
        {
            true
        };

        template <typename structure, typename back, typename... args>
        inline constexpr auto method<back ( structure::* )( args... ) const volatile && noexcept>
        {
            true
        };
    }


    /// @brief  Checks if the target type is a method of some class.
    /// @tparam in taget type for testing
    template <typename in>
    concept method = ini::method<in>;
}


namespace moonmice
{
    namespace ini
    {
        template <typename in>
        inline constexpr auto structure
        {
            false
        };

        template <typename in>
        inline constexpr auto structure<int in::*>
        {
            true
        };
    }


    /// @brief  Checks if the target type is a union, class or struct.
    /// @tparam in taget type for testing
    template <typename in>
    concept structure = ini::structure<int in::*>;
}


namespace moonmice
{
    /// @brief  Checks if the target type is floating point number.
    /// @tparam in target type for testing
    template <typename in>
    concept  floating = same
    <
        remove::defenses<in>,
        float,
        double
    >;


    /// @brief  Checks if the target type is character type.
    /// @tparam in target type for testing
    template <typename in>
    concept  symbolic = same
    <
        remove::defenses<in>,
        char,
        wchar_t,
        char8_t,
        char16_t,
        char32_t
    >;


    /// @brief  Checks if the target type is 'void'.
    /// @tparam in target type for testing
    template <typename in>
    concept   nothing = same
    <
        remove::defenses<in>,
        void
    >;


    /// @brief  Checks if the target type is 'bool'.
    /// @tparam in target type for testing
    template <typename in>
    concept   logical = same
    <
        remove::defenses<in>,
        bool
    >;


    /// @brief  Checks if the target type is the type of 'nullptr'.
    /// @tparam in target type for testing
    template <typename in>
    concept nullpoint = same
    <
        remove::defenses<in>,
        decltype( nullptr )
    >;


    /// @brief  Checks if the target type is a signed integer.
    /// @tparam in target type for testing
    template <typename in>
    concept sintegral = same
    <
        remove::defenses<in>,
        signed char,
        signed short int,
        signed int,
        signed long int,
        signed long long int
    >;


    /// @brief  Checks if the target type is an unsigned integer.
    /// @tparam in target type for testing
    template <typename in>
    concept uintegral = same
    <
        remove::defenses<in>,
        unsigned char,
        unsigned short int,
        unsigned int,
        unsigned long int,
        unsigned long long int
    >;


    /// @brief  Checks if the target type is an integer.
    /// @tparam in target type for testing
    template <typename in>
    concept    integral = requires
    {
        requires
            sintegral<in> or
            uintegral<in>;
    };


    /// @brief  Checks if the target type is an enumeration.
    /// @tparam in target type for testing
    template <typename in>
    concept enumeration = requires
    {
        requires
            not reference<in> and
            not     point<in> and
            not    member<in> and
            not  function<in> and
            not structure<in> and
            not  floating<in> and
            not  integral<in> and
            not  symbolic<in> and
            not   nothing<in> and
            not   logical<in> and
            not nullpoint<in>;
    };
}


#endif