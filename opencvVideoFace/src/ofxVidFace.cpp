#include "ofxVidFace.h"

using namespace std;



ofxVidFace::ofxVidFace(){

}

void ofxVidFace::setup(){

    	//we can now get back a list of devices.
    	vector<ofVideoDevice> devices = vidGrabber.listDevices();
	
    	for(auto device : devices){
        	if(device.bAvailable){
            		ofLogNotice() << device.id << ": " << device.deviceName;
        	}else{
            		ofLogNotice() << device.id << ": " << device.deviceName << " - unavailable ";
        	}
    	}

	vidGrabber.setUseTexture(false);
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
		finder.findHaarObjects(std::move(colorImg));
	}
}

void ofxVidFace::draw(){

	
	static const ofPoint vidPos((ofGetWidth()-camWidth)/2,(ofGetHeight()-camHeight)/2);
	ofTranslate(vidPos);

	ofPushMatrix();
	
		vidGrabber.draw(camWidth,0,-camWidth,camHeight);

		static const float CV_VID_RATIO = camWidth/cvWidth;

		for(auto blob : finder.blobs) {
			ofRectangle cur = std::move(blob.boundingRect);
			ofDrawRectangle(cur.x * CV_VID_RATIO, cur.y * CV_VID_RATIO, cur.width * CV_VID_RATIO, cur.height * CV_VID_RATIO);
		}


	ofPopMatrix();
}

std::vector<ofPoint> ofxVidFace::centroids(){
	
	std::vector<ofPoint> centroids;
	
	for(auto blob : finder.blobs)
	{
		blob.centroid.x = blob.centroid.x / cvWidth - 0.5;
		blob.centroid.y = blob.centroid.y / cvHeight - 0.5;
		centroids.push_back(blob.centroid);
	}

	return std::move(centroids);
}
