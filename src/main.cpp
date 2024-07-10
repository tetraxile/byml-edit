#include <fstream>
#include <vector>

#include "types.h"

int main() {
	std::vector<u8> data = {
		0x59, 0x42, 0x03, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00
	};

	const char* filename = "test/file.byml";
	std::ofstream outfile(filename, std::ios::out | std::ios::binary);
	outfile.write(reinterpret_cast<const char*>(data.data()), data.size());
}
