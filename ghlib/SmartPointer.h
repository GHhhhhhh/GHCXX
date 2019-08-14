//
// Created by 78455 on 2019/1/4.
//

#ifndef GH_CODE_SMARTPOINTER_H
#define GH_CODE_SMARTPOINTER_H

#include <cassert>
#include <cstdlib>

template<typename T>
class SmartPointer {
private:
    T* _ptr;
    size_t* _count;
public:
    explicit SmartPointer(T* ptr = nullptr) :
            _ptr(ptr) {
        if (_ptr) {
            _count = new size_t(1);
        } else {
            _count = new size_t(0);
        }
    }

    SmartPointer(const SmartPointer& ptr) {
        if (this != &ptr) {
            this->_ptr = ptr._ptr;
            this->_count = ptr._count;
            ++(*this->_count);
        }
    }

    SmartPointer& operator=(const SmartPointer& ptr) {
        if (this->_ptr == ptr._ptr) {
            return *this;
        }

        if (this->_ptr) {
            --(*this->_count);
            if (*this->_count == 0) {
                delete this->_ptr;
                delete this->_count;
            }
        }

        this->_ptr = ptr._ptr;
        this->_count = ptr._count;
        ++(*this->_count);
        return *this;
    }

    T& operator*() {
        assert(this->_ptr == nullptr);
        return *(this->_ptr);

    }

    T* operator->() {
        assert(this->_ptr == nullptr);
        return this->_ptr;
    }

    ~SmartPointer() {
        (*this->_count)--;
        if (*this->_count == 0) {
            delete this->_ptr;
            delete this->_count;
        }
    }

    size_t use_count(){
        return *this->_count;
    }
};




#endif //GH_CODE_SMARTPOINTER_H
