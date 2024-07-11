#include "writer.h"

#include <bit>
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

void BinaryWriter::writeU24(u32 value) {
	if (mByteOrder == ByteOrder::Big) {
		mInner.at(mCursor++) = (value >> 16) & 0xff;
		mInner.at(mCursor++) = (value >> 8) & 0xff;
		mInner.at(mCursor++) = value & 0xff;
	} else if (mByteOrder == ByteOrder::Little) {
		mInner.at(mCursor++) = value & 0xff;
		mInner.at(mCursor++) = (value >> 8) & 0xff;
		mInner.at(mCursor++) = (value >> 16) & 0xff;
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

void BinaryWriter::writeU64(u64 value) {
	if (mByteOrder == ByteOrder::Big) {
		mInner.at(mCursor++) = (value >> 56) & 0xff;
		mInner.at(mCursor++) = (value >> 48) & 0xff;
		mInner.at(mCursor++) = (value >> 40) & 0xff;
		mInner.at(mCursor++) = (value >> 32) & 0xff;
		mInner.at(mCursor++) = (value >> 24) & 0xff;
		mInner.at(mCursor++) = (value >> 16) & 0xff;
		mInner.at(mCursor++) = (value >> 8) & 0xff;
		mInner.at(mCursor++) = value & 0xff;
	} else if (mByteOrder == ByteOrder::Little) {
		mInner.at(mCursor++) = value & 0xff;
		mInner.at(mCursor++) = (value >> 8) & 0xff;
		mInner.at(mCursor++) = (value >> 16) & 0xff;
		mInner.at(mCursor++) = (value >> 24) & 0xff;
		mInner.at(mCursor++) = (value >> 32) & 0xff;
		mInner.at(mCursor++) = (value >> 40) & 0xff;
		mInner.at(mCursor++) = (value >> 48) & 0xff;
		mInner.at(mCursor++) = (value >> 56) & 0xff;
	}
}

void BinaryWriter::writeS8(s8 value) {
	writeU8(static_cast<u8>(value));
}

void BinaryWriter::writeS16(s16 value) {
	writeU16(static_cast<u16>(value));
}

void BinaryWriter::writeS32(s32 value) {
	writeU32(static_cast<u32>(value));
}

void BinaryWriter::writeS64(s64 value) {
	writeU64(static_cast<u64>(value));
}

void BinaryWriter::writeF32(f32 value) {
	writeU32(std::bit_cast<u32>(value));
}

void BinaryWriter::writeF64(f64 value) {
	writeU64(std::bit_cast<u64>(value));
}
