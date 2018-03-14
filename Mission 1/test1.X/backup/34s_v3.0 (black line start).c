
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
    //PORTC=0x03; /* both motor on */
    //wait00(0.05); /* 0.03msec wait */
    PORTC=0x02; /* right motor on */
    wait00(7); /* 0.18msec wait */
    PORTC=0x00; /* both motor off */
    wait00(6); /* 0.79msec wait */
    return 1;
}

int right_down(void){
    //PORTC=0x03; /* both motor on */
    //wait00(0.05); /* 0.03msec wait */
    PORTC=0x01; /* left motor on */
    wait00(7); /* 0.18msec wait */
    PORTC=0x00; /* both motor off */
    wait00(6); /* 0.79msec wait */
    return 2;
}

int left_down_sharp(void){
    //PORTC=0x03; /* both motor on */
    //wait00(0.05); /* 0.03msec wait */
    PORTC=0x02; /* right motor on */
    wait00(13); /* 0.18msec wait */
    PORTC=0x00; /* both motor off */
    wait00(10); /* 0.79msec wait */
    return 3;
}

int right_down_sharp(void){
    //PORTC=0x03; /* both motor on */
    //wait00(0.05); /* 0.03msec wait */
    PORTC=0x01; /* left motor on */
    wait00(13); /* 0.18msec wait */
    PORTC=0x00; /* both motor off */
    wait00(10); /* 0.79msec wait */
    return 4;
}

int left_down_small(void){
    PORTC=0x03; /* both motor on */
    wait00(1); /* 0.03msec wait */
    PORTC=0x02; /* left motor on */
    wait00(3); /* 0.18msec wait */
    PORTC=0x00; /* both motor off */
    wait00(8); /* 0.79msec wait */
    return 5;
}

int right_down_small(void){
    PORTC=0x03; /* both motor on */
    wait00(1); /* 0.03msec wait */
    PORTC=0x01; /* left motor on */
    wait00(3); /* 0.18msec wait */
    PORTC=0x00; /* both motor off */
    wait00(8); /* 0.79msec wait */
    return 6;
}

int straight(void){
    PORTC=0x03; /* both motor on */
    wait00(10); /* 0.20msec wait */
    PORTC=0x00; /* both motor off */
    wait00(10); /* 0.80msec wait */
    return 0;
}

int accelerate(void){
    PORTC=0x03; /* both motor on */
    wait00(11); /* 0.20msec wait */
    PORTC=0x00; /* both motor off */
    wait00(10); /* 0.80msec wait */
    return 0;
}
int accelerate_small(void){
    PORTC=0x03; /* both motor on */
    wait00(10); /* 0.20msec wait */
    PORTC=0x00; /* both motor off */
    wait00(10); /* 0.80msec wait */
    return 0;
}

