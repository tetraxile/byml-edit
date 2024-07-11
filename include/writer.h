#ifndef WRITER_H
#define WRITER_H

#include <vector>

#include "types.h"

enum class ByteOrder { Big, Little };

class BinaryWriter {
public:
	BinaryWriter(size_t size, ByteOrder byteOrder);
	
	void writeU8(u8 value);
	void writeU16(u16 value);
	void writeU32(u32 value);
	void writeU64(u64 value);

	void writeS8(s8 value);
	void writeS16(s16 value);
	void writeS32(s32 value);
	void writeS64(s64 value);
	
	void writeF32(f32 value);
	void writeF64(f64 value);

	void save(const char* filename);

private:
	ByteOrder mByteOrder;
	size_t mCursor = 0;
	std::vector<u8> mInner;
};

#endif
