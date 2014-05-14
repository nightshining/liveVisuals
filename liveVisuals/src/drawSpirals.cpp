
#include "drawSpirals.h"


drawSpirals::drawSpirals() {
    
    
}

drawSpirals::~drawSpirals() {
    
}

void drawSpirals::setup() {
    //Spiral bool
    spiralOn = false;
    
}

void drawSpirals::update() {
    
    counterSpiral += 0.25f;
    sineSpiral += 0.05f;
    rotateSpiral = 1000 + sin(sineSpiral);
}

void drawSpirals::draw() {
    
    for (int i = 0; i < ofGetWidth(); i += 3) {
        ofPushMatrix();
        ofSetColor(ofColor::salmon, i);
        ofFill();
        ofRotateX(i * PI / 2 + counterSpiral);
        ofTranslate(0, ofGetHeight());
        ofLine(i, counterSpiral, ofGetWidth(), 0);
        ofPopMatrix();
        
    }
}