int led_sens(void)
{
PORTAbits.RA0 = PORTBbits.RB0;     
PORTAbits.RA1 = PORTBbits.RB1; 
PORTAbits.RA2 = PORTBbits.RB2; 
PORTAbits.RA3 = PORTBbits.RB3; 
PORTAbits.RA4 = PORTBbits.RB4;      
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
    int state;
    
    while(1){/* infinite loop */
        led_sens();
        
        // black line
        //left
        if(PORTBbits.RB0==0  &&  PORTBbits.RB1==1 &&  PORTBbits.RB2==1 && PORTBbits.RB3==1 && PORTBbits.RB4==1){ 
           /*White White White White black*/
            state=left_down_sharp();/* turn left */
        }
        else if (PORTBbits.RB0==0  &&  PORTBbits.RB1==0 &&  PORTBbits.RB2==1 && PORTBbits.RB3==1 && PORTBbits.RB4==1){
            state=left_down();
        }
        else if (PORTBbits.RB0==1  &&  PORTBbits.RB1==0 &&  PORTBbits.RB2==1 && PORTBbits.RB3==1 && PORTBbits.RB4==1){
            state=left_down_small();
        }
        
        //right
        else if (PORTBbits.RB0==1  &&  PORTBbits.RB1==1 &&  PORTBbits.RB2==1 && PORTBbits.RB3==1 && PORTBbits.RB4==0){
            state=right_down_sharp();
        }
        else if (PORTBbits.RB0==1  &&  PORTBbits.RB1==1 &&  PORTBbits.RB2==1 && PORTBbits.RB3==0 && PORTBbits.RB4==0){
            state=right_down();
        }
        else if (PORTBbits.RB0==1  &&  PORTBbits.RB1==1 &&  PORTBbits.RB2==1 && PORTBbits.RB3==0 && PORTBbits.RB4==1){
            state=right_down_small();
        }
        
        // white line
        //left
        else if (PORTBbits.RB0==1  &&  PORTBbits.RB1==0 &&  PORTBbits.RB2==0 && PORTBbits.RB3==0 && PORTBbits.RB4==0){
            state=left_down_sharp();
        }
        else if (PORTBbits.RB0==1  &&  PORTBbits.RB1==1 &&  PORTBbits.RB2==0 && PORTBbits.RB3==0 && PORTBbits.RB4==0){
            state=left_down();
        }
        else if (PORTBbits.RB0==0  &&  PORTBbits.RB1==1 &&  PORTBbits.RB2==0 && PORTBbits.RB3==0 && PORTBbits.RB4==0){
            state=left_down_small();
        }
        
        //right
        else if (PORTBbits.RB0==0  &&  PORTBbits.RB1==0 &&  PORTBbits.RB2==0 && PORTBbits.RB3==0 && PORTBbits.RB4==1){
            state=right_down_sharp();
        }
        else if (PORTBbits.RB0==0  &&  PORTBbits.RB1==0 &&  PORTBbits.RB2==0 && PORTBbits.RB3==1 && PORTBbits.RB4==1){
            state=right_down();
        }
        else if (PORTBbits.RB0==0  &&  PORTBbits.RB1==0 &&  PORTBbits.RB2==0 && PORTBbits.RB3==1 && PORTBbits.RB4==0){
            state=right_down_small();
        }
        
        // accelerate
        else if (PORTBbits.RB0==0  &&  PORTBbits.RB1==0 &&  PORTBbits.RB2==1 && PORTBbits.RB3==0 && PORTBbits.RB4==0){
            accelerate();
        }
        else if (PORTBbits.RB0==0  &&  PORTBbits.RB1==1 &&  PORTBbits.RB2==1 && PORTBbits.RB3==0 && PORTBbits.RB4==0){
            accelerate_small();
        }
        else if (PORTBbits.RB0==0  &&  PORTBbits.RB1==0 &&  PORTBbits.RB2==1 && PORTBbits.RB3==1 && PORTBbits.RB4==0){
            accelerate_small();
        }
        else if (PORTBbits.RB0==1  &&  PORTBbits.RB1==1 &&  PORTBbits.RB2==0 && PORTBbits.RB3==1 && PORTBbits.RB4==1){
            accelerate();
        }
        else if (PORTBbits.RB0==1  &&  PORTBbits.RB1==0 &&  PORTBbits.RB2==0 && PORTBbits.RB3==1 && PORTBbits.RB4==1){
            accelerate_small();
        }
        else if (PORTBbits.RB0==1  &&  PORTBbits.RB1==1 &&  PORTBbits.RB2==0 && PORTBbits.RB3==0 && PORTBbits.RB4==1){
            accelerate_small();
        }
        
        else if (PORTBbits.RB0==0  &&  PORTBbits.RB1==0 &&  PORTBbits.RB2==0 && PORTBbits.RB3==0 && PORTBbits.RB4==0){
            if (state==1)
                left_down();
            if (state==3)
                left_down_sharp();
            if (state==5)
                left_down_small();
            if (state==2)
                right_down();
            if (state==4)
                right_down_sharp();
            if (state==6) 
                right_down_small();
  
        }
        
        else if (PORTBbits.RB0==1  &&  PORTBbits.RB1==1 &&  PORTBbits.RB2==1 && PORTBbits.RB3==1 && PORTBbits.RB4==1){
            if (state==1)
                left_down();
            if (state==3)
                left_down_sharp();
            if (state==5)
                left_down_small();
            if (state==2)
                right_down();
            if (state==4)
                right_down_sharp();
            if (state==6) 
                right_down_small();
        }

        
        else{ /* The other case */
            state=straight(); /* go to straight */
        }





    }
            
}


