#include "ofApp.h"

using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetFullscreen(true);
	ofSetCircleResolution(128);

	eye.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
	
	eye.setEyePosition(ofPoint(0.35,0.35));	
	eye.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackground(ofColor::white);

	eye.draw();
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
