# ArduinoSoftTouchPower
A single tactile button controls full circuit power. Push ON, hold OFF.

Full circuit walkthrough from https://www.youtube.com/watch?v=0IjJH3ksqfs 

# Errata
The SENSE pin should have an external pull-down resistor connected.
For a Vsupp of 12V, 10kOhm is fine.
For a lower Vsupp eg 5V, a higher value is needed so as not to lower the signal voltage. This is because a voltage divider is created with the existing 10k. Try 100k-1M.
