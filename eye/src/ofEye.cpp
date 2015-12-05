#include "ofEye.h"

using namespace std;

array<ofPoint,7> whiteEyePoints{ofPoint(-0.25,-0.52),ofPoint(-0.4,0.),ofPoint(-0.333,0.5),ofPoint(0.1,0.7),ofPoint(0.5,0.4),ofPoint(0.62,-0.1),/*ofPoint(0.5,-0.42),*/ofPoint(0.2,-0.55)};
array<ofPoint,8> matsugePoints{ofPoint(-0.4,0.2),ofPoint(-0.45,0.42),ofPoint(0.1,0.9),ofPoint(0.6,0.5),ofPoint(0.8,0.),ofPoint(0.65,-0.2),ofPoint(0.5,0.4),ofPoint(0.1,0.65)};


void ofEye::setup(){


}

void ofEye::update(){

}


void ofEye::draw(){


	for(int i = 0 ; i < 2 ; i++){
	int isMirror = (i==0)?1:-1;
	ofPushMatrix();
		ofTranslate(ofGetWidth()/2,ofGetHeight()/2);

		ofTranslate(ofGetWidth()/5.0 * isMirror,0);

		float scale = ofGetHeight()/2 * 4./5.;
		ofScale(scale * isMirror,-scale );
		ofFill();
		ofEnableSmoothing();	
			ofBeginShape();
				ofPushMatrix();	
				//	ofTranslate(isMirror * sin(ofGetFrameNum()/600.*TWO_PI)/8.,0);
					ofTranslate(isMirror * _pos.x,_pos.y);
					///Draw Black Eye
					ofSetColor(8,0,0);
					ofDrawEllipse(0,0,0.7,1.2);
					//Draw Kousai
					ofSetColor(95,82,65);
					ofDrawEllipse(0,-0.3,0.4,0.6);
					///Draw Doko
					ofSetColor(0,0,0);
					ofDrawCircle(0,0,0.2);
				
					//DrawLight   
					ofSetColor(234,232,237);
					ofDrawCircle(-0.1,0.4,0.15);
					ofDrawCircle(0.1,-0.3,0.1);
				ofPopMatrix();
			ofEndShape();

			//Draw White Eye
			ofBeginShape();
				//ofSetColor(255,0,0);
				//ofDrawRectangle(-1,-1,2,2);
				ofSetColor(228,200,176);
				ofVertex(-1,-2);
				ofVertex(-1,2);
				ofVertex(2,2);
				ofVertex(2,-2);
				ofNextContour(true);
					ofCurveVertex(whiteEyePoints[0]);	
					for(auto whiteEyePoint : whiteEyePoints){
						ofCurveVertex(whiteEyePoint);
					}
					ofCurveVertex(whiteEyePoints[whiteEyePoints.size()-1]);
				ofNextContour(false);
			ofEndShape();
				
			//Draw Debug Circle
			ofEnableAlphaBlending();
				ofSetColor(0,0,0,125);
					
				for(auto whiteEyePoint : whiteEyePoints){
					ofDrawCircle(whiteEyePoint,0.01);
				}
			ofDisableAlphaBlending();
			
			//Matsuge
			ofBeginShape();
				ofSetColor(ofColor::black);
				ofVertex(matsugePoints[0]);
				ofVertex(matsugePoints[1]);
				ofCurveVertex(matsugePoints[1]);
				ofCurveVertex(matsugePoints[1]);
				ofCurveVertex(matsugePoints[2]);
				ofCurveVertex(matsugePoints[3]);
				ofCurveVertex(matsugePoints[4]);
				ofCurveVertex(matsugePoints[5]);
				ofCurveVertex(matsugePoints[5]);
				
				ofCurveVertex(matsugePoints[5]);
				ofCurveVertex(matsugePoints[5]);
				ofCurveVertex(matsugePoints[6]);
				ofCurveVertex(matsugePoints[7]);
				ofCurveVertex(matsugePoints[0]);
				ofCurveVertex(matsugePoints[0]);
			ofEndShape();
			

		ofDisableSmoothing();
	ofPopMatrix();
	}
}

void ofEye::setEyePosition(ofPoint pos)
{
	_pos = pos;
}
