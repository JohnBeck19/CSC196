#include "Memory.h"
#include <iostream>

using namespace std;
meow::MemoryTracker meow::g_memoryTracker;


void* operator new (size_t size) {
	void* p = malloc(size);
	meow::g_memoryTracker.Add(p,size);

	return p;
}

void operator delete(void* address, size_t size) {
	meow::g_memoryTracker.Remove(address, size);
	free(address);
}

namespace meow {

	void MemoryTracker::Add(void* address, size_t size)
	{
		m_bytesAllocated += size;
		m_numAllocations++;
	}
	void MemoryTracker::Remove(void* address, size_t size)
	{
		m_bytesAllocated -= size;
		m_numAllocations--;
	}
	void MemoryTracker::displayInfo()
	{

		cout << "Current bytes allocated: " << m_bytesAllocated << endl;
		cout << "Current number allocations: " << m_numAllocations << endl;

	}
}