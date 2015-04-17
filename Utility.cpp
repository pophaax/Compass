#include "Utility.h"


int Utility::combineBytes(uint8_t MSB, uint8_t LSB)
{
	int combined = 0;

	combined = MSB;
	combined = (MSB << 8) + LSB;

	return combined;
}

int Utility::combineBytesSigned(uint8_t MSB, uint8_t LSB)
{
	int16_t combined = 0;

	combined = MSB;
	combined = (MSB << 8) + LSB;

	return int(combined);
}