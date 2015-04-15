#include "HMC6343.h"
#include <wiringPiI2C.h>
#include <wiringPi.h> // delay
#include <unistd.h> // close
#include "Utility.h"


HMC6343::HMC6343()
{
	m_address = DEFAULT_I2C_ADDRESS;
	m_fd = -1;

	m_heading = 0;
	m_pitch = 0;
	m_roll = 0;
}

HMC6343::~HMC6343()
{
	// behöver man lägga den i sleep/standby?
	close(m_fd);
}

bool HMC6343::init()
{
	bool success = true;
	uint8_t data = 0x00;

	// set up I2C
	m_fd = wiringPiI2CSetup(m_address);

	if (m_fd == -1) {
		success = false; // you can consult errno?
	}
	else {
		// Check for device by reading I2C address from EEPROM
		data = readEEPROM(REG_SLAVE_ADDRESS);
		
		// Check if value read in EEPROM is the expected value for the HMC6343 I2C address
		if (data != DEFAULT_I2C_ADDRESS)	{
			success = false; // Init failed, EEPROM did not read expected I2C address value
		}
	}

	return success;
}

int HMC6343::getHeading()
{
	return m_heading;
}

void HMC6343::readHeading()
{
	const int transferSize = 6;
	// head(MSB/LSB), pitch(MSB/LSB), roll(MSB/LSB)
	uint8_t postHeadingData[transferSize];

	wiringPiI2CWrite(m_fd, COM_POST_HEADING);
	delay(1); // wait for processing of command

	for(int i = 0; i < transferSize; i++) {
		postHeadingData[i] = wiringPiI2CRead(m_fd);
	}

	m_heading = Utility::combineBytes(postHeadingData[0], postHeadingData[1]);
	m_pitch = Utility::combineBytes(postHeadingData[2], postHeadingData[3]);
	m_roll = Utility::combineBytes(postHeadingData[4], postHeadingData[5]);
}

// Send a command to the HMC6343 to read a specified register of the EEPROM
uint8_t HMC6343::readEEPROM(uint8_t reg)
{
	uint8_t data = 0x00;
	wiringPiI2CWrite(m_fd, COM_READ_EEPROM);
	wiringPiI2CWrite(m_fd, reg);
	delay(10); // wait for processing of command

	data = wiringPiI2CRead(m_fd);

	return data;
}