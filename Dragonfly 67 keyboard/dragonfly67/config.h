#pragma once

// handedness
#define MASTER_LEFT
#define USB_VBUS_PIN GP29

// Split keyboard definitions
#undef SPLIT_USB_DETECT

#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE

/* WS2812B LED setup */
#define WS2812_DI_PIN GP16       // The GPIO pin for WS2812B data
#define RGBLIGHT_LED_COUNT 2           // Two LEDs total (CapsLock + ScrollLock)
#define RGBLIGHT_SPLIT         // Enables master to handle both sides
#define RGBLIGHT_LIMIT_VAL 255 // Optional: brightness limit
#define RGBLIGHT_SLEEP         // Turn off LEDs when host sleeps
#define RGBLED_SPLIT {1, 1}

// Enable lighting layers
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF

// Optional: Enable specific RGB effects you want
#define RGBLIGHT_EFFECT_STATIC_LIGHT
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_BREATHING 
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_KNIGHT 
#define RGBLIGHT_EFFECT_RAINBOW_MOOD 
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL 
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_SNAKE 
#define RGBLIGHT_EFFECT_STATIC_GRADIENT 
#define RGBLIGHT_EFFECT_TWINKLE 
// Add more effects as desired

// Optional: Animation speed/timing
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8

#define ADC_RESOLUTION ADC_CFGR1_RES_12BIT

//ENCODER DEFINITION
#define ENCODER_A_PINS_RIGHT { GP15 }
#define ENCODER_B_PINS_RIGHT { GP14 }
#define ENCODER_RESOLUTION 4 