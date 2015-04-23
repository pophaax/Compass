/*
 * MockCompass.h
 *
 *  Created on: Apr 23, 2015
 *      Author: sailbot
 */

#ifndef COMPASS_MOCKCOMPASS_H_
#define COMPASS_MOCKCOMPASS_H_

class MockCompass {
public:
	MockCompass();
	~MockCompass();

	// initialize module
	bool init();

	// returns heading
	int getHeading();

	// returns pitch
	int getPitch();

	// returns roll
	int getRoll();

	// read values from module
	void readValues();
};

#endif /* COMPASS_MOCKCOMPASS_H_ */
