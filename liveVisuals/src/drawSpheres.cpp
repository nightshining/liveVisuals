#include "drawSpheres.h"


drawSpheres::drawSpheres() {
    
    
}

drawSpheres::~drawSpheres() {
    
}

void drawSpheres::setup() {
    
    //Sphere bool
    spherePos.set(0, 0);
    sphereOn = false;
    
    
}

void drawSpheres::update() {
    
    rotateSphere += 0.33f;
    noise += 0.06f;
    sphereNoise = 100 * ofNoise(noise);
    
}

void drawSpheres::draw(ofColor c1, int size) {
    
    ofSetCircleResolution(100);
    for (int i = 0; i < 200; i += 5) {
        ofPushMatrix();
        ofSetColor(c1, i + 50);
        ofNoFill();
        ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
        ofScale(1.0, 1.0);
        ofRotateX(i + rotateSphere);
        ofRotateY(i + rotateSphere);
        ofCircle(spherePos, size);
        ofPopMatrix();
    }
    
    
}
