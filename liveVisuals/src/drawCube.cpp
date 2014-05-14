
#include "drawCube.h"


drawCube::drawCube() {
    
    
}

drawCube::~drawCube() {
    
}

void drawCube::setup() {
    
    cubeOn = false;
}

void drawCube::update() {
    
    rotate += 0.53f;
    alphaTrigger -= 5;
    
}

void drawCube::draw(float alpha) {
    
    for (int i = 0; i < 200; i += 35) {
        
        ofPushMatrix();
        ofSetColor(ofColor::whiteSmoke, 180);
        ofNoFill();
        ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
        ofRotateY(rotate);
        ofDrawBox(0, 0, -1, i + 100, i + 100, i + 100);
        ofSetColor(ofColor::teal, alpha);
        ofFill();
        ofDrawBox(0, 0, -1, i + 50, i + 50, i + 50);
        ofPopMatrix();
        
    }
}

