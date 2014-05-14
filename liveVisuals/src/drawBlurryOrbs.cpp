

#include "drawBlurryOrbs.h"


drawBlurryOrbs::drawBlurryOrbs() {
    
    
}

drawBlurryOrbs::~drawBlurryOrbs() {
    
}

void drawBlurryOrbs::setup() {
    //Orbs bool
    orbsOn = false;
}

void drawBlurryOrbs::update() {
    
    rotateOrbs += 0.75f;
    alphaOrbsTrigger -= 10;
}

void drawBlurryOrbs::drawOrbs(ofColor insideOrb, ofVec2f scale, float alpha) {

    for(int i = 0; i < 50; i+=2){
        
        ofSetCircleResolution(10);
        
        ofPushMatrix();
        ofSetColor(insideOrb, alpha);
        ofNoFill();
        ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
        ofRotateY(rotateOrbs + i * PI);
        ofRotateX(rotateOrbs / PI / 2);
        ofScale(scale.x, scale.y);
        ofCircle(0, 0, 150);
        ofPopMatrix();
        
    }
}

