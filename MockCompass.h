/*
 * MockCompass.h
 *
 *  Created on: Apr 1, 2015
 *      Author: sailbot
 */

#ifndef _MOCKCOMPASS_H_
#define _MOCKCOMPASS_H_

#include <cstdlib>

class MockCompass {
public:
	MockCompass();
	/**
	 * param i init
	 * param mode [1 - 3] [static],[shifting] or [spinning] compass
	 */
	MockCompass(bool i, int mode);
	virtual ~MockCompass();
	bool init();
	int getHeading();
	void setHeading(int heading);
private:
	/**
	 * Selector for  mode 1 - 3. 1: static, 2:shifting, 3 rotating
	 */
	int m_mode;
	bool m_init;
	int m_heading;

	void sync();
};

#endif /* _MOCKCOMPASS_H_ */
