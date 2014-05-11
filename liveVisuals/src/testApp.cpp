
#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetFullscreen(false);
    ofBackground(0);
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofSetFrameRate(60);
    
    //Logo imd and bool
    img.loadImage("logo.jpg");
    logoOn == false;
    
    //Points vid and bool
    vid1.loadMovie("1.mov");
    pointsOn = false;
    
    //Key Counter
    counter = -1;
    
    //Cube bool
    cubeOn = false;
    
    //Line bool
    linesOn = false;
    lineLeft.set(0, 0);
    lineRight.set(1, 0);
    
    //Pent bool
    pentOn = false;
    
    //Orbs bool
    orbsOn = false;
    
    //Bars bool
    barsOn = false;
    barsMove.set(0, 0);
    
    //Spiral bool
    spiralOn = false;
    
    //Tri bool
    triOn == false;
    triPos.set(0, 0);
    
    //Cir bool
    cirOn == false;
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    if (logoOn == true) {
        logoAlpha -= 3;
    }
    
    if (cubeOn == true) {
    rotate += 0.53f;
    alphaTrigger -= 5;
    }
    
    if (linesOn == true) {
    lineLeft.x -= 0.10f;
    lineRight.x += 0.10f;
    counterLine += 0.003f;
    sineWave = 50 * sin(counterLine);
    }
 
    if (pentOn == true) {
    rotatePent += 0.75f;
    alphaTriggerPent -= 5;
    }
    
    if (orbsOn == true) {
    rotateOrbs += 0.75f;
    alphaOrbsTrigger -= 10;
    }
    
    if (pointsOn == true) {
    vid1.update();
    pointsCounter += 0.003f;
    pointsGreen = 255 * ofNoise(pointsCounter);
    
    pointsCounter += 0.005f;
    pointsRed = 255 * ofNoise(pointsCounter2);
    }
    
    if (barsOn == true) {

    barsMove.y += 2.0f;
    if (barsMove.y >= ofGetHeight()) {
        barsMove.y *= -2.0f;
    }
    barsCounter += 0.05f;
    barsNoise = 255 * ofNoise(barsCounter);
    }
    
    if (spiralOn == true) {
    counterSpiral += 0.25f;
    sineSpiral += 0.05f;
    rotateSpiral = 1000 + sin(sineSpiral);
    }
    
    if (triOn == true) {
    rotateTri += 2.0f;
    rotateTri2 += 0.33f;
    }
    
    if (cirOn == true){
    cirAlpha -= 5;
    cirRotate += 0.50f;
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){

    
    if(cubeOn == true){
    drawCube(alphaTrigger);
    }
    
    if (linesOn == true) {
    drawLines(sineWave);
    }
   
    if (pentOn == true) {
    drawPent(alphaTriggerPent);
    }
    
    if (orbsOn == true) {
    ofVec2f scaleSet;
    scaleSet.set(2.0, 2.0);
    drawBlurryOrbs(ofColor::salmon, scaleSet - 1.50, alphaOrbsTrigger);
    drawBlurryOrbs(ofColor::white, scaleSet, 100);
    }
    
    if (pointsOn == true) {
    drawPoints();
    }
    
    if (barsOn == true) {
    drawBars();
    }
    
    if (spiralOn == true) {
    drawSpiral();
    }
    
    if (triOn == true) {
    drawTri(-200, 0);
    drawTri(0, 0);
    drawTri(200, 0);
    }
    
    if (cirOn == true) {
    drawCir();
    }
    
    if (logoOn == true) {
    drawLogo();
    }
}
void testApp::drawLogo(){
    
    ofPushMatrix();
    ofSetColor(255, 255, 255, logoAlpha);
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    img.setAnchorPoint(ofGetWidth() / 2 - 300, ofGetHeight() / 2 - 100);
    img.draw(0, 0, 600, 500);
    ofPopMatrix();
}
void testApp::drawCube(float alpha) {
    
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

void testApp::drawLines(float counterLine) {
    
    for(int i = 0; i < 200; i++){
    ofPushMatrix();
    ofSetColor(ofColor::magenta, i + 50);
        ofRotateY(i * PI / 2 + sineWave);
        ofRotateX(i * PI + sineWave);
    ofTranslate(ofGetWidth() / 2, ofGetHeight() - 200);
    ofScale(counterLine, counterLine);
    ofLine(lineLeft.x, lineLeft.y - i, lineRight.x, lineRight.y + i);
    ofPopMatrix();
    }
}

void testApp::drawPent(float alpha) {
    
    for(int i = 0; i < 200; i += 15){
        
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

void testApp::drawBlurryOrbs(ofColor insideOrb, ofVec2f scale, float alpha) {
    
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

void testApp::drawPoints() {
    
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
            ofTranslate(150, 100);
            ofScale(1.0, 1.0);
            ofFill();
            ofCircle(i, j, ofMap(val, 0.0, 1.0, -1, -200), val + 1.0);
            ofPopMatrix();
        
        }
    }

}

void testApp::drawBars() {
    
    for (int i = 0; i < ofGetHeight(); i += 20) {
        ofPushMatrix();
        ofSetColor(255);
        ofRotateX(i * PI);
        ofLine(barsMove.x, barsMove.y + i, ofGetWidth(), barsMove.y + i);
        ofSetColor(100, 255, 255, barsNoise);
        ofRect(barsMove.x, barsMove.y + i, ofGetWidth(), 100);
        ofPopMatrix();
    }
}

void testApp::drawSpiral() {

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

void testApp::drawTri(int moveL, int moveR) {
    
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

void testApp::drawCir() {
    
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


//--------------------------------------------------------------
void testApp::keyPressed(int key){

    ///// SIFT THROUGH VISUALS /////
    
    if (key == OF_KEY_UP) {
        counter++;
        //Keep an eye on Key Counter
        cout << "Change Visual: " << counter << endl;
    }
    else if (key == OF_KEY_DOWN){
        counter--;
        //Keep an eye on Key Counter
        cout << "Change Visual: " << counter << endl;
    }
    
    if (key == '1') {
        ofSetFullscreen(false);
    }
    if (key == '2') {
        ofSetFullscreen(true);
    }
    
    //Turn LOGO on
    counter == 0 ? logoOn = true : logoOn = false;
    if (key == 'l') {
        logoAlpha = 255;
    }
     
    //Turn CUBE on
    counter == 1 ? cubeOn = true : cubeOn = false;
    
    //CUBE ACTIONS//
    if (key == 'c') {
        alphaTrigger = 150;
    }
    
    //Turn LINES on
    counter == 2 ? linesOn = true : linesOn = false;

    //LINES ACTIONS
    if (counter == 2) {
        lineLeft.x = 0.0;
        lineRight.x = 0.0;
        counterLine = 0.0;
    } 
    
    //Turn LINES on
    counter == 3 ? pentOn = true : pentOn = false;
    
    //PENT ACTIONS
    if (key == 'p') {
    alphaTriggerPent = 250;
    }
    
    //Turn ORBS on
    counter == 4 ? orbsOn = true : orbsOn = false;
    
    //ORBS ACTION
    if (key == 'o') {
    alphaOrbsTrigger = 255;
    }
    
    //Turn POINTS on
    counter == 5 ? pointsOn = true : pointsOn = false;
    
    //Turn BARS on
    counter == 6 ? barsOn = true : barsOn = false;
    
    //Turn SPIRAL on
    counter == 7 ? spiralOn = true : spiralOn = false;
    
    //Turn TRI on
    counter == 8 ? triOn = true : triOn = false;
    
    
    //Turn CIR on
    counter == 9 ? cirOn = true : cirOn = false;
    
    if (key == 'a') {
    cirAlpha = 230;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

    
   
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

  
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

   
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
