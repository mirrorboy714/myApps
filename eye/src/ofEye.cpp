#include "ofEye.h"

using namespace std;

array<ofPoint,7> whiteEyePoints{ofPoint(-0.25,-0.52),ofPoint(-0.4,0.),ofPoint(-0.333,0.5),ofPoint(0.1,0.7),ofPoint(0.5,0.4),ofPoint(0.62,-0.1),/*ofPoint(0.5,-0.42),*/ofPoint(0.2,-0.55)};
array<ofPoint,8> matsugePoints{ofPoint(-0.4,0.2),ofPoint(-0.45,0.42),ofPoint(0.1,0.9),ofPoint(0.6,0.5),ofPoint(0.8,0.),ofPoint(0.65,-0.2),ofPoint(0.5,0.4),ofPoint(0.1,0.65)};


void ofEye::setup(){


}

void ofEye::update(){
	
	ofFill();
}


void ofEye::draw(){


	ofPushMatrix();
	
	ofTranslate(_posEye);

	_isMirror = true;
	drawEye();

	_isMirror = false;
	drawEye();

	ofPopMatrix();
}

int ofEye::getMirror()
{
	return (_isMirror ? 1 : -1);
}

void ofEye::drawEye()
{
	ofPushMatrix();
		//position
		ofTranslate(_scale * getMirror(),0);

		//scale	
		//float scale = ofGetHeight()/2 * 4./5.;
		ofScale(_scale * getMirror(),-_scale );
		
		//draw
		ofEnableSmoothing();	
			drawWhiteEye();
			drawBlackEye();
			drawSkin();			
			drawMatsuge();
		ofDisableSmoothing();
	ofPopMatrix();
}

void ofEye::drawWhiteEye(){
	
	ofBeginShape();

		ofSetColor(ofColor::white);
		ofDrawRectangle(-1,-1,2.,2.);

	ofEndShape();

}

void ofEye::drawBlackEye()
{

		//draw hitomi	
			ofBeginShape();
				ofPushMatrix();	
					ofTranslate(getMirror() * _posBlackEye.x,_posBlackEye.y);
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
}

void ofEye::drawSkin()
{
	
			//Draw White Eye but drawing skin....
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
}

void ofEye::drawMatsuge()
{

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
}

void ofEye::setPosEye(ofPoint pos)
{
	_posEye = pos;
}


void ofEye::setPosBlackEye(ofPoint pos)
{
	_posBlackEye = pos;
}

void ofEye::setScale(float scale)
{
	_scale = scale;
}
