#include "ofApp.h"
#include "wiringPiI2C.h"

using namespace std;

const auto itgAddress = 0x69;

const char WHO_AM_I = 0x00;
const char SMPLRT_DIV= 0x15;
const char DLPF_FS = 0x16;
const char GYRO_XOUT_H = 0x1D;
const char GYRO_XOUT_L = 0x1E;
const char GYRO_YOUT_H = 0x1F;
const char GYRO_YOUT_L = 0x20;
const char GYRO_ZOUT_H = 0x21;
const char GYRO_ZOUT_L = 0x22;

const char DLPF_CFG_0 = 1<<0;
const char DLPF_CFG_1 = 1<<1;
const char DLPF_CFG_2 = 1<<2;
const char DLPF_FS_SEL_0 = 1<<3;
const char DLPF_FS_SEL_1 = 1<<4;

auto fd = -1;

//--------------------------------------------------------------
void ofApp::setup(){

	//I2C Setting
	fd = wiringPiI2CSetup(itgAddress);
	cout << "fd:" << fd  << "\n";
	cout << "WHO_AM_I:" << wiringPiI2CReadReg16(fd,WHO_AM_I) << "\n";	
	cout << "Write DLPF_FS:" << wiringPiI2CWriteReg8(fd,DLPF_FS,(DLPF_FS_SEL_0|DLPF_FS_SEL_1|DLPF_CFG_0)) << "\n";
	cout << "Write SMPLRT_DIV:" << wiringPiI2CWriteReg8(fd,SMPLRT_DIV,9) << "\n";

	ofSetFullscreen(true);	
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofPushMatrix();

	ofTranslate(0,ofGetHeight()/2);

	ofBackground(0);

	function<int16_t(char H,char L)> getValue = [](char H,char L){

		int data = 0;
		data = static_cast<int8_t>(wiringPiI2CReadReg8(fd,H)) << 8;
		data += static_cast<int8_t>(wiringPiI2CReadReg8(fd,L));
	
		return data;
	};

	ofSetColor(255);

	const auto MAX_DATA = 10000;

	auto x = getValue(GYRO_XOUT_H,GYRO_XOUT_L);
	ofRect(0,0,ofGetWidth()/3.,ofMap(x,-MAX_DATA,MAX_DATA,ofGetHeight()/2.,-ofGetHeight()/2.));

	ofTranslate(ofGetWidth()/3,0);
	auto y = getValue(GYRO_YOUT_H,GYRO_YOUT_L);
	ofRect(0,0,ofGetWidth()/3,ofMap(y,-MAX_DATA,MAX_DATA,ofGetHeight()/2,-ofGetHeight()/2));

	ofTranslate(ofGetWidth()/3,0);
	auto z = getValue(GYRO_ZOUT_H,GYRO_ZOUT_L);
	ofRect(0,0,ofGetWidth()/3,ofMap(z,-MAX_DATA,MAX_DATA,ofGetHeight()/2,-ofGetHeight()/2));

	ofPopMatrix();
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
