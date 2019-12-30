//
//  ofApp.hpp
//  001_midi_module
//
//  Created by nicola bertelloni on 25/12/2019.
//

#pragma once

#include "ofMain.h"
#include "ofMidiModule.h"
#include "ofSoundModule.h"
#include "ofColorModule.h"

class ofApp : public ofBaseApp{
  
public:
  void setup();
  void update();
  void draw();
  
  void scene();
  void cubes();
  void camera();
  void circle();
  
  float cubesRotationInc = 0.1;
  float cubesRotationIncFactor = .001;
  
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
  
  ofShader shader;
  
  ofVideoGrabber vidGrabber;
//  int camWidth;
//  int camHeight;
  
  float sceneRotation = 0;
  float sceneRotationInc = 0.1;
  float sceneRotationIncFactor = .001;
  
  shared_ptr<ofMidiModule> midi;
  shared_ptr<ofSoundModule> sound;
  shared_ptr<ofColorModule> color;
  
  bool FULLSCREEN;
};
