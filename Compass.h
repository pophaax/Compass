/*
 * Compass.h
 *
 *  Created on: Apr 23, 2015
 *      Author: sailbot
 */

#ifndef COMPASS_COMPASS_H_
#define COMPASS_COMPASS_H_

#include "HMC6343.h"

class Compass:public HMC6343 {

	public:

		Compass();
		~Compass();

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

#endif
