#include "testing.h"

/* Whether debug msg are enabled */
static bool debugEnabled = false;

bool isDebuggEnabled() {
    return debugEnabled;
}

void setDebugEnabled(bool enabled) {
    debugEnabled = enabled;
}