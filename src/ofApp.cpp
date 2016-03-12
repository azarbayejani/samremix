#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    x,y = 0;
    velocity.set(1,1);
    shader.load("shaders/shader");
    videos = ofDirectory("/Users/azar/tmp/SAM remix/videos/").getFiles();
    images = ofDirectory("/Users/azar/tmp/SAM remix/images/").getFiles();
    //videos = ofDirectory("/Users/aashishgadani/Sources/Videos/SAM Remix/").getFiles();
    //images = ofDirectory("/Users/aashishgadani/Sources/Images/Animals").getFiles();
    currVid.load(videos.at(0).getAbsolutePath());
    texture.load(images.at(0).getAbsolutePath());
    currVid.play();
    
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
        threshold = 0.88;
    }
    if (random() < 0.0001) {
        texture.load(images.at(rand() % images.size()).getAbsolutePath());
        x=0;
        y=0;
        threshold = 0.88;
    }
    
    beat.update(ofGetElapsedTimeMillis());
    if (beat.isKick()) {
        velocity.set(ofRandom(0.99,1.01), ofRandom(0.99,1.01));
    }
    if (beat.isSnare()) {
        drawTexture = !drawTexture;
    }
    if (beat.isHat()) {
        threshold = ofRandom(0,0.88);
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
    
    if (x < -textureWidth+width || x > 0) {
        velocity.x = -velocity.x;
    }
    if (y < -textureHeight+height || y > 0) {
        velocity.y = -velocity.y;
    }
    
    fbo.begin();
    ofPushMatrix();
    ofTranslate(x+=velocity.x,y+=velocity.y);
    
    if(drawTexture){
        texture.draw(0,0);
    }
    ofPopMatrix();
    shader.begin();
    currVid.draw(0,0,width,height);
    shader.setUniform1f("threshold", threshold);
    shader.end();
    fbo.end();
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
