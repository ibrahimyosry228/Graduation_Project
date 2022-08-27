/*
 * File: Ready_to_deploy.c
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

#include "Ready_to_deploy.h"
#include "Ready_to_deploy_private.h"

/* Block signals (default storage) */
B_Ready_to_deploy_T Ready_to_deploy_B;

/* Block states (default storage) */
DW_Ready_to_deploy_T Ready_to_deploy_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Ready_to_deploy_T Ready_to_deploy_PrevZCX;

/* Real-time model */
RT_MODEL_Ready_to_deploy_T Ready_to_deploy_M_;
RT_MODEL_Ready_to_deploy_T *const Ready_to_deploy_M = &Ready_to_deploy_M_;

/* Forward declaration for local functions */
static void Ready_to_deploy_abs(const real_T x[602], real_T y[602]);
static void Ready_to_deploy_diag(const real_T v[3], real_T d[9]);
static void Ready_to_deploy_blkdiag(const real_T varargin_1[9], const real_T
  varargin_2[4], real_T y[25]);
static void Ready_to_deploy_stateEqn(coder_internal_ref_Ready_to_d_T *RC,
  coder_internal_ref_Ready_to_d_T *G, coder_internal_ref_Ready_to_d_T *Q,
  coder_internal_ref_Ready_to_d_T *deltat, coder_internal_ref_Ready_to_d_T
  *zkInd, coder_internal_ref_Ready_to_d_T *irkInd,
  coder_internal_ref_Ready_to_d_T *hkInd, const real_T xold[33], real_T current,
  const real_T xnoise[11], real_T parameter_RC, real_T parameter_G, real_T
  parameter_Q, real_T parameter_zkInd, real_T parameter_irkInd, real_T
  parameter_hkInd, real_T xnew[33]);
static void Ready_to_deploy_outputEqn(coder_internal_ref_1_Ready_to_T *soc,
  coder_internal_ref_1_Ready_to_T *ocv, coder_internal_ref_Ready_to_d_T *R0,
  coder_internal_ref_Ready_to_d_T *R, coder_internal_ref_Ready_to_d_T *M0,
  coder_internal_ref_Ready_to_d_T *M, coder_internal_ref_Ready_to_d_T *zkInd,
  coder_internal_ref_Ready_to_d_T *irkInd, coder_internal_ref_Ready_to_d_T
  *hkInd, const real_T x[33], real_T current, const real_T ynoise[11], real_T
  signIk, const parameter_bus *parameter, real_T y[11]);
static void rate_monotonic_scheduler(void);
uint16_T MW_adcAInitFlag = 0;
uint16_T MW_adcCInitFlag = 0;

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Ready_to_deploy_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Ready_to_deploy_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(Ready_to_deploy_M, 2));
  eventFlags[3] = ((boolean_T)rtmStepTask(Ready_to_deploy_M, 3));
  eventFlags[4] = ((boolean_T)rtmStepTask(Ready_to_deploy_M, 4));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rates: 1, 2 */
  Ready_to_deploy_M->Timing.RateInteraction.TID0_1 =
    (Ready_to_deploy_M->Timing.TaskCounters.TID[1] == 0);
  Ready_to_deploy_M->Timing.RateInteraction.TID0_2 =
    (Ready_to_deploy_M->Timing.TaskCounters.TID[2] == 0);

  /* tid 1 shares data with slower tid rates: 2, 4 */
  if (Ready_to_deploy_M->Timing.TaskCounters.TID[1] == 0) {
    Ready_to_deploy_M->Timing.RateInteraction.TID1_2 =
      (Ready_to_deploy_M->Timing.TaskCounters.TID[2] == 0);
    Ready_to_deploy_M->Timing.RateInteraction.TID1_4 =
      (Ready_to_deploy_M->Timing.TaskCounters.TID[4] == 0);
  }

  /* tid 2 shares data with slower tid rate: 4 */
  if (Ready_to_deploy_M->Timing.TaskCounters.TID[2] == 0) {
    Ready_to_deploy_M->Timing.RateInteraction.TID2_4 =
      (Ready_to_deploy_M->Timing.TaskCounters.TID[4] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Ready_to_deploy_M->Timing.TaskCounters.TID[1])++;
  if ((Ready_to_deploy_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.001s, 0.0s] */
    Ready_to_deploy_M->Timing.TaskCounters.TID[1] = 0;
  }

  (Ready_to_deploy_M->Timing.TaskCounters.TID[2])++;
  if ((Ready_to_deploy_M->Timing.TaskCounters.TID[2]) > 999) {/* Sample time: [0.1s, 0.0s] */
    Ready_to_deploy_M->Timing.TaskCounters.TID[2] = 0;
  }

  (Ready_to_deploy_M->Timing.TaskCounters.TID[3])++;
  if ((Ready_to_deploy_M->Timing.TaskCounters.TID[3]) > 4999) {/* Sample time: [0.5s, 0.0s] */
    Ready_to_deploy_M->Timing.TaskCounters.TID[3] = 0;
  }

  (Ready_to_deploy_M->Timing.TaskCounters.TID[4])++;
  if ((Ready_to_deploy_M->Timing.TaskCounters.TID[4]) > 35999999) {/* Sample time: [3600.0s, 0.0s] */
    Ready_to_deploy_M->Timing.TaskCounters.TID[4] = 0;
  }
}

/* Function for MATLAB Function: '<Root>/Unscented Kalman Filter' */
static void Ready_to_deploy_abs(const real_T x[602], real_T y[602])
{
  int16_T k;
  for (k = 0; k < 602; k++) {
    y[k] = fabs(x[k]);
  }
}

/* Function for MATLAB Function: '<Root>/Unscented Kalman Filter' */
static void Ready_to_deploy_diag(const real_T v[3], real_T d[9])
{
  int16_T i;
  for (i = 0; i < 9; i++) {
    d[i] = 0.0;
  }

  d[0] = v[0];
  d[4] = v[1];
  d[8] = v[2];
}

/* Function for MATLAB Function: '<Root>/Unscented Kalman Filter' */
static void Ready_to_deploy_blkdiag(const real_T varargin_1[9], const real_T
  varargin_2[4], real_T y[25])
{
  int16_T i;
  memset(&y[0], 0, 25U * sizeof(real_T));
  for (i = 0; i < 3; i++) {
    y[5 * i] = varargin_1[3 * i];
    y[5 * i + 1] = varargin_1[3 * i + 1];
    y[5 * i + 2] = varargin_1[3 * i + 2];
  }

  y[18] = varargin_2[0];
  y[19] = varargin_2[1];
  y[23] = varargin_2[2];
  y[24] = varargin_2[3];
}

