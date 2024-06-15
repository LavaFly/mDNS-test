# mDNS tesing on the ESP8266 with PlattformIO

The `main.cpp`-file contains a minimal working example using [`ESP8266mDNS`](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266mDNS)
and [`ESPAsyncWebServer`](https://github.com/me-no-dev/ESPAsyncWebServer).
This purpose of this Repo was to test if multiple Domain-Names could be assigned
to a single ESP8266 using these libraries. As of now, it doesnt seem possible.


## Second `MDNS.begin()`

Using just a second call of `MDNS.begin()` results in the first name not
being found anymore, as each MDNS-Instance can only hold one hostname.
See [`Commit Difference`](https://github.com/LavaFly/mDNS-test/commit/a556abc82f375a96cd1d4163f2b6c9190250a39e).

## Second MDNS-Instance

Modifying the `ESP8266mDNS`-library code to create a second MDNS-Instance
did not work either. The call `MDNS2.begin()` now fails.
See [`Commit Difference`](https://github.com/LavaFly/mDNS-test/commit/af6bbbd79cdb4ebe3175b18a66dad2b2e6e2727a).

## Second WebServer

Creating a second WebServer which runs on port 81 and adding the service of
the second MDNS-Instance to that port did not work, though both WebServers are
responding the requests, only one hostname can be resolved.
See [`Commit Difference`](https://github.com/LavaFly/mDNS-test/commit/bf5b63decb08e0ea9bc709c674b448076d74a97b).

