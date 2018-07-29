#ifndef __SINGLETON_H__
#define __SINGLETON_H__
#include <cassert>
#include <iostream>
template<typename T>
class Singleton {
	
	static T* ms_Singleton;

public:
	
 	Singleton() 
	{
		assert(!ms_Singleton);
		int offset = (int)(T*)1 - (int)(Singleton<T>*)(T*)1;
		ms_Singleton = (T*)((int)this + offset);
		std::cout << "offset" << offset << std::endl 
				  << "ms_Singleton" << (int)ms_Singleton << std::endl
			      << "Singleton this:" << (int)this << std::endl;
	}

	~Singleton()
	{
		assert(ms_Singleton);
		ms_Singleton = 0;
	}
	static T& GetSingleton()
	{
		assert(ms_Singleton);
		return (*ms_Singleton);
	}
	static T* GetSingletonPtr()
	{
		assert(ms_Singleton);
		return (ms_Singleton);
	}
};

template <typename T>
T* Singleton<T>::ms_Singleton = 0;
#define INSTANCE(T) T::GetSingleton()
#endif

