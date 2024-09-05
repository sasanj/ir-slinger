#include <stdio.h>
#include <string.h>
#include "irslinger.h"
/**
	* This program sends the same signal that 'test.c' sends.
**/
int main(int argc, char *argv[])
{
	uint32_t outPin = 22;            // The Broadcom pin number the signal will be sent on
	int frequency = 38000;           // The frequency of the IR signal in Hz
	double dutyCycle = 0.5;          // The duty cycle of the IR signal. 0.5 means for every cycle,
	// the LED will turn on for half the cycle time, and off the other half
	int leadingPulseDuration = 9000; // The duration of the beginning pulse in microseconds
	int leadingGapDuration = 4500;   // The duration of the gap in microseconds after the leading pulse
	int onePulse = 562;              // The duration of a pulse in microseconds when sending a logical 1
	int zeroPulse = 562;             // The duration of a pulse in microseconds when sending a logical 0
	int oneGap = 1688;               // The duration of the gap in microseconds when sending a logical 1
	int zeroGap = 562;               // The duration of the gap in microseconds when sending a logical 0
	int sendTrailingPulse = 1;       // 1 = Send a trailing pulse with duration equal to "onePulse"
	// 0 = Don't send a trailing pulse
	uint32_t bits = 0;
	char *code = "01000001101101100101100010100111";
	int t = strlen(code);
	int i = 0;
	for( i=0;i < t - 1;i++) {
		if (code[i] == '1') {
			bits |=1;
		}
		bits <<= 1;
	}
	if ( code[i] == '1') {
		bits |=1;
	}
	printf("code is 0x%x and size is %d\n",bits,t);
	int result = irSlingBit(
		outPin,
		frequency,
		dutyCycle,
		leadingPulseDuration,
		leadingGapDuration,
		onePulse,
		zeroPulse,
		oneGap,
		zeroGap,
		sendTrailingPulse,
		bits,
		t,IR_PROTOCOL_IS_MSB_FIRST);

	return result;
}
