#ifndef __SINGLETON_H__
#define __SINGLETON_H__

/**
 * (c) 2013 Cleversoap
 */

#include <cstdint>
#include <cstddef>

// Get the singleton instance of a class
#define SING(t) t::getInstance()

// Allow protected singleton inheritance
#define INHERIT_SINGLETON(t) friend class Singleton<t>;

// Singleton template class
template <class T>
class Singleton
{
    public:
        inline static T & getInstance() {
            static uint8_t allocation[sizeof(T)];

            if (_instance == nullptr)
                _instance = new (allocation) T;

            return *_instance;
        }

    public:
        Singleton() {};
        virtual ~Singleton() {
            _instance = nullptr;
            delete _instance;
        };

    protected:
        T & operator=(const T &) = delete;

        Singleton(const T &) = delete;

        inline static void* operator new(std::size_t, void* location) {
            return location;
        }

        static T* _instance;
};

template <class T>
T* Singleton<T>::_instance = nullptr;

#endif
