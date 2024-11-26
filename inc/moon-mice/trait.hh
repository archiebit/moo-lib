#ifndef MOONMICE_TRAIT_HH
#define MOONMICE_TRAIT_HH


namespace moonmice
{
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
            struct    entire;
        };


    public:
        template <typename in>
        using  constant = typename  ini::constant<in>::type;

        template <typename in>
        using  unstable = typename  ini::unstable<in>::type;

        template <typename in>
        using  defenses = typename  ini::defenses<in>::type;

        template <typename in>
        using reference = typename ini::reference<in>::type;

        template <typename in>
        using     point = typename     ini::point<in>::type;

        template <typename in>
        using    member = typename    ini::member<in>::type;

        template <typename in>
        using     array = typename     ini::array<in>::type;

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
}


#endif