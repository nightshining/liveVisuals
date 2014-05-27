
#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetFullscreen(true);
    ofBackground(0);
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofSetFrameRate(60);
    
    //setup fbo
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    
#ifdef TARGET_OPENGLES
	fboFloat.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA ); // with alpha, 32 bits red, 32 bits green, 32 bits blue, 32 bits alpha, from 0 to 1 in 'infinite' steps
    ofLogWarning("testApp") << "GL_RGBA32F_ARB is not available for OPENGLES.  Using RGBA.";	
#else
    fboFloat.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F_ARB); // with alpha, 32 bits red, 32 bits green, 32 bits blue, 32 bits alpha, from 0 to 1 in 'infinite' steps
#endif
    
    fbo.begin();
	ofClear(255,255,255, 0);
    fbo.end();
	
	fboFloat.begin();
	ofClear(255,255,255, 0);
    fboFloat.end();
    
    ////Core Image//////
   // sourceFbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F_ARB); //32-bit framebuffer for smoothness
   // sourceFbo.begin();
   // ofClear(0);
   // sourceFbo.end();
    
   // setupFilters();
    ///////////////////////
    
    //SETUP ALL GRAPHICS//
    
    logo.setup();
    cube.setup();
    points.setup();
    lines.setup();
    pent.setup();
    orbs.setup();
    bars.setup();
    spirals.setup();
    triangles.setup();
    circles.setup();
    squares.setup();
    alphas.setup();
    spheres.setup();
    diamonds.setup();
    tunnel.setup();
    numbers.setup();
    
    //Key Counter
    counter = -1; 
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    fbo.begin();
    ofClear(255);
    if (logo.logoOn == true) {
        logo.update();
    }
    
    if (cube.cubeOn == true) {
        cube.update();
    }
    
    if (lines.linesOn == true) {
        lines.update();
    }
 
    if (pent.pentOn == true) {
        pent.update();
    }
    
    if (orbs.orbsOn == true) {
        orbs.update();
    }
    
    if (points.pointsOn == true) {
        points.update();
    }
    
    if (bars.barsOn == true) {
        bars.update();
    }
    
    if (spirals.spiralOn == true) {
        spirals.update();
    }
    
    if (triangles.triOn == true) {
        triangles.update();
    }
    
    if (circles.cirOn == true){
        circles.update();
    }
    
    if (squares.squaresOn == true){
        squares.update();
    }
    
    if (alphas.alphasOn == true) {
        alphas.update();
    }
    
    if (spheres.sphereOn == true) {
        spheres.update();
    }    
    
    if (diamonds.diamondsOn == true) {
        diamonds.update();
    }
    
    if (tunnel.tunnelOn == true) {
        tunnel.update();
    }
    
    if (numbers.numbersOn == true) {
        numbers.update();
    }
    
    
    fbo.end();
    
    //cout << "Frame Rate: " << ofGetFrameRate() << endl;
}

