#ifndef VERTEX_GPIO_H_
#define VERTEX_GPIO_H_

// C libraries, must be everywhere

#include <stddef.h>
#include <stdint.h>
#include <float.h>

// Types for C and C++ style (wrapper without _t)

typedef uint8_t gpio_pin_t;
typedef uint8_t gpio_state_t;
typedef struct gpio_conf gpio_conf_t;   // opaque
typedef struct adc_conf adc_conf_t;     // opaque
typedef uint8_t adc_channel_t;
typedef float adc_value_t;  // [0, 1]
typedef float pwm_value_t;  // [0, 1]

// !! (except; must be in enum : uint8_t in wrapper)
#define GPIO_HIGH   1
#define GPIO_LOW    0

// Functions for C style (called in wrapper)

extern bool gpio_write(gpio_pin_t pin, gpio_state_t state);
extern gpio_state_t gpio_read(gpio_pin_t pin);
extern bool gpio_mode(gpio_pin_t pin, const gpio_conf_t* config);
extern bool gpio_adc(adc_value_t* value, adc_channel_t channel, const adc_conf_t* config);
extern bool gpio_pwm(gpio_pin_t pin, pwm_value_t value);

#endif // VERTEX_GPIO_H_
