#include "FastLedLightController.hpp"

FastLedLightController::FastLedLightController() {
  FastLED.addLeds<NEOPIXEL, kLedPin>(leds, kNumLeds);
  FastLED.showColor(CRGB(0, 0, 0));

  for (uint8_t pole_index = 0; pole_index < 6; pole_index++) {
    poles.push_back(new Pole());
  }
}

void FastLedLightController::WriteOutLights() {
  for (uint8_t pole_index = 0; pole_index < poles.size(); pole_index++) {
    Pole* pole = poles[pole_index];
    leds[kLedOffset + pole_index * kGridSize] = pole->get_grid_lights()[0][0];
    leds[kLedOffset + pole_index * kGridSize + 1] =
        pole->get_grid_lights()[0][1];
    leds[kLedOffset + pole_index * kGridSize + 2] =
        pole->get_grid_lights()[0][2];

    leds[kLedOffset + pole_index * kGridSize + 7] =
        pole->get_grid_lights()[1][0];
    leds[kLedOffset + pole_index * kGridSize + 6] =
        pole->get_grid_lights()[1][1];
    leds[kLedOffset + pole_index * kGridSize + 5] =
        pole->get_grid_lights()[1][2];

    leds[kLedOffset + pole_index * kGridSize + 8] =
        pole->get_grid_lights()[2][0];
    leds[kLedOffset + pole_index * kGridSize + 9] =
        pole->get_grid_lights()[2][1];
    leds[kLedOffset + pole_index * kGridSize + 10] =
        pole->get_grid_lights()[2][2];
  }
  FastLED.show();
}