/* Function for MATLAB Function: '<Root>/Unscented Kalman Filter' */
static void Ready_to_deploy_stateEqn(coder_internal_ref_Ready_to_d_T *RC,
  coder_internal_ref_Ready_to_d_T *G, coder_internal_ref_Ready_to_d_T *Q,
  coder_internal_ref_Ready_to_d_T *deltat, coder_internal_ref_Ready_to_d_T
  *zkInd, coder_internal_ref_Ready_to_d_T *irkInd,
  coder_internal_ref_Ready_to_d_T *hkInd, const real_T xold[33], real_T current,
  const real_T xnoise[11], real_T parameter_RC, real_T parameter_G, real_T
  parameter_Q, real_T parameter_zkInd, real_T parameter_irkInd, real_T
  parameter_hkInd, real_T xnew[33])
{
  real_T Ah[11];
  real_T b_current[11];
  int16_T k;
  real_T b_current_0;
  int16_T irkInd_tmp;
  int16_T hkInd_tmp;
  real_T tmp;
  int16_T zkInd_tmp;
  RC->contents = parameter_RC;
  G->contents = parameter_G;
  Q->contents = parameter_Q;
  deltat->contents = 0.1;
  zkInd->contents = parameter_zkInd;
  irkInd->contents = parameter_irkInd;
  hkInd->contents = parameter_hkInd;
  tmp = 3600.0 * Q->contents;
  for (k = 0; k < 11; k++) {
    b_current_0 = current + xnoise[k];
    b_current[k] = b_current_0;
    Ah[k] = exp(-fabs(b_current_0 * G->contents * deltat->contents / tmp));
  }

  for (k = 0; k < 33; k++) {
    xnew[k] = 0.0 * xold[k];
  }

  irkInd_tmp = (int16_T)irkInd->contents;
  hkInd_tmp = (int16_T)hkInd->contents;
  zkInd_tmp = (int16_T)zkInd->contents;
  for (k = 0; k < 11; k++) {
    xnew[(irkInd_tmp + 3 * k) - 1] = xold[(3 * k + irkInd_tmp) - 1] *
      RC->contents + (1.0 - RC->contents) * b_current[k];
    if (b_current[k] < 0.0) {
      b_current_0 = -1.0;
    } else if (b_current[k] > 0.0) {
      b_current_0 = 1.0;
    } else if (b_current[k] == 0.0) {
      b_current_0 = 0.0;
    } else {
      b_current_0 = (rtNaN);
    }

    xnew[(hkInd_tmp + 3 * k) - 1] = xold[(3 * k + hkInd_tmp) - 1] * Ah[k] +
      (Ah[k] - 1.0) * b_current_0;
    xnew[(zkInd_tmp + 3 * k) - 1] = xold[(3 * k + zkInd_tmp) - 1] - b_current[k]
      * deltat->contents / tmp;
  }
}

/* Function for MATLAB Function: '<Root>/Unscented Kalman Filter' */
static void Ready_to_deploy_outputEqn(coder_internal_ref_1_Ready_to_T *soc,
  coder_internal_ref_1_Ready_to_T *ocv, coder_internal_ref_Ready_to_d_T *R0,
  coder_internal_ref_Ready_to_d_T *R, coder_internal_ref_Ready_to_d_T *M0,
  coder_internal_ref_Ready_to_d_T *M, coder_internal_ref_Ready_to_d_T *zkInd,
  coder_internal_ref_Ready_to_d_T *irkInd, coder_internal_ref_Ready_to_d_T
  *hkInd, const real_T x[33], real_T current, const real_T ynoise[11], real_T
  signIk, const parameter_bus *parameter, real_T y[11])
{
  int16_T k;
  int16_T irkInd_0;
  real_T R0_0;
  int16_T hkInd_0;
  real_T M0_0;
  memcpy(&soc->contents[0], &parameter->soc[0], 602U * sizeof(real_T));
  memcpy(&ocv->contents[0], &parameter->ocv[0], 602U * sizeof(real_T));
  R0->contents = parameter->R0;
  R->contents = parameter->R;
  M0->contents = parameter->M0;
  M->contents = parameter->M;
  zkInd->contents = parameter->zkInd;
  irkInd->contents = parameter->irkInd;
  hkInd->contents = parameter->hkInd;
  irkInd_0 = (int16_T)irkInd->contents;
  R0_0 = R0->contents * current;
  hkInd_0 = (int16_T)hkInd->contents;
  M0_0 = M0->contents * signIk;
  for (k = 0; k < 11; k++) {
    y[k] = ((((ocv->contents[0] - x[(3 * k + irkInd_0) - 1] * R->contents) -
              R0_0) + x[(3 * k + hkInd_0) - 1] * M->contents) + M0_0) + ynoise[k];
  }
}

