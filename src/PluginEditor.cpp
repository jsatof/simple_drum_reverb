#include <PluginProcessor.h>
#include <PluginEditor.h>

SynthPluginAudioProcessorEditor::SynthPluginAudioProcessorEditor(SynthPluginAudioProcessor& p)
    : AudioProcessorEditor(&p)
    , processor(p)
{
    setSize(800, 600);
}


void SynthPluginAudioProcessorEditor::paint(juce::Graphics& g) {
    g.fillAll(juce::Colours::darkgrey);
}

void SynthPluginAudioProcessorEditor::resized() {
}
