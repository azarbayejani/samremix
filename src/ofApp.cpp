#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    THRESHOLD = 0.12;
    zf = 0.0;
    x,y = 0;
    velocity.set(1,1);
    shader.load("shaders/shader");
    redShader.load("shaders/red_shader");
    videos = ofDirectory("/Users/azar/Movies/jlin1/").getFiles();
    images = ofDirectory("/Users/azar/tmp/SAM remix/images/").getFiles();
    currVid.load(videos.at(0).getAbsolutePath());
    texture.load(images.at(0).getAbsolutePath());
    texture2.load(images.at(1).getAbsolutePath());
    currVid.play();
    currVid.setVolume(0);
    
    fbo2.allocate(ofGetWidth(),ofGetHeight());
    fbo2.begin();
    ofClear(0);
    fbo2.end();
    
    fbo.allocate(ofGetWidth(),ofGetHeight());
    fbo.begin();
    ofClear(0);
    fbo.end();
    
    ofSoundStreamSetup(0, 1, this, 44100, beat.getBufferSize(), 4);
}

//--------------------------------------------------------------
void ofApp::update(){
    currVid.update();
    if (random() < 0.0001) {
        currVid.load(videos.at(rand() % videos.size()).getAbsolutePath());
        currVid.play();
        threshold = THRESHOLD;
    }
    if (random() < 0.0001) {
        texture.load(images.at(rand() % images.size()).getAbsolutePath());
        x=0;
        y=0;
        threshold = THRESHOLD;
    }
    
    beat.update(ofGetElapsedTimeMillis());
    if (beat.isKick()) {
        velocity.set(ofRandom(0.99,1.01)*(ofRandom(1,2)), ofRandom(0.99,1.01)*(ofRandom(1,2)));
        zf = ofRandom(0.1,1.0);
        //velocity.rotate(ofRandom(TWO_PI), ofVec3f(0,0,1));
    }
    if (beat.isSnare()) {
        drawTexture = !drawTexture;
    }
    if (beat.isHat() || ofRandom(0,1) < 0.3) {
        threshold = ofRandom(0.1,THRESHOLD);
    }
    if(zf > 0) {
        zf -=0.01;
    }
}

void ofApp::audioReceived(float* input, int bufferSize, int nChannels) {
    beat.audioReceived(input, bufferSize, nChannels);
}
//--------------------------------------------------------------
void ofApp::draw(){
    int width = fbo.getWidth();
    int height = fbo.getHeight();
    int textureWidth = texture.getWidth();
    int textureHeight = texture.getHeight();

    x+=velocity.x;
    y+=velocity.y;
    if (x + width > textureWidth || x < 0) {
        velocity.x = -velocity.x;
    }
    if (y + height > textureHeight ||y < 0) {
        velocity.y = -velocity.y;
    }
    
    ofPushMatrix();
    ofTranslate(-x,-y);
    texture.draw(0,0);
    ofPopMatrix();
    
    fbo2.begin(); {
        ofPushMatrix();
        ofTranslate(-x,-y);
        texture2.draw(0,0);
        ofPopMatrix();
    } fbo2.end();
    

    fbo.begin(); {
        if(drawTexture){
            ofClear(0);
        }
        shader.begin(); {
            currVid.draw(0,0,width*(1+zf),height+(1+zf));
            shader.setUniform1f("threshold", threshold);
            shader.setUniform1f("comparator", 1);
            shader.setUniformTexture("tex", fbo2.getTexture(), 1);
        } shader.end();
    } fbo.end();
    fbo.draw(0,0,width,height);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == (int) '1') {
        currVid.load(videos.at(rand() % videos.size()).getAbsolutePath());
        currVid.play();
    }
    if (key == (int) '2') {
        texture.load(images.at(rand() % images.size()));
        x=0;
        y=0;
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
