//
//  CameraModule.cpp
//  002_camera_tunnel
//
//  Created by nicola bertelloni on 27/12/2019.
//

#include "ofApp.h"


void ofApp::scene(){
  ofTranslate(ofGetWidth() * .5, ofGetHeight() * .5);
  
  sceneRotation = ofMap(midi->knobsONE[0], 0, 100, 0, 360);
  sceneRotationIncFactor = ofMap(midi->knobsONE[8], 0, 100, .001, .1);
  
  if(midi->knobsONE[8] > 0) sceneRotationInc += sceneRotationIncFactor;
  else sceneRotationInc = 0.1;
  
  float angle = sceneRotation + sceneRotationInc;
  ofRotateDeg(angle);
};


void ofApp::camera(){
  ofPushMatrix();
  ofPushStyle();
  ofTranslate(ofGetWidth() * -.5, ofGetHeight() * -.5);
  
  ofEnableBlendMode(OF_BLENDMODE_DISABLED);
  ofSetColor(color->palette[0]);
  vidGrabber.draw(0,0);
  
  ofPopMatrix();
  ofPopStyle();
}

void ofApp::circle(){
  ofPushMatrix();
//  ofTranslate(ofGetWidth() * .5, ofGetHeight() * .5);
  
  if(midi->padsTWO[1]) ofFill();
  else ofNoFill();
  
  if(midi->padsTWO[7]) ofEnableBlendMode(OF_BLENDMODE_SCREEN);
  else ofEnableBlendMode(OF_BLENDMODE_ADD);
  
  float circNumb = ofMap(midi->knobsTWO[0], 0, 100, 1, 20);
  
  float soundPump = sound->centroid * ofMap(midi->knobsTWO[3], 0, 100, 0, 1000);
  float maxRadius = ofMap(midi->knobsTWO[1], 0, 100, 10, min(ofGetWidth(), ofGetHeight())) + soundPump;
//  float maxRadius = ofMap(midi->knobsTWO[1], 0, 100, 10, min(ofGetWidth(), ofGetHeight()));
  float radiusStep = maxRadius / circNumb;
  float angleStep = 360 / float(sound->bands.size());
  
  //  std::cout << "circcle number: " << circNumb << "\n";
  //  std::cout << "midi value: " << midi->knobsONE[0] << "\n";
  //  std::cout << "--------------------------\n\n";
  
  
  for(unsigned int i = 0; i < circNumb; i++){
    int circAlpha = ofMap(i, 0, circNumb, 100, 250);
    ofColor circColor = ofColor(color->palette[1], circAlpha);
    ofSetColor(circColor);
    
    
    ofBeginShape();
    for (unsigned int p = 0; p < sound->bands.size(); p++) {
      float soundImpact = sound->bands[p] * midi->knobsTWO[2];
      float radius = (radiusStep * (circNumb - i)) + (soundImpact);
      float angle = ofDegToRad(angleStep * (p + 1));
      float x = cos(angle) * radius;
      float y = sin(angle) * radius;
      float z = (i + 1) * soundImpact;
  
//      ofCurveVertex(x, y);
      if(midi->padsTWO[2]) {
        if(!midi->padsTWO[1]) ofEnableBlendMode(OF_BLENDMODE_DISABLED);
        
        soundImpact = ofMap(soundImpact, 0, 100, 100, 500);
        ofSetSphereResolution(6);
        ofDrawSphere(x, y, z, soundImpact * .1);
      }
      else ofVertex(x, y, z);
      
    }
    
    float soundImpact = sound->bands[0] * midi->knobsTWO[2];
    float radius = (radiusStep * (circNumb - i)) + (soundImpact);
    float angle = ofDegToRad(angleStep * (1));
    float x = cos(angle) * radius;
    float y = sin(angle) * radius;
    
    ofEndShape(TRUE);
    
  }
  
  ofPopMatrix();
  ofPopStyle();
}
