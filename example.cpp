#include <iostream>
#include "Compass.h"
#include "MockCompass.h"

int main() {
	std::cout << "Compass example" << std::endl;
	std::cout << "---------------" << std::endl;
    std::cout << "creating object" << std::endl;

	Compass compass;

	std::cout << "initialization: " << compass.init() << std::endl;
	std::cout << "read" << std::endl;
	int i=0;
	while(i++<100) {
	compass.readValues();
		std::cout << "heading	: " << compass.getHeading() << std::endl;
		std::cout << "pitch		: " << compass.getPitch() << std::endl;
		std::cout << "roll		: " << compass.getRoll() << std::endl;
	}
}
