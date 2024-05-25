#include <PluginProcessor.h>
#include <PluginEditor.h>

Processor::Processor()
    : AudioProcessor(BusesProperties() // this plugin doesnt need midi input, also is not a synthesizer
                       .withInput("Input",  juce::AudioChannelSet::stereo(), true)
                       .withOutput("Output", juce::AudioChannelSet::stereo(), true))
    //, treeState(*this, nullptr, "PARAMETERS", {
    // these default values should match the Editor values, these are loaded and set before the gui
    //std::make_unique<juce::AudioParameterFloat>("attack", "Attack", juce::NormalisableRange<float>{0.f, 5000.f}, 0.f),
    //})
{
}

const juce::String Processor::getName() const {
    return JucePlugin_Name;
}

bool Processor::acceptsMidi() const {
    return false;
}

bool Processor::producesMidi() const {
    return false;
}

bool Processor::isMidiEffect() const {
    return false;
}

double Processor::getTailLengthSeconds() const {
    return 0.0;
}

int Processor::getNumPrograms() {
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int Processor::getCurrentProgram() {
    return 0;
}

void Processor::setCurrentProgram(int index) {
    juce::ignoreUnused(index);
}

const juce::String Processor::getProgramName(int index) {
    juce::ignoreUnused(index);
    return {};
}

void Processor::changeProgramName(int index, const juce::String& newName) {
    juce::ignoreUnused(index, newName);
}

void Processor::prepareToPlay(double sampleRate, int samplesPerBlock) {
    juce::ignoreUnused(sampleRate);
    juce::ignoreUnused(samplesPerBlock);
}

void Processor::releaseResources() {}

bool Processor::isBusesLayoutSupported(const BusesLayout& layouts) const {
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo()) {
        return false;
    }
    return true;
}

void Processor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages) {
    buffer.clear();
    juce::ignoreUnused(midiMessages);
}

bool Processor::hasEditor() const {
    return true;
}

juce::AudioProcessorEditor* Processor::createEditor() {
    return new ProcessorEditor(*this);
}

void Processor::getStateInformation(juce::MemoryBlock& destData) {
    auto xml = std::unique_ptr<juce::XmlElement>(new juce::XmlElement("exampleSynthesizer"));
    //xml->setAttribute("gain", double(*gain));
    //xml->setAttribute("invertPhase", *invertPhase);
    copyXmlToBinary(*xml, destData);
}

void Processor::setStateInformation(const void* data, int sizeInBytes) {
    auto xml = std::unique_ptr<juce::XmlElement>(getXmlFromBinary(data, sizeInBytes));
    if (xml.get()) {
        if (xml->hasTagName("exampleSynthesizer")) {
        }
    }
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
    return new Processor();
}
