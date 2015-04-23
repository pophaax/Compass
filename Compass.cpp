/*
 * Compass.cpp
 *
 *  Created on: Apr 23, 2015
 *      Author: sailbot
 */

#include "Compass.h"
#include "HMC6343.h"

HMC6343 sensor;


Compass::Compass() {

}

Compass::~Compass() {

}

bool Compass::init(){
	return sensor.init();
}

int Compass::getHeading(){
	return sensor.getHeading();
}

int Compass::getPitch(){
	return sensor.getPitch();
}

int Compass::getRoll(){
	return sensor.getRoll();
}

void Compass::readValues(){
	sensor.readValues();
}
