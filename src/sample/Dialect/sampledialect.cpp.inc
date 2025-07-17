/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Dialect Definitions                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: sampledialect.td                                                     *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::sample::sampledialect)
namespace mlir {
namespace sample {

sampledialect::sampledialect(::mlir::MLIRContext *context)
    : ::mlir::Dialect(getDialectNamespace(), context, ::mlir::TypeID::get<sampledialect>())
    
     {
  
  initialize();
}

sampledialect::~sampledialect() = default;

} // namespace sample
} // namespace mlir
