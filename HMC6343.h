#ifndef HMC6343_h
#define HMC6343_h

#include <stdint.h> // uint8_t


#define DEFAULT_I2C_ADDRESS 0x32

// HMC6343 Registers
#define REG_SLAVE_ADDRESS 0x00

// HMC6343 Commands
#define COM_POST_HEADING 0x50
#define COM_READ_EEPROM 0xE1

class HMC6343 {
public:
	HMC6343();
	~HMC6343();

	// setup for the connection between Raspberry Pi and the compass
	bool init();

	// returns m_heading
	int getHeading();

	// read heading, pitch and roll
	void readHeading();

private:
	// file descriptor
	int m_fd;
	uint8_t m_address;

	int m_heading;
	int m_pitch;
	int m_roll;

	// read a specified register of the EEPROM
	uint8_t readEEPROM(uint8_t reg);
};

#endif
