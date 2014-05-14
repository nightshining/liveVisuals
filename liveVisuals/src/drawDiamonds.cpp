#include "drawDiamonds.h"


drawDiamonds::drawDiamonds() {
    
    
}

drawDiamonds::~drawDiamonds() {
    
}

void drawDiamonds::setup() {
    
    //Diamonds bool
    diamondsOn = false;
    diamondsPos.set(0, 0);
    
}

void drawDiamonds::update() {
    
    rotateDiamonds += 0.33f;
    counterDiamonds += 0.005f;
    sineDiamonds = 255 * sin(counterDiamonds);
}

void drawDiamonds::draw() {
    
    ofSetCircleResolution(4);
    for (int i = 0; i < ofGetWidth(); i += 100) {
        for (int j = 0; j < ofGetHeight(); j += 100) {
            ofPushMatrix();
            ofTranslate( i, j );
            ofRotateX(rotateDiamonds);
            ofRotateY(sineDiamonds);
            ofSetColor(ofColor::white);
            ofNoFill();
            ofCircle(diamondsPos, 50);
            ofSetColor(ofColor::white, ofMap(-sineDiamonds, 255, -255, 255, 0, true));
            ofFill();
            ofCircle(diamondsPos, 40);
            ofSetColor(ofColor::salmon, ofMap(sineDiamonds, -255, 255, 0, 255, true));
            ofFill();
            ofCircle(diamondsPos, 25);
            ofPopMatrix();
        }
    }
}
