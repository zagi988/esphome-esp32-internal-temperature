#include "esphome.h"

#ifdef __cplusplus
  extern "C"
  {
    #endif

      uint8_t temprature_sens_read();

    #ifdef __cplusplus
  }
#endif

uint8_t temprature_sens_read();

class esp32inttemp : public PollingComponent, public Sensor {
public:
  // constructor
  esp32inttemp() : PollingComponent(15000) {}

  float get_setup_priority() const override { return esphome::setup_priority::DATA; }

  void setup() override {
    // This will be called by App.setup()
  }
  void update() override {
    publish_state((temprature_sens_read() - 32) / 1.8);
  }
};
