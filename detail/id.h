#pragma once

//------------------------------------------------------------------------------

#ifdef __cplusplus

    class id {
        void* _p = nullptr;
    public:
        id() = default;
        id(void* p) : _p(p) {}
        operator void*() const { return _p; }
        template<typename T> operator T*() const { return (T*)_p; }
    };

    template<typename T>
    bool operator==(const id& a, const T* const b) {
        return (void*)a == (void*)b;
    }
    bool operator==(const id& a, const void* const b) {
        return (void*)a == (void*)b;
    }
    template<typename T>
    bool operator==(const T* const a, const id& b) {
        return (void*)a == (void*)b;
    }
    bool operator==(const void* const a, const id& b) {
        return (void*)a == (void*)b;
    }

    template<typename T>
    bool operator!=(const id& a, const T* const b) {
        return (void*)a != (void*)b;
    }
    bool operator!=(const id& a, const void* const b) {
        return (void*)a != (void*)b;
    }
    template<typename T>
    bool operator!=(const T* const a, const id& b) {
        return (void*)a != (void*)b;
    }
    bool operator!=(const void* const a, const id& b) {
        return (void*)a != (void*)b;
    }

#else // C ---------------------------------------------------------------------

    typedef void* id;

#endif // __cplusplus / C

//------------------------------------------------------------------------------
