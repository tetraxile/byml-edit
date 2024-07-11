#include <fstream>
#include <vector>

#include "types.h"
#include "writer.h"

int main() {
	BinaryWriter writer(16, ByteOrder::Little);

	writer.writeU16(0x4259); // signature
	writer.writeU16(0x0003); // version
	writer.writeU32(0);      // hash key table offset
	writer.writeU32(0);      // string table offset
	writer.writeU32(0);      // root offset

	writer.save("test/file.byml");
}
