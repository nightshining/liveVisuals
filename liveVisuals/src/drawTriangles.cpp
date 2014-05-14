
#include "drawTriangles.h"


drawTriangles::drawTriangles() {
    
    
}

drawTriangles::~drawTriangles() {
    
}

void drawTriangles::setup() {
    //Tri bool
    triOn = false;
    triPos.set(0, 0);
    
}

void drawTriangles::update() {
    
    rotateTri += 2.0f;
    rotateTri2 += 0.33f;
}

void drawTriangles::draw(int moveL, int moveR) {
    
        for (int i = 0; i < 50; i += 5) {
            ofSetColor(180, 180 + i, 240, i + 50);
            ofFill();
            ofPushMatrix();
            ofTranslate(ofGetWidth() / 2 + moveL, ofGetHeight() / 2 + moveR);
            ofScale(200.0, 200.0);
            ofRotateY(rotateTri + i * PI);
            ofRotateX(rotateTri2 + i * PI);
            ofBeginShape();
            ofVertex(triPos);
            ofVertex(triPos.x + 1, triPos.y);
            ofVertex(triPos.x + 0.50, triPos.y - 1);
            ofVertex(triPos);
            ofEndShape();
            ofPopMatrix();
            
            ofSetColor(ofColor::whiteSmoke, i + 75);
            ofNoFill();
            ofPushMatrix();
            ofTranslate(ofGetWidth() / 2 + moveL, ofGetHeight() / 2 + moveR);
            ofScale(200.0, 200.0);
            ofRotateY(rotateTri + i * PI);
            ofRotateX(rotateTri2 + i * PI);
            ofBeginShape();
            ofVertex(triPos);
            ofVertex(triPos.x + 1, triPos.y);
            ofVertex(triPos.x + 0.50, triPos.y - 1);
            ofVertex(triPos);
            ofEndShape();
            ofPopMatrix();
            
            }
        }



