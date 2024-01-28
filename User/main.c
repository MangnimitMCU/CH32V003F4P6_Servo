
#include "systick_delay.h"



/////////////////////////////////////////////////////////////////////
void TIMER1_Config(void) {
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct = {0};
    TIM_OCInitTypeDef TIM_OCInitStruct = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);

    TIM_TimeBaseInitStruct.TIM_Prescaler = 48-1; // 48MHZ/1MHZ
    TIM_TimeBaseInitStruct.TIM_Period = 20000-1; // 20000us/1000 = 20ms
    TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
    //TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
    //TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM1, &TIM_TimeBaseInitStruct);

    TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStruct.TIM_Pulse = 1500;

    TIM_OCInitStruct.TIM_OCIdleState = TIM_OCIdleState_Reset;
    //TIM_OCInitStruct.TIM_OCNIdleState = TIM_OCNIdleState_Reset;

    TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;
    //TIM_OCInitStruct.TIM_OCNPolarity = TIM_OCNPolarity_High;

    TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
    //TIM_OCInitStruct.TIM_OutputNState = TIM_OutputNState_Enable;
    TIM_OC1Init(TIM1, &TIM_OCInitStruct);

    TIM_CtrlPWMOutputs(TIM1, ENABLE);
    //TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);
    //TIM_ARRPreloadConfig(TIM1, ENABLE);

    TIM_Cmd(TIM1, ENABLE);
}

/////////////////////////////////////////////////////////////////////
void GPIO_Config(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2; // T1CH1
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &GPIO_InitStruct);
}

/////////////////////////////////////////////////////////////////////
int main(void) {
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    SystemCoreClockUpdate();
    Delay_Init();
    TIMER1_Config();
    GPIO_Config();

    while(1) {
        TIM_SetCompare1(TIM1, 900);
        Delay_Ms(1000);
        TIM_SetCompare1(TIM1, 1500);
        Delay_Ms(1000);
        TIM_SetCompare1(TIM1, 2300);
        Delay_Ms(1000);
    }
}
