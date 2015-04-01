include "mbed.h";

Serial dash(p9, p10);  // tx, rx

void flush()
{
    char obl[8];
    while(rpi.readable())
    {
        obl[0] = rpi.getc();
    }
}

int main() 
{    
    dash.format(8, SerialBase::None, 1);
    rpi.baud(38400);
    
    char current[1];
    
    flush();
    
    while(1) 
    {
        if(rpi.readable())
        {
            current[0] = rpi.getc();
            if (current == 'A')
	    {
		wait(0.010);
		for(int index = 0; index < 209; index++)
		{
			dash.putc("%c", index);
		}
	    else
	    {
		flush();
	    }
	}
    }
}