#ifndef _Mem1FrameAllocator_H_
#define _Mem1FrameAllocator_H_

class MemNode;

class Mem1FrameAllocator
{
public:
	Mem1FrameAllocator(size_t size);
    ~Mem1FrameAllocator();

    void* Add(size_t size); // TODO: Find a way to return the proper type, not just void*
    void Remove(void* object);

    void Pop();
    void Clear();

private:
    MemBlock m_Block;

    GBYTE* m_Top;
    char* m_Marker; //
    MemNode* m_Markers;
};

#endif //!_Mem1FrameAllocator_H_