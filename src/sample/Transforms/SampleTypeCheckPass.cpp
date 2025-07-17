#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/IR/PatternMatch.h"
#include "mlir/Pass/Pass.h"
#include "sample/Dialect/sampledialect.h"
#include "sample/Transforms/Passes.h"

using namespace mlir;

namespace mlir::sample {

#define GEN_PASS_DEF_SAMPLETYPECHECK
#include "sample/Transforms/Passes.h.inc"

namespace {
class SampleTypeCheck : public impl::SampleTypeCheckBase<SampleTypeCheck> {
public:
  void runOnOperation() override;
};
} // namespace

static bool isValidArgType(Type argType) { return argType.isInteger(8); }

void SampleTypeCheck::runOnOperation() {
  ModuleOp module = dyn_cast<ModuleOp>(getOperation());
  llvm::outs() << module.getSymName() << "\n";
  // bool hasError = false;

  // for (func::FuncOp funcOp : module.getOps<func::FuncOp>()) {
  //   for (BlockArgument arg : funcOp.getArguments()) {
  //     if (!isValidArgType(arg.getType())) {
  //       funcOp.emitError() << "Invalid argument type: " << arg.getType()
  //                          << ". Expected i8.";
  //       hasError = true;
  //     }
  //   }
  // }

  // if (hasError) {
  //   signalPassFailure();
IRRewriter rewriter(module.getContext());
rewriter.setInsertionPointToStart(module.getBody());
func::FuncOp funcOp = *module.getOps<func::FuncOp>().begin();
auto newFnName = (funcOp.getSymName() + "_outlined").str();
auto fnType = rewriter.getFunctionType({}, {});
auto newFuncOp =
    rewriter.create<func::FuncOp>(funcOp.getLoc(), newFnName, fnType);
newFuncOp.setVisibility(SymbolTable::Visibility::Private);
auto entryBlock = newFuncOp.addEntryBlock();
rewriter.setInsertionPointToStart(entryBlock);
auto i32Type = rewriter.getIntegerType(32);
auto constOp = rewriter.create<arith::ConstantOp>(
    newFuncOp.getLoc(), i32Type, rewriter.getIntegerAttr(i32Type, 10));
rewriter.create<SampleWriteOp>(newFuncOp.getLoc(), constOp);
rewriter.create<func::ReturnOp>(newFuncOp.getLoc());
}

std::unique_ptr<mlir::Pass> createSampleTypeCheckPass() {
  return std::make_unique<mlir::sample::SampleTypeCheck>();
}
} // namespace mlir::sample
