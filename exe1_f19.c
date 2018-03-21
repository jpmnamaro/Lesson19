// colocar aqui os protótipos das funções (não da RSI!)
// colocar declarações feitas na Tarefa B
__data __at(0x3B) unsigned char contadorOverflows=0;

char pino=0;


void main()
{
	//SP=0x60; //localiza a pilha
	configDevice(); //configura a placa
	configInts(); //configura as interrupções
	configTimer(); //configura o timer
	while(1)
	{
	  Tempo();
	   if (TF0==1){
	        TF0=0;
		if (pino==0)
		{
			P2_2 = 0;
			pino= 1;
		} 
		else
		{
			P2_2 = 1;
			pino = 0;
		}	
		}
	   }
}
//----------------------
void RSI_timer0(void) __interrupt(1) {}

	if (pino==0)
	{
		P2_2 = 0;
		pino= 1;
	} 
	else
	{
		P2_2 = 1;
		pino = 0;
	}	
	count++;

}

//----------------------
void configDevice(void)
{
	XBR1 = 0x40; // enable crossbar
	OSCICN = 0x83; // configure clock int = 1Mhz
	PCA0MD&= 0xBF; // desliga watchdog
	PCA0MD = 0x00;
}

//----------------------
void configInt(void)
{
	IE= 0b10000010;
}
//----------------------
void configTimer(void)
{
	TMOD=0x02;
	reloadTimer();
	TR0=1;  //TCON = 0b00010000;
}
//----------------------
void reloadTimer(void)
{
	unsigned int reload=??;
	TL0=5; //8 LSB
	TH0=5; //8 MSB;
	TF0=??;
}