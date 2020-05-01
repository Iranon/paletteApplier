/* =====================
   Matteo Vinci --- 2020
   ===================== */

#include "ofApp.h"
#include "paletteHandler.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("paletteApplier");
    //Load dialogue window
    ofFileDialogResult loadRes = ofSystemLoadDialog("Load Target Image");
    if(loadRes.bSuccess){
        string path = loadRes.getPath();
        target.load(path);
    }
    //Set program's window
    ofSetWindowShape(int(target.getWidth()), int(target.getHeight()));

    ofPixels & pixel = target.getPixels();  //array of image pixels
    for(int y = 0; y < ofGetHeight(); y++) {
        for(int x = 0; x < ofGetWidth(); x++) {

            int offset = (x + (y * ofGetWidth())) * 3;
            unsigned char rIn = pixel[offset +0];
            unsigned char gIn = pixel[offset +1];
            unsigned char bIn = pixel[offset +2];

            ofColor resultingColor = getPaletteColor(rIn, gIn, bIn);
            pixel[offset +0] = resultingColor.r;
            pixel[offset +1] = resultingColor.g;
            pixel[offset +2] = resultingColor.b;
        }
    }
    target.update();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    target.draw(0, 0);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    //Save dialogue window
    if(key == 's' || 'S'){
        ofFileDialogResult saveRes = ofSystemSaveDialog("result.jpg", "Save resulting image");
        if(saveRes.bSuccess) {
          string path = saveRes.getPath();
          target.save(path);
        }
    }

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
