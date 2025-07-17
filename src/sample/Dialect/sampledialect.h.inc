/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Dialect Declarations                                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: sampledialect.td                                                     *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
namespace sample {

class sampledialect : public ::mlir::Dialect {
  explicit sampledialect(::mlir::MLIRContext *context);

  void initialize();
  friend class ::mlir::MLIRContext;
public:
  ~sampledialect() override;
  static constexpr ::llvm::StringLiteral getDialectNamespace() {
    return ::llvm::StringLiteral("sample");
  }
};
} // namespace sample
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::sample::sampledialect)
