#pragma once


#include "ofMain.h"
#include "ofxCvHaarFinder.h"
#include <vector>

class ofxVidFace {

public:
	ofxVidFace();
	void setup();
	void update();
	void draw();

	std::vector<ofPoint> centroids();

private:
		ofVideoGrabber vidGrabber;
		ofImage colorImg;
		ofFbo fbo;
		ofxCvHaarFinder finder;
		int camWidth;
		int camHeight;
		int cvWidth;
		int cvHeight;
		
};
