
#define FFT_N       2048  // Must be a power of 2
#define SAMPLEFREQ  218   //
//#define TOTAL_TIME  9.391904 //The time in which data was captured. This is equal to FFT_N/sampling_freq


float fft_input[FFT_N];
float fft_output[FFT_N];


#include "ESP32_fft.h" // include the library
#include "fft_signal.h"


ESP_fft FFT(FFT_N, SAMPLEFREQ, FFT_REAL, FFT_FORWARD, fft_input, fft_output);

void setup() {
  Serial.begin(115200); // use the serial port
  while (!Serial);
  Serial.println("Hello. FFT test");
  for (int k = 0 ; k < FFT_N ; k++)
    fft_input[k] = (float)fft_signal[k];

  long int t1 = micros();
  // Execute transformation
  FFT.removeDC();
  FFT.hammingWindow();
  
  FFT.execute();
  FFT.complexToMagnitude();
  long int t2 = micros();
  //FFT.print();
  Serial.print("Time taken: ");Serial.print((t2-t1)*1.0/1000);Serial.println(" milliseconds!");
  
  // Print the output
  
  Serial.println();
  /*Multiply the magnitude of the DC component with (1/FFT_N) to obtain the DC component*/
  Serial.printf("DC component : %f g\n", (fft_output[0])/FFT_N);  // DC is at [0]

  /*Multiply the magnitude at all other frequencies with (2/FFT_N) to obtain the amplitude at that frequency*/
  Serial.printf("Fundamental Freq : %f Hz\t Mag: %f g\n", FFT.majorPeakFreq(), (FFT.majorPeak()/10000)*2/FFT_N);
  for (int i=0; i< 10; i++) {
    Serial.printf("%f:%f\n", FFT.frequency(i),fft_output[i]);
  }
  //Serial.print("\nTime taken: ");Serial.print((t2-t1)*1.0/1000);Serial.println(" milliseconds!");
  
  // Clean up at the end to free the memory allocated
  
}

void loop() {
  
}
