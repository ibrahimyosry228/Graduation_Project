/*
 * File: Ready_to_deploy.h
 *
 * Code generated for Simulink model 'Ready_to_deploy'.
 *
 * Model version                  : 1.108
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue May 11 03:15:02 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Ready_to_deploy_h_
#define RTW_HEADER_Ready_to_deploy_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef Ready_to_deploy_COMMON_INCLUDES_
# define Ready_to_deploy_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "c2000BoardSupport.h"
#include "F2837xD_device.h"
#include "F2837xD_Examples.h"
#endif                                 /* Ready_to_deploy_COMMON_INCLUDES_ */

#include "Ready_to_deploy_types.h"
#include "MW_target_hardware_resources.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_zcfcn.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  parameter_bus parameter;
  real_T varargin_1_tmp[602];
  real_T dv[602];
  coder_internal_ref_1_Ready_to_T soc;
  coder_internal_ref_1_Ready_to_T ocv;
  real_T Buffer[500];                  /* '<Root>/Buffer' */
  real_T Buffer1[500];                 /* '<Root>/Buffer1' */
  int16_T ii_data[602];
  real_T Xa[55];
  real_T dv1[55];
  real_T Xx[33];
  real_T Xs[33];
  real_T TmpRTBAtSampleandHoldInport1; /* '<Root>/Gain3' */
  real_T TmpRTBAtSampleandHold1Inport1;/* '<Root>/Gain2' */
  real_T ADC;                          /* '<Root>/ADC' */
  real_T ADC1;                         /* '<Root>/ADC1' */
  real_T TmpRTBAtSum4Inport2;          /* '<Root>/Constant1' */
  real_T TmpRTBAtProductInport1;       /* '<Root>/R0' */
  real_T TmpRTBAtUnscentedKalmanFilterIn;/* '<Root>/initial condition' */
  real_T In;                           /* '<S2>/In' */
  real_T In_i;                         /* '<S1>/In' */
} B_Ready_to_deploy_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Buffer1_CircBuf[1000];        /* '<Root>/Buffer1' */
  real_T Buffer_CircBuf[1000];         /* '<Root>/Buffer' */
  real_T SigmaX[9];                    /* '<Root>/Unit Delay1' */
  real_T xhat[3];                      /* '<Root>/Unit Delay' */
  real_T priorI;                       /* '<Root>/Unit Delay2' */
  real_T signIk;                       /* '<Root>/Unit Delay3' */
  real_T ICic_DSTATE;                  /* '<S6>/IC=ic' */
  real_T TmpRTBAtSampleandHoldInport1_Bu;/* synthesized block */
  real_T TmpRTBAtUnscentedKalmanFilterIn;/* synthesized block */
  real_T TmpRTBAtSampleandHold1Inport1_B;/* synthesized block */
  real_T TmpRTBAtUnscentedKalmanFilter_o;/* synthesized block */
  real_T TmpRTBAtSum4Inport2_Buffer0;  /* synthesized block */
  real_T TmpRTBAtProductInport1_Buffer0;/* synthesized block */
  real_T TmpRTBAtSwitchInport1_Buffer; /* synthesized block */
  real_T TmpRTBAtUnscentedKalmanFilter_b;/* synthesized block */
  real_T TmpRTBAtDataTypeConversionInpor;/* synthesized block */
  int32_T Buffer1_inBufPtrIdx;         /* '<Root>/Buffer1' */
  int32_T Buffer1_outBufPtrIdx;        /* '<Root>/Buffer1' */
  int32_T Buffer_inBufPtrIdx;          /* '<Root>/Buffer' */
  int32_T Buffer_outBufPtrIdx;         /* '<Root>/Buffer' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  int32_T clockTickCounter_a;          /* '<Root>/Pulse Generator1' */
} DW_Ready_to_deploy_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState SampleandHold1_Trig_ZCE;  /* '<Root>/Sample and Hold1' */
  ZCSigState SampleandHold_Trig_ZCE;   /* '<Root>/Sample and Hold' */
} PrevZCX_Ready_to_deploy_T;

