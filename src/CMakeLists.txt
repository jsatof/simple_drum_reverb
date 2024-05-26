cmake_minimum_required(VERSION 3.22)
project(simpleDrumReverb VERSION 0.0.1)

juce_add_plugin(simpleDrumReverb
    # VERSION ...                               # Set this if the plugin version is different to the project version
    # ICON_BIG ...                              # ICON_* arguments specify a path to an image file to use as an icon for the Standalone
    # ICON_SMALL ...
    COMPANY_NAME "JamesFerrarelli"
    COMPANY_WEBSITE "https://github.com/jsatof"
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
    IS_MIDI_EFFECT FALSE
    EDITOR_WANTS_KEYBOARD_FOCUS TRUE
    VST_COPY_DIR ${VST3_INSTALL_PREFIX}
    LV2_COPY_DIR ${LV2_INSTALL_PREFIX}
    AU_COPY_DIR ${AU_INSTALL_PREFIX}
    COPY_PLUGIN_AFTER_BUILD TRUE
    PLUGIN_MANUFACTURER_CODE JAMF
    PLUGIN_CODE Dem0
    FORMATS LV2
    PRODUCT_NAME "simpleDrumReverb")

juce_generate_juce_header(simpleDrumReverb)

target_sources(simpleDrumReverb
    PRIVATE
		AllPassFilter.cpp
        PluginEditor.cpp
        PluginProcessor.cpp)

target_include_directories(simpleDrumReverb
    PRIVATE
        .)

target_compile_definitions(simpleDrumReverb
    PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0)

target_link_libraries(simpleDrumReverb
    PRIVATE
        juce::juce_audio_utils
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags)
