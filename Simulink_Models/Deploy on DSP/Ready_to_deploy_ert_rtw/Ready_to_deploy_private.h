/*
 * File: Ready_to_deploy_private.h
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

#ifndef RTW_HEADER_Ready_to_deploy_private_h_
#define RTW_HEADER_Ready_to_deploy_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"

void InitAdcA (void);
void config_ADCA_SOC0 (void);
void InitAdcC (void);
void config_ADCC_SOC0 (void);
extern uint16_T MW_adcAInitFlag;
extern uint16_T MW_adcCInitFlag;

#endif                               /* RTW_HEADER_Ready_to_deploy_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
