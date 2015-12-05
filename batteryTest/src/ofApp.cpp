#include "ofApp.h"

using namespace std;

const auto CHARGING_TIME = 0.016;

const int MARGIN = 20;
const int WIDTH = 200;

const int MAX_CHARGING_COUNT = 100;

auto counter = 0.0;

//auto startCount = 0.0;
auto chargeCount = 0;

bool timerFlg = false;
bool reverseFlg = false;
bool finishFlg = false;

auto reset = []{
	cout << "RESET COUNT\n";	
	counter = 0.0;
	timerFlg = false;
	reverseFlg = false;
	chargeCount = 0;
	ofResetElapsedTimeCounter();
	finishFlg = false;
	
};

//--------------------------------------------------------------
void ofApp::setup(){


	//Gui
	startButton.addListener(this,&ofApp::onStartPressed);
	resetButton.addListener(this,&ofApp::onResetPressed);

	gui.setup("BATTERY TEST","settings.xml",MARGIN,120);
	gui.add(startButton.setup("PLAY",false));
	gui.add(resetButton.setup("RESET"));

	reset();
}

void ofApp::startTimer(){

	cout << "START TIMER\n";
	timerFlg = true;

	(reverseFlg) ? battery.discharge() : battery.charge();
}

void ofApp::stopTimer(){
	
	cout << "STOP TIMER\n";
	timerFlg = false;

	battery.stop();
}

void ofApp::onStartPressed(bool & state){
	
	cout << "OnStartButtonPressed\n";// << state << "\n";
	if(state)
	{
		cout << "PLAY ON\n";
		startTimer();
	}else
	{
		cout << "PLAY OFF\n";
		stopTimer();
	}
}

void ofApp::onResetPressed(){

	cout << "OnResetPressed\n";
	reset();
}


void ofApp::finishTest()
{
	finishFlg = true;
	battery.stop();
	
}
//--------------------------------------------------------------
void ofApp::update(){

	static auto preTimef = 0.;

	if(finishFlg) return;

	if(timerFlg){

		if(!reverseFlg){
			counter += ofGetElapsedTimef() - preTimef;
			
			if(counter >= CHARGING_TIME){
				reverseFlg = true;
				battery.discharge();
			}
		}else{
			counter += (preTimef - ofGetElapsedTimef());

	
			if(counter <= 0){
				chargeCount++;
				
				if(chargeCount >= MAX_CHARGING_COUNT)
				{
					finishTest();
				}else{

					reverseFlg = false;
					battery.charge();
				}
			}
		}
	
	}
	
	preTimef = ofGetElapsedTimef();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackgroundGradient(ofColor::white,ofColor::gray);
	gui.draw();

	string timerStr = (reverseFlg) ? "discharging : " : "charging : ";
	timerStr += ofToString(counter);
	
	(reverseFlg) ? ofSetColor(ofColor::red) : ofSetColor(ofColor::yellow); 
	ofDrawRectangle(MARGIN,40,counter/CHARGING_TIME * WIDTH,20);	
	ofDrawLine(MARGIN+WIDTH,40,MARGIN+WIDTH,60);
	
	ofSetColor(ofColor::black);
	ofDrawBitmapString(timerStr,MARGIN,20);

	string chargeCountStr = "charge count : " + ofToString(chargeCount);
	ofDrawBitmapString(chargeCountStr,MARGIN,80);

	if(finishFlg)
		ofDrawBitmapString("Finish " + ofToString(MAX_CHARGING_COUNT) + " times charge/discharge.",MARGIN,100); 
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