/* Parameters (default storage) */
struct P_Ready_to_deploy_T_ {
  parameter_bus parameter;             /* Variable: parameter
                                        * Referenced by:
                                        *   '<Root>/Constant6'
                                        *   '<Root>/R0'
                                        */
  real_T SampleandHold_ic;             /* Mask Parameter: SampleandHold_ic
                                        * Referenced by: '<S6>/IC=ic'
                                        */
  real_T _Y0;                          /* Expression: initCond
                                        * Referenced by: '<S1>/ '
                                        */
  real_T _Y0_p;                        /* Expression: initCond
                                        * Referenced by: '<S2>/ '
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<Root>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<Root>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T TmpRTBAtSampleandHoldInport1_In;/* Expression: 0
                                          * Referenced by: synthesized block
                                          */
  real_T PulseGenerator1_Amp;          /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Period;   /* Computed Parameter: PulseGenerator1_Period
                                    * Referenced by: '<Root>/Pulse Generator1'
                                    */
  real_T PulseGenerator1_Duty;       /* Computed Parameter: PulseGenerator1_Duty
                                      * Referenced by: '<Root>/Pulse Generator1'
                                      */
  real_T PulseGenerator1_PhaseDelay;   /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator1'
                                        */
  real_T TmpRTBAtSampleandHold1Inport1_I;/* Expression: 0
                                          * Referenced by: synthesized block
                                          */
  real_T Gain6_Gain;                   /* Expression: 3/4095
                                        * Referenced by: '<Root>/Gain6'
                                        */
  real_T TmpRTBAtSum4Inport2_InitialCond;/* Expression: 0
                                          * Referenced by: synthesized block
                                          */
  real_T Gain5_Gain;                   /* Expression: 1/0.185
                                        * Referenced by: '<Root>/Gain5'
                                        */
  real_T Buffer1_ic;                   /* Expression: 0
                                        * Referenced by: '<Root>/Buffer1'
                                        */
  real_T Gain2_Gain;                   /* Expression: -1
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T TmpRTBAtProductInport1_InitialC;/* Expression: 0
                                          * Referenced by: synthesized block
                                          */
  real_T Gain4_Gain;                   /* Expression: 3/4095
                                        * Referenced by: '<Root>/Gain4'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1.5
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T Buffer_ic;                    /* Expression: 0
                                        * Referenced by: '<Root>/Buffer'
                                        */
  real_T UnitDelay1_InitialCondition[9];/* Expression: diag([1e-6 1e-8 2e-4])
                                         * Referenced by: '<Root>/Unit Delay1'
                                         */
  real_T TmpRTBAtUnscentedKalmanFilterIn;/* Expression: 0
                                          * Referenced by: synthesized block
                                          */
  real_T UnitDelay_InitialCondition[3];/* Expression: [1;0;0]
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  real_T UnitDelay2_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay2'
                                        */
  real_T UnitDelay3_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay3'
                                        */
  real_T Constant1_Value;              /* Expression: 2.5
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S4>/Constant2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Ready_to_deploy_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick2;
    struct {
      uint32_T TID[5];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
      boolean_T TID0_2;
      boolean_T TID1_2;
      boolean_T TID1_4;
      boolean_T TID2_4;
    } RateInteraction;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Ready_to_deploy_T Ready_to_deploy_P;

/* Block signals (default storage) */
extern B_Ready_to_deploy_T Ready_to_deploy_B;

/* Block states (default storage) */
extern DW_Ready_to_deploy_T Ready_to_deploy_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_Ready_to_deploy_T Ready_to_deploy_PrevZCX;

/* External function called from main */
extern void Ready_to_deploy_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void Ready_to_deploy_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void Ready_to_deploy_initialize(void);
extern void Ready_to_deploy_step0(void);
extern void Ready_to_deploy_step1(void);
extern void Ready_to_deploy_step2(void);
extern void Ready_to_deploy_step3(void);
extern void Ready_to_deploy_step4(void);
extern void Ready_to_deploy_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Ready_to_deploy_T *const Ready_to_deploy_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<Root>/Display1' : Unused code path elimination
 * Block '<Root>/Display2' : Unused code path elimination
 * Block '<Root>/Gain' : Unused code path elimination
 * Block '<Root>/Gain1' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Sum' : Unused code path elimination
 * Block '<Root>/Sum1' : Unused code path elimination
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
 * '<Root>' : 'Ready_to_deploy'
 * '<S1>'   : 'Ready_to_deploy/Sample and Hold'
 * '<S2>'   : 'Ready_to_deploy/Sample and Hold1'
 * '<S3>'   : 'Ready_to_deploy/Unscented Kalman Filter'
 * '<S4>'   : 'Ready_to_deploy/initial condition'
 * '<S5>'   : 'Ready_to_deploy/initial condition/Sample and Hold'
 * '<S6>'   : 'Ready_to_deploy/initial condition/Sample and Hold/Model'
 */
#endif                                 /* RTW_HEADER_Ready_to_deploy_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
