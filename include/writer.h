#ifndef WRITER_H
#define WRITER_H

#include <vector>

#include "types.h"

enum class ByteOrder { Big, Little };

class BinaryWriter {
public:
	BinaryWriter(ByteOrder byteOrder);
	
	void save(const char* filename) const;
	void seek(size_t position);

	size_t size() const { return mInner.size(); }
	size_t position() const { return mCursor; }

	void writeU8(u8 value);
	void writeU16(u16 value);
	void writeU24(u32 value);
	void writeU32(u32 value);
	void writeU64(u64 value);

	void writeS8(s8 value);
	void writeS16(s16 value);
	void writeS32(s32 value);
	void writeS64(s64 value);
	
	void writeF32(f32 value);
	void writeF64(f64 value);

private:
	void checkSize(size_t elementSize);

	ByteOrder mByteOrder;
	size_t mCursor = 0;
	std::vector<u8> mInner;
};

#endif
