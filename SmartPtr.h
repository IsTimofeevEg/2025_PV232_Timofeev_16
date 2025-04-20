#ifndef SMARTPTR_H
#define SMARTPTR_H

template <class T>
class smart_ptr {
    T* obj;

public:
    smart_ptr(T* p = nullptr) : obj(p) {}
    smart_ptr(const smart_ptr& other) : obj(other.obj ? new T(*other.obj) : nullptr) {}

    smart_ptr(smart_ptr&& other) noexcept : obj(other.release()) {}

    ~smart_ptr() {
        reset();
    }

    smart_ptr& operator=(const smart_ptr& other) {
        if (this != &other) {
            reset(other.obj ? new T(*other.obj) : nullptr);
        }
        return *this;
    }

    smart_ptr& operator=(smart_ptr&& other) noexcept {
        if (this != &other) {
            reset(other.release());
        }
        return *this;
    }

    T* operator->() const { return obj; }
    T& operator*() const { return *obj; }
    explicit operator bool() const { return obj != nullptr; }

    T* get() const { return obj; }

    T* release() {
        T* p = obj;
        obj = nullptr;
        return p;
    }

    void reset(T* p = nullptr) {
        if (obj != p) {
            delete obj;
            obj = p;
        }
    }
};

#endif // SMARTPTR_H
