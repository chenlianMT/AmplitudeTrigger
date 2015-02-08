#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup()
{
	ofSetWindowTitle( "IACD-Amplitude Trigger" );
	ofBackground( 110, 120, 132 );
	ofSetFrameRate( 10 );
	
	if ( !m_emitter.loadFromXml( "circles_beitai.pex" ) )
	{
		ofLog( OF_LOG_ERROR, "testApp::setup() - failed to load emitter config" );
	}
    
    activeUnit = NULL;
    input.listInputDevices();
    input.connectTo(tap).connectTo(output);
    input.start();
    activeUnit = &input;
    
    output.start();
    ofSetVerticalSync(true);
    ofEnableSmoothing();

}

//--------------------------------------------------------------
void testApp::exit()
{
	// TODO
}

//--------------------------------------------------------------
void testApp::update()
{
    m_emitter.update();
}

//--------------------------------------------------------------
void testApp::draw()
{
    if(tap.getLeftChannelRMS() > 0.01){
        m_emitter.sourcePosition.x = RANDOM_0_TO_1()*ofGetWidth();
        m_emitter.sourcePosition.y = RANDOM_0_TO_1()*ofGetHeight();
    }
	m_emitter.draw(0, 0);

}


//--------------------------------------------------------------
void testApp::keyPressed  (int key)
{
	// nothing
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key)
{
	// nothing
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y )
{
    // nothing
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{
    // nothing
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{
	// nothing
}


//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{
	// nothing
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{
	// nothing
}
