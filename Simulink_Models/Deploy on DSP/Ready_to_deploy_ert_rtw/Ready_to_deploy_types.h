/*
 * File: Ready_to_deploy_types.h
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

#ifndef RTW_HEADER_Ready_to_deploy_types_h_
#define RTW_HEADER_Ready_to_deploy_types_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_parameter_bus_
#define DEFINED_TYPEDEF_FOR_parameter_bus_

typedef struct {
  real_T R0;
  real_T R;
  real_T RC;
  real_T M0;
  real_T M;
  real_T G;
  real_T Q;
  real_T deltat;
  real_T zkInd;
  real_T irkInd;
  real_T hkInd;
  real_T soc[602];
  real_T ocv[602];
} parameter_bus;

#endif

/* Custom Type definition for MATLAB Function: '<Root>/Unscented Kalman Filter' */
#ifndef struct_tag_93jCuAwinqpEBOkXbG4uRG
#define struct_tag_93jCuAwinqpEBOkXbG4uRG

struct tag_93jCuAwinqpEBOkXbG4uRG
{
  real_T contents;
};

#endif                                 /*struct_tag_93jCuAwinqpEBOkXbG4uRG*/

#ifndef typedef_coder_internal_ref_Ready_to_d_T
#define typedef_coder_internal_ref_Ready_to_d_T

typedef struct tag_93jCuAwinqpEBOkXbG4uRG coder_internal_ref_Ready_to_d_T;

#endif                               /*typedef_coder_internal_ref_Ready_to_d_T*/

#ifndef struct_tag_87Xpyfmxfaiw8RutKo46OB
#define struct_tag_87Xpyfmxfaiw8RutKo46OB

struct tag_87Xpyfmxfaiw8RutKo46OB
{
  real_T contents[602];
};

#endif                                 /*struct_tag_87Xpyfmxfaiw8RutKo46OB*/

#ifndef typedef_coder_internal_ref_1_Ready_to_T
#define typedef_coder_internal_ref_1_Ready_to_T

typedef struct tag_87Xpyfmxfaiw8RutKo46OB coder_internal_ref_1_Ready_to_T;

#endif                               /*typedef_coder_internal_ref_1_Ready_to_T*/

/* Parameters (default storage) */
typedef struct P_Ready_to_deploy_T_ P_Ready_to_deploy_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Ready_to_deploy_T RT_MODEL_Ready_to_deploy_T;

#endif                                 /* RTW_HEADER_Ready_to_deploy_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
