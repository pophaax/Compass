/*
 * Compass.cpp
 *
 *  Created on: Apr 1, 2015
 *      Author: sailbot
 */
#include <wiringSerial.h>
#include "Compass.h"
#include "MockCompass.h"


Compass::Compass() {

}
Compass::Compass(MockCompass mc) {
	m_compass = mc;
	m_heading = 0;
}

Compass::~Compass() {
	// TODO Auto-generated destructor stub
}

bool Compass::setup() {
	if (!m_compass.init())
	{
		return false;
	}
	return true;
}

void Compass::loop() {

}

int Compass::getHeading() {
	if (m_compass.init()){
		return m_compass.getHeading();
	}
	return 0;

}
