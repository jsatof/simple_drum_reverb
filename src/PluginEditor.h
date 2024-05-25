#pragma once

#include <PluginProcessor.h>

class ProcessorEditor final : public juce::AudioProcessorEditor {
public:
    explicit ProcessorEditor(Processor&);

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    Processor &processor;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProcessorEditor)
};
