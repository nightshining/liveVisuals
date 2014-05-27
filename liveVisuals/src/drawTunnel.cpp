
#include "drawTunnel.h"

drawTunnel::drawTunnel() {
    
    
}

drawTunnel::~drawTunnel() {
    
}

void drawTunnel::setup() {
    
    trails = true;
    controlSpeed = 0.0;
}

void drawTunnel::update() {
    
    rotateX += 0.50f + controlSpeed;
    rotateY += 0.44f + controlSpeed;

  }

void drawTunnel::draw() {
    
    for (int i = 0; i < ofGetWidth(); i += 200) {
    ofSetCircleResolution(3);
    ofPushMatrix();
    ofSetBackgroundAuto(trails);
   
    ofTranslate(i, ofGetHeight() / 2);
    ofRotateX(rotateX + i * PI / 2);
    ofRotateY(rotateY * PI);
    ofScale(2.0, 2.0);
    ofSetColor(ofColor::magenta, 240);
    ofNoFill();
    ofCircle(0, 0, 50);
    ofPopMatrix();
    }
}

void drawTunnel::changeDirection( int key ) {
    
    if (key == 't') {
        trails = !trails;
        
    }
    
    
    if (key == OF_KEY_RIGHT) {
        controlSpeed += 0.55f;
        
    }
    
    if (key == OF_KEY_LEFT) {
        controlSpeed -= 0.55f;
        
    }
    
}


