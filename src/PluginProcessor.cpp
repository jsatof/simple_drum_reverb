#include <PluginProcessor.h>
#include <PluginEditor.h>

SynthPluginAudioProcessor::SynthPluginAudioProcessor()
    : AudioProcessor(BusesProperties() // this plugin doesnt need midi input, also is not a synthesizer
                       .withInput("Input",  juce::AudioChannelSet::stereo(), true)
                       .withOutput("Output", juce::AudioChannelSet::stereo(), true))
    //, treeState(*this, nullptr, "PARAMETERS", {
    // these default values should match the Editor values, these are loaded and set before the gui
    //std::make_unique<juce::AudioParameterFloat>("attack", "Attack", juce::NormalisableRange<float>{0.f, 5000.f}, 0.f),
    //})
{
}

const juce::String SynthPluginAudioProcessor::getName() const {
    return JucePlugin_Name;
}

bool SynthPluginAudioProcessor::acceptsMidi() const {
    return false;
}

bool SynthPluginAudioProcessor::producesMidi() const {
    return false;
}

bool SynthPluginAudioProcessor::isMidiEffect() const {
    return false;
}

double SynthPluginAudioProcessor::getTailLengthSeconds() const {
    return 0.0;
}

int SynthPluginAudioProcessor::getNumPrograms() {
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int SynthPluginAudioProcessor::getCurrentProgram() {
    return 0;
}

void SynthPluginAudioProcessor::setCurrentProgram(int index) {
    juce::ignoreUnused(index);
}

const juce::String SynthPluginAudioProcessor::getProgramName(int index) {
    juce::ignoreUnused(index);
    return {};
}

void SynthPluginAudioProcessor::changeProgramName(int index, const juce::String& newName) {
    juce::ignoreUnused(index, newName);
}

void SynthPluginAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock) {
    juce::ignoreUnused(sampleRate);
    juce::ignoreUnused(samplesPerBlock);
}

void SynthPluginAudioProcessor::releaseResources() {}

bool SynthPluginAudioProcessor::isBusesLayoutSupported(const BusesLayout& layouts) const {
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo()) {
        return false;
    }
    return true;
}

void SynthPluginAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages) {
    buffer.clear();
    juce::ignoreUnused(midiMessages);
}

bool SynthPluginAudioProcessor::hasEditor() const {
    return true;
}

juce::AudioProcessorEditor* SynthPluginAudioProcessor::createEditor() {
    return new SynthPluginAudioProcessorEditor(*this);
}

void SynthPluginAudioProcessor::getStateInformation(juce::MemoryBlock& destData) {
    auto xml = std::unique_ptr<juce::XmlElement>(new juce::XmlElement("exampleSynthesizer"));
    //xml->setAttribute("gain", double(*gain));
    //xml->setAttribute("invertPhase", *invertPhase);
    copyXmlToBinary(*xml, destData);
}

void SynthPluginAudioProcessor::setStateInformation(const void* data, int sizeInBytes) {
    auto xml = std::unique_ptr<juce::XmlElement>(getXmlFromBinary(data, sizeInBytes));
    if (xml.get()) {
        if (xml->hasTagName("exampleSynthesizer")) {
        }
    }
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
    return new SynthPluginAudioProcessor();
}
