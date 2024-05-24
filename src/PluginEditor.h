#pragma once

#include <PluginProcessor.h>

class SynthPluginAudioProcessorEditor final : public juce::AudioProcessorEditor {
public:
    explicit SynthPluginAudioProcessorEditor(SynthPluginAudioProcessor&);

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    SynthPluginAudioProcessor &processor;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SynthPluginAudioProcessorEditor)
};
