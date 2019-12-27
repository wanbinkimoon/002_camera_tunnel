//
//  SoundModule.hpp
//  001_midi_module
//
//  Created by nicola bertelloni on 25/12/2019.
//

#ifndef SoundModule_hpp
#define SoundModule_hpp

#include "ofMain.h"
#include "ofxGuiExtended.h"
#include "ofxAudioAnalyzer.h"

class ofSoundModule : public ofBaseApp {
  
public:
  void setup();
  void audioIn(ofSoundBuffer &inBuffer);
  void update();
  void draw();
  void exit();


  ofSoundStream soundStream;
  ofxAudioAnalyzer audioAnalyzer;
  float LEFT, RIGHT;
  vector<float> bands;
  vector<float> spectrum;
  
  int MARGIN = 20;
  int GRAPH_HEIGHT = 180;
  int GRAPH_WIDTH  = ofGetWidth() - (MARGIN * 2);
  
  int CELL_NUMB = 8;
  int CELL_GAP = 3;
  float CELL_HEIGHT = (GRAPH_HEIGHT / CELL_NUMB) - CELL_GAP;
  
  float BAND_WIDTH;
  int BAND_NUMB;
  int BAND_GAP = 6;
  
  float SLIDER_WIDTH = 80;
  float SLIDER_HEIGHT = 120;
  
  float SLIDER_WIDTH_H = 250;
  float SLIDER_HEIGHT_H = 55;
  
  ofColor RED = ofColor(250, 80, 50);
  ofColor ORANGE = ofColor(250, 160, 30);
  ofColor YELLOW = ofColor(250, 200, 30);
  ofColor GREEN = ofColor(150, 210, 80);
  int ALPHA;
  
  ofxGui gui;
  ofxGuiPanel* audioPanelONE;
  ofxGuiContainer* audioContONE;
  ofParameter<float> smooth = .5;
  ofParameter<float> audioAmp = 2200.0;
  ofParameter<float> audioIndex = 0.05;
  float audioIndexAmp = audioIndex;
  ofParameter<float> audioIndexStep = 0.025;
  
  ofxGuiPanel* audioPanelTWO;
  ofxGuiContainer* audioContTWO;
  ofParameter<float> centroid;
  ofParameter<float> power;
};



#endif /* SoundModule_hpp */
