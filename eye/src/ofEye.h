#pragma once

#include "ofMain.h"

class ofEye {

	public:
		void setup();
		void update();
		void draw();

		void setPosBlackEye(ofPoint pos);
		void setPosEye(ofPoint pos);
		void setScale(float scale);
	private:
		ofPoint _posBlackEye;
		ofPoint _posEye;
		float _scale;
		bool _isMirror;

		void drawEye();
		void drawWhiteEye();	
		void drawBlackEye();
		void drawMatsuge();
		void drawSkin();
		int getMirror();
};

