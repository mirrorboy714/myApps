#include "ofApp.h"
#include "wiringPi.h"
#include "softPwm.h"

using namespace std;

int SERVO = 1;
//int BIN1 = 4; 
//int AIN2 = 5;
//int BIN2 = 6;


//array<int,4> sig{1,0,0,0};

int step = 100;
//int dir = 1;

//--------------------------------------------------------------
void ofApp::setup(){

	wiringPiSetup();

	/*
	pinMode(AIN1,OUTPUT);
	pinMode(AIN2,OUTPUT);
	pinMode(BIN1,OUTPUT);
	pinMode(BIN2,OUTPUT);
	*/
	pinMode(SERVO,OUTPUT);
	softPwmCreate(SERVO,50,100);

	//digitalWrite(AIN1,LOW);
	//digitalWrite(AIN2,LOW);
}

//--------------------------------------------------------------
void ofApp::update(){

//	for(int i = 0 ; i < step ; i++)
	{
		softPwmWrite(SERVO,ofMap(ofRandom(100.),0.,100.,5.,25.));
		//printf("i:%d\n",i);
		delay(1000);

		/*
		for(auto i : sig) cout << i << " ";
		cout << "\n";
		*/

		/*
		digitalWrite(AIN1,sig[0]);
		digitalWrite(BIN1,sig[1]);
		digitalWrite(AIN2,sig[2]);
		digitalWrite(BIN2,sig[3]);


		if(dir > 0){
			rotate(sig.rbegin(),sig.rbegin()+1,sig.rend());
		}else{
			rotate(sig.begin(),sig.begin()+1,sig.end());
		}

		delay(10);
		*/		
	}

	/*
	dir = dir * -1;
	printf("dir:%d\n",dir);
	*/
}

//--------------------------------------------------------------
void ofApp::draw(){

	/*
	const auto delayTime = 10;

	(is1) ? digitalWrite(AIN1,HIGH) : digitalWrite(AIN2,HIGH);

	is1 = !is1;

	softPwmWrite(PWMA,100);
	delay(delayTime);
	digitalWrite(AIN1,LOW);
	digitalWrite(AIN2,LOW);

	delay(delayTime);
	*/
	
/*
	digitalWrite(AIN1,HIGH);
	
	for(int i = 0 ; i < 100 ; i++)
	{
		softPwmWrite(PWMA,i);
		delay(delayTime);
	}
        for(int i = 0 ; i < 100 ; i++)
        {
                softPwmWrite(PWMA,99-i);
                delay(delayTime);
        }

	digitalWrite(AIN1,LOW);

	delay(delayTime);

	digitalWrite(AIN2,HIGH);

	for(int i = 0 ; i < 100 ; i++)
	{
		softPwmWrite(PWMA,i);
		delay(delayTime);
	}
	for(int i = 0 ; i < 100 ; i++)
        {
                softPwmWrite(PWMA,99-i);
                delay(delayTime);
        }


	digitalWrite(AIN2,LOW);

	delay(delayTime);
*/	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
