#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define SPEAKER_PORT	PORTC
#define SPEAKER_DDR  	DDRC
#define SPEAKER_PIN  	7
/*
1Do (262 Hz)x38=09,956
2Re (294 Hz)x38=11,172
3Mi (330 Hz)x38=12,540
4Fa (349 Hz)x38=13,262
5Sol (392 Hz)x38=14,896
6La (440 Hz)x38=16,720
7Si (494 Hz)x38=18,772
*/
void PLAYNOTE_Do(float frequency)
{
	frequency=9956;
	float duration=5;
	long int i,cycles;
	//int half_period;
	float wavelength;
	wavelength=(1/frequency)*1000;
	cycles=duration/wavelength;
	//half_period = (int) (wavelength/2);

	SPEAKER_DDR |= (1 << SPEAKER_PIN);

	for (i=0; i<cycles; i++)
	{
		_delay_ms(.0502209);
		SPEAKER_PORT |= (1 << SPEAKER_PIN);
		_delay_ms(.0502209);
		SPEAKER_PORT &= ~(1 << SPEAKER_PIN);
	}

	return;
}
void PLAYNOTE_Re(float frequency)
{
	frequency=11172;
	float duration=5;
	long int i,cycles;
	//int half_period;
	float wavelength;
	wavelength=(1/frequency)*1000;
	cycles=duration/wavelength;
	//half_period = (int) (wavelength/2);

	SPEAKER_DDR |= (1 << SPEAKER_PIN);

	for (i=0; i<cycles; i++)
	{
		_delay_ms(.0447547);
		SPEAKER_PORT |= (1 << SPEAKER_PIN);
		_delay_ms(.0447547);
		SPEAKER_PORT &= ~(1 << SPEAKER_PIN);
	}

	return;
}
void PLAYNOTE_Mi(float frequency)
{
	frequency=12540;
	float duration=5;
	long int i,cycles;
	//int half_period;
	float wavelength;
	wavelength=(1/frequency)*1000;
	cycles=duration/wavelength;
	//half_period = (int) (wavelength/2);

	SPEAKER_DDR |= (1 << SPEAKER_PIN);

	for (i=0; i<cycles; i++)
	{
		_delay_ms(.039872);
		SPEAKER_PORT |= (1 << SPEAKER_PIN);
		_delay_ms(.039872);
		SPEAKER_PORT &= ~(1 << SPEAKER_PIN);
	}

	return;
}
void PLAYNOTE_Fa(float frequency)
{
	frequency=13262;
	float duration=5;
	long int i,cycles;
	//int half_period;
	float wavelength;
	wavelength=(1/frequency)*1000;
	cycles=duration/wavelength;
	//half_period = (int) (wavelength/2);

	SPEAKER_DDR |= (1 << SPEAKER_PIN);

	for (i=0; i<cycles; i++)
	{
		_delay_ms(.0377017);
		SPEAKER_PORT |= (1 << SPEAKER_PIN);
		_delay_ms(.0377017);
		SPEAKER_PORT &= ~(1 << SPEAKER_PIN);
	}

	return;
}
void PLAYNOTE_Sol(float frequency)
{
	frequency=14896;
	float duration=5;	long int i,cycles;
	//	int half_period;
	float wavelength;
	wavelength=(1/frequency)*1000;
	cycles=duration/wavelength;
	//half_period = (int) (wavelength/2);

	SPEAKER_DDR |= (1 << SPEAKER_PIN);

	for (i=0; i<cycles; i++)
	{
		_delay_ms(.033566);
		SPEAKER_PORT |= (1 << SPEAKER_PIN);
		_delay_ms(.033566);
		SPEAKER_PORT &= ~(1 << SPEAKER_PIN);
	}

	return;
}
void PLAYNOTE_La(float frequency)
{
	frequency=16720;
	float duration=5;	long int i,cycles;
	//int half_period;
	float wavelength;
	wavelength=(1/frequency)*1000;
	cycles=duration/wavelength;
	//half_period = (int) (wavelength/2);

	SPEAKER_DDR |= (1 << SPEAKER_PIN);

	for (i=0; i<cycles; i++)
	{
		_delay_ms(.0299043);
		SPEAKER_PORT |= (1 << SPEAKER_PIN);
		_delay_ms(.0299043);
		SPEAKER_PORT &= ~(1 << SPEAKER_PIN);
	}

	return;
}
void PLAYNOTE_Si(float frequency)
{
	frequency=18772;
	float duration=5;	long int i,cycles;
	//	int half_period;
	float wavelength;
	wavelength=(1/frequency)*1000;
	cycles=duration/wavelength;
	//half_period = (int) (wavelength/2);

	SPEAKER_DDR |= (1 << SPEAKER_PIN);

	for (i=0; i<cycles; i++)
	{
		_delay_ms(.0266354);
		SPEAKER_PORT |= (1 << SPEAKER_PIN);
		_delay_ms(.0266354);
		SPEAKER_PORT &= ~(1 << SPEAKER_PIN);
	}

	return;
}
void PLAYNOTE_Doh(float frequency)
{
	frequency=19912;float duration=5;	long int i,cycles;
	//	int half_period;
	float wavelength;
	wavelength=(1/frequency)*1000;
	cycles=duration/wavelength;
	//half_period = (int) (wavelength/2);

	SPEAKER_DDR |= (1 << SPEAKER_PIN);

	for (i=0; i<cycles; i++)
	{
		_delay_ms(.0251104);
		SPEAKER_PORT |= (1 << SPEAKER_PIN);
		_delay_ms(.0251104);
		SPEAKER_PORT &= ~(1 << SPEAKER_PIN);
	}

	return;
}

