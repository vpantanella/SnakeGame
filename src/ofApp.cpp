#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    dx[0]=0;
    dx[1]=0;
    dx[2]=1;
    dx[3]=-1;
    dy[0]=1;
    dy[1]=-1;
    dy[2]=0;
    dy[3]=0;
    gameover=false;
    startscreen = true;
    myfont.loadFont("arial black copy.ttf", 25);
    x.push_back(5);
    y.push_back(5);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(startscreen){
        ofSetBackgroundColor(ofColor::green);
        ofSetColor(ofColor::black);
        myfont.drawString("PRESS P TO START", 100, 300);
    }
    
    ofSetColor(ofColor::black);
    for(int i=0;i<w;i++)
        ofLine(i*bs,0,i*bs,ofGetHeight());
    for(int i=0;i<h;i++)
        ofLine(0,i*bs,ofGetWidth(),i*bs);
    ofSetColor(ofColor::green);
    for(int i = 0; i < x.size(); i++)
    {
        ofRect(x.get_at(i)*bs,y.get_at(i)*bs,bs,bs);
    }
    ofSetColor(ofColor::red);
    ofRect(applex*bs,appley*bs,bs,bs);
    if(!gameover&&!startscreen) {
        if(ofGetFrameNum()%5==0) {
            x.insert_at(0, x.get_at(0) + dx[dir]);
            y.insert_at(0, y.get_at(0) + dy[dir]);
            if(x.get_at(0) < 0 || y.get_at(0) < 0 || x.get_at(0) >= w || y.get_at(0) >= h){
                gameover=true;
            }
            for(int i = 1; i < x.size(); i++){
                if(x.get_at(0) == x.get_at(i) && y.get_at(0) == y.get_at(i)) gameover=true;
            }
            
            if(x.get_at(0)==applex&&y.get_at(0)==appley){
                applex=(int)ofRandom(20);
                appley=(int)ofRandom(20);
                
            }
            else{
                x.delete_at(x.size()-1);
                y.delete_at(y.size()-1);
            }
        }
    }
    if(gameover){
        ofSetColor(ofColor::black);
        myfont.drawString("GAMEOVER", 100, 300);
        myfont.drawString("PRESS SPACE TO RESTART", 25, 400);
    }
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
        x.clear();
        y.clear();
        x.insert_at(0,5);
        y.insert_at(0,5);
        gameover = false;
        ofSetColor(225);
    }
    if (key == 'p'){
        gameover=false;
        startscreen=false;
    }
    
    if(key==OF_KEY_UP)
        dir=1;
    if(key==OF_KEY_DOWN)
        dir=0;
    if(key==OF_KEY_LEFT)
        dir=3;
    if(key==OF_KEY_RIGHT)
        dir=2;
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
