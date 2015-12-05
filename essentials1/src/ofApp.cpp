#include "ofApp.h"
#include <array>

//ofPolyline poly;
ofPolyline kyuketsumaku;

std::array<ofPoint,4> kyoketsuArr{ofPoint(0,100),ofPoint(80,0),ofPoint(0,-100),ofPoint(-50,0)};


//--------------------------------------------------------------
void ofApp::setup(){


        ofSetWindowTitle("Video synth");
        ofSetWindowShape(1920,1080);
        ofSetFrameRate(60);
        ofBackground(ofColor::white);

	ofBackground(239,204,176);

	/*
	poly.addVertex(100,100);
	poly.bezierTo(0,0,-100,100,-100,-100);
	poly.close();
	//poly.bezierTo(100,-100);
	*/

	//kyuketsumaku.setClosed(true);

}

//--------------------------------------------------------------
void ofApp::update(){

	kyuketsumaku.clear();

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2 );


	ofFill();
	ofSetColor(ofColor::white);
	
	//int size = kyoketsuArr.size();
	//for(int i = 0 ; i < 1 ; i++)
	{
		kyuketsumaku.curveTo(kyoketsuArr[0]);
		kyuketsumaku.curveTo(kyoketsuArr[1]);
		kyuketsumaku.curveTo(kyoketsuArr[2]);
		kyuketsumaku.curveTo(kyoketsuArr[3]);
		kyuketsumaku.curveTo(kyoketsuArr[0]);
		kyuketsumaku.curveTo(kyoketsuArr[1]);
		kyuketsumaku.curveTo(kyoketsuArr[2]);
		//kyuketsumaku.close();
	}

//	ofSetStrokeColor(ofColor::black);
//	kyuketsumaku.clear();
//	kyuketsumaku.curveTo(0,100);
//	kyuketsumaku.curveTo(80,0);
//	kyuketsumaku.curveTo(0,-100);
//	kyuketsumaku.curveTo(-50,0);
//	kyuketsumaku.curveTo(0,100);
	kyuketsumaku.draw();

//	kyuketsumaku.

	

	/*
	ofSetLineWidth(3.0);
	ofSetColor(ofColor::black);
	ofLine(0,-100,0,100);
	*/

	/*
	ofSetCircleResolution(120);
	ofSetColor(ofColor::yellow);
	ofNoFill();
	ofCircle(0,0,ofGetFrameNum()%(ofGetWidth()/2));
	*/

	/*
	poly.draw();
	*/

	//polyline.clear();


	/*
	auto angle=0.;
	while(angle < TWO_PI)
	{
		polyline.curveTo(100*cos(angle),0,100*sin(angle));
		polyline.curveTo(300*cos(angle),300,300*sin(angle));
		angle += TWO_PI / (ofGetFrameNum() % 1000);
	}

	ofSetColor(ofColor::yellow);
	polyline.draw();
	*/

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
