/*
 * File: ControlMRAC.h
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

#ifndef RTW_HEADER_ControlMRAC_h_
#define RTW_HEADER_ControlMRAC_h_
#include "ControlMRAC_TIM.h"
#include "ControlMRAC_USART.h"
#include "STM32_Config.h"
#include "ControlMRAC_External_Functions.h"
#include "ControlMRAC_EXTI.h"
#ifndef ControlMRAC_COMMON_INCLUDES_
# define ControlMRAC_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ControlMRAC_COMMON_INCLUDES_ */

#include "ControlMRAC_types.h"

/* GPIOB output mask value declaration. */
extern uint16_t GPIOB_maskWrite;

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Divide;                       /* '<S10>/Divide' */
  uint32_T Buff;                       /* '<S1>/MATLAB Function1' */
  uint16_T USART_Send;                 /* '<S1>/USART_Send' */
  uint16_T NbChar;                     /* '<S1>/MATLAB Function1' */
} B_ControlMRAC;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T uk1_DSTATE;                   /* '<S9>/u(k-1)' */
  real_T uk2_DSTATE;                   /* '<S9>/u(k.-2)' */
  real_T yk1_DSTATE;                   /* '<S9>/y(k-1)' */
  real_T yk2_DSTATE;                   /* '<S9>/y(k-2)' */
  real_T UD_DSTATE;                    /* '<S12>/UD' */
  real_T Integrator_DSTATE;            /* '<S11>/Integrator' */
  real_T theta_DSTATE;                 /* '<S2>/theta' */
  real_T stateControl;                 /* '<Root>/para realizar el control' */
  real_T Ref;                          /* '<Root>/referencia' */
  real_T rads;                         /* '<Root>/velocidad (rad//s)' */
  real_T pulses;                       /* '<Root>/pulsos del encoder' */
} DW_ControlMRAC;

/* Real-time Model Data Structure */
struct tag_RTM_ControlMRAC {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_ControlMRAC ControlMRAC_B;

/* Block states (default storage) */
extern DW_ControlMRAC ControlMRAC_DW;

/* Model entry point functions */
extern void ControlMRAC_initialize(void);
extern void ControlMRAC_step(void);

/* Real-time Model object */
extern RT_MODEL_ControlMRAC *const ControlMRAC_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S12>/Data Type Duplicate' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ControlMRAC'
 * '<S1>'   : 'ControlMRAC/ISR lectura rads//s'
 * '<S2>'   : 'ControlMRAC/MRAC'
 * '<S3>'   : 'ControlMRAC/Tarea adicional'
 * '<S4>'   : 'ControlMRAC/lectura pulsos encoder '
 * '<S5>'   : 'ControlMRAC/ISR lectura rads//s/MATLAB Function'
 * '<S6>'   : 'ControlMRAC/ISR lectura rads//s/MATLAB Function1'
 * '<S7>'   : 'ControlMRAC/MRAC/CONTROLADOR'
 * '<S8>'   : 'ControlMRAC/MRAC/MATLAB Function'
 * '<S9>'   : 'ControlMRAC/MRAC/RefModel'
 * '<S10>'  : 'ControlMRAC/MRAC/Subsystem'
 * '<S11>'  : 'ControlMRAC/MRAC/CONTROLADOR/PID'
 * '<S12>'  : 'ControlMRAC/MRAC/CONTROLADOR/PID/D'
 */
#endif                                 /* RTW_HEADER_ControlMRAC_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] ControlMRAC.h
 */
