
include "mlir/IR/OpBase.td"
include "mlir/IR/DialectBase.td"
include "mlir/Interfaces/InferTypeOpInterface.td"
include "mlir/Interfaces/SideEffectInterfaces.td"
include "mlir/Pass/PassBase.td"
include "mlir/IR/AttrTypeBase.td"

def sample_dialect : Dialect {
    let name = "sample";
    let cppNamespace = "::mlir::sample";
}