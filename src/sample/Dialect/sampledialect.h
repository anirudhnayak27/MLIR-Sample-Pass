#ifndef _SAMPLEDIALECT_H_
#define _SAMPLEDIALECT_H_

#include "mlir/Dialect/Tosa/IR/TosaOps.h"
#include "mlir/IR/Dialect.h"
#include "mlir/IR/IRMapping.h"
#include "mlir/Interfaces/CallInterfaces.h"
#include "mlir/Interfaces/CastInterfaces.h"
#include "mlir/Interfaces/FunctionInterfaces.h"
#include "mlir/Interfaces/SideEffectInterfaces.h"

#include "sample/Dialect/sampledialect.h.inc"

#define GET_OP_CLASSES
#include "sample/Dialect/sampleOps.h.inc"

#endif // _SAMPLEDIALECT_H_
