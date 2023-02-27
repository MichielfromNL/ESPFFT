/*
  ESP FFT
  =========
  This provides a vanilla radix-2 FFT implementation and a test example.

  ------
  This code was originally written by [Robin Scheibler](http://www.robinscheibler.org) during rainy days in October 2017.

  "Classified" for ESP and Arduino by M. Steltman May 2021
  
  License
  -------
  Copyright (c) 2017 Robin Scheibler, 2021 Michiel Steltman

  The MIT license

*/

#define FFT_N       2048  // The length of the FFT. Must be a power of 2
#define SAMPLEFREQ  8192   //

float fft_output[FFT_N];

#include "ESP_fft.h"
#include "fft_signal.h"

// Create the class instance
// Typical embedded FFT use is forward (sigal->frequencies) and real (get each freq & amplitude)
// use the signal from our file
// 
ESP_fft FFT(FFT_N, SAMPLEFREQ, FFT_REAL, FFT_FORWARD, samples, spectrum);

void setup() {
  Serial.begin(115200); // use the serial port

  long int t1 = micros();
  
  // Execute transformation
  //  Window the signal. See theory: without windowing, the tranition from nothing to signal at the beginning,
  // and signal to nothing at the end will cause the presence of frequencies that we don;t actually have
  // 
  FFT.hammingWindow();
  
  // optional:  
  // after Hamming, usually some DC (offset from average) is introduced in the signal
  // with removeDC (which is in fact 'make AC'), average is subtracted so that signal centers around 0
  // you can safely skip this step, the FFT 'formula' puts DC value in output[0]   
  FFT.removeDC();

  // then do the actual FFT
  FFT.execute();
  
  // we usually want the amplitudes of each frequency, so tis step is required
  //
  FFT.complexToMagnitude();
  long int t2 = micros();

  Serial.print("Time taken: ");Serial.print((t2-t1)*1.0/1000);Serial.println(" milliseconds!");
  
  Serial.println();

  // Below is what the original doc states, but I found by testing 
  // (using parseval's law, comparing power/RMS of signal and spectrum after removing DC) that 
  // this is quite a different value.  Anyway, needs quite a bit more work
  // and in practice the actual amplitude / power in the frequency domain is not really that important.

  /*Multiply the magnitude of the DC component with (1/FFT_N) to obtain the actual DC component*/
  Serial.printf("DC component : %f g\n", (spectrum[0])/FFT_N);  // DC is at [0]

  /*Multiply the magnitude at all other frequencies with (2/FFT_N) to obtain the amplitude at that frequency*/
  Serial.printf("Fundamental Freq : %f Hz\t Mag: %f g\n", FFT.majorPeakFreq(), (FFT.majorPeak()/10000)*2/FFT_N);
  for (int i=0; i< 10; i++) {
    Serial.printf("%f:%f\n", FFT.frequency(i),spectrum[i]);
  }

}
void loop() {}