#include "ofBattery.h"
#include "wiringPi.h"
#include "softPwm.h"


using namespace std;

ofBattery::ofBattery(){

	cout << "ofBattery()" << "\n";
	wiringPiSetup();

	pinMode(GPIO_OUT1,OUTPUT);
	pinMode(GPIO_OUT2,OUTPUT);

	stop();
}

void ofBattery::charge(){

	cout << "charge" << "\n";
	digitalWrite(GPIO_OUT1,true);
	digitalWrite(GPIO_OUT2,false);

}

void ofBattery::discharge(){

	cout << "discharge" << "\n";
	digitalWrite(GPIO_OUT1,false);
	digitalWrite(GPIO_OUT2,true);
}

void ofBattery::stop(){

	cout << "stop" << "\n";
	digitalWrite(GPIO_OUT1,false);
	digitalWrite(GPIO_OUT2,false);	
}


