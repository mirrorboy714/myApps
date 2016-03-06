#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	 
	vidFace.setup();

	ofHideCursor();
	ofSetFullscreen(true);
	ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL_BILLBOARD);
}

//--------------------------------------------------------------
void ofApp::update(){

	vidFace.update();

	centroids = vidFace.centroids();

	for(auto centroid : centroids)
	{
		ofLog() << centroid; 
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	vidFace.draw();

	
	//Draw Text
	const ofPoint FONT_SIZE(8,11);
	const int MARGINE = 10;
	int textX = MARGINE;
	int textY = MARGINE+FONT_SIZE.y;
	string str = ("FrameRate:" + ofToString(ofGetFrameRate()));
	ofDrawBitmapStringHighlight(str,textX,textY);

	for(auto centroid : centroids){

		textY += MARGINE + textY;
		string centroidStr = "Centroid: " + ofToString(centroid.x) + " " + ofToString(centroid.y);

		ofDrawBitmapStringHighlight(centroidStr,textX,textY);
	}	
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	ofLog() << "key:" << key ;
	
	switch(key){
		case 32:
			ofImage img;
			img.grabScreen(0,0,ofGetWidth(),ofGetHeight());
			
			std::string fileName = "capture/" + ofGetTimestampString() + ".png";
			img.save(fileName,OF_IMAGE_QUALITY_BEST);
		break;
	};
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
