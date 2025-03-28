#ifndef VERTEX_GPIO_WRAPPER_H_
#define VERTEX_GPIO_WRAPPER_H_

#include "gpio.h"

namespace vx {

namespace gpio {
    typedef uint8_t pin;
    typedef uint8_t state;
    typedef struct gpio_conf conf;  // opaque
}

namespace adc {
    typedef struct adc_conf conf;   // opaque
    typedef uint8_t channel;
    typedef float value;  // [0, 1]
}

namespace pwm {
    typedef float value;  // [0, 1]
}

namespace gpio {
    bool write(gpio::pin pin, gpio::state state) {
        return gpio_write(pin, state);
    }
    gpio::state read(gpio::pin pin) {
        return gpio_read(pin);
    }
    bool mode(gpio::pin pin, const gpio::conf* config) {
        return gpio_mode(pin, config);
    }
    bool adc(adc::value* value, adc::channel channel, const adc::conf* config) {
        return gpio_adc(value, channel, config);
    }
    bool pwm(gpio_pin_t pin, pwm_value_t value) {
        return gpio_pwm(pin, value);
    }
}

}

#endif // VERTEX_GPIO_WRAPPER_H_

