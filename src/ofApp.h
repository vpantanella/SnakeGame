#pragma once

#include "ofMain.h"
#include "List.h"
#include "iostream"

using namespace std;

class ofApp : public ofBaseApp{
public:
    
    bool startscreen;
    bool gameover;
    List x,y;
    int w=30,h=30,bs=20,dir=2,applex=12,appley=10;
    int dx[4],dy[4];
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
    ofTrueTypeFont	myfont;
   
    
};
