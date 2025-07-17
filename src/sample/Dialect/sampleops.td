include "mlir/IR/OpBase.td"
include "mlir/Interfaces/CallInterfaces.td"
include "mlir/Interfaces/SideEffectInterfaces.td"
include "mlir/Interfaces/InferTypeOpInterface.td"
include "sample/Dialect/sampledialect.td"

class sample_dialect_op<string mnemonic, list<Trait> traits = []> :
    Op<sample_dialect, mnemonic, traits>;

def SampleWriteOp : sample_dialect_op<"write",
    []> {
  let arguments = (ins I32:$val);
  let assemblyFormat = "$val attr-dict `:` type($val)";
}
