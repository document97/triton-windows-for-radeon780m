// ArmSME stub implementations for MSVC/Windows builds.
// These pass creation functions are referenced by MLIR libraries but not
// usable on x64 Windows. We provide no-op stubs returning nullptr so the
// linker resolves them without dragging in platform-specific code.

#include <memory>
#include "mlir/Pass/Pass.h"

namespace mlir {
class Pass;
} // namespace mlir

// Forward-declare the ArmSME enums defined in PassesEnums.h.inc.
namespace mlir::arm_sme {
enum class ArmStreamingMode : uint32_t;
enum class ArmZaMode : uint32_t;
struct TestTileAllocationOptions {
  bool dumpTileLiveRanges = false;
  bool preprocessOnly = false;
};
} // namespace mlir::arm_sme

// -- Conversion passes (in mlir namespace) --------------------------------

namespace mlir {

std::unique_ptr<Pass> createArithToArmSMEConversionPass() { return nullptr; }

std::unique_ptr<Pass> createConvertArmSMEToLLVMPass(bool /*dumpTileLiveRanges*/) {
  return nullptr;
}

std::unique_ptr<Pass> createConvertArmSMEToSCFPass() { return nullptr; }

std::unique_ptr<Pass> createConvertVectorToArmSMEPass() { return nullptr; }

} // namespace mlir

// -- Transform passes (in mlir::arm_sme namespace) ------------------------

namespace mlir::arm_sme {

std::unique_ptr<mlir::Pass> createEnableArmStreamingPass(
    ArmStreamingMode /*mode*/, ArmZaMode /*zaMode*/,
    bool /*ifRequiredByOps*/, bool /*ifContainsScalableVectors*/) {
  return nullptr;
}

std::unique_ptr<mlir::Pass> createOuterProductFusionPass() { return nullptr; }

std::unique_ptr<mlir::Pass> createVectorLegalizationPass() { return nullptr; }

std::unique_ptr<mlir::Pass> createTestTileAllocation() { return nullptr; }

std::unique_ptr<mlir::Pass> createTestTileAllocation(TestTileAllocationOptions /*options*/) {
  return nullptr;
}

} // namespace mlir::arm_sme
