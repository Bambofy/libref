#pragma once

#include <set>

template <class T>
class Reference
{
public:
	/*
	 * Creates a null reference.
	 */
	Reference() : object(nullptr) {
	}
	
	/*
	 * Creates a reference from a newly allocated object.
	 *
	 * If the given object is not in the allocated_objects set
	 * then we need to insert it.
	 *
	 * If the given object is in the allocated_objects set then no action is
	 * required.
	 *
	 * If given a nullptr then do not add it to the allocated set.
	 */
	Reference(T* object) : object(object)
	{
		if (object != nullptr)
		{
			if (AllocatedObjects().find(object) == AllocatedObjects().end()) // not in the allocated objects set.
			{
				AllocatedObjects().insert(object);
			}
			else
			{
				// no action required.
			}
		}
		else
		{
			// no action required.
		}
	}

	/*
	 * Destroys this reference. Nothing
	 * happens to the object.
	 */
	~Reference()
	{
		object = nullptr;
	}

	/*
	 * Constructs this reference from then
	 * given.
	 */
	Reference(Reference& from)
	{
		object = from.object;
	}

	/*
	 * Constructs this reference from the
	 * given.
	 */
	Reference(Reference&& from)
	{
		object = from.object;
	}

	/*
	 * Constructs this reference from
	 * an assignment.
	 */
	Reference& operator=(Reference& rhs)
	{
		object = rhs.object;
		return *this;
	}

	/*
	 * Constructs this reference from
	 * a move assignment.
	 */
	Reference&& operator=(Reference&& rhs)
	{
		object = rhs.object;
		return *this;
	}

	/*
	 * Provides access to the object.
	 */
	T* operator->()
	{
		return object;
	}
	
	/*
	 * Creates a null pointer.
	 */
	static Reference<T> Null() {
		return NullReference();
	}

	/*
	 * Destroys the object, all references
	 * to it now are invalidated.
	 */
	void Destroy()
	{
		if (AllocatedObjects().find(object) == AllocatedObjects().end())
		{
			throw std::runtime_error("cannot destroy null reference.");
		}
		else
		{
			AllocatedObjects().erase(object);
			delete object;
			object = nullptr;
		}
	}
	
	/*
	 * Checks wheather this reference
	 * points to a valid object.
	 */
	bool Nulled()
	{
		bool nulled;
		
		if (object == nullptr)
		{
			nulled = true;
		}
		else
		{
			if (AllocatedObjects().find(object) == AllocatedObjects().end())
			{
				nulled = true;
			}
			else
			{
				nulled = false;
			}
		}
		
		return nulled;
	}
	
private:
	T* object;
	
	/*
	 * Cannot instantiate a static in a template
	 * .cpp file, this means that each allocated
	 * object set would be per translation unit
	 * instead of per whole program.
	 */
	static std::set<T*>& AllocatedObjects()
	{
		static std::set<T*> allocated_objects;
		return allocated_objects;
	}
	
	static Reference<T>& NullReference()
	{
		static Reference<T> null;
		return null;
	}
};
