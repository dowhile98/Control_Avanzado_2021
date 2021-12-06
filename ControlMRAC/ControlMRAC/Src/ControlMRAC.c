/*
 * File: ControlMRAC.c
 *
 * Code generated for Simulink model :ControlMRAC.
 *
 * Model version      : 1.16
 * Simulink Coder version    : 9.3 (R2020a) 18-Nov-2019
 * TLC version       : 9.3 (Jan 23 2020)
 * C/C++ source code generated on  : Thu Dec  2 16:51:09 2021
 *
 * Target selection: stm32.tlc
 * Embedded hardware selection: STM32CortexM
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 *
 *
 * ******************************************************************************
 * * attention
 * *
 * * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
 * * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 * *
 * ******************************************************************************
 */

#include "ControlMRAC.h"
#include "ControlMRAC_private.h"

/* GPIOB output mask value definition. */
uint16_t GPIOB_maskWrite;

/* Block signals (default storage) */
B_ControlMRAC ControlMRAC_B;

/* Block states (default storage) */
DW_ControlMRAC ControlMRAC_DW;

/* Real-time model */
RT_MODEL_ControlMRAC ControlMRAC_M_;
RT_MODEL_ControlMRAC *const ControlMRAC_M = &ControlMRAC_M_;

/* Model step function */
void ControlMRAC_step(void)
{
  real_T rtb_volt;
  real_T rtb_theta;
  real_T rtb_uk1;
  real_T rtb_Error;
  real_T rtb_yk1;
  real_T rtb_Sum1;
  real_T rtb_TSamp;
  real_T rtb_detTheta;
  if (ControlMRAC_DW.stateControl == 1.0) {
    ControlMRAC_DW.stateControl = 0.0;
    rtb_uk1 = ControlMRAC_DW.uk1_DSTATE;
    rtb_yk1 = ControlMRAC_DW.yk1_DSTATE;
    rtb_Sum1 = (0.006854 * ControlMRAC_DW.uk1_DSTATE + 0.006412 *
                ControlMRAC_DW.uk2_DSTATE) + (1.805 * ControlMRAC_DW.yk1_DSTATE
      + -0.8187 * ControlMRAC_DW.yk2_DSTATE);
    rtb_detTheta = (ControlMRAC_DW.rads - rtb_Sum1) * rtb_Sum1 * -2.5 /
      (rtb_Sum1 * rtb_Sum1 + 1225.0);
    rtb_Error = ControlMRAC_DW.Ref - ControlMRAC_DW.rads;
    rtb_TSamp = 0.0008954 * rtb_Error * 100.0;
    rtb_theta = ((rtb_TSamp - ControlMRAC_DW.UD_DSTATE) + 0.0121 * rtb_Error) +
      ControlMRAC_DW.Integrator_DSTATE;
    if (rtb_theta > 8.37) {
      rtb_volt = 8.37;
    } else if (rtb_theta < 0.0) {
      rtb_volt = 0.0;
    } else {
      rtb_volt = rtb_theta;
    }

    rtb_theta = (rtb_volt - rtb_theta) * 32.231404958677686;
    rtb_volt *= ControlMRAC_DW.theta_DSTATE;
    if (rtb_volt > 8.37) {
      rtb_volt = 8.37;
    } else {
      if (rtb_volt < 0.0) {
        rtb_volt = 0.0;
      }
    }

    ControlMRAC_B.Divide = 100.0 * rtb_volt / 8.37;

    {
      HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_3);
    }

    ControlMRAC_DW.uk1_DSTATE = ControlMRAC_DW.Ref;
    ControlMRAC_DW.uk2_DSTATE = rtb_uk1;
    ControlMRAC_DW.yk1_DSTATE = rtb_Sum1;
    ControlMRAC_DW.yk2_DSTATE = rtb_yk1;
    ControlMRAC_DW.UD_DSTATE = rtb_TSamp;
    ControlMRAC_DW.Integrator_DSTATE += (0.39 * rtb_Error + rtb_theta) * 0.01;
    ControlMRAC_DW.theta_DSTATE += 0.01 * rtb_detTheta;

    {
      if (ControlMRAC_B.Divide != TIM15_Conf.CH2_duty) {
        TIM15_Conf.CH2_duty = ControlMRAC_B.Divide;
        if (ControlMRAC_B.Divide >= 0) {
          /* Channel2 duty cycle is an input port. */
          __HAL_TIM_SET_COMPARE(&htim15,TIM_CHANNEL_2,(uint32_t)
                                (ControlMRAC_B.Divide * (&htim15)->Instance->ARR
            / 100));
        }
      }
    }
  }

  {
    /* Set GPIOB output mask value. */
    GPIOB_maskWrite = GPIOB->ODR;
    GPIOB_maskWrite &= 0xFFBD ;
    GPIOB_maskWrite |= (uint16_t)1.0 << 1;
    GPIOB_maskWrite |= (uint16_t)0.0 << 6;

    /* Write GPIOB input value */
    GPIOB->ODR = (uint16_t)GPIOB_maskWrite;
  }

  {
  }
}

