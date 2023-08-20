#include "ArduinoJson.h"


namespace utils {
    struct Status;
    Status deserializeStatus(String);
}

struct utils::Status {
    int x;
    int y;
    int turn;
};

utils::Status utils::deserializeStatus(String json) {
    DynamicJsonDocument doc(128);
    deserializeJson(doc, json);
    Status result = {
        doc["x"],
        doc["y"],
        doc["turn"]
    };
    return result;
}
