#ifndef COLOR_CYCLE_EFFECT_HPP_
#define COLOR_CYCLE_EFFECT_HPP_

#include <vector>
#include "Effect.hpp"
#include "Pole.hpp"

class ColorCycleEffect : public Effect {
 public:
  ColorCycleEffect(std::vector<Pole*> poles);

 protected:
  void DoRun() override;

 private:
  uint32_t timer = 0;
};

#endif