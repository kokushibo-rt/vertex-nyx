#ifndef VERTEX_GPIO_H_
#define VERTEX_GPIO_H_

// C libraries, must be everywhere

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <float.h>

// Types for C and C++ style (wrapper without _t)

typedef uint8_t gpio_pin_t;

#ifdef __cplusplus
namespace vx {
namespace gpio {
    enum class state : uint8_t {
        LOW = 0,
        HIGH = 1,
        UNDEF = 2,
    };
}
}
#else
typedef uint8_t gpio_state_t;
#define GPIO_UNDEF  2
#define GPIO_HIGH   1
#define GPIO_LOW    0
#endif

typedef struct gpio_conf gpio_conf_t;   // opaque
typedef struct adc_conf adc_conf_t;     // opaque
typedef uint8_t adc_channel_t;
typedef float adc_value_t;  // [0, 1]
typedef float pwm_value_t;  // [0, 1]


// Functions for C style (called in wrapper)

extern bool gpio_write(gpio_pin_t pin, gpio_state_t state);
extern gpio_state_t gpio_read(gpio_pin_t pin);
extern bool gpio_mode(gpio_pin_t pin, const gpio_conf_t* config);
extern bool gpio_adc(adc_value_t* value, adc_channel_t channel, const adc_conf_t* config);
extern bool gpio_pwm(gpio_pin_t pin, pwm_value_t value);

#endif // VERTEX_GPIO_H_
