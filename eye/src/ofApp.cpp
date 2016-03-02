#include "ofApp.h"

using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetFullscreen(true);
	ofSetCircleResolution(128);

	eye.setup();
	eye2.setup();

	eye.setPosEye(ofPoint(490,0));
	eye2.setPosEye(ofPoint(-200,200));
	eye.setScale(100);
	eye2.setScale(200);
}

//--------------------------------------------------------------
void ofApp::update(){
	
	eye.setPosBlackEye(ofPoint(0.35,0.35));	
	eye.update();
	eye2.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackground(ofColor::gray);
	ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
	
	eye.draw();
	eye2.draw();
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
