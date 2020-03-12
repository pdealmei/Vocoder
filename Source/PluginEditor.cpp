//
// Vocoder editor
// By Paul De Almeida
// Creation Date: 12th March 2020
//

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
VocoderAudioProcessorEditor::VocoderAudioProcessorEditor (VocoderAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    setSize (200, 200);
    
    // Dry/Wet slider
    blend.setSliderStyle (Slider::LinearBarVertical);
    blend.setRange(0.0, 100.0, 1.0);
    blend.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
    blend.setPopupDisplayEnabled (true, false, this);
    blend.setValue(1.0);
    addAndMakeVisible (&blend);
    blend.addListener (this);
    
    // Carrier frequency slider
    frequency.setSliderStyle (Slider::LinearBarVertical);
    frequency.setRange (50.0, 5000.0);
    frequency.setSkewFactorFromMidPoint (500.0);
    frequency.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
    frequency.setPopupDisplayEnabled (true, false, this);
    frequency.setValue(1.0);
   addAndMakeVisible (&frequency);
   frequency.addListener (this);
}

VocoderAudioProcessorEditor::~VocoderAudioProcessorEditor()
{
}

//==============================================================================
void VocoderAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::white);
    g.setColour (Colours::black);
    g.setFont (15.0f);
    g.drawFittedText ("Dry/Wet", getLocalBounds(), Justification::topLeft, 1);
    g.drawFittedText ("Carrier Frequency", getLocalBounds(), Justification::topRight, 1);
}

void VocoderAudioProcessorEditor::resized()
{
    blend.setBounds (20, 30, 20, getHeight() - 60);
    frequency.setBounds (160, 30, 20, getHeight() - 60);
}

void VocoderAudioProcessorEditor::sliderValueChanged (Slider* slider)
{
    processor.blendPercentage = blend.getValue();
    processor.carrierFrequency = frequency.getValue();
}
