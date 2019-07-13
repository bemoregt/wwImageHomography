#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	originalCorners[0].set(0, 0);
	originalCorners[1].set(100, 0);
	originalCorners[2].set(100, 100);
	originalCorners[3].set(0, 100);
	
	distortedCorners[0].set(50, 50);
	distortedCorners[1].set(450, 50);
	distortedCorners[2].set(450, 450);
	distortedCorners[3].set(50, 450);
    
    img1.load("/Users/mun/Desktop/lena512.png");
    img1.update();
    
    ofBackground(50);
}

//--------------------------------------------------------------
void testApp::update(){

	distortedCorners[2].set(mouseX, mouseY);
	homography = ofxHomography::findHomography(originalCorners, distortedCorners);
}

//--------------------------------------------------------------
void testApp::draw(){
	// Define a point to be drawn in the warped space
	ofPoint point(80,80);
	
	ofPushMatrix();
	ofMultMatrix(homography);
	
	ofSetColor(255);
	//ofDrawRectangle(0, 0, 100, 100);
    img1.draw(0, 0, 100, 100);
	
	// Draw a point in the warped space
	ofSetColor(ofColor::red);
	ofDrawCircle(point, 1);
	
	ofPopMatrix();
	
	// Draw the screen coordinates of that point
	ofSetColor(ofColor::white);
	ofPoint pointInScreen = ofxHomography::toScreenCoordinates(point, homography);
	ofDrawBitmapString("Local coordinates " + ofToString(point) + "\nScreen coordinates " + ofToString(pointInScreen) , pointInScreen);
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