/* Model step function for TID0 */
void Ready_to_deploy_step0(void)       /* Sample time: [0.0001s, 0.0s] */
{
  real_T rtb_PulseGenerator;
  ZCEventType zcEvent;

  {                                    /* Sample time: [0.0001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (Ready_to_deploy_DW.clockTickCounter <
                        Ready_to_deploy_P.PulseGenerator_Duty) &&
    (Ready_to_deploy_DW.clockTickCounter >= 0L) ?
    Ready_to_deploy_P.PulseGenerator_Amp : 0.0;
  if (Ready_to_deploy_DW.clockTickCounter >=
      Ready_to_deploy_P.PulseGenerator_Period - 1.0) {
    Ready_to_deploy_DW.clockTickCounter = 0L;
  } else {
    Ready_to_deploy_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* RateTransition generated from: '<Root>/Sample and Hold' */
  if (Ready_to_deploy_M->Timing.RateInteraction.TID0_1) {
    Ready_to_deploy_B.TmpRTBAtSampleandHoldInport1 =
      Ready_to_deploy_DW.TmpRTBAtSampleandHoldInport1_Bu;
  }

  /* End of RateTransition generated from: '<Root>/Sample and Hold' */

  /* Outputs for Triggered SubSystem: '<Root>/Sample and Hold' incorporates:
   *  TriggerPort: '<S1>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &Ready_to_deploy_PrevZCX.SampleandHold_Trig_ZCE,
                     (rtb_PulseGenerator));
  if (zcEvent != NO_ZCEVENT) {
    /* Inport: '<S1>/In' */
    Ready_to_deploy_B.In_i = Ready_to_deploy_B.TmpRTBAtSampleandHoldInport1;
  }

  /* End of Outputs for SubSystem: '<Root>/Sample and Hold' */

  /* RateTransition generated from: '<Root>/Unscented Kalman Filter' */
  if (Ready_to_deploy_M->Timing.RateInteraction.TID0_2) {
    Ready_to_deploy_DW.TmpRTBAtUnscentedKalmanFilterIn = Ready_to_deploy_B.In_i;
  }

  /* End of RateTransition generated from: '<Root>/Unscented Kalman Filter' */

  /* DiscretePulseGenerator: '<Root>/Pulse Generator1' */
  rtb_PulseGenerator = (Ready_to_deploy_DW.clockTickCounter_a <
                        Ready_to_deploy_P.PulseGenerator1_Duty) &&
    (Ready_to_deploy_DW.clockTickCounter_a >= 0L) ?
    Ready_to_deploy_P.PulseGenerator1_Amp : 0.0;
  if (Ready_to_deploy_DW.clockTickCounter_a >=
      Ready_to_deploy_P.PulseGenerator1_Period - 1.0) {
    Ready_to_deploy_DW.clockTickCounter_a = 0L;
  } else {
    Ready_to_deploy_DW.clockTickCounter_a++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator1' */

  /* RateTransition generated from: '<Root>/Sample and Hold1' */
  if (Ready_to_deploy_M->Timing.RateInteraction.TID0_1) {
    Ready_to_deploy_B.TmpRTBAtSampleandHold1Inport1 =
      Ready_to_deploy_DW.TmpRTBAtSampleandHold1Inport1_B;
  }

  /* End of RateTransition generated from: '<Root>/Sample and Hold1' */

  /* Outputs for Triggered SubSystem: '<Root>/Sample and Hold1' incorporates:
   *  TriggerPort: '<S2>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &Ready_to_deploy_PrevZCX.SampleandHold1_Trig_ZCE,
                     (rtb_PulseGenerator));
  if (zcEvent != NO_ZCEVENT) {
    /* Inport: '<S2>/In' */
    Ready_to_deploy_B.In = Ready_to_deploy_B.TmpRTBAtSampleandHold1Inport1;
  }

  /* End of Outputs for SubSystem: '<Root>/Sample and Hold1' */

  /* RateTransition generated from: '<Root>/Unscented Kalman Filter' */
  if (Ready_to_deploy_M->Timing.RateInteraction.TID0_2) {
    Ready_to_deploy_DW.TmpRTBAtUnscentedKalmanFilter_o = Ready_to_deploy_B.In;
  }

  /* End of RateTransition generated from: '<Root>/Unscented Kalman Filter' */
}

/* Model step function for TID1 */
void Ready_to_deploy_step1(void)       /* Sample time: [0.001s, 0.0s] */
{
  int32_T i;
  int32_T offsetFromMemBase;
  int32_T nSamps;
  real_T rtb_Gain2;
  real_T Gain5;

  /* S-Function (c2802xadc): '<Root>/ADC' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    AdcaRegs.ADCSOCFRC1.bit.SOC0 = 1;

    /* Wait for the period of Sampling window and EOC result to be latched after trigger */
    asm(" RPT #75 || NOP");
    Ready_to_deploy_B.ADC = (AdcaResultRegs.ADCRESULT0);
  }

  /* S-Function (c2802xadc): '<Root>/ADC1' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    AdccRegs.ADCSOCFRC1.bit.SOC0 = 1;

    /* Wait for the period of Sampling window and EOC result to be latched after trigger */
    asm(" RPT #75 || NOP");
    Ready_to_deploy_B.ADC1 = (AdccResultRegs.ADCRESULT0);
  }

  /* RateTransition generated from: '<Root>/Sum4' */
  if (Ready_to_deploy_M->Timing.RateInteraction.TID1_2) {
    Ready_to_deploy_B.TmpRTBAtSum4Inport2 =
      Ready_to_deploy_DW.TmpRTBAtSum4Inport2_Buffer0;
  }

  /* End of RateTransition generated from: '<Root>/Sum4' */

  /* Gain: '<Root>/Gain5' incorporates:
   *  Gain: '<Root>/Gain6'
   *  Sum: '<Root>/Sum4'
   */
  Gain5 = (Ready_to_deploy_P.Gain6_Gain * Ready_to_deploy_B.ADC1 -
           Ready_to_deploy_B.TmpRTBAtSum4Inport2) * Ready_to_deploy_P.Gain5_Gain;

  /* Buffer: '<Root>/Buffer1' */
  nSamps = 1000L;
  offsetFromMemBase = Ready_to_deploy_DW.Buffer1_inBufPtrIdx;
  if (1000L - Ready_to_deploy_DW.Buffer1_inBufPtrIdx <= 1L) {
    for (i = 0L; i < 1000L - Ready_to_deploy_DW.Buffer1_inBufPtrIdx; i++) {
      Ready_to_deploy_DW.Buffer1_CircBuf[Ready_to_deploy_DW.Buffer1_inBufPtrIdx
        + i] = Gain5;
    }

    offsetFromMemBase = 0L;
    nSamps = Ready_to_deploy_DW.Buffer1_inBufPtrIdx;
  }

  for (i = 0L; i < nSamps - 999L; i++) {
    Ready_to_deploy_DW.Buffer1_CircBuf[offsetFromMemBase + i] = Gain5;
  }

  Ready_to_deploy_DW.Buffer1_inBufPtrIdx++;
  if (Ready_to_deploy_DW.Buffer1_inBufPtrIdx >= 1000L) {
    Ready_to_deploy_DW.Buffer1_inBufPtrIdx -= 1000L;
  }

  /* End of Buffer: '<Root>/Buffer1' */

  /* Gain: '<Root>/Gain2' */
  rtb_Gain2 = Ready_to_deploy_P.Gain2_Gain * Gain5;

  /* RateTransition generated from: '<Root>/Sample and Hold1' */
  Ready_to_deploy_DW.TmpRTBAtSampleandHold1Inport1_B = rtb_Gain2;

  /* RateTransition generated from: '<Root>/Product' */
  if (Ready_to_deploy_M->Timing.RateInteraction.TID1_2) {
    Ready_to_deploy_B.TmpRTBAtProductInport1 =
      Ready_to_deploy_DW.TmpRTBAtProductInport1_Buffer0;
  }

  /* End of RateTransition generated from: '<Root>/Product' */

  /* Gain: '<Root>/Gain3' incorporates:
   *  Gain: '<Root>/Gain4'
   */
  rtb_Gain2 = Ready_to_deploy_P.Gain4_Gain * Ready_to_deploy_B.ADC *
    Ready_to_deploy_P.Gain3_Gain;

  /* RateTransition generated from: '<S6>/Switch' incorporates:
   *  Product: '<Root>/Product'
   *  Sum: '<Root>/Sum2'
   */
  if (Ready_to_deploy_M->Timing.RateInteraction.TID1_4) {
    Ready_to_deploy_DW.TmpRTBAtSwitchInport1_Buffer = rtb_Gain2 -
      Ready_to_deploy_B.TmpRTBAtProductInport1 * Gain5;
  }

  /* End of RateTransition generated from: '<S6>/Switch' */

  /* Buffer: '<Root>/Buffer' */
  nSamps = 1000L;
  offsetFromMemBase = Ready_to_deploy_DW.Buffer_inBufPtrIdx;
  if (1000L - Ready_to_deploy_DW.Buffer_inBufPtrIdx <= 1L) {
    for (i = 0L; i < 1000L - Ready_to_deploy_DW.Buffer_inBufPtrIdx; i++) {
      Ready_to_deploy_DW.Buffer_CircBuf[Ready_to_deploy_DW.Buffer_inBufPtrIdx +
        i] = rtb_Gain2;
    }

    offsetFromMemBase = 0L;
    nSamps = Ready_to_deploy_DW.Buffer_inBufPtrIdx;
  }

  for (i = 0L; i < nSamps - 999L; i++) {
    Ready_to_deploy_DW.Buffer_CircBuf[offsetFromMemBase + i] = rtb_Gain2;
  }

  Ready_to_deploy_DW.Buffer_inBufPtrIdx++;
  if (Ready_to_deploy_DW.Buffer_inBufPtrIdx >= 1000L) {
    Ready_to_deploy_DW.Buffer_inBufPtrIdx -= 1000L;
  }

  /* End of Buffer: '<Root>/Buffer' */

  /* RateTransition generated from: '<Root>/Sample and Hold' */
  Ready_to_deploy_DW.TmpRTBAtSampleandHoldInport1_Bu = rtb_Gain2;
}

