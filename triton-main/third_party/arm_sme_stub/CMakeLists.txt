# ArmSME stub library for MSVC/Windows builds
# The ArmSME MLIR dialect targets ARM/NEON/SVE and is not supported on x64 Windows.
# Some MLIR libraries reference ArmSME pass creation functions; this stub satisfies
# those link-time dependencies with no-op implementations.

add_library(ArmSMEStub STATIC ArmSMEStub.cpp)
target_link_libraries(ArmSMEStub PUBLIC MLIRIR MLIRPass)
