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
		const int camWidth = 320;
		const int camHeight = 240;
		const int cvWidth = 80;
		const int cvHeight = 60;
		
};
