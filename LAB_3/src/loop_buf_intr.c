// loop_buf_intr.c 

#include "audio.h"

static const int buffer_size = 256;
float32_t rbuffer[buffer_size];
float32_t lbuffer[buffer_size];

void I2S_HANDLER(void) {   /****** I2S Interruption Handler *****/
  static int16_t rbufptr = 0;
  static int16_t lbufptr = 0;
  int16_t audio_chR=0;    
  int16_t audio_chL=0;
	
  audio_IN = i2s_rx();	
  audio_chL = audio_IN & 0x0000FFFF;       
  audio_chR = (audio_IN >>16)& 0x0000FFFF; 

  lbuffer[lbufptr++] = (float32_t)audio_chL;
	lbufptr %= buffer_size;  // return to start if we just wrote to the end
	rbuffer[rbufptr++] = (float32_t)audio_chR;
  rbufptr %= buffer_size;  // return to start if we just wrote to the end
	
  audio_OUT = ((audio_chR<<16) & 0xFFFF0000) | (audio_chL & 0x0000FFFF);	
  i2s_tx(audio_OUT);
}

int main(void) {
  audio_init (hz8000, line_in, intr, I2S_HANDLER); 
  while(1){}
}

