//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  indexShapeCheck.h
//
//  Code generation for function 'indexShapeCheck'
//


#pragma once

// Include files
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "mex.h"
#include "emlrt.h"
#include "covrt.h"
#include "rtwtypes.h"
#include "mpc_direct_tran_types.h"

// Function Declarations
void b_indexShapeCheck(const emlrtStack *sp, int32_T matrixSize);
void indexShapeCheck(const emlrtStack *sp, int32_T matrixSize, const int32_T
                     indexSize[2]);

// End of code generation (indexShapeCheck.h)
