
#include "drawCircles.h"


drawCircles::drawCircles() {
    
    
}

drawCircles::~drawCircles() {
    
}

void drawCircles::setup() {
    
    //Cir bool
    cirOn = false;
    
}

void drawCircles::update() {
    cirAlpha -= 5;
    cirRotate += 0.50f;
}

void drawCircles::draw() {
    
    ofSetCircleResolution(100);
    
    for (int i = 0; i < ofGetWidth(); i+=75 ) {
        for (int j = 0; j < ofGetHeight(); j+=75) {
            ofPushMatrix();
            ofTranslate(i, j);
            ofRotateX(cirAlpha + i * PI / 2);
            ofRotateY(cirRotate + i * PI / 2);
            ofSetColor(ofColor::white, 180);
            ofNoFill();
            ofCircle(0, 0, 25 + ofMap(cirAlpha, 0, ofGetWidth(), 0, 35));
            ofSetColor(ofColor::white, cirAlpha);
            ofFill();
            ofCircle(0, 0, 25 + ofMap(cirAlpha, 0, ofGetWidth(), 0, 35));
            ofPopMatrix();
        }
    }
 
}



