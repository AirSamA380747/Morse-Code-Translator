const int txPin = 9;
const unsigned long carrierFreq = 1700000; // 1.7 MHz carrier
const unsigned int audioToneFreq = 1000;   // 1 kHz modulation
const unsigned int dotDuration = 100;      // ms
const unsigned int dashDuration = 3 * dotDuration;
const unsigned int symbolSpace = dotDuration;
const unsigned int letterSpace = 3 * dotDuration;
const unsigned int wordSpace = 7 * dotDuration;


String morseMessage = ".... . .-.. .-.. --- --..-- / .. / .- -- / ... .- -- ..- . .-..";

// Transmit a 1.7 MHz carrier modulated with 1 kHz tone
void transmitTone(unsigned long duration_ms) {
  unsigned long endTime = millis() + duration_ms;
  unsigned long tonePeriodMicros = 1000000 / audioToneFreq / 2;

  while (millis() < endTime) {
    // Turn on the carrier in 1 kHz bursts (AM modulation)
    unsigned long toneStart = micros();
    while (micros() - toneStart < tonePeriodMicros) {
      // 1.7 MHz square wave
      digitalWrite(txPin, HIGH);
      delayMicroseconds(0);  // ~0.3 µs per toggle — adjust if needed
      digitalWrite(txPin, LOW);
      delayMicroseconds(0);
    }

    // Silent half of 1 kHz tone
    delayMicroseconds(tonePeriodMicros);
  }
}

void sendDot() {
  transmitTone(dotDuration);
  delay(symbolSpace);
}

void sendDash() {
  transmitTone(dashDuration);
  delay(symbolSpace);
}

void letterBreak() {
  delay(letterSpace - symbolSpace);
}

void wordBreak() {
  delay(wordSpace - symbolSpace);
}

// Function to transmit the morse code of a given message
void transmitMessage(String message) {
  for (int i = 0; i < message.length(); i++) {
    char c = message.charAt(i);

    if (c == '.') {
      sendDot();
    } else if (c == '-') {
      sendDash();
    } else if (c == ' ') {
      letterBreak();
    } else if (c == '/') {
      wordBreak();
    }
  }
}

void setup() {
  pinMode(txPin, OUTPUT);
}

void loop() {
  // Send the message in Morse Code
  transmitMessage(morseMessage);
  delay(1500); // Pause before repeating
}
