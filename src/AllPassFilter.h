#pragma once

#include <juce_audio_basics/juce_audio_basics.h>

#include <vector>

class AllPassFilter {
public:
	void setHighPass(bool isHighPass);
	void setCutoffHz(float cutoff);
	void setSamplingRate(float sampleRate);
	void processBlock(juce::AudioBuffer<float> &buffer, juce::MidiBuffer&);

private:
	void updateParams();

	bool isHighPass;
	float cutoffHz;
	float sampleRate;
	std::vector<float> mbuffer;

	struct Params {
		float pi;
		float phase;
		double tan;
		float alpha;
	};
	Params params;
};
