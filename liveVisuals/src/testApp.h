
#pragma once

////VISUAL SOFTWARE FOR CITYGIRL PERFORMANCE////

#include "ofMain.h"
//#include "ofxCoreImage.h"
#include "drawLogo.h"
#include "drawCube.h"
#include "drawPoints.h"
#include "drawLines.h"
#include "drawPent.h"
#include "drawBlurryOrbs.h"
#include "drawBars.h"
#include "drawSpirals.h"
#include "drawTriangles.h"
#include "drawCircles.h"
#include "drawSquares.h"
#include "drawAlphas.h"
#include "drawSpheres.h"
#include "drawDiamonds.h"
#include "drawTunnel.h"
#include "drawNumbers.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
   		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    drawLogo logo;
    drawCube cube;
    drawPoints points;
    drawLines lines;
    drawPent pent;
    drawBlurryOrbs orbs;
    drawBars bars;
    drawSpirals spirals;
    drawTriangles triangles;
    drawCircles circles;
    drawSquares squares;
    drawAlphas alphas;
    drawSpheres spheres;
    drawDiamonds diamonds;
    drawTunnel tunnel;
    drawNumbers numbers;
    
	//Cycle through visuals//
    int counter;
    
    ofFbo fbo, fboFloat;
    
    /*
     //Core Image//
    void setupFilters();
    ofxCI coreBase;
    ofxCIBloom bloomFilter;
    ofFbo sourceFbo;
     */
};
