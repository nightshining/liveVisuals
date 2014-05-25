
#include "drawPoints.h"

drawPoints::drawPoints() {
    
    
}

drawPoints::~drawPoints() {
    
}

void drawPoints::setup() {
    //Points vid and bool
    vid1.loadMovie("1.mov");
    pointsOn = false;
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    fbo.begin();
	ofClear(255,255,255, 0);
    fbo.end();
    
}

void drawPoints::update() {
    vid1.update();
    pointsCounter += 0.003f;
    pointsGreen = 255 * ofNoise(pointsCounter);
    
    pointsCounter += 0.005f;
    pointsRed = 255 * ofNoise(pointsCounter2);
    
}

void drawPoints::draw() {
    fbo.begin();
    ofClear(255);
    vid1.play();
    vid1.setSpeed(1.0);
    
    unsigned char * pixels = vid1.getPixels();
    
    int nChannels = vid1.getPixelsRef().getNumChannels();
    
    // let's move through the "RGB(A)" char array
    // using the red pixel to control the size of a circle.
    for (int i = 0; i < vid1.width; i += 5 ) {
        for (int j = 0; j < vid1.height; j += 5 ) {
            unsigned char r = pixels[(j * vid1.width + i) * nChannels     ];
            unsigned char g = pixels[(j * vid1.width + i) * nChannels  + 1];
            unsigned char b = pixels[(j * vid1.width + i) * nChannels  + 2];
            
            float val = 1 - ((float)b  / 255.0f);
            ofSetColor(r + pointsRed, pointsGreen, b, 200);
            ofPushMatrix();
            ofTranslate(275, 100);
            ofScale(1.0, 1.0);
            ofFill();
            ofCircle(i, j, ofMap(val, 0.0, 1.0, -1, -200), val + 1.0);
            ofPopMatrix();
            
        }
    }
    fbo.end();

    fbo.draw(0, 0);
    
}

