#ifndef HTML
#define HTML

#include <avr/pgmspace.h>
const char INDEX_HTML[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="refresh" content="5">
    </head>
    <body>
        <h1>
            Temperature Readings
        </h1>
        <p>{{Temperature}}</p>
        <h1>
            Humidity
        </h1>
        <p>{{Humidity}}</p>
    </body>
</html>
)rawliteral";
#endif
