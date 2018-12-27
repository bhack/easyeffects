#include "pitch_preset.hpp"

PitchPreset::PitchPreset()
    : input_settings(Gio::Settings::create(
          "com.github.wwmm.pulseeffects.sourceoutputs.pitch")) {}

void PitchPreset::save(boost::property_tree::ptree& root,
                       const std::string& section,
                       const Glib::RefPtr<Gio::Settings>& settings) {
  root.put(section + ".pitch.state", settings->get_boolean("state"));

  root.put(section + ".pitch.cents", settings->get_double("cents"));

  root.put(section + ".pitch.semitones", settings->get_int("semitones"));

  root.put(section + ".pitch.octaves", settings->get_int("octaves"));

  root.put(section + ".pitch.crispness", settings->get_int("crispness"));

  root.put(section + ".pitch.formant-preserving",
           settings->get_boolean("formant-preserving"));

  root.put(section + ".pitch.faster", settings->get_boolean("faster"));
}

void PitchPreset::load(boost::property_tree::ptree& root,
                       const std::string& section,
                       const Glib::RefPtr<Gio::Settings>& settings) {
  update_key<bool>(root, settings, "state", section + ".pitch.state");

  update_key<double>(root, settings, "cents", section + ".pitch.cents");

  update_key<int>(root, settings, "semitones", section + ".pitch.semitones");

  update_key<int>(root, settings, "octaves", section + ".pitch.octaves");

  update_key<int>(root, settings, "crispness", section + ".pitch.crispness");

  update_key<bool>(root, settings, "formant-preserving",
                   section + ".pitch.formant-preserving");

  update_key<bool>(root, settings, "faster", section + ".pitch.faster");
}

void PitchPreset::write(boost::property_tree::ptree& root) {
  save(root, "input", input_settings);
}

void PitchPreset::read(boost::property_tree::ptree& root) {
  load(root, "input", input_settings);
}