void PLAYNOTE_TestDoh(float frequency)
{
	frequency=1000;float duration=5;
	long int i,cycles;
	//	int half_period;
	float wavelength;
	wavelength=(1/frequency)*1000;
	cycles=duration/wavelength;
	//half_period = (int) (wavelength/2);

	SPEAKER_DDR |= (1 << SPEAKER_PIN);

	for (i=0; i<cycles; i++)
	{
		_delay_ms(1);
		SPEAKER_PORT |= (1 << SPEAKER_PIN);
		_delay_ms(1);
		SPEAKER_PORT &= ~(1 << SPEAKER_PIN);
	}

	return;
}

void printPoint( char x, char y )
{
	PORTD = (1<<y);
	PORTB = ~(1<<x);
}

void printLine(int LineNum)
{	LineNum--;
	int px[] = {0,0,0,0,0,0,0,0};
	int	py[] = {0,1,2,3,4,5,6,7};
	for( int k = 0; k < 200; k++ )	//Loop to hold the blinks
	{
		for(int i=0;i<8;i++)		//Loop to print 8 points in a line
		{
			printPoint(px[i]+LineNum,py[i]);
			printPoint(px[i]+LineNum,py[i]);
			//		_delay_ms(0.02);  //This Delay Holds the line as a colomn,commenting it out produces an animation like vibe
		}
		PORTD = 0;
	}
};


int main(void)
{
	DDRD = 255;
	DDRB = 255;
	DDRA = 0b00000000;
	//	printLine(1);
	//	printLine(2);
	//	printLine(3);

	unsigned char d;
	while(1)
	{
		d = PINA;
		if(d&0b00000001)
		{
			PLAYNOTE_Do(1);
//		printLine(1);
		}
		if(d&0b00000010)
		{
		PLAYNOTE_Re(2);
//		printLine(2);
		}
		if(d&0b00000100)
		{
		PLAYNOTE_Mi(3);
//		printLine(3);
		}
		if(d&0b00001000)
		{
			PLAYNOTE_Fa(4);
//		printLine(4);
		}
		if(d&0b00010000)
		{
			PLAYNOTE_Sol(5);
//		printLine(5);
		}
		if(d&0b00100000)
		{
			PLAYNOTE_La(6);
//		printLine(6);
		}
		if(d&0b01000000)
		{
			PLAYNOTE_Si(7);
//		printLine(7);
		}
		if(d&0b10000000)
		{
			PLAYNOTE_Doh(8);
//		printLine(8);
		}
	}
}