/* Model step function for TID2 */
void Ready_to_deploy_step2(void)       /* Sample time: [0.1s, 0.0s] */
{
  coder_internal_ref_Ready_to_d_T M;
  coder_internal_ref_Ready_to_d_T M0;
  coder_internal_ref_Ready_to_d_T R;
  coder_internal_ref_Ready_to_d_T R0;
  coder_internal_ref_Ready_to_d_T deltat;
  coder_internal_ref_Ready_to_d_T Q;
  coder_internal_ref_Ready_to_d_T G;
  coder_internal_ref_Ready_to_d_T RC;
  coder_internal_ref_Ready_to_d_T hkInd;
  coder_internal_ref_Ready_to_d_T irkInd;
  coder_internal_ref_Ready_to_d_T zkInd;
  real_T Y[11];
  real_T L[3];
  real_T ytelda;
  real_T sigmaXa[25];
  int16_T idxAjj;
  real_T ssq;
  int16_T b_idx;
  int16_T k;
  int16_T iy;
  int16_T e;
  int16_T ia;
  int16_T b_ix;
  int16_T b_iy;
  int16_T d_k;
  real_T tmp[5];
  real_T Xa[11];
  real_T Xx[9];
  real_T L_0[9];
  real_T L_1;
  static const real_T g[4] = { 0.44721359549995793, 0.0, 0.0,
    0.44721359549995793 };

  static const real_T h[3] = { 1.0E-6, 1.0E-8, 0.0002 };

  static const real_T b_b[11] = { -0.666666666666667, 0.16666666666666669,
    0.16666666666666669, 0.16666666666666669, 0.16666666666666669,
    0.16666666666666669, 0.16666666666666669, 0.16666666666666669,
    0.16666666666666669, 0.16666666666666669, 0.16666666666666669 };

  static const real_T c_b[121] = { -0.666666666666667, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.16666666666666669, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.16666666666666669, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.16666666666666669, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.16666666666666669, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.16666666666666669, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.16666666666666669, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.16666666666666669, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.16666666666666669, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.16666666666666669, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.16666666666666669 };

  boolean_T exitg1;

  /* RateTransition generated from: '<Root>/Unscented Kalman Filter' */
  if (Ready_to_deploy_M->Timing.RateInteraction.TID2_4) {
    Ready_to_deploy_B.TmpRTBAtUnscentedKalmanFilterIn =
      Ready_to_deploy_DW.TmpRTBAtUnscentedKalmanFilter_b;
  }

  /* End of RateTransition generated from: '<Root>/Unscented Kalman Filter' */

  /* MATLAB Function: '<Root>/Unscented Kalman Filter' incorporates:
   *  Constant: '<Root>/Constant6'
   *  DigitalClock: '<Root>/Digital Clock'
   *  RateTransition generated from: '<Root>/Unscented Kalman Filter'
   *  UnitDelay: '<Root>/Unit Delay'
   *  UnitDelay: '<Root>/Unit Delay1'
   *  UnitDelay: '<Root>/Unit Delay2'
   * */
  Ready_to_deploy_B.parameter = Ready_to_deploy_P.parameter;
  Ready_to_deploy_B.parameter.deltat = 0.1;
  memcpy(&Ready_to_deploy_B.ocv.contents[0], &Ready_to_deploy_P.parameter.ocv[0],
         602U * sizeof(real_T));
  memcpy(&Ready_to_deploy_B.soc.contents[0], &Ready_to_deploy_P.parameter.soc[0],
         602U * sizeof(real_T));
  RC.contents = Ready_to_deploy_P.parameter.RC;
  G.contents = Ready_to_deploy_P.parameter.G;
  Q.contents = Ready_to_deploy_P.parameter.Q;
  deltat.contents = 0.1;
  R0.contents = Ready_to_deploy_P.parameter.R0;
  R.contents = Ready_to_deploy_P.parameter.R;
  M0.contents = Ready_to_deploy_P.parameter.M0;
  M.contents = Ready_to_deploy_P.parameter.M;
  zkInd.contents = Ready_to_deploy_P.parameter.zkInd;
  irkInd.contents = Ready_to_deploy_P.parameter.irkInd;
  hkInd.contents = Ready_to_deploy_P.parameter.hkInd;
  if (((Ready_to_deploy_M->Timing.clockTick2) * 0.1) < 0.0001) {
    for (b_idx = 0; b_idx < 602; b_idx++) {
      Ready_to_deploy_B.dv[b_idx] = Ready_to_deploy_P.parameter.ocv[b_idx] -
        Ready_to_deploy_B.TmpRTBAtUnscentedKalmanFilterIn;
    }

    Ready_to_deploy_abs(Ready_to_deploy_B.dv, Ready_to_deploy_B.varargin_1_tmp);
    if (!rtIsNaN(Ready_to_deploy_B.varargin_1_tmp[0])) {
      b_idx = 1;
    } else {
      b_idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 603)) {
        if (!rtIsNaN(Ready_to_deploy_B.varargin_1_tmp[k - 1])) {
          b_idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (b_idx == 0) {
      ssq = Ready_to_deploy_B.varargin_1_tmp[0];
    } else {
      ssq = Ready_to_deploy_B.varargin_1_tmp[b_idx - 1];
      while (b_idx + 1 < 603) {
        if (ssq > Ready_to_deploy_B.varargin_1_tmp[b_idx]) {
          ssq = Ready_to_deploy_B.varargin_1_tmp[b_idx];
        }

        b_idx++;
      }
    }

    b_idx = 0;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 602)) {
      if (ssq == Ready_to_deploy_B.varargin_1_tmp[k]) {
        b_idx++;
        Ready_to_deploy_B.ii_data[b_idx - 1] = k + 1;
        if (b_idx >= 602) {
          exitg1 = true;
        } else {
          k++;
        }
      } else {
        k++;
      }
    }

    Ready_to_deploy_DW.xhat[0] =
      Ready_to_deploy_P.parameter.soc[Ready_to_deploy_B.ii_data[0] - 1];
    Ready_to_deploy_DW.xhat[1] = 0.0;
    Ready_to_deploy_DW.xhat[2] = 0.0;
    Ready_to_deploy_diag(h, Ready_to_deploy_DW.SigmaX);
    Ready_to_deploy_DW.priorI = 0.0;
    Ready_to_deploy_DW.signIk = 0.0;
  }

  if (fabs(Ready_to_deploy_DW.TmpRTBAtUnscentedKalmanFilter_o) >
      Ready_to_deploy_P.parameter.Q / 100.0) {
    if (Ready_to_deploy_DW.TmpRTBAtUnscentedKalmanFilter_o < 0.0) {
      Ready_to_deploy_DW.signIk = -1.0;
    } else if (Ready_to_deploy_DW.TmpRTBAtUnscentedKalmanFilter_o > 0.0) {
      Ready_to_deploy_DW.signIk = 1.0;
    } else if (Ready_to_deploy_DW.TmpRTBAtUnscentedKalmanFilter_o == 0.0) {
      Ready_to_deploy_DW.signIk = 0.0;
    } else {
      Ready_to_deploy_DW.signIk = (rtNaN);
    }
  }

  b_idx = 0;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 3)) {
    idxAjj = k * 3 + k;
    ssq = 0.0;
    if (k >= 1) {
      b_ix = k;
      b_iy = k;
      for (d_k = 0; d_k < k; d_k++) {
        ssq += Ready_to_deploy_DW.SigmaX[b_ix] * Ready_to_deploy_DW.SigmaX[b_iy];
        b_ix += 3;
        b_iy += 3;
      }
    }

    ssq = Ready_to_deploy_DW.SigmaX[idxAjj] - ssq;
    if (ssq > 0.0) {
      ssq = sqrt(ssq);
      Ready_to_deploy_DW.SigmaX[idxAjj] = ssq;
      if (k + 1 < 3) {
        if (k != 0) {
          b_ix = k;
          b_iy = ((k - 1) * 3 + k) + 2;
          for (d_k = k + 2; d_k <= b_iy; d_k += 3) {
            ytelda = -Ready_to_deploy_DW.SigmaX[b_ix];
            iy = idxAjj + 1;
            e = (d_k - k) + 1;
            for (ia = d_k; ia <= e; ia++) {
              Ready_to_deploy_DW.SigmaX[iy] += Ready_to_deploy_DW.SigmaX[ia - 1]
                * ytelda;
              iy++;
            }

            b_ix += 3;
          }
        }

        ssq = 1.0 / ssq;
        b_ix = (idxAjj - k) + 3;
        for (idxAjj++; idxAjj < b_ix; idxAjj++) {
          Ready_to_deploy_DW.SigmaX[idxAjj] *= ssq;
        }
      }

      k++;
    } else {
      Ready_to_deploy_DW.SigmaX[idxAjj] = ssq;
      b_idx = k + 1;
      exitg1 = true;
    }
  }

  if (b_idx == 0) {
    b_idx = 4;
  }

  b_idx--;
  for (k = 1; k < b_idx; k++) {
    for (idxAjj = 0; idxAjj < k; idxAjj++) {
      Ready_to_deploy_DW.SigmaX[idxAjj + 3 * k] = 0.0;
    }
  }

  Ready_to_deploy_blkdiag(Ready_to_deploy_DW.SigmaX, g, sigmaXa);
  tmp[0] = Ready_to_deploy_DW.xhat[0];
  tmp[1] = Ready_to_deploy_DW.xhat[1];
  tmp[2] = Ready_to_deploy_DW.xhat[2];
  tmp[3] = 0.0;
  tmp[4] = 0.0;
  for (b_idx = 0; b_idx < 5; b_idx++) {
    Ready_to_deploy_B.dv1[b_idx] = 0.0;
  }

  for (b_idx = 0; b_idx < 25; b_idx++) {
    Ready_to_deploy_B.dv1[b_idx + 5] = 1.7320508075688772 * sigmaXa[b_idx];
    Ready_to_deploy_B.dv1[b_idx + 30] = 1.7320508075688772 * -sigmaXa[b_idx];
  }

  for (b_idx = 0; b_idx < 11; b_idx++) {
    for (k = 0; k < 5; k++) {
      idxAjj = 5 * b_idx + k;
      Ready_to_deploy_B.Xa[idxAjj] = Ready_to_deploy_B.dv1[idxAjj] + tmp[k];
    }

    Ready_to_deploy_B.Xs[3 * b_idx] = Ready_to_deploy_B.Xa[5 * b_idx];
    Ready_to_deploy_B.Xs[3 * b_idx + 1] = Ready_to_deploy_B.Xa[5 * b_idx + 1];
    Ready_to_deploy_B.Xs[3 * b_idx + 2] = Ready_to_deploy_B.Xa[5 * b_idx + 2];
    Xa[b_idx] = Ready_to_deploy_B.Xa[5 * b_idx + 3];
  }

  Ready_to_deploy_stateEqn(&RC, &G, &Q, &deltat, &zkInd, &irkInd, &hkInd,
    Ready_to_deploy_B.Xs, Ready_to_deploy_DW.priorI, Xa,
    Ready_to_deploy_P.parameter.RC, Ready_to_deploy_P.parameter.G,
    Ready_to_deploy_P.parameter.Q, Ready_to_deploy_P.parameter.zkInd,
    Ready_to_deploy_P.parameter.irkInd, Ready_to_deploy_P.parameter.hkInd,
    Ready_to_deploy_B.Xx);
  for (b_idx = 0; b_idx < 3; b_idx++) {
    Ready_to_deploy_DW.xhat[b_idx] = 0.0;
    for (k = 0; k < 11; k++) {
      Ready_to_deploy_DW.xhat[b_idx] += Ready_to_deploy_B.Xx[3 * k + b_idx] *
        b_b[k];
    }
  }

  for (b_idx = 0; b_idx < 11; b_idx++) {
    Ready_to_deploy_B.Xs[3 * b_idx] = Ready_to_deploy_B.Xx[3 * b_idx] -
      Ready_to_deploy_DW.xhat[0];
    k = 3 * b_idx + 1;
    Ready_to_deploy_B.Xs[k] = Ready_to_deploy_B.Xx[k] - Ready_to_deploy_DW.xhat
      [1];
    k = 3 * b_idx + 2;
    Ready_to_deploy_B.Xs[k] = Ready_to_deploy_B.Xx[k] - Ready_to_deploy_DW.xhat
      [2];
    Xa[b_idx] = Ready_to_deploy_B.Xa[5 * b_idx + 4];
  }

  Ready_to_deploy_outputEqn(&Ready_to_deploy_B.soc, &Ready_to_deploy_B.ocv, &R0,
    &R, &M0, &M, &zkInd, &irkInd, &hkInd, Ready_to_deploy_B.Xx,
    Ready_to_deploy_DW.TmpRTBAtUnscentedKalmanFilter_o, Xa,
    Ready_to_deploy_DW.signIk, &Ready_to_deploy_B.parameter, Y);
  ytelda = 0.0;
  for (b_idx = 0; b_idx < 11; b_idx++) {
    ytelda += Y[b_idx] * b_b[b_idx];
  }

  for (b_idx = 0; b_idx < 11; b_idx++) {
    Y[b_idx] -= ytelda;
  }

  ssq = 0.0;
  for (b_idx = 0; b_idx < 11; b_idx++) {
    Xa[b_idx] = 0.0;
    for (k = 0; k < 11; k++) {
      Xa[b_idx] += c_b[11 * b_idx + k] * Y[k];
    }

    ssq += Xa[b_idx] * Y[b_idx];
  }

  ytelda = Ready_to_deploy_DW.TmpRTBAtUnscentedKalmanFilterIn - ytelda;
  for (b_idx = 0; b_idx < 3; b_idx++) {
    L_1 = 0.0;
    for (k = 0; k < 11; k++) {
      idxAjj = b_idx + 3 * k;
      Ready_to_deploy_B.Xx[idxAjj] = 0.0;
      for (b_ix = 0; b_ix < 11; b_ix++) {
        Ready_to_deploy_B.Xx[idxAjj] += Ready_to_deploy_B.Xs[3 * b_ix + b_idx] *
          c_b[11 * k + b_ix];
      }

      L_1 += Ready_to_deploy_B.Xx[idxAjj] * Y[k];
    }

    L_1 /= ssq;
    Ready_to_deploy_DW.xhat[b_idx] += L_1 * ytelda;
    for (k = 0; k < 3; k++) {
      idxAjj = b_idx + 3 * k;
      Xx[idxAjj] = 0.0;
      for (b_ix = 0; b_ix < 11; b_ix++) {
        Xx[idxAjj] += Ready_to_deploy_B.Xx[3 * b_ix + b_idx] *
          Ready_to_deploy_B.Xs[3 * b_ix + k];
      }
    }

    L[b_idx] = L_1;
  }

  b_idx = (int16_T)hkInd.contents - 1;
  if ((-0.99 > Ready_to_deploy_DW.xhat[b_idx]) || rtIsNaN
      (Ready_to_deploy_DW.xhat[b_idx])) {
    ytelda = -0.99;
  } else {
    ytelda = Ready_to_deploy_DW.xhat[b_idx];
  }

  if ((0.99 < ytelda) || rtIsNaN(ytelda)) {
    Ready_to_deploy_DW.xhat[b_idx] = 0.99;
  } else {
    Ready_to_deploy_DW.xhat[b_idx] = ytelda;
  }

  for (b_idx = 0; b_idx < 3; b_idx++) {
    L_0[3 * b_idx] = L[0] * ssq * L[b_idx];
    L_0[3 * b_idx + 1] = L[1] * ssq * L[b_idx];
    L_0[3 * b_idx + 2] = L[2] * ssq * L[b_idx];
  }

  for (b_idx = 0; b_idx < 9; b_idx++) {
    Ready_to_deploy_DW.SigmaX[b_idx] = Xx[b_idx] - L_0[b_idx];
  }

  Ready_to_deploy_DW.priorI = Ready_to_deploy_DW.TmpRTBAtUnscentedKalmanFilter_o;

  /* End of MATLAB Function: '<Root>/Unscented Kalman Filter' */

  /* RateTransition generated from: '<Root>/Sum4' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  Ready_to_deploy_DW.TmpRTBAtSum4Inport2_Buffer0 =
    Ready_to_deploy_P.Constant1_Value;

  /* Constant: '<Root>/R0' */
  ssq = Ready_to_deploy_P.parameter.R0;

  /* RateTransition generated from: '<Root>/Product' */
  Ready_to_deploy_DW.TmpRTBAtProductInport1_Buffer0 = ssq;

  /* RateTransition generated from: '<S6>/Data Type Conversion' incorporates:
   *  Constant: '<S4>/Constant2'
   */
  if (Ready_to_deploy_M->Timing.RateInteraction.TID2_4) {
    Ready_to_deploy_DW.TmpRTBAtDataTypeConversionInpor =
      Ready_to_deploy_P.Constant2_Value;
  }

  /* End of RateTransition generated from: '<S6>/Data Type Conversion' */

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Ready_to_deploy_M->Timing.clockTick2++;
}

