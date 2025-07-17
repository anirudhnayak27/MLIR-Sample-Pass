#include "sample/Dialect/sampledialect.h"

using namespace mlir;
using namespace mlir::sample;

MLIR_DEFINE_EXPLICIT_TYPE_ID(mlir::sample::sampledialect);

sampledialect::~sampledialect() = default;

void sampledialect::initialize() {
  addOperations<
      SampleWriteOp
  >();
}
sampledialect::sampledialect(MLIRContext *context)
    : Dialect(getDialectNamespace(), context, TypeID::get<sampledialect>()) {
  initialize();
}

#define GET_OP_CLASSES
#include "sample/Dialect/sampleOps.cpp.inc"