#ifndef SINGLETON_H
#define SINGLETON_H
#include "include/global.h"

template <typename T>
class Singleton {
public:
    static std::shared_ptr<T> GetInstance(){
        static std::once_flag _flag;
        std::call_once(_flag,[](){
            _instance=std::shared_ptr<T>(new T);
        });
        return _instance;
    }
protected:
    Singleton()=default;
    ~Singleton(){}
    Singleton(const Singleton<T>&)=delete;
    Singleton<T>& operator=(const Singleton<T>&)=delete;
    static std::shared_ptr<T> _instance;
};

template <typename T>
std::shared_ptr<T> Singleton<T>::_instance=nullptr;

#endif // SINGLETON_H
