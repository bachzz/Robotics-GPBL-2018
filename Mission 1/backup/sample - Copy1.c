//test

#include <xc.h>
#include <p18f2553.h>

wait00(short k)
{ 	 
/*Wait time about (kÅ~0.01 sec.) */ 		 
    short i; 		 
    short j; /* Declaration of 16 bit variables 	*/ 	 
    for(j=0;j<k;j++){ /*(kÅ~3000) times iteration */ 	 
		for(i=0;i<3000;i++){ 	 
		}	 
	} 		 
} 			 


int left_down(void){
    PORTC=0x03; /* both motor on */
    wait00(0.05); /* 0.03msec wait */
    PORTC=0x01; /* right motor on */
    wait00(8); /* 0.18msec wait */
    PORTC=0x00; /* both motor off */
    wait00(10); /* 0.79msec wait */
}

int right_down(void){
    PORTC=0x03; /* both motor on */
    wait00(0.05); /* 0.03msec wait */
    PORTC=0x02; /* left motor on */
    wait00(8); /* 0.18msec wait */
    PORTC=0x00; /* both motor off */
    wait00(10); /* 0.79msec wait */
}

int left_down_sharp(void){
    //PORTC=0x03; /* both motor on */
    //wait00(0.05); /* 0.03msec wait */
    PORTC=0x01; /* right motor on */
    wait00(10); /* 0.18msec wait */
    PORTC=0x00; /* both motor off */
    wait00(10); /* 0.79msec wait */
}

int right_down_sharp(void){
    //PORTC=0x03; /* both motor on */
    //wait00(0.05); /* 0.03msec wait */
    PORTC=0x02; /* left motor on */
    wait00(10); /* 0.18msec wait */
    PORTC=0x00; /* both motor off */
    wait00(10); /* 0.79msec wait */
}

int straight(void){
    PORTC=0x03; /* both motor on */
    wait00(8); /* 0.20msec wait */
    PORTC=0x00; /* both motor off */
    wait00(10); /* 0.80msec wait */
}

int led_sens(void)
{
PORTAbits.RA0 = ~PORTBbits.RB0;     
PORTAbits.RA1 = ~PORTBbits.RB1; 
PORTAbits.RA2 = ~PORTBbits.RB2; 
PORTAbits.RA3 = ~PORTBbits.RB3; 
PORTAbits.RA4 = ~PORTBbits.RB4;      
}

main(void)
{
    //setting digital or analog pin
    ADCON1 = 0x0F;

    //setting input or output
    TRISA = 0x20;            //  portA   RA0,1,2,3,4:output, RA5:input   10 0000
    TRISB = 0xFF;            //  portB   RB all input   1111 1111
    TRISC = 0x00;            //  portC   RC all output
    
    //reset to port
    PORTA = 0x00;            //  portA   reset output
    PORTB = 0x00;           //  portB    reset output
    PORTC = 0x00;           //  portC    reset output
    
    //Start SW
    while(PORTAbits.RA5==1){
        led_sens();
    }
    
    //Push Start SW
    //infinit loop
    while(1){/* infinite loop */
        led_sens();
        
        // black line
        
        if(PORTBbits.RB0==1 && PORTBbits.RB2==1 && PORTBbits.RB4==0){ 
            /*red NULL red NULL black*/
            left_down();/* turn left */
        }
        else if (PORTBbits.RB0==1 && PORTBbits.RB1==1 && PORTBbits.RB2==1 && PORTBbits.RB4==0){
            // red red red NULL black
            left_down();
        }
        else if (PORTBbits.RB0==1 && PORTBbits.RB1==1 && PORTBbits.RB2==0 && PORTBbits.RB3==0 && PORTBbits.RB4==0){
            // red red red NULL black
            left_down();
        }
        else if (PORTBbits.RB0==1 && PORTBbits.RB1==0 && PORTBbits.RB2==0 && PORTBbits.RB3==0 && PORTBbits.RB4==0){
            // red red red red black
            left_down_sharp();
        }
        else if (PORTBbits.RB0==0 && PORTBbits.RB2==1 && PORTBbits.RB3==1 && PORTBbits.RB4==1){
            //black NULL red red red
            right_down();
        }
        else if(PORTBbits.RB0==0 && PORTBbits.RB2==1 && PORTBbits.RB4==1){ 
            /*Black NULL red NULL red*/
            right_down(); /* turn right */
        }
        else if (PORTBbits.RB0==0 && PORTBbits.RB1==0 && PORTBbits.RB2==0 && PORTBbits.RB3==1 && PORTBbits.RB4==1){
            // red red red NULL black
            right_down();
        }
        else if (PORTBbits.RB0==0 && PORTBbits.RB1==0 && PORTBbits.RB2==0 && PORTBbits.RB3==0 && PORTBbits.RB4==1){
            // red red red NULL black
            right_down_sharp();
        }
        
        // white line
        
        else if(PORTBbits.RB0==0 && PORTBbits.RB2==0 && PORTBbits.RB4==1){ 
            /*red NULL red NULL black*/
            left_down();/* turn left */
        }
        else if (PORTBbits.RB0==0 && PORTBbits.RB1==0 && PORTBbits.RB2==0 && PORTBbits.RB4==1){
            // red red red NULL black
            left_down();
        }
        else if (PORTBbits.RB0==0 && PORTBbits.RB1==0 && PORTBbits.RB2==1 && PORTBbits.RB3==1 && PORTBbits.RB4==1){
            // red red red NULL black
            left_down();
        }
        else if (PORTBbits.RB0==0 && PORTBbits.RB1==1 && PORTBbits.RB2==1 && PORTBbits.RB3==1 && PORTBbits.RB4==1){
            // red red red red black
            left_down_sharp();
        }
        else if (PORTBbits.RB0==1 && PORTBbits.RB2==0 && PORTBbits.RB3==0 && PORTBbits.RB4==0){
            //black NULL red red red
            right_down();
        }
        else if(PORTBbits.RB0==1 && PORTBbits.RB2==0 && PORTBbits.RB4==0){ 
            /*Black NULL red NULL red*/
            right_down(); /* turn right */
        }
        else if (PORTBbits.RB0==1 && PORTBbits.RB1==1 && PORTBbits.RB2==1 && PORTBbits.RB3==0 && PORTBbits.RB4==0){
            // red red red NULL black
            right_down();
        }
        else if (PORTBbits.RB0==1 && PORTBbits.RB1==1 && PORTBbits.RB2==1 && PORTBbits.RB3==1 && PORTBbits.RB4==0){
            // red red red NULL black
            right_down_sharp();
        }

        else{ /* The other case */
            straight(); /* go to straight */
        }
    }
            
}

