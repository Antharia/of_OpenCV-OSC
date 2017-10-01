#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	lecteurVideo.load("fingers.mov");
	lecteurVideo.play();
	lecteurVideo.setLoopState(OF_LOOP_NORMAL);

	couleurImg.allocate(320, 240);
	grisImg.allocate(320, 240);
	grisBg.allocate(320, 240);
	grisDiff.allocate(320, 240);

	sender.setup(HOST, PORT);

	boolFrameInit = true;

	seuil = 80;



}

//--------------------------------------------------------------
void ofApp::update(){
	ofBackground(50, 50, 50);

	bool boolNouvelleFrame;

	lecteurVideo.update();
	boolNouvelleFrame = lecteurVideo.isFrameNew();

	if (boolNouvelleFrame == true) {
		couleurImg.setFromPixels(lecteurVideo.getPixels());
		grisImg = couleurImg;
		if (boolFrameInit == true) {
			grisBg = grisImg;
			boolFrameInit = false;
		}
		grisDiff.absDiff(grisBg, grisImg);
		grisDiff.threshold(seuil);
		contourDetecteur.findContours(grisDiff, 20, (320*240)/3, 10, false);
	}

	if (contourDetecteur.nBlobs > 0) {
		blob = contourDetecteur.blobs[0];
		blobHauteur = blob.length;
		if (blobHauteur > 1) {
			m.setAddress("/main/proximite");
			blobHauteur = ofMap(blobHauteur, 1, 800, 0, 1);
			m.addFloatArg(blobHauteur);
			sender.sendMessage(m, false);
			m.clear();
		}
	}

	
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < contourDetecteur.nBlobs; i++) {
		contourDetecteur.blobs[i].draw(10, 10);
	}

	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
