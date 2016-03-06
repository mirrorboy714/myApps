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

	auto centroids = vidFace.centroids();

	ofLog() << "update:" ;

	for(auto centroid : centroids)
	{
		ofLog() << centroid; 
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	vidFace.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	ofLog() << "key:" << key ;
	
	switch(key){
		case 32:
			ofImage img;
			img.grabScreen(0,0,ofGetWidth(),ofGetHeight());
			
			string fileName = "capture/" + ofGetTimestampString() + ".png";
			img.saveImage(fileName,OF_IMAGE_QUALITY_BEST);
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
