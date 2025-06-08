#pragma once

#include <JuceHeader.h>
#include <array>

class UltimateMasteringPluginProcessor  : public juce::AudioProcessor
{
public:
    UltimateMasteringPluginProcessor();
    ~UltimateMasteringPluginProcessor() override;

    //==========================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif
    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==========================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==========================================================================
    const juce::String getName() const override;
    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==========================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==========================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    juce::AudioProcessorValueTreeState& getParameters() { return parameters; }

private:
    //==============================================================================
    // The APVTS holds all our plugin parameters.
    juce::AudioProcessorValueTreeState parameters;

    // DSP modules:
    // Pre-Gain.
    juce::dsp::Gain<float> preGain;
    // Bass booster: a low-shelf filter.
    juce::dsp::IIR::Filter<float> bassBoostFilter;
    // 12-band EQ: A fixed array of 12 peaking filters.
    std::array<juce::dsp::IIR::Filter<float>, 12> eqFilters;
    // Voice separator: a mix factor for mid boosting.
    float voiceSeparatorMix = 1.0f; // (1.0 = full separation emphasis)
    // Sound limiter.
    juce::dsp::Limiter<float> limiter;
    // Final output gain.
    juce::dsp::Gain<float> outputGain;
    
    // Cached sample rate.
    double currentSampleRate = 44100.0;

    // Updates all DSP parameters from our APVTS.
    void updateParameters();

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (UltimateMasteringPluginProcessor)
};
};
