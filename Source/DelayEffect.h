#pragma once

#include <JuceHeader.h>

class DelayEffect : public juce::AudioProcessor
{
public:
    DelayEffect();
    ~DelayEffect();

    void prepareToPlay(double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    void processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer&) override;

private:
    static constexpr int MAX_DELAY_SAMPLES = 88200; // Примерное количество отсчетов для 2 секунд задержки
    juce::AudioBuffer<float> delayBuffer;
    int delayIndex;
    float delayTime; // Время задержки в миллисекундах
};
