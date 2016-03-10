#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){

	cam.setDesiredFrameRate(30);
	cam.setDeviceID(0);
	cam.initGrabber(640,480);

	finder.setup("haarcascade_frontalface_default.xml");
	finder.setPreset(ObjectFinder::Fast);

	ofSetCircleResolution(128);
	
	for(auto i = 0 ; i < EYE_NUM ; i++){
		posEyes[i] = ofPoint(ofRandom(-1.,1),ofRandom(-1.,1));
	}
}
//--------------------------------------------------------------
void ofApp::update(){

	cam.update();
	if(cam.isFrameNew()){
		finder.update(cam);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	//Draw Video
	ofPushMatrix();

	const float SCALE = (ofGetWidth()/cam.getWidth());
	const float OFFSET = -ofGetHeight()/3./SCALE;
	ofScale(SCALE,SCALE);
	ofTranslate(0,OFFSET);
	ofSetColor(60);
	cam.draw(cam.getWidth(),0,-cam.getWidth(),cam.getHeight());

	//Draw Face Rectangle
	ofRectangle *pRect = nullptr;//ofRectangle(0,0,0,0);

	ofSetColor(255,100,0);
	for(unsigned int index = 0 ; index < finder.size() ; index++){
	
		auto tempRect = finder.getObjectSmoothed(index);
		pRect = &tempRect; 
		auto center = pRect->getCenter();
		center.x = cam.getWidth() - center.x;
		pRect->setFromCenter(center,pRect->getWidth(),pRect->getHeight());
		ofDrawRectangle(*pRect);
	}
	ofPopMatrix();
	
	//update center
	if(pRect != nullptr){
		center = pRect->getCenter() / ofPoint(cam.getWidth()/2.,cam.getWidth()/2.) - ofPoint(1,1);
		center.z = 1.0 - pRect->getPerimeter()/ofGetWidth()/2.;
	}

	auto drawEye =[&](const ofPoint &pos){
			
			ofSetColor(255);
			const auto delta = center - pos;
			len = delta.length();
			theta = acos(center.z/len);
			const auto phi = atan2(delta.y,delta.x); 
			ofDrawCircle(0,0,.2);
			ofSetColor(30);
			ofDrawCircle(0.1 * theta * cos(phi),0.1 * theta * sin(phi),.1);

	};

	//Draw Eye
	ofPushMatrix();
		ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
		ofScale(ofGetWidth()/2.,ofGetWidth()/2.);

		
		for(auto i = 0 ; i < EYE_NUM ; i++)
		{
			ofPushMatrix();
				auto pos = posEyes[i];
				ofTranslate(pos);
				drawEye(pos);
			ofPopMatrix();
		}

		/*
		ofPushMatrix();
			ofTranslate(posLeftEye);
			drawEye(posLeftEye);
		ofPopMatrix();	
		ofPushMatrix();
			ofTranslate(posRightEye);
			drawEye(posRightEye);
		ofPopMatrix();
		*/
	ofPopMatrix();


	//Draw Information
	ofDrawBitmapStringHighlight("Framerate :" + ofToString(ofGetFrameRate()),10,40);
	ofDrawBitmapStringHighlight("Face Num :" + ofToString(finder.size()),10,20);

	ofDrawBitmapStringHighlight("Rect Center :" + ofToString(center),10,60);
	ofDrawBitmapStringHighlight("len:" + ofToString(len),10,80);
	ofDrawBitmapStringHighlight("theta:" + ofToString(theta),10,100);
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
