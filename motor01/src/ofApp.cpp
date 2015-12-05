#include "ofApp.h"
#include "wiringPi.h"
#include "softPwm.h"

int AIN1 = 2;
int AIN2 = 3;
int PWMA = 1;

bool is1 = true;

//--------------------------------------------------------------
void ofApp::setup(){

	wiringPiSetup();

	pinMode(AIN1,OUTPUT);
	pinMode(AIN2,OUTPUT);
	//pinMode(PWMA,OUTPUT);
	softPwmCreate(PWMA,50,100);

	digitalWrite(AIN1,LOW);
	digitalWrite(AIN2,LOW);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	const auto delayTime = 10;

	(is1) ? digitalWrite(AIN1,HIGH) : digitalWrite(AIN2,HIGH);

	is1 = !is1;

	softPwmWrite(PWMA,100);
	delay(delayTime);
	digitalWrite(AIN1,LOW);
	digitalWrite(AIN2,LOW);

	delay(delayTime);

	
/*
	digitalWrite(AIN1,HIGH);
	
	for(int i = 0 ; i < 100 ; i++)
	{
		softPwmWrite(PWMA,i);
		delay(delayTime);
	}
        for(int i = 0 ; i < 100 ; i++)
        {
                softPwmWrite(PWMA,99-i);
                delay(delayTime);
        }

	digitalWrite(AIN1,LOW);

	delay(delayTime);

	digitalWrite(AIN2,HIGH);

	for(int i = 0 ; i < 100 ; i++)
	{
		softPwmWrite(PWMA,i);
		delay(delayTime);
	}
	for(int i = 0 ; i < 100 ; i++)
        {
                softPwmWrite(PWMA,99-i);
                delay(delayTime);
        }


	digitalWrite(AIN2,LOW);

	delay(delayTime);
*/	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
