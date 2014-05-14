
#include "drawPent.h"

drawPent::drawPent() {
    
    
}

drawPent::~drawPent() {
    
}

void drawPent::setup() {
    //Pent bool
    pentOn = false;
}

void drawPent::update() {
    
    rotatePent += 0.75f;
    alphaTriggerPent -= 5;

}

void drawPent::draw(float alpha) {
    
    for (int i = 0; i < 200; i += 15){
        
        ofSetCircleResolution(5);
        
        ofPushMatrix();
        ofSetColor(ofColor::teal, alphaTriggerPent);
        ofFill();
        ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
        ofRotateZ(-rotatePent);
        ofCircle(0, 0, i);
        ofPopMatrix();
        
        ofPushMatrix();
        ofSetColor(ofColor::whiteSmoke, 180);
        ofNoFill();
        ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
        ofRotateZ(rotatePent);
        ofCircle(0, 0, i + 100);
        ofPopMatrix();
    }
}

