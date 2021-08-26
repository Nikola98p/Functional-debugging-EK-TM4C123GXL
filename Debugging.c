#define SIZE 20
#define NVIC_ST_CTRL_R      (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R    (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R   (*((volatile unsigned long *)0xE000E018))

unsigned long Time[50];
unsigned long Data[50];
unsigned char HappyBuf[SIZE];
unsigned char SadBuf[SIZE];
unsigned long Cnt;

void SysTick_Init(void){
  NVIC_ST_CTRL_R = 0;              // 1) disable SysTick during setup
  NVIC_ST_RELOAD_R = 0x00FFFFFF;   // 2) maximum reload value
  NVIC_ST_CURRENT_R = 0;           // 3) any write to current clears it
  NVIC_ST_CTRL_R = 0x00000005;     // 4) enable SysTick with core clock
}

//Filtered dump two integers, alt. debugging method
void Save(void){
  if(sad > 100){     // conditional debug; dump only if sad>100
    if(Cnt < SIZE){  // make sure there is room
      HappyBuf[Cnt] = happy; // dump strategic data
      SadBuf[Cnt] = sad;
      Cnt++;
    }
  }
}
