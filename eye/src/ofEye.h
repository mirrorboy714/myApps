#pragma once

#include "ofMain.h"

class ofEye {

	public:
		void setup();
		void update();
		void draw();

		void setEyePosition(ofPoint pos);


	private:
		ofPoint _pos;
};

