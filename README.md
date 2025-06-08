# MixMaster1

MixMaster1 is an advanced, cross‑platform audio plugin built using the JUCE framework. Designed for professional mastering in all major DAWs, MixMaster1 features a complete processing chain including:

- **Pre‑Gain and Output Gain Control:** Adjust overall levels at the input and output stages.
- **Bass Booster:** A low‑shelf filter enhances low frequencies for added punch.
- **12‑Band Equalizer:** Twelve peaking EQ filters with fixed center frequencies (from 80 Hz to 12 kHz) and adjustable gain (–12 dB to +12 dB) for precise tonal balance.
- **Voice Separator:** A mid/side processing algorithm designed to emphasize vocal or center‑placed content.
- **Sound Limiter:** A robust limiter using JUCE’s dsp::Limiter to control dynamics and prevent clipping.

MixMaster1 is fully downloadable as a compiled VST, AU, or AAX plugin (depending on your target platform) and showcases advanced audio DSP techniques, making it ideal for both professional mastering and DSP experimentation.

---

## Features

- **Advanced DSP Chain:**  
  Combines pre‑gain, bass boosting, 12‑band EQ, voice separation, limiting, and output gain into one cohesive processing chain.
  
- **Fully Customizable:**  
  Every parameter—ranging from gain values, EQ gains, limiter threshold, to voice separator mix—is adjustable via an intuitive graphical user interface.
  
- **Cross‑Platform Compatibility:**  
  Developed with JUCE, MixMaster1 can be built as a VST, AU, or AAX plugin for use in virtually any DAW.
  
- **Downloadable & Ready-to-Use:**  
  Compile your own version using the Projucer, or obtain pre-built binaries to integrate directly into your digital audio workstation.

---

## Getting Started

### Prerequisites

- **JUCE Framework:** Download JUCE from [juce.com](https://juce.com/get-juce) and install it.
- **C++ IDE:** Use a compatible IDE (Visual Studio on Windows, Xcode on macOS, etc.) for compiling the plugin.
- **Basic Audio DSP Knowledge:** Familiarity with JUCE’s DSP module will assist in further customization.

### Installation & Build Instructions

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/Debalent/MixMaster1.git
   cd MixMaster1
