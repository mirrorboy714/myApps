#include "ofxVidFace.h"

using namespace std;



ofxVidFace::ofxVidFace(){

}

void ofxVidFace::setup(){

    	camWidth = 320;  // try to grab at this size.
	camHeight = 240;

	cvWidth = 80;
	cvHeight = 60;

    	//we can now get back a list of devices.
    	vector<ofVideoDevice> devices = vidGrabber.listDevices();
	
    	for(int i = 0; i < devices.size(); i++){
        	if(devices[i].bAvailable){
            		ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
        	}else{
            		ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
        	}
    	}

    	vidGrabber.setDeviceID(0);
    	vidGrabber.setDesiredFrameRate(60);
    	vidGrabber.initGrabber(camWidth, camHeight);

	fbo.allocate(cvWidth,cvHeight,GL_RGB);
	colorImg.allocate(cvWidth,cvHeight,OF_IMAGE_COLOR);

	finder.setup("haarcascade_frontalface_default.xml");
}

void ofxVidFace::update(){

	vidGrabber.update();	
	
	if(vidGrabber.isFrameNew())
	{
		fbo.begin();
			vidGrabber.draw(0,0,fbo.getWidth(),fbo.getHeight());
		fbo.end();

		fbo.readToPixels(colorImg);
		colorImg.mirror(false,true);
		finder.findHaarObjects(colorImg);
	}
}

void ofxVidFace::draw(){

	
	ofPoint vidPos((ofGetWidth()-camWidth)/2,(ofGetHeight()-camHeight)/2);
	ofTranslate(vidPos);

	ofPushMatrix();
	
	vidGrabber.draw(camWidth,0,-camWidth,camHeight);

	static const float CV_VID_RATIO = camWidth/cvWidth;

	for(int i = 0; i < finder.blobs.size(); i++) {
		ofRectangle cur = finder.blobs[i].boundingRect;
		ofDrawRectangle(cur.x * CV_VID_RATIO, cur.y * CV_VID_RATIO, cur.width * CV_VID_RATIO, cur.height * CV_VID_RATIO);
	}

	//Draw Text
	const ofPoint FONT_SIZE(8,11);
	const int MARGINE = 10;
	string str = ("FrameRate:" + ofToString(ofGetFrameRate()));
	ofDrawBitmapStringHighlight(str,MARGINE,MARGINE+FONT_SIZE.y);

	ofPopMatrix();
}

std::vector<ofPoint> ofxVidFace::centroids(){
	
	std::vector<ofPoint> centroids;
	
	for(auto blob : finder.blobs)
	{
		centroids.push_back(blob.centroid);
	}

	return centroids;
}
