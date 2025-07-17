#include "sample/Dialect/sampledialect.h"

using namespace mlir;
using namespace mlir::sample;

sampledialect::sampledialect(MLIRContext *context)
    : Dialect(getDialectNamespace(), context, TypeID::get<sampledialect>()) {
  addOperations<
      SampleWriteOp
  >();
}
