#include <PluginProcessor.h>
#include <PluginEditor.h>

ProcessorEditor::ProcessorEditor(Processor& p)
    : AudioProcessorEditor(&p)
    , processor(p)
{
    setSize(800, 600);
}


void ProcessorEditor::paint(juce::Graphics& g) {
    g.fillAll(juce::Colours::darkgrey);
}

void ProcessorEditor::resized() {
}
