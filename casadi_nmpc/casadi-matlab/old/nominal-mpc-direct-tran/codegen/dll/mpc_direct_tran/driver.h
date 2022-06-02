//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: driver.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 08-Jul-2020 19:43:17
//
#ifndef DRIVER_H
#define DRIVER_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "mpc_direct_tran_types.h"

// Function Declarations
extern void driver(const coder::array<double, 2U> &H, const coder::array<double,
                   1U> &f, b_struct_T *solution, c_struct_T *memspace,
                   g_struct_T *workingset, e_struct_T *qrmanager, f_struct_T
                   *cholmanager, d_struct_T *objective, struct_T runTimeOptions);

#endif

//
// File trailer for driver.h
//
// [EOF]
//