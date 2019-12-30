//
//  ofPublicScreen.hpp
//  002_camera_tunnel
//
//  Created by nicola bertelloni on 30/12/2019.
//

#ifndef ofPublicScreen_hpp
#define ofPublicScreen_hpp

#include "ofMain.h"
#include "ofApp.h"
#include <stdio.h>

class ofPublicScreen : public ofBaseApp {
public:
  void setup();
  void update();
  void draw();
  void keyPressed(int key);
  void windowResized(int w, int h);
  
  ofFbo fbo;
  shared_ptr<ofApp> app;
};


#endif /* ofPublicScreen_hpp */
