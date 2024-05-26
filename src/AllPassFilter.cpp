#include <AllPassFilter.h>

#include <cmath>

void AllPassFilter::setHighPass(bool isHighPass) {
	this->isHighPass = isHighPass;
	updateParams();
}

void AllPassFilter::setCutoffHz(float cutoffHz) {
	this->cutoffHz = cutoffHz;
	updateParams();
}

void AllPassFilter::setSamplingRate(float sampleRate) {
	this->sampleRate = sampleRate;
	updateParams();
}

void AllPassFilter::updateParams() {
	params.pi = 3.14159265359f;
	params.phase = isHighPass ? -1.f : 1.f;
	params.tan = std::tan(params.pi * cutoffHz / sampleRate);
	params.alpha = (params.tan - 1.f) / (params.tan + 1.f);
}

void AllPassFilter::processBlock(juce::AudioBuffer<float> &buffer, juce::MidiBuffer&) {
	mbuffer.resize(buffer.getNumChannels(), 0.f);

	for (int channel = 0; channel < buffer.getNumChannels(); ++channel) {
		auto samples = buffer.getWritePointer(channel);
		for (int i = 0; i < buffer.getNumChannels(); ++i) {
			float filteredSample = params.alpha * samples[i] + mbuffer[channel]; // all pass filter
			mbuffer[channel] = samples[i] - params.alpha * filteredSample;
			float output = 0.5f * (samples[i] + params.phase * filteredSample); // final filter
			samples[i] = output;
		}
	}
}
