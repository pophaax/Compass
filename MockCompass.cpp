/*
 * MockCompass.cpp
 *
 *  Created on: Apr 1, 2015
 *      Author: sailbot
 */

#include "MockCompass.h"

MockCompass::MockCompass() {
}

MockCompass::MockCompass(bool init, int mode) {
	m_init = init;
	m_heading = rand() % 360;
	m_mode = mode;
}

MockCompass::~MockCompass() {
	// TODO Auto-generated destructor stub
}

bool MockCompass::init() {
	return m_init;
}

int MockCompass::getHeading() {
	int shift;
	switch (m_mode) {
		case 1:
			// nothing to do
			break;
		case 2:
			shift = rand() % 3;
			if ( shift == 2){
				m_heading++;
			}
			else if (shift == 0) {
				m_heading--;
			}
			break;
		case 3:
			m_heading++;
			break;
		default:
			return 0;
	}
	sync();
	return m_heading;
}
void MockCompass::setHeading(int heading) {
	m_heading = heading;
}

void MockCompass::sync() {
	if (m_heading > 360){
		m_heading = m_heading - 361;
	}
	else if (m_heading < 0){
		m_heading = m_heading + 361;
	}
}