/* Model initialize function */
void ControlMRAC_initialize(void)
{
  {
    /* user code (Start function Header) */
    {
      /* TIM6 initialization. */
      /* Store TIM6 informations and its handler. */
      G_TIM_Conf[G_TIM_Count] = &TIM6_Conf;
      G_TIM_Handler[G_TIM_Count] = &htim6;
      G_TIM_Count++;

      /* Store TIM information. */
      TIM6_Conf.TIM_Prescaler = 79;
      TIM6_Conf.TIM_APBClock = 80000000;
      TIM6_Conf.TIM_ARR = 10000 - 1;
      TIM6_Conf.TIM_Clock = 1.0E+6;
      TIM6_Conf.TIM_Freq = 100.0;
      TIM6_Conf.CH1_duty = 0.0;
      TIM6_Conf.CH2_duty = 0.0;
      TIM6_Conf.CH3_duty = 0.0;
      TIM6_Conf.CH4_duty = 0.0;
      TIM6_Conf.CH1_type = UNKNOWN;
      TIM6_Conf.CH2_type = UNKNOWN;
      TIM6_Conf.CH3_type = UNKNOWN;
      TIM6_Conf.CH4_type = UNKNOWN;

      /* Interrupt handler default initialization. */
      TIM6_Conf.ItUpFcn = NULL;
      TIM6_Conf.ItTrgFcn = NULL;
      TIM6_Conf.ItComFcn = NULL;
      TIM6_Conf.ItBrkFcn = NULL;
      TIM6_Conf.ItCcFcn = NULL;

      /* Update interrupt function. */
      TIM6_Conf.ItUpFcn = TIM6_ItUpFcn;

      /* Auto-reload preload enable */
      /*****Bugzilla 63376 *****/
      /*SET_BIT((&htim6)->Instance->CR1,TIM_CR1_ARPE);*/

      /* Update register value with blockset value. */
      /* Prescaler. */
      __HAL_TIM_SET_PRESCALER(&htim6,TIM6_Conf.TIM_Prescaler);

      /* Autoreload: ARR. */
      __HAL_TIM_SET_AUTORELOAD(&htim6,10000 - 1);

      /* Update registers before start operation to come. */
      HAL_TIM_GenerateEvent(&htim6,TIM_EVENTSOURCE_UPDATE);
    }

    {
      /* TIM15 initialization. */
      /* Store TIM15 informations and its handler. */
      G_TIM_Conf[G_TIM_Count] = &TIM15_Conf;
      G_TIM_Handler[G_TIM_Count] = &htim15;
      G_TIM_Count++;

      /* Store TIM information. */
      TIM15_Conf.TIM_Prescaler = 39;
      TIM15_Conf.TIM_APBClock = 80000000;
      TIM15_Conf.TIM_ARR = 50 - 1;
      TIM15_Conf.TIM_Clock = 2.0E+6;
      TIM15_Conf.TIM_Freq = 40000.0;
      TIM15_Conf.CH1_duty = 0.0;
      TIM15_Conf.CH2_duty = 0.0;
      TIM15_Conf.CH3_duty = 0.0;
      TIM15_Conf.CH4_duty = 0.0;
      TIM15_Conf.CH1_type = UNKNOWN;
      TIM15_Conf.CH2_type = OUTPUT_PWM;
      TIM15_Conf.CH3_type = UNKNOWN;
      TIM15_Conf.CH4_type = UNKNOWN;

      /* Interrupt handler default initialization. */
      TIM15_Conf.ItUpFcn = NULL;
      TIM15_Conf.ItTrgFcn = NULL;
      TIM15_Conf.ItComFcn = NULL;
      TIM15_Conf.ItBrkFcn = NULL;
      TIM15_Conf.ItCcFcn = NULL;

      /* Auto-reload preload enable */
      /*****Bugzilla 63376 *****/
      /*SET_BIT((&htim15)->Instance->CR1,TIM_CR1_ARPE);*/

      /* Update register value with blockset value. */
      /* Prescaler. */
      __HAL_TIM_SET_PRESCALER(&htim15,TIM15_Conf.TIM_Prescaler);

      /* Autoreload: ARR. */
      __HAL_TIM_SET_AUTORELOAD(&htim15,50 - 1);

      /* Set CH2 Pulse value. */
      __HAL_TIM_SET_COMPARE(&htim15,TIM_CHANNEL_2,(uint32_t)((50 - 1)/2));

      /* Update registers before start operation to come. */
      HAL_TIM_GenerateEvent(&htim15,TIM_EVENTSOURCE_UPDATE);
    }

    /* user code (Start function Body) */

    /* USART2 initialization for send. */
    USART2_Tx_Initialization();

    {
      /* External interrupt function registering. */
      EXTI_Callback[0] = EXTI0_Callback;
    }

    {
      /* TIM6 Start. */
      /* Starts the TIM Base generation in interrupt mode. */
      HAL_TIM_Base_Start_IT(&htim6);

      /* Start interrupt for Update event*/
      HAL_TIM_Base_Start_IT(&htim6);
    }

    {
      /* TIM15 Start. */

      /* Wait for htim15 State READY. */
      while ((&htim15)->State == HAL_TIM_STATE_BUSY) {
      }

      HAL_TIM_PWM_Start(&htim15,TIM_CHANNEL_2);
    }
  }
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] ControlMRAC.c
 */
