/*
 * Compass.h
 *
 *  Created on: Apr 1, 2015
 *      Author: sailbot
 */

#ifndef _COMPASS_H_
#define _COMPASS_H_

#include "MockCompass.h"


class Compass {
public:
	Compass();
	Compass(MockCompass mc);
	virtual ~Compass();
	bool setup();
	void loop();
	int getHeading();


private:
	MockCompass m_compass;
	int m_heading;

};

#endif /* _COMPASS_H_ */
