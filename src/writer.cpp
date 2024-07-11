#include "writer.h"

#include <fstream>

BinaryWriter::BinaryWriter(size_t size, ByteOrder byteOrder) : mByteOrder(byteOrder) {
	mInner = std::vector<u8>(size);
}

void BinaryWriter::save(const char* filename) {
	std::ofstream outfile(filename, std::ios::out | std::ios::binary);
	outfile.write(reinterpret_cast<const char*>(mInner.data()), mInner.size());
}

void BinaryWriter::writeU8(u8 value) {
	mInner.at(mCursor++) = value;
}

void BinaryWriter::writeU16(u16 value) {
	if (mByteOrder == ByteOrder::Big) {
		mInner.at(mCursor++) = (value >> 8) & 0xff;
		mInner.at(mCursor++) = value & 0xff;
	} else if (mByteOrder == ByteOrder::Little) {
		mInner.at(mCursor++) = value & 0xff;
		mInner.at(mCursor++) = (value >> 8) & 0xff;
	}
}

void BinaryWriter::writeU32(u32 value) {
	if (mByteOrder == ByteOrder::Big) {
		mInner.at(mCursor++) = (value >> 24) & 0xff;
		mInner.at(mCursor++) = (value >> 16) & 0xff;
		mInner.at(mCursor++) = (value >> 8) & 0xff;
		mInner.at(mCursor++) = value & 0xff;
	} else if (mByteOrder == ByteOrder::Little) {
		mInner.at(mCursor++) = value & 0xff;
		mInner.at(mCursor++) = (value >> 8) & 0xff;
		mInner.at(mCursor++) = (value >> 16) & 0xff;
		mInner.at(mCursor++) = (value >> 24) & 0xff;
	}
}