/* Model step function for TID3 */
void Ready_to_deploy_step3(void)       /* Sample time: [0.5s, 0.0s] */
{
  int32_T i;
  int32_T uyIdx;
  int32_T nSampsAtBot;
  int32_T nSamps;

  /* Buffer: '<Root>/Buffer' */
  uyIdx = 0L;
  if (Ready_to_deploy_DW.Buffer_outBufPtrIdx < 0L) {
    Ready_to_deploy_DW.Buffer_outBufPtrIdx += 1000L;
  }

  nSampsAtBot = 1000L - Ready_to_deploy_DW.Buffer_outBufPtrIdx;
  nSamps = 500L;
  if (1000L - Ready_to_deploy_DW.Buffer_outBufPtrIdx <= 500L) {
    for (i = 0L; i < 1000L - Ready_to_deploy_DW.Buffer_outBufPtrIdx; i++) {
      Ready_to_deploy_B.Buffer[i] =
        Ready_to_deploy_DW.Buffer_CircBuf[Ready_to_deploy_DW.Buffer_outBufPtrIdx
        + i];
    }

    uyIdx = 1000L - Ready_to_deploy_DW.Buffer_outBufPtrIdx;
    Ready_to_deploy_DW.Buffer_outBufPtrIdx = 0L;
    nSamps = 500L - nSampsAtBot;
  }

  for (i = 0L; i < nSamps; i++) {
    Ready_to_deploy_B.Buffer[uyIdx + i] =
      Ready_to_deploy_DW.Buffer_CircBuf[Ready_to_deploy_DW.Buffer_outBufPtrIdx +
      i];
  }

  Ready_to_deploy_DW.Buffer_outBufPtrIdx += nSamps;

  /* End of Buffer: '<Root>/Buffer' */

  /* Buffer: '<Root>/Buffer1' */
  uyIdx = 0L;
  if (Ready_to_deploy_DW.Buffer1_outBufPtrIdx < 0L) {
    Ready_to_deploy_DW.Buffer1_outBufPtrIdx += 1000L;
  }

  nSampsAtBot = 1000L - Ready_to_deploy_DW.Buffer1_outBufPtrIdx;
  nSamps = 500L;
  if (1000L - Ready_to_deploy_DW.Buffer1_outBufPtrIdx <= 500L) {
    for (i = 0L; i < 1000L - Ready_to_deploy_DW.Buffer1_outBufPtrIdx; i++) {
      Ready_to_deploy_B.Buffer1[i] =
        Ready_to_deploy_DW.Buffer1_CircBuf[Ready_to_deploy_DW.Buffer1_outBufPtrIdx
        + i];
    }

    uyIdx = 1000L - Ready_to_deploy_DW.Buffer1_outBufPtrIdx;
    Ready_to_deploy_DW.Buffer1_outBufPtrIdx = 0L;
    nSamps = 500L - nSampsAtBot;
  }

  for (i = 0L; i < nSamps; i++) {
    Ready_to_deploy_B.Buffer1[uyIdx + i] =
      Ready_to_deploy_DW.Buffer1_CircBuf[Ready_to_deploy_DW.Buffer1_outBufPtrIdx
      + i];
  }

  Ready_to_deploy_DW.Buffer1_outBufPtrIdx += nSamps;

  /* End of Buffer: '<Root>/Buffer1' */
}

