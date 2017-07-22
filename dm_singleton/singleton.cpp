#ifndef __SINGLETON_H
#define __SINGLETON_H

/**
* Singleton design pattern; only one instance is allowed.
*/
template <class T> class Singleton
{
public:

	/**
	* Constructor
	* @param instance New instance of T.
	*/
	Singleton<T>(T *obj)
	{
		instance = obj;
	}

	/** One and only instance. */
	static T *instance;
};

/* Initialize the static member obj. */
template <class T> T* Singleton<T>::instance = 0;

#endif /* __SINGLETON_H */


void main()
{

}