//--------------------------------------------------------------
void testApp::draw(){
    
   
    
    if(cube.cubeOn == true){
    cube.draw(cube.alphaTrigger);
    }
    
    if (lines.linesOn == true) {
        lines.draw(lines.sineWave);
    }
   
    if (pent.pentOn == true) {
        pent.draw(pent.alphaTriggerPent);
    }
    
    if (orbs.orbsOn == true) {
        ofVec2f scaleSet;
        scaleSet.set(2.0, 2.0);
        orbs.drawOrbs(ofColor::salmon, scaleSet- 1.50, orbs.alphaOrbsTrigger);
        orbs.drawOrbs(ofColor::white, scaleSet, 100);
    }
    
    if (points.pointsOn == true) {
        points.draw();
    }
    
    if (bars.barsOn == true) {
        bars.draw();
    }
    
    if (spirals.spiralOn == true) {
        spirals.draw();
    }
    
    if (triangles.triOn == true) {
        triangles.draw(-200, 0);
        triangles.draw(0, 0);
        triangles.draw(200, 0);
    }
    
    if (circles.cirOn == true) {
        circles.draw();
    }
    
    if (logo.logoOn == true) {
        logo.draw();
    }
    
    if (squares.squaresOn == true) {
        squares.draw();
    }
    
    if (alphas.alphasOn == true) {
    alphas.draw(alphas.alphasSetPos.x, alphas.alphasSetPos.y, alphas.sineAlphas);
    alphas.draw(alphas.alphasSetPos.x, alphas.alphasSetPos.y + ofGetHeight() / 2, alphas.sineAlphas2);
        }

    if (spheres.sphereOn == true) {
        spheres.draw(ofColor::magenta, spheres.sphereNoise);
        spheres.draw(ofColor::white, 300);
    }
    
    if (diamonds.diamondsOn == true) {
        diamonds.draw();
    }    
   
    if (tunnel.tunnelOn == true) {
        tunnel.draw();
    }
    if (numbers.numbersOn == true) {
        numbers.draw();
    }
   fbo.draw(0, 0);
   
    
    // bloomFilter.update(sourceFbo.getTextureReference());
   // bloomFilter.setIntensity(ofMap(mouseX,0,ofGetWidth(),0,1));
   // bloomFilter.draw(0,0);
    
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
    counter == 0 ? logo.logoOn = true : logo.logoOn = false;
    if (key == 'l') {
        logo.logoAlpha = 255;
    }
     
    //Turn CUBE on
    counter == 1 ? cube.cubeOn = true : cube.cubeOn = false;
    
    //CUBE ACTIONS//
    if (key == 'c') {
        cube.alphaTrigger = 150;
    }
    
    //Turn LINES on
    counter == 2 ? lines.linesOn = true : lines.linesOn = false;

    //LINES ACTIONS
    if (counter == 2) {
        lines.reset();
    } 
    
    //Turn LINES on
    counter == 3 ? pent.pentOn = true : pent.pentOn = false;
    
    //PENT ACTIONS
    if (key == 'p') {
    pent.alphaTriggerPent = 250;
    }
    
    //Turn ORBS on
    counter == 4 ? orbs.orbsOn = true : orbs.orbsOn = false;
    
    //ORBS ACTION
    if (key == 'o') {
    orbs.alphaOrbsTrigger = 255;
    }
    
    //Turn POINTS on
    counter == 5 ? points.pointsOn = true : points.pointsOn = false;
    
    //Turn BARS on
    counter == 6 ? bars.barsOn = true : bars.barsOn = false;
    
    //Turn SPIRAL on
    counter == 7 ? spirals.spiralOn = true : spirals.spiralOn = false;
    
    //Turn TRI on
    counter == 8 ? triangles.triOn = true : triangles.triOn = false;
    
    
    //Turn CIR on
    counter == 9 ? circles.cirOn = true : circles.cirOn = false;
    
    if (key == 'a') {
    circles.cirAlpha = 230;
    }
    
    //Turn SQUARES on
    counter == 10 ? squares.squaresOn = true : squares.squaresOn = false;
    if (key == 's') {
        squares.alphaSquares = 240;
    }
    
    //Turn ALPHAS on
    if (key == ' ') {
        alphas.alphasOn = true;
    }
    
    //Turn SPHERE on
    counter == 11 ? spheres.sphereOn = true : spheres.sphereOn = false;

    //Turn DIAMONDS on
    counter == 12 ? diamonds.diamondsOn = true : diamonds.diamondsOn = false;
    
    //Turn TUNNEL on
    counter == 13 ? tunnel.tunnelOn = true : tunnel.tunnelOn = false;
    tunnel.changeDirection(key);

    counter == 14 ? numbers.numbersOn = true : numbers.numbersOn = false;
    
    if (key == '`' ) {
        setup();
    }
    
    if (key == 'r') { ///KILL ALL///
        
        logo.logoAlpha = 0;
        cube.rotate = 0;
        cube.alphaTrigger = 0;
        lines.counterLine = 0;
        lines.sineWave = 0;
        pent.rotatePent = 0;
        pent.alphaTriggerPent = 0;
        orbs.rotateOrbs = 0;
        orbs.alphaOrbs = 0;
        orbs.alphaOrbsTrigger = 0;
        points.pointsGreen = 0;
        points.pointsCounter = 0;
        points.pointsRed = 0;
        points.pointsCounter2 = 0;
        bars.barsCounter = 0;
        bars.barsNoise = 0;
        spirals.counterSpiral = 0;
        spirals.rotateSpiral = 0;
        spirals.sineSpiral = 0;
        triangles.rotateTri = 0;
        triangles.rotateTri2 = 0;
        circles.cirAlpha = 0;
        circles.cirRotate = 0;
        squares.rotateSquares = 0;
        squares.alphaSquares = 0;
        alphas.sineAlphas = 0;
        alphas.counterAlphas = 0;
        alphas.sineAlphas2 = 0;
        alphas.counterAlphas2 = 0;
        spheres.rotateSphere = 0;
        spheres.noise = 0;
        spheres.sphereNoise = 0;
        diamonds.rotateDiamonds = 0;
        diamonds.counterDiamonds = 0;
        diamonds.sineDiamonds = 0;   
        tunnel.controlSpeed = 0;
        tunnel.rotateX = 0;
        tunnel.rotateY = 0;
    }
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

    if (key == ' ') {
        alphas.alphasOn = false;
    }
   
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

/*void testApp::setupFilters() {
    coreBase.setup();
    bloomFilter.setup(ofGetWidth(), ofGetHeight(), coreBase.glCIcontext);
}*/