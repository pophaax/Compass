/*
 * Compass.cpp
 *
 *  Created on: Apr 23, 2015
 *      Author: sailbot
 */

#include "Compass.h"
#include "HMC6343.h"

HMC6343 compass;

Compass::Compass() {

}

bool init(){
	return compass.init();
}


int Compass::getHeading(){
	return compass.getHeading();
}


int Compass::getPitch(){
	return getPitch();
}


int Compass::getRoll(){
	getRoll();
}


void Compass::readValues(){
	readValues();
}