/* Model step function for TID4 */
void Ready_to_deploy_step4(void)       /* Sample time: [3600.0s, 0.0s] */
{
  /* Switch: '<S6>/Switch' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion'
   *  RateTransition generated from: '<S6>/Data Type Conversion'
   *  RateTransition generated from: '<S6>/Switch'
   *  UnitDelay: '<S6>/IC=ic'
   */
  if (Ready_to_deploy_DW.TmpRTBAtDataTypeConversionInpor != 0.0) {
    Ready_to_deploy_DW.ICic_DSTATE =
      Ready_to_deploy_DW.TmpRTBAtSwitchInport1_Buffer;
  }

  /* End of Switch: '<S6>/Switch' */

  /* RateTransition generated from: '<Root>/Unscented Kalman Filter' incorporates:
   *  UnitDelay: '<S6>/IC=ic'
   */
  Ready_to_deploy_DW.TmpRTBAtUnscentedKalmanFilter_b =
    Ready_to_deploy_DW.ICic_DSTATE;
}

/* Model initialize function */
void Ready_to_deploy_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Ready_to_deploy_M, 0,
                sizeof(RT_MODEL_Ready_to_deploy_T));

  /* block I/O */
  (void) memset(((void *) &Ready_to_deploy_B), 0,
                sizeof(B_Ready_to_deploy_T));

  /* states (dwork) */
  (void) memset((void *)&Ready_to_deploy_DW, 0,
                sizeof(DW_Ready_to_deploy_T));

  {
    int16_T i;

    /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
    Ready_to_deploy_DW.clockTickCounter = 0L;

    /* Start for RateTransition generated from: '<Root>/Sample and Hold' */
    Ready_to_deploy_B.TmpRTBAtSampleandHoldInport1 =
      Ready_to_deploy_P.TmpRTBAtSampleandHoldInport1_In;

    /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator1' */
    Ready_to_deploy_DW.clockTickCounter_a = 0L;

    /* Start for RateTransition generated from: '<Root>/Sample and Hold1' */
    Ready_to_deploy_B.TmpRTBAtSampleandHold1Inport1 =
      Ready_to_deploy_P.TmpRTBAtSampleandHold1Inport1_I;

    /* Start for S-Function (c2802xadc): '<Root>/ADC' */
    if (MW_adcAInitFlag == 0) {
      InitAdcA();
      MW_adcAInitFlag = 1;
    }

    config_ADCA_SOC0 ();

    /* Start for S-Function (c2802xadc): '<Root>/ADC1' */
    if (MW_adcCInitFlag == 0) {
      InitAdcC();
      MW_adcCInitFlag = 1;
    }

    config_ADCC_SOC0 ();

    /* Start for RateTransition generated from: '<Root>/Sum4' */
    Ready_to_deploy_B.TmpRTBAtSum4Inport2 =
      Ready_to_deploy_P.TmpRTBAtSum4Inport2_InitialCond;

    /* Start for RateTransition generated from: '<Root>/Product' */
    Ready_to_deploy_B.TmpRTBAtProductInport1 =
      Ready_to_deploy_P.TmpRTBAtProductInport1_InitialC;

    /* Start for RateTransition generated from: '<Root>/Unscented Kalman Filter' */
    Ready_to_deploy_B.TmpRTBAtUnscentedKalmanFilterIn =
      Ready_to_deploy_P.TmpRTBAtUnscentedKalmanFilterIn;
    Ready_to_deploy_PrevZCX.SampleandHold_Trig_ZCE = UNINITIALIZED_ZCSIG;
    Ready_to_deploy_PrevZCX.SampleandHold1_Trig_ZCE = UNINITIALIZED_ZCSIG;

    /* InitializeConditions for RateTransition generated from: '<Root>/Sample and Hold' */
    Ready_to_deploy_DW.TmpRTBAtSampleandHoldInport1_Bu =
      Ready_to_deploy_P.TmpRTBAtSampleandHoldInport1_In;

    /* InitializeConditions for RateTransition generated from: '<Root>/Sample and Hold1' */
    Ready_to_deploy_DW.TmpRTBAtSampleandHold1Inport1_B =
      Ready_to_deploy_P.TmpRTBAtSampleandHold1Inport1_I;

    /* InitializeConditions for RateTransition generated from: '<Root>/Sum4' */
    Ready_to_deploy_DW.TmpRTBAtSum4Inport2_Buffer0 =
      Ready_to_deploy_P.TmpRTBAtSum4Inport2_InitialCond;

    /* InitializeConditions for Buffer: '<Root>/Buffer1' */
    for (i = 0; i < 1000; i++) {
      Ready_to_deploy_DW.Buffer1_CircBuf[i] = Ready_to_deploy_P.Buffer1_ic;
    }

    Ready_to_deploy_DW.Buffer1_inBufPtrIdx = 500L;
    Ready_to_deploy_DW.Buffer1_outBufPtrIdx = 0L;

    /* End of InitializeConditions for Buffer: '<Root>/Buffer1' */

    /* InitializeConditions for RateTransition generated from: '<Root>/Product' */
    Ready_to_deploy_DW.TmpRTBAtProductInport1_Buffer0 =
      Ready_to_deploy_P.TmpRTBAtProductInport1_InitialC;

    /* InitializeConditions for Buffer: '<Root>/Buffer' */
    for (i = 0; i < 1000; i++) {
      Ready_to_deploy_DW.Buffer_CircBuf[i] = Ready_to_deploy_P.Buffer_ic;
    }

    Ready_to_deploy_DW.Buffer_inBufPtrIdx = 500L;
    Ready_to_deploy_DW.Buffer_outBufPtrIdx = 0L;

    /* End of InitializeConditions for Buffer: '<Root>/Buffer' */

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay1' */
    for (i = 0; i < 9; i++) {
      Ready_to_deploy_DW.SigmaX[i] =
        Ready_to_deploy_P.UnitDelay1_InitialCondition[i];
    }

    /* End of InitializeConditions for UnitDelay: '<Root>/Unit Delay1' */

    /* InitializeConditions for RateTransition generated from: '<Root>/Unscented Kalman Filter' */
    Ready_to_deploy_DW.TmpRTBAtUnscentedKalmanFilter_b =
      Ready_to_deploy_P.TmpRTBAtUnscentedKalmanFilterIn;

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
    Ready_to_deploy_DW.xhat[0] = Ready_to_deploy_P.UnitDelay_InitialCondition[0];
    Ready_to_deploy_DW.xhat[1] = Ready_to_deploy_P.UnitDelay_InitialCondition[1];
    Ready_to_deploy_DW.xhat[2] = Ready_to_deploy_P.UnitDelay_InitialCondition[2];

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay2' */
    Ready_to_deploy_DW.priorI = Ready_to_deploy_P.UnitDelay2_InitialCondition;

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay3' */
    Ready_to_deploy_DW.signIk = Ready_to_deploy_P.UnitDelay3_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S6>/IC=ic' */
    Ready_to_deploy_DW.ICic_DSTATE = Ready_to_deploy_P.SampleandHold_ic;

    /* SystemInitialize for Triggered SubSystem: '<Root>/Sample and Hold' */
    /* SystemInitialize for Outport: '<S1>/ ' */
    Ready_to_deploy_B.In_i = Ready_to_deploy_P._Y0;

    /* End of SystemInitialize for SubSystem: '<Root>/Sample and Hold' */

    /* SystemInitialize for Triggered SubSystem: '<Root>/Sample and Hold1' */
    /* SystemInitialize for Outport: '<S2>/ ' */
    Ready_to_deploy_B.In = Ready_to_deploy_P._Y0_p;

    /* End of SystemInitialize for SubSystem: '<Root>/Sample and Hold1' */

    /* ConstCode for S-Function (memorycopy): '<Root>/Memory Copy' */
    {
      int_T i;
      real_T *memindsrc = (real_T *) (&Ready_to_deploy_B.Buffer[0]);
      real_T *meminddst = (real_T *) (8192U);
      for (i=0; i<500U; i++)
        *(real_T *) (meminddst++) = *(real_T *) (memindsrc++);
    }

    /* ConstCode for S-Function (memorycopy): '<Root>/Memory Copy1' */
    {
      int_T i;
      real_T *memindsrc = (real_T *) (&Ready_to_deploy_B.Buffer1[0]);
      real_T *meminddst = (real_T *) (8192U);
      for (i=0; i<500U; i++)
        *(real_T *) (meminddst++) = *(real_T *) (memindsrc++);
    }
  }
}

/* Model terminate function */
void Ready_to_deploy_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
