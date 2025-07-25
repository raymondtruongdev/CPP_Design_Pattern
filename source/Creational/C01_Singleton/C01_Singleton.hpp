/**
 * Generated by: Raymond Truong
 * Date: 2025/07/22
 */

#pragma once
#include <iostream>
#include <mutex>
using namespace std;
namespace myapp {
    class Singleton {
        /**
        * The Singleton's constructor/destructor should always be private to
        * prevent direct construction/destruction calls with the `new`/`delete`
        * operator.
        */
    private:
        inline static mutex mutex;
        inline static unique_ptr<Singleton> instance = nullptr;
        explicit Singleton(string value);
        ~Singleton() ;

        // Allow unique_ptr to call private destructor
        friend struct std::default_delete<Singleton>;

        string value_;
    protected:

    public:
        // Singletons should not be cloneable.
        Singleton(const Singleton &) = delete;

        // Singletons should not be assignable.
        void operator=(const Singleton &) = delete;

        static Singleton *getInstance(const string& value);

        static void print_demo();

        [[nodiscard]] string value() const{
            return value_;
        }

    };
} // namespace myapp
