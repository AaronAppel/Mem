#ifndef _MemBlock_H_
#define _MemBlock_H_

typedef char GBYTE; // Guardian standardized BYTE value

struct MemBlock
{
public:
    MemBlock() {}; // default constructor
	// MemBlock(int, int) object size, max # of objects
	MemBlock(int cellSize, int cellCount);
    MemBlock(int blockSize);
	~MemBlock();

    void InitUniform(int cellSize, int cellCount);
    void InitNonUniform(int blockSize);

	// Getters + Setters
    // Getters
    GBYTE* GetFirst();
	int GetCount();
	int GetCellSize();
	void GetRange(int* start, int* last); // return addresses of the first and last cells
	void* GetCellLocation(int index);
    int GetBlockSize();

    // Setters
    void NullCell(int index);
    void NullData(); // assign Mem_Null to each cell
    void SetData(int value); // assign a value to each cell

    // Private members currently public
	int m_CellSize = -1; // the size in BYTEs of one object. 0 means non-uniform size
	int m_CellCount = 0; // max # of objects
    size_t m_BlockSize = -1; // size of block in bytes
	GBYTE* m_Data = nullptr; // RAM block
};

#endif // !_MemBlock_H_
