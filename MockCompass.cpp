/*
 * MockCompass.cpp
 *
 *  Created on: Apr 23, 2015
 *      Author: sailbot
 */

#include "MockCompass.h"

MockCompass::MockCompass() {

}

MockCompass::~MockCompass() {

}

bool MockCompass::init(){
	return true;
}

int MockCompass::getHeading(){
	return 100;
}

int MockCompass::getPitch(){
	return 200;
}

int MockCompass::getRoll(){
	return 300;
}

void MockCompass::readValues(){

}
int MockCompass::getAccel(){
	return 5;
}

void MockCompass::readTilt(){
}

void MockCompass::readMag(){
}

void MockCompass::readAccel(){
}

void MockCompass::setOrientation(uint8_t orientation){
}

CompassModel MockCompass::getModel(){
	return CompassModel(0,0,0);
}
