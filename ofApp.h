#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxOsc.h"

#define HOST "192.168.0.12"
#define PORT 9500

class ofApp : public ofBaseApp{

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofVideoPlayer lecteurVideo;

		ofxCvColorImage couleurImg;
		ofxCvGrayscaleImage grisImg;
		ofxCvGrayscaleImage grisBg;
		ofxCvGrayscaleImage grisDiff;
		ofxCvContourFinder contourDetecteur;
		ofxCvBlob blob;

		ofxOscSender sender;
		ofxOscMessage m;

		bool boolFrameInit;
		int seuil;
		float blobHauteur;

		




		
};
