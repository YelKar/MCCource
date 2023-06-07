#include "arduino/Arduino.h"
#include "arduino/IPAddress.h"
#include "arduino/Print.h"
#include "arduino/Client.h"
#define CDC_ENABLED false
#define USBCON false
#define UBRRH
typedef int CDCDescriptor;
#include "arduino/CDC.cpp"