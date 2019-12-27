//
//  SoundModule.cpp
//  001_midi_module
//
//  Created by nicola bertelloni on 25/12/2019.
//

#include "ofSoundModule.h"

void ofSoundModule::setup(){
  ofSetWindowTitle("Sound Analysis LAB");
  int sampleRate = 44100;
  int bufferSize = 512;
  int outChannels = 0;
  int inChannels = 2;
  
  soundStream.setup(this, outChannels, inChannels, sampleRate, bufferSize, 3);
  //setup ofxAudioAnalyzer with the SAME PARAMETERS
  audioAnalyzer.setup(sampleRate, bufferSize, inChannels);
  
  audioPanelONE = gui.addPanel("AUDIO IMPACT");
  audioPanelONE->loadTheme("themes/three.json", true);
  audioPanelONE->setPosition(ofPoint(20,20));
  audioContONE = audioPanelONE->addContainer("", ofJson({{"direction", "horizontal"}}));
  audioContONE->add(smooth.set("smoothing", .5, 0, 1), ofJson({{"width", SLIDER_WIDTH}, {"height", SLIDER_HEIGHT}}));
  audioContONE->add(audioAmp.set("ampliphier", 2200.0, 0.0, 5000.0), ofJson({{"width", SLIDER_WIDTH}, {"height", SLIDER_HEIGHT}}));
  audioContONE->add(audioIndex.set("index", .05, 0, .1), ofJson({{"width", SLIDER_WIDTH}, {"height", SLIDER_HEIGHT}}));
  audioContONE->add(audioIndexStep.set("step index", .025, 0, .1), ofJson({{"width", SLIDER_WIDTH}, {"height", SLIDER_HEIGHT}}));
  
  audioPanelTWO = gui.addPanel("AUDIO IMPACT");
  audioPanelTWO->loadTheme("themes/three.json", true);
  audioPanelTWO->setPosition(audioPanelONE->getShape().getTopRight() + ofPoint(20,0));
  audioContTWO = audioPanelTWO->addContainer("", ofJson({{"direction", "vertical"}}));
  audioContTWO->add(centroid.set("centroid", 0, -1, 1), ofJson({{"width", SLIDER_WIDTH_H}, {"height", SLIDER_HEIGHT_H}}));
  audioContTWO->add<ofxGuiValuePlotter>(power.set("power", 0.0, 0.0, 1.0), ofJson({{"precision", 2}, {"width", SLIDER_WIDTH_H}, {"height", SLIDER_HEIGHT_H}}));
  
  ofBackground(10);
}
//   ----------------------------------------------------
void ofSoundModule::audioIn(ofSoundBuffer &inBuffer){
  //ANALYZE SOUNDBUFFER:
  audioAnalyzer.analyze(inBuffer);
}
//   ----------------------------------------------------
void ofSoundModule::update(){
  //  Stereo AUDIO VARIABLES
  LEFT = audioAnalyzer.getValue(RMS, 0, smooth);
  RIGHT = audioAnalyzer.getValue(RMS, 1, smooth);
  
  centroid = audioAnalyzer.getValue(CENTROID, 0, smooth, TRUE);
  bands = audioAnalyzer.getValues(MEL_BANDS, 0, smooth);
  power   = audioAnalyzer.getValue(POWER, 0, smooth);
  spectrum = audioAnalyzer.getValues(SPECTRUM, 0, smooth);

  BAND_NUMB = bands.size();
  BAND_WIDTH = (GRAPH_WIDTH / BAND_NUMB) - BAND_GAP;
  
  for (unsigned int i = 0; i < BAND_NUMB; i++){
    bands[i] = ofMap(bands[i], DB_MIN, DB_MAX, 0.0, 1.0, true);
    bands[i] = (bands[i] * audioAmp) * audioIndexAmp;
    bands[i] = ofMap(bands[i], 0.0, audioAmp * audioIndex, 0.0, 1.0, true);
    audioIndexAmp += audioIndexStep;
  }
  audioIndexAmp = audioIndex;
}

//   ----------------------------------------------------
void ofSoundModule::draw(){
  ofBackground(10, 10, 10, 10);
  
  ofPushMatrix();
  ofTranslate(MARGIN, ofGetHeight() - GRAPH_HEIGHT - MARGIN);
  
  for (unsigned int x = 0; x < BAND_NUMB; x++){
    for(unsigned int y = 0; y < CELL_NUMB; y++){
      ofColor fillColor  = ofColor(0, 0, 0, 0);
      float CELL_VALUE = 1 / float(CELL_NUMB);
      
      ALPHA = bands[x] > CELL_VALUE * y ? 200 : 40;
      
      if(y < 2) fillColor = ofColor(GREEN, ALPHA);
      else if(y >= 2 && y < 4) fillColor = ofColor(YELLOW, ALPHA);
      else if(y >= 4 && y < 6) fillColor = ofColor(ORANGE, ALPHA);
      else if(y >= 6) fillColor = ofColor(RED, ALPHA);
      
      float rectX = ((BAND_WIDTH + BAND_GAP) * x) + BAND_GAP;
      float rectY = GRAPH_HEIGHT - ((CELL_HEIGHT + CELL_GAP) * y) - CELL_HEIGHT - CELL_GAP;
      
      ofSetColor(fillColor); ofFill();
      ofDrawRectangle(rectX, rectY, BAND_WIDTH, CELL_HEIGHT);
    }
  }
  
  ofPopMatrix();
}
//   ----------------------------------------------------
void ofSoundModule::exit(){
  audioAnalyzer.exit();
}
