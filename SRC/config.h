#ifndef CONFIG
#define CONFIG
//General purpose config file for MQTT
//Set a unique name for THING_NAME

#define BROKER "192.168.1.176"
#define PORT 1883

#define THING_NAME "ajm_thing"

#define TEMPERATURE_TOPIC "/temperatureC"
#define LIGHT_LEVEL_TOPIC "/lightlevel"
#define ANNOUNCE_TOPIC "/yay"

#endif