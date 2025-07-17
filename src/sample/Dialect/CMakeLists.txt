set(CMAKE_CURRENT_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(dialect sampledialect)
set(dialect_namespace sample)

# Dialect definition generation
set(LLVM_TARGET_DEFINITIONS sampledialect.td)
mlir_tablegen(sampledialect.h.inc -gen-dialect-decls -dialect=${dialect_namespace})
mlir_tablegen(sampledialect.cpp.inc -gen-dialect-defs -dialect=${dialect_namespace})

# Operation definition generation
set(LLVM_TARGET_DEFINITIONS sampleops.td)
mlir_tablegen(sampleOps.h.inc -gen-op-decls)
mlir_tablegen(sampleOps.cpp.inc -gen-op-defs)

add_public_tablegen_target(MLIR${dialect}IncGen)

add_mlir_dialect_library(MLIRTinyFusion
        sampledialect.cpp
        sampleOps.cpp

        PARTIAL_SOURCES_INTENDED

        DEPENDS
        MLIR${dialect}IncGen

        LINK_LIBS PUBLIC

        MLIRAnalysis
        MLIRCallInterfaces
        MLIRCastInterfaces
        MLIRExecutionEngine
        MLIRIR
        MLIRTosaDialect
        MLIRLLVMCommonConversion
        MLIRLLVMDialect
        MLIRLLVMToLLVMIRTranslation
        MLIRMemRefDialect
        MLIRParser
        MLIRPass
        MLIRSideEffectInterfaces
        MLIRSupport
        MLIRTargetLLVMIRExport
        MLIRTransforms
)
