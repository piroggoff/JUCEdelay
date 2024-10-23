#include "DelayEffect.h"

DelayEffect::DelayEffect()
{
    // Инициализация параметров задержки
    delayBuffer.setSize(2, MAX_DELAY_SAMPLES);
    delayBuffer.clear();
    delayIndex = 0;
    delayTime = 500; // Задержка в миллисекундах
}

DelayEffect::~DelayEffect()
{
}

void DelayEffect::prepareToPlay(double sampleRate, int samplesPerBlock)
{
}

void DelayEffect::releaseResources()
{
}

void DelayEffect::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer&)
{
    const int numSamples = buffer.getNumSamples();
    const float* inData = buffer.getReadPointer(0);
    float* outData = buffer.getWritePointer(0);

    for (int sample = 0; sample < numSamples; ++sample)
    {
        // Применение эффекта задержки
        float delayedSample = delayBuffer.getSample(0, delayIndex);
        outData[sample] = inData[sample] + delayedSample;

        // Запись в буфер задержки
        delayBuffer.setSample(0, delayIndex, inData[sample] + delayedSample);
        delayBuffer.setSample(1, delayIndex, inData[sample] + delayedSample);

        // Обновление индекса задержки
        ++delayIndex;
        if (delayIndex >= delayBuffer.getNumSamples())
            delayIndex = 0;
    }
}
