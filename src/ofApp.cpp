#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetDataPathRoot("../Resources/data/");

//  shad4er.load("shader/shader");
  color->palette[0] = ofColor(36,36,22,255);
  color->palette[1] = ofColor(124,127,255,255);
  
  camWidth = ofGetWidth();
  camHeight = ofGetHeight();
  
  vidGrabber.setVerbose(true);
  vidGrabber.setup(camWidth,camHeight);

  ofEnableAlphaBlending();
  
  ofBackground(color->palette[0]);
}

//--------------------------------------------------------------
void ofApp::update(){
    vidGrabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofBackground(color->palette[0]);
//  shader.begin();
//  shader.setUniform1f("u_time", ofGetElapsedTimef());
//  shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
  ofApp::scene();
  
  if(midi->padsONE[0]) ofApp::camera();
  if(midi->padsTWO[0]) ofApp::circle();

//  shader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  std::cout << "Letter pressed: " << key << "\n";
  
  if(key == 'f' || key == 'F') FULLSCREEN = !FULLSCREEN;
  if(key == 's' || key == 'S') vidGrabber.videoSettings();
  
//  midi->keyPressed(key);
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

