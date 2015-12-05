#ifndef _OF_BATTERY
#define _OF_BATTERY

#include "ofMain.h"

class ofBattery{

	public:
	//	void update();
	//	void draw();

		ofBattery();

		void charge();
		void discharge();
		void stop();
	private:
		bool isCharging = true;
		static const auto GPIO_OUT1 = 1;
		static const auto GPIO_OUT2 = 2;
};

#endif 
