#ifndef Utility_h
#define Utility_h

#include <stdint.h> // uint8_t


class Utility {
public:
	static int combineBytes(uint8_t MSB, uint8_t LSB);
	static int combineBytesSigned(uint8_t MSB, uint8_t LSB);
};

#endif