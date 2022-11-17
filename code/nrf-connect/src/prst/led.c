#include "led.h"

#include <drivers/gpio.h>

#include "macros.h"

LOG_MODULE_REGISTER(led, LOG_LEVEL_DBG);

struct gpio_dt_spec led = GPIO_DT_SPEC_GET(DT_NODELABEL(led0), gpios);

int prst_led_init() {
  RET_IF_ERR(!device_is_ready(led.port));
  return gpio_pin_configure_dt(&led, GPIO_OUTPUT);
}