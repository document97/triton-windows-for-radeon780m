/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Op Declarations                                                            *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: TensorTransformOps.td                                                *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
namespace transform {
class ApplyBubbleUpExtractSlicePatternsOp;
} // namespace transform
} // namespace mlir
namespace mlir {
namespace transform {
class ApplyDecomposeTensorConcatPatternsOp;
} // namespace transform
} // namespace mlir
namespace mlir {
namespace transform {
class ApplyDropRedundantInsertSliceRankExpansionPatternsOp;
} // namespace transform
} // namespace mlir
namespace mlir {
namespace transform {
class ApplyFoldTensorEmptyPatternsOp;
} // namespace transform
} // namespace mlir
namespace mlir {
namespace transform {
class ApplyFoldTensorSubsetOpsIntoVectorTransfersPatternsOp;
} // namespace transform
} // namespace mlir
namespace mlir {
namespace transform {
class ApplyFoldTensorSubsetOpsPatternsOp;
} // namespace transform
} // namespace mlir
namespace mlir {
namespace transform {
class ApplyMergeConsecutiveInsertExtractSlicePatternsOp;
} // namespace transform
} // namespace mlir
namespace mlir {
namespace transform {
class ApplyReassociativeReshapeFoldingPatternsOp;
} // namespace transform
} // namespace mlir
namespace mlir {
namespace transform {
class ApplyRewriteTensorOpsAsConstantPatternsOp;
} // namespace transform
} // namespace mlir
namespace mlir {
namespace transform {
class MakeLoopIndependentOp;
} // namespace transform
} // namespace mlir
namespace mlir {
namespace transform {
class TypeConversionCastShapeDynamicDimsOp;
} // namespace transform
} // namespace mlir
#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES

namespace mlir {
namespace transform {

//===----------------------------------------------------------------------===//
// ::mlir::transform::ApplyBubbleUpExtractSlicePatternsOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class ApplyBubbleUpExtractSlicePatternsOpGenericAdaptorBase {
public:
  using Properties = ::mlir::EmptyProperties;
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  ApplyBubbleUpExtractSlicePatternsOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("transform.apply_patterns.tensor.bubble_up_extract_slice", odsAttrs.getContext());
  }

  ApplyBubbleUpExtractSlicePatternsOpGenericAdaptorBase(ApplyBubbleUpExtractSlicePatternsOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

};
} // namespace detail
template <typename RangeT>
class ApplyBubbleUpExtractSlicePatternsOpGenericAdaptor : public detail::ApplyBubbleUpExtractSlicePatternsOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::ApplyBubbleUpExtractSlicePatternsOpGenericAdaptorBase;
public:
  ApplyBubbleUpExtractSlicePatternsOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  ApplyBubbleUpExtractSlicePatternsOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : ApplyBubbleUpExtractSlicePatternsOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  ApplyBubbleUpExtractSlicePatternsOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : ApplyBubbleUpExtractSlicePatternsOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  ApplyBubbleUpExtractSlicePatternsOpGenericAdaptor(RangeT values, const ApplyBubbleUpExtractSlicePatternsOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = ApplyBubbleUpExtractSlicePatternsOp, typename = std::enable_if_t<std::is_same_v<LateInst, ApplyBubbleUpExtractSlicePatternsOp>>>
  ApplyBubbleUpExtractSlicePatternsOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class ApplyBubbleUpExtractSlicePatternsOpAdaptor : public ApplyBubbleUpExtractSlicePatternsOpGenericAdaptor<::mlir::ValueRange> {
public:
  using ApplyBubbleUpExtractSlicePatternsOpGenericAdaptor::ApplyBubbleUpExtractSlicePatternsOpGenericAdaptor;
  ApplyBubbleUpExtractSlicePatternsOpAdaptor(ApplyBubbleUpExtractSlicePatternsOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class ApplyBubbleUpExtractSlicePatternsOp : public ::mlir::Op<ApplyBubbleUpExtractSlicePatternsOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::ZeroOperands, ::mlir::OpTrait::OpInvariants, ::mlir::transform::PatternDescriptorOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ApplyBubbleUpExtractSlicePatternsOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = ApplyBubbleUpExtractSlicePatternsOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("transform.apply_patterns.tensor.bubble_up_extract_slice");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  static ::llvm::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs);
  static ::llvm::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  void populatePatterns(::mlir::RewritePatternSet &patterns);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
public:
};
} // namespace transform
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::transform::ApplyBubbleUpExtractSlicePatternsOp)

namespace mlir {
namespace transform {

//===----------------------------------------------------------------------===//
// ::mlir::transform::ApplyDecomposeTensorConcatPatternsOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class ApplyDecomposeTensorConcatPatternsOpGenericAdaptorBase {
public:
  using Properties = ::mlir::EmptyProperties;
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  ApplyDecomposeTensorConcatPatternsOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("transform.apply_patterns.tensor.decompose_concat", odsAttrs.getContext());
  }

  ApplyDecomposeTensorConcatPatternsOpGenericAdaptorBase(ApplyDecomposeTensorConcatPatternsOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

};
} // namespace detail
template <typename RangeT>
class ApplyDecomposeTensorConcatPatternsOpGenericAdaptor : public detail::ApplyDecomposeTensorConcatPatternsOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::ApplyDecomposeTensorConcatPatternsOpGenericAdaptorBase;
public:
  ApplyDecomposeTensorConcatPatternsOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  ApplyDecomposeTensorConcatPatternsOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : ApplyDecomposeTensorConcatPatternsOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  ApplyDecomposeTensorConcatPatternsOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : ApplyDecomposeTensorConcatPatternsOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  ApplyDecomposeTensorConcatPatternsOpGenericAdaptor(RangeT values, const ApplyDecomposeTensorConcatPatternsOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = ApplyDecomposeTensorConcatPatternsOp, typename = std::enable_if_t<std::is_same_v<LateInst, ApplyDecomposeTensorConcatPatternsOp>>>
  ApplyDecomposeTensorConcatPatternsOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class ApplyDecomposeTensorConcatPatternsOpAdaptor : public ApplyDecomposeTensorConcatPatternsOpGenericAdaptor<::mlir::ValueRange> {
public:
  using ApplyDecomposeTensorConcatPatternsOpGenericAdaptor::ApplyDecomposeTensorConcatPatternsOpGenericAdaptor;
  ApplyDecomposeTensorConcatPatternsOpAdaptor(ApplyDecomposeTensorConcatPatternsOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class ApplyDecomposeTensorConcatPatternsOp : public ::mlir::Op<ApplyDecomposeTensorConcatPatternsOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::ZeroOperands, ::mlir::OpTrait::OpInvariants, ::mlir::transform::PatternDescriptorOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ApplyDecomposeTensorConcatPatternsOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = ApplyDecomposeTensorConcatPatternsOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("transform.apply_patterns.tensor.decompose_concat");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  static ::llvm::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs);
  static ::llvm::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  void populatePatterns(::mlir::RewritePatternSet &patterns);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
public:
};
} // namespace transform
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::transform::ApplyDecomposeTensorConcatPatternsOp)

namespace mlir {
namespace transform {

//===----------------------------------------------------------------------===//
// ::mlir::transform::ApplyDropRedundantInsertSliceRankExpansionPatternsOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class ApplyDropRedundantInsertSliceRankExpansionPatternsOpGenericAdaptorBase {
public:
  using Properties = ::mlir::EmptyProperties;
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  ApplyDropRedundantInsertSliceRankExpansionPatternsOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("transform.apply_patterns.tensor.drop_redundant_insert_slice_rank_expansion", odsAttrs.getContext());
  }

  ApplyDropRedundantInsertSliceRankExpansionPatternsOpGenericAdaptorBase(ApplyDropRedundantInsertSliceRankExpansionPatternsOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

};
} // namespace detail
template <typename RangeT>
class ApplyDropRedundantInsertSliceRankExpansionPatternsOpGenericAdaptor : public detail::ApplyDropRedundantInsertSliceRankExpansionPatternsOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::ApplyDropRedundantInsertSliceRankExpansionPatternsOpGenericAdaptorBase;
public:
  ApplyDropRedundantInsertSliceRankExpansionPatternsOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  ApplyDropRedundantInsertSliceRankExpansionPatternsOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : ApplyDropRedundantInsertSliceRankExpansionPatternsOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  ApplyDropRedundantInsertSliceRankExpansionPatternsOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : ApplyDropRedundantInsertSliceRankExpansionPatternsOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  ApplyDropRedundantInsertSliceRankExpansionPatternsOpGenericAdaptor(RangeT values, const ApplyDropRedundantInsertSliceRankExpansionPatternsOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = ApplyDropRedundantInsertSliceRankExpansionPatternsOp, typename = std::enable_if_t<std::is_same_v<LateInst, ApplyDropRedundantInsertSliceRankExpansionPatternsOp>>>
  ApplyDropRedundantInsertSliceRankExpansionPatternsOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class ApplyDropRedundantInsertSliceRankExpansionPatternsOpAdaptor : public ApplyDropRedundantInsertSliceRankExpansionPatternsOpGenericAdaptor<::mlir::ValueRange> {
public:
  using ApplyDropRedundantInsertSliceRankExpansionPatternsOpGenericAdaptor::ApplyDropRedundantInsertSliceRankExpansionPatternsOpGenericAdaptor;
  ApplyDropRedundantInsertSliceRankExpansionPatternsOpAdaptor(ApplyDropRedundantInsertSliceRankExpansionPatternsOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class ApplyDropRedundantInsertSliceRankExpansionPatternsOp : public ::mlir::Op<ApplyDropRedundantInsertSliceRankExpansionPatternsOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::ZeroOperands, ::mlir::OpTrait::OpInvariants, ::mlir::transform::PatternDescriptorOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ApplyDropRedundantInsertSliceRankExpansionPatternsOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = ApplyDropRedundantInsertSliceRankExpansionPatternsOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("transform.apply_patterns.tensor.drop_redundant_insert_slice_rank_expansion");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  static ::llvm::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs);
  static ::llvm::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  void populatePatterns(::mlir::RewritePatternSet &patterns);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
public:
};
} // namespace transform
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::transform::ApplyDropRedundantInsertSliceRankExpansionPatternsOp)

namespace mlir {
namespace transform {

//===----------------------------------------------------------------------===//
// ::mlir::transform::ApplyFoldTensorEmptyPatternsOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class ApplyFoldTensorEmptyPatternsOpGenericAdaptorBase {
public:
  struct Properties {
    using fold_single_use_onlyTy = ::mlir::BoolAttr;
    fold_single_use_onlyTy fold_single_use_only;

    auto getFoldSingleUseOnly() const {
      auto &propStorage = this->fold_single_use_only;
      return ::llvm::dyn_cast_or_null<::mlir::BoolAttr>(propStorage);
    }
    void setFoldSingleUseOnly(const ::mlir::BoolAttr &propValue) {
      this->fold_single_use_only = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.fold_single_use_only == this->fold_single_use_only &&
        true;
    }
    bool operator!=(const Properties &rhs) const {
      return !(*this == rhs);
    }
  };
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  ApplyFoldTensorEmptyPatternsOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("transform.apply_patterns.tensor.fold_tensor_empty", odsAttrs.getContext());
  }

  ApplyFoldTensorEmptyPatternsOpGenericAdaptorBase(ApplyFoldTensorEmptyPatternsOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::BoolAttr getFoldSingleUseOnlyAttr();
  bool getFoldSingleUseOnly();
};
} // namespace detail
template <typename RangeT>
class ApplyFoldTensorEmptyPatternsOpGenericAdaptor : public detail::ApplyFoldTensorEmptyPatternsOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::ApplyFoldTensorEmptyPatternsOpGenericAdaptorBase;
public:
  ApplyFoldTensorEmptyPatternsOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  ApplyFoldTensorEmptyPatternsOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : ApplyFoldTensorEmptyPatternsOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  ApplyFoldTensorEmptyPatternsOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : ApplyFoldTensorEmptyPatternsOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  ApplyFoldTensorEmptyPatternsOpGenericAdaptor(RangeT values, const ApplyFoldTensorEmptyPatternsOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = ApplyFoldTensorEmptyPatternsOp, typename = std::enable_if_t<std::is_same_v<LateInst, ApplyFoldTensorEmptyPatternsOp>>>
  ApplyFoldTensorEmptyPatternsOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class ApplyFoldTensorEmptyPatternsOpAdaptor : public ApplyFoldTensorEmptyPatternsOpGenericAdaptor<::mlir::ValueRange> {
public:
  using ApplyFoldTensorEmptyPatternsOpGenericAdaptor::ApplyFoldTensorEmptyPatternsOpGenericAdaptor;
  ApplyFoldTensorEmptyPatternsOpAdaptor(ApplyFoldTensorEmptyPatternsOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class ApplyFoldTensorEmptyPatternsOp : public ::mlir::Op<ApplyFoldTensorEmptyPatternsOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::ZeroOperands, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::transform::PatternDescriptorOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ApplyFoldTensorEmptyPatternsOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = ApplyFoldTensorEmptyPatternsOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("fold_single_use_only")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getFoldSingleUseOnlyAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getFoldSingleUseOnlyAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("transform.apply_patterns.tensor.fold_tensor_empty");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  static ::llvm::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs);
  static ::llvm::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::llvm::LogicalResult readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state);
  void writeProperties(::mlir::DialectBytecodeWriter &writer);
  ::mlir::BoolAttr getFoldSingleUseOnlyAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::BoolAttr>(getProperties().fold_single_use_only);
  }

  bool getFoldSingleUseOnly();
  void setFoldSingleUseOnlyAttr(::mlir::BoolAttr attr) {
    getProperties().fold_single_use_only = attr;
  }

  void setFoldSingleUseOnly(bool attrValue);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::BoolAttr fold_single_use_only);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::BoolAttr fold_single_use_only);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, bool fold_single_use_only = false);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, bool fold_single_use_only = false);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes = {});
  static void populateDefaultProperties(::mlir::OperationName opName, Properties &properties);
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  void populatePatterns(::mlir::RewritePatternSet &patterns);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 1 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
};
} // namespace transform
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::transform::ApplyFoldTensorEmptyPatternsOp)

namespace mlir {
namespace transform {

//===----------------------------------------------------------------------===//
// ::mlir::transform::ApplyFoldTensorSubsetOpsIntoVectorTransfersPatternsOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class ApplyFoldTensorSubsetOpsIntoVectorTransfersPatternsOpGenericAdaptorBase {
public:
  using Properties = ::mlir::EmptyProperties;
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  ApplyFoldTensorSubsetOpsIntoVectorTransfersPatternsOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("transform.apply_patterns.tensor.fold_tensor_subset_ops_into_vector_transfers", odsAttrs.getContext());
  }

  ApplyFoldTensorSubsetOpsIntoVectorTransfersPatternsOpGenericAdaptorBase(ApplyFoldTensorSubsetOpsIntoVectorTransfersPatternsOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

};
} // namespace detail
template <typename RangeT>
class ApplyFoldTensorSubsetOpsIntoVectorTransfersPatternsOpGenericAdaptor : public detail::ApplyFoldTensorSubsetOpsIntoVectorTransfersPatternsOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::ApplyFoldTensorSubsetOpsIntoVectorTransfersPatternsOpGenericAdaptorBase;
public:
  ApplyFoldTensorSubsetOpsIntoVectorTransfersPatternsOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  ApplyFoldTensorSubsetOpsIntoVectorTransfersPatternsOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : ApplyFoldTensorSubsetOpsIntoVectorTransfersPatternsOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  ApplyFoldTensorSubsetOpsIntoVectorTransfersPatternsOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : ApplyFoldTensorSubsetOpsIntoVectorTransfersPatternsOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  ApplyFoldTensorSubsetOpsIntoVectorTransfersPatternsOpGenericAdaptor(RangeT values, const ApplyFoldTensorSubsetOpsIntoVectorTransfersPatternsOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = ApplyFoldTensorSubsetOpsIntoVectorTransfersPatternsOp, typename = std::enable_if_t<std::is_same_v<LateInst, ApplyFoldTensorSubsetOpsIntoVectorTransfersPatternsOp>>>
  ApplyFoldTensorSubsetOpsIntoVectorTransfersPatternsOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class ApplyFoldTensorSubsetOpsIntoVectorTransfersPatternsOpAdaptor : public ApplyFoldTensorSubsetOpsIntoVectorTransfersPatternsOpGenericAdaptor<::mlir::ValueRange> {
public:
  using ApplyFoldTensorSubsetOpsIntoVectorTransfersPatternsOpGenericAdaptor::ApplyFoldTensorSubsetOpsIntoVectorTransfersPatternsOpGenericAdaptor;
  ApplyFoldTensorSubsetOpsIntoVectorTransfersPatternsOpAdaptor(ApplyFoldTensorSubsetOpsIntoVectorTransfersPatternsOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class ApplyFoldTensorSubsetOpsIntoVectorTransfersPatternsOp : public ::mlir::Op<ApplyFoldTensorSubsetOpsIntoVectorTransfersPatternsOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::ZeroOperands, ::mlir::OpTrait::OpInvariants, ::mlir::transform::PatternDescriptorOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ApplyFoldTensorSubsetOpsIntoVectorTransfersPatternsOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = ApplyFoldTensorSubsetOpsIntoVectorTransfersPatternsOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("transform.apply_patterns.tensor.fold_tensor_subset_ops_into_vector_transfers");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  static ::llvm::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs);
  static ::llvm::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  void populatePatterns(::mlir::RewritePatternSet &patterns);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
public:
};
} // namespace transform
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::transform::ApplyFoldTensorSubsetOpsIntoVectorTransfersPatternsOp)

namespace mlir {
namespace transform {

//===----------------------------------------------------------------------===//
// ::mlir::transform::ApplyFoldTensorSubsetOpsPatternsOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class ApplyFoldTensorSubsetOpsPatternsOpGenericAdaptorBase {
public:
  using Properties = ::mlir::EmptyProperties;
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  ApplyFoldTensorSubsetOpsPatternsOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("transform.apply_patterns.tensor.fold_tensor_subset_ops", odsAttrs.getContext());
  }

  ApplyFoldTensorSubsetOpsPatternsOpGenericAdaptorBase(ApplyFoldTensorSubsetOpsPatternsOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

};
} // namespace detail
template <typename RangeT>
class ApplyFoldTensorSubsetOpsPatternsOpGenericAdaptor : public detail::ApplyFoldTensorSubsetOpsPatternsOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::ApplyFoldTensorSubsetOpsPatternsOpGenericAdaptorBase;
public:
  ApplyFoldTensorSubsetOpsPatternsOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  ApplyFoldTensorSubsetOpsPatternsOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : ApplyFoldTensorSubsetOpsPatternsOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  ApplyFoldTensorSubsetOpsPatternsOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : ApplyFoldTensorSubsetOpsPatternsOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  ApplyFoldTensorSubsetOpsPatternsOpGenericAdaptor(RangeT values, const ApplyFoldTensorSubsetOpsPatternsOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = ApplyFoldTensorSubsetOpsPatternsOp, typename = std::enable_if_t<std::is_same_v<LateInst, ApplyFoldTensorSubsetOpsPatternsOp>>>
  ApplyFoldTensorSubsetOpsPatternsOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class ApplyFoldTensorSubsetOpsPatternsOpAdaptor : public ApplyFoldTensorSubsetOpsPatternsOpGenericAdaptor<::mlir::ValueRange> {
public:
  using ApplyFoldTensorSubsetOpsPatternsOpGenericAdaptor::ApplyFoldTensorSubsetOpsPatternsOpGenericAdaptor;
  ApplyFoldTensorSubsetOpsPatternsOpAdaptor(ApplyFoldTensorSubsetOpsPatternsOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class ApplyFoldTensorSubsetOpsPatternsOp : public ::mlir::Op<ApplyFoldTensorSubsetOpsPatternsOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::ZeroOperands, ::mlir::OpTrait::OpInvariants, ::mlir::transform::PatternDescriptorOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ApplyFoldTensorSubsetOpsPatternsOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = ApplyFoldTensorSubsetOpsPatternsOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("transform.apply_patterns.tensor.fold_tensor_subset_ops");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  static ::llvm::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs);
  static ::llvm::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  void populatePatterns(::mlir::RewritePatternSet &patterns);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
public:
};
} // namespace transform
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::transform::ApplyFoldTensorSubsetOpsPatternsOp)

namespace mlir {
namespace transform {

//===----------------------------------------------------------------------===//
// ::mlir::transform::ApplyMergeConsecutiveInsertExtractSlicePatternsOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class ApplyMergeConsecutiveInsertExtractSlicePatternsOpGenericAdaptorBase {
public:
  using Properties = ::mlir::EmptyProperties;
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  ApplyMergeConsecutiveInsertExtractSlicePatternsOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("transform.apply_patterns.tensor.merge_consecutive_insert_extract_slice", odsAttrs.getContext());
  }

  ApplyMergeConsecutiveInsertExtractSlicePatternsOpGenericAdaptorBase(ApplyMergeConsecutiveInsertExtractSlicePatternsOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

};
} // namespace detail
template <typename RangeT>
class ApplyMergeConsecutiveInsertExtractSlicePatternsOpGenericAdaptor : public detail::ApplyMergeConsecutiveInsertExtractSlicePatternsOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::ApplyMergeConsecutiveInsertExtractSlicePatternsOpGenericAdaptorBase;
public:
  ApplyMergeConsecutiveInsertExtractSlicePatternsOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  ApplyMergeConsecutiveInsertExtractSlicePatternsOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : ApplyMergeConsecutiveInsertExtractSlicePatternsOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  ApplyMergeConsecutiveInsertExtractSlicePatternsOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : ApplyMergeConsecutiveInsertExtractSlicePatternsOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  ApplyMergeConsecutiveInsertExtractSlicePatternsOpGenericAdaptor(RangeT values, const ApplyMergeConsecutiveInsertExtractSlicePatternsOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = ApplyMergeConsecutiveInsertExtractSlicePatternsOp, typename = std::enable_if_t<std::is_same_v<LateInst, ApplyMergeConsecutiveInsertExtractSlicePatternsOp>>>
  ApplyMergeConsecutiveInsertExtractSlicePatternsOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class ApplyMergeConsecutiveInsertExtractSlicePatternsOpAdaptor : public ApplyMergeConsecutiveInsertExtractSlicePatternsOpGenericAdaptor<::mlir::ValueRange> {
public:
  using ApplyMergeConsecutiveInsertExtractSlicePatternsOpGenericAdaptor::ApplyMergeConsecutiveInsertExtractSlicePatternsOpGenericAdaptor;
  ApplyMergeConsecutiveInsertExtractSlicePatternsOpAdaptor(ApplyMergeConsecutiveInsertExtractSlicePatternsOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class ApplyMergeConsecutiveInsertExtractSlicePatternsOp : public ::mlir::Op<ApplyMergeConsecutiveInsertExtractSlicePatternsOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::ZeroOperands, ::mlir::OpTrait::OpInvariants, ::mlir::transform::PatternDescriptorOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ApplyMergeConsecutiveInsertExtractSlicePatternsOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = ApplyMergeConsecutiveInsertExtractSlicePatternsOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("transform.apply_patterns.tensor.merge_consecutive_insert_extract_slice");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  static ::llvm::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs);
  static ::llvm::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  void populatePatterns(::mlir::RewritePatternSet &patterns);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
public:
};
} // namespace transform
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::transform::ApplyMergeConsecutiveInsertExtractSlicePatternsOp)

namespace mlir {
namespace transform {

//===----------------------------------------------------------------------===//
// ::mlir::transform::ApplyReassociativeReshapeFoldingPatternsOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class ApplyReassociativeReshapeFoldingPatternsOpGenericAdaptorBase {
public:
  using Properties = ::mlir::EmptyProperties;
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  ApplyReassociativeReshapeFoldingPatternsOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("transform.apply_patterns.tensor.reassociative_reshape_folding", odsAttrs.getContext());
  }

  ApplyReassociativeReshapeFoldingPatternsOpGenericAdaptorBase(ApplyReassociativeReshapeFoldingPatternsOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

};
} // namespace detail
template <typename RangeT>
class ApplyReassociativeReshapeFoldingPatternsOpGenericAdaptor : public detail::ApplyReassociativeReshapeFoldingPatternsOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::ApplyReassociativeReshapeFoldingPatternsOpGenericAdaptorBase;
public:
  ApplyReassociativeReshapeFoldingPatternsOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  ApplyReassociativeReshapeFoldingPatternsOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : ApplyReassociativeReshapeFoldingPatternsOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  ApplyReassociativeReshapeFoldingPatternsOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : ApplyReassociativeReshapeFoldingPatternsOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  ApplyReassociativeReshapeFoldingPatternsOpGenericAdaptor(RangeT values, const ApplyReassociativeReshapeFoldingPatternsOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = ApplyReassociativeReshapeFoldingPatternsOp, typename = std::enable_if_t<std::is_same_v<LateInst, ApplyReassociativeReshapeFoldingPatternsOp>>>
  ApplyReassociativeReshapeFoldingPatternsOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class ApplyReassociativeReshapeFoldingPatternsOpAdaptor : public ApplyReassociativeReshapeFoldingPatternsOpGenericAdaptor<::mlir::ValueRange> {
public:
  using ApplyReassociativeReshapeFoldingPatternsOpGenericAdaptor::ApplyReassociativeReshapeFoldingPatternsOpGenericAdaptor;
  ApplyReassociativeReshapeFoldingPatternsOpAdaptor(ApplyReassociativeReshapeFoldingPatternsOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class ApplyReassociativeReshapeFoldingPatternsOp : public ::mlir::Op<ApplyReassociativeReshapeFoldingPatternsOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::ZeroOperands, ::mlir::OpTrait::OpInvariants, ::mlir::transform::PatternDescriptorOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ApplyReassociativeReshapeFoldingPatternsOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = ApplyReassociativeReshapeFoldingPatternsOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("transform.apply_patterns.tensor.reassociative_reshape_folding");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  static ::llvm::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs);
  static ::llvm::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  void populatePatterns(::mlir::RewritePatternSet &patterns);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
public:
};
} // namespace transform
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::transform::ApplyReassociativeReshapeFoldingPatternsOp)

namespace mlir {
namespace transform {

//===----------------------------------------------------------------------===//
// ::mlir::transform::ApplyRewriteTensorOpsAsConstantPatternsOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class ApplyRewriteTensorOpsAsConstantPatternsOpGenericAdaptorBase {
public:
  struct Properties {
    using aggressiveTy = ::mlir::UnitAttr;
    aggressiveTy aggressive;

    auto getAggressive() const {
      auto &propStorage = this->aggressive;
      return ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(propStorage);
    }
    void setAggressive(const ::mlir::UnitAttr &propValue) {
      this->aggressive = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.aggressive == this->aggressive &&
        true;
    }
    bool operator!=(const Properties &rhs) const {
      return !(*this == rhs);
    }
  };
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  ApplyRewriteTensorOpsAsConstantPatternsOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("transform.apply_patterns.tensor.rewrite_as_constant", odsAttrs.getContext());
  }

  ApplyRewriteTensorOpsAsConstantPatternsOpGenericAdaptorBase(ApplyRewriteTensorOpsAsConstantPatternsOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::UnitAttr getAggressiveAttr();
  bool getAggressive();
};
} // namespace detail
template <typename RangeT>
class ApplyRewriteTensorOpsAsConstantPatternsOpGenericAdaptor : public detail::ApplyRewriteTensorOpsAsConstantPatternsOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::ApplyRewriteTensorOpsAsConstantPatternsOpGenericAdaptorBase;
public:
  ApplyRewriteTensorOpsAsConstantPatternsOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  ApplyRewriteTensorOpsAsConstantPatternsOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : ApplyRewriteTensorOpsAsConstantPatternsOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  ApplyRewriteTensorOpsAsConstantPatternsOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : ApplyRewriteTensorOpsAsConstantPatternsOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  ApplyRewriteTensorOpsAsConstantPatternsOpGenericAdaptor(RangeT values, const ApplyRewriteTensorOpsAsConstantPatternsOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = ApplyRewriteTensorOpsAsConstantPatternsOp, typename = std::enable_if_t<std::is_same_v<LateInst, ApplyRewriteTensorOpsAsConstantPatternsOp>>>
  ApplyRewriteTensorOpsAsConstantPatternsOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class ApplyRewriteTensorOpsAsConstantPatternsOpAdaptor : public ApplyRewriteTensorOpsAsConstantPatternsOpGenericAdaptor<::mlir::ValueRange> {
public:
  using ApplyRewriteTensorOpsAsConstantPatternsOpGenericAdaptor::ApplyRewriteTensorOpsAsConstantPatternsOpGenericAdaptor;
  ApplyRewriteTensorOpsAsConstantPatternsOpAdaptor(ApplyRewriteTensorOpsAsConstantPatternsOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class ApplyRewriteTensorOpsAsConstantPatternsOp : public ::mlir::Op<ApplyRewriteTensorOpsAsConstantPatternsOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::ZeroOperands, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::transform::PatternDescriptorOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ApplyRewriteTensorOpsAsConstantPatternsOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = ApplyRewriteTensorOpsAsConstantPatternsOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("aggressive")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getAggressiveAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getAggressiveAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("transform.apply_patterns.tensor.rewrite_as_constant");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  static ::llvm::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs);
  static ::llvm::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::llvm::LogicalResult readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state);
  void writeProperties(::mlir::DialectBytecodeWriter &writer);
  ::mlir::UnitAttr getAggressiveAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(getProperties().aggressive);
  }

  bool getAggressive();
  void setAggressiveAttr(::mlir::UnitAttr attr) {
    getProperties().aggressive = attr;
  }

  void setAggressive(bool attrValue);
  ::mlir::Attribute removeAggressiveAttr() {
      auto attr = getProperties().aggressive;
      getProperties().aggressive = {};
      return attr;
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, /*optional*/::mlir::UnitAttr aggressive);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, /*optional*/::mlir::UnitAttr aggressive);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, /*optional*/bool aggressive = false);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, /*optional*/bool aggressive = false);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  void populatePatterns(::mlir::RewritePatternSet &patterns);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 1 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
};
} // namespace transform
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::transform::ApplyRewriteTensorOpsAsConstantPatternsOp)

namespace mlir {
namespace transform {

//===----------------------------------------------------------------------===//
// ::mlir::transform::MakeLoopIndependentOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class MakeLoopIndependentOpGenericAdaptorBase {
public:
  struct Properties {
    using num_loopsTy = ::mlir::IntegerAttr;
    num_loopsTy num_loops;

    auto getNumLoops() const {
      auto &propStorage = this->num_loops;
      return ::llvm::cast<::mlir::IntegerAttr>(propStorage);
    }
    void setNumLoops(const ::mlir::IntegerAttr &propValue) {
      this->num_loops = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.num_loops == this->num_loops &&
        true;
    }
    bool operator!=(const Properties &rhs) const {
      return !(*this == rhs);
    }
  };
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  MakeLoopIndependentOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("transform.tensor.make_loop_independent", odsAttrs.getContext());
  }

  MakeLoopIndependentOpGenericAdaptorBase(MakeLoopIndependentOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::IntegerAttr getNumLoopsAttr() {
    auto attr = ::llvm::cast<::mlir::IntegerAttr>(getProperties().num_loops);
    return attr;
  }

  uint64_t getNumLoops();
};
} // namespace detail
template <typename RangeT>
class MakeLoopIndependentOpGenericAdaptor : public detail::MakeLoopIndependentOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::MakeLoopIndependentOpGenericAdaptorBase;
public:
  MakeLoopIndependentOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  MakeLoopIndependentOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : MakeLoopIndependentOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  MakeLoopIndependentOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : MakeLoopIndependentOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  MakeLoopIndependentOpGenericAdaptor(RangeT values, const MakeLoopIndependentOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = MakeLoopIndependentOp, typename = std::enable_if_t<std::is_same_v<LateInst, MakeLoopIndependentOp>>>
  MakeLoopIndependentOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getTarget() {
    return (*getODSOperands(0).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class MakeLoopIndependentOpAdaptor : public MakeLoopIndependentOpGenericAdaptor<::mlir::ValueRange> {
public:
  using MakeLoopIndependentOpGenericAdaptor::MakeLoopIndependentOpGenericAdaptor;
  MakeLoopIndependentOpAdaptor(MakeLoopIndependentOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class MakeLoopIndependentOp : public ::mlir::Op<MakeLoopIndependentOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::transform::TransformHandleTypeInterface>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::transform::FunctionalStyleTransformOpTrait, ::mlir::MemoryEffectOpInterface::Trait, ::mlir::transform::TransformOpInterface::Trait, ::mlir::transform::TransformEachOpTrait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = MakeLoopIndependentOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = MakeLoopIndependentOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("num_loops")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getNumLoopsAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getNumLoopsAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("transform.tensor.make_loop_independent");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::transform::TransformHandleTypeInterface> getTarget() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::transform::TransformHandleTypeInterface>>(*getODSOperands(0).begin());
  }

  ::mlir::OpOperand &getTargetMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::transform::TransformHandleTypeInterface> getTransformed() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::transform::TransformHandleTypeInterface>>(*getODSResults(0).begin());
  }

  static ::llvm::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs);
  static ::llvm::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::llvm::LogicalResult readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state);
  void writeProperties(::mlir::DialectBytecodeWriter &writer);
  ::mlir::IntegerAttr getNumLoopsAttr() {
    return ::llvm::cast<::mlir::IntegerAttr>(getProperties().num_loops);
  }

  uint64_t getNumLoops();
  void setNumLoopsAttr(::mlir::IntegerAttr attr) {
    getProperties().num_loops = attr;
  }

  void setNumLoops(uint64_t attrValue);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type transformed, ::mlir::Value target, ::mlir::IntegerAttr num_loops);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value target, ::mlir::IntegerAttr num_loops);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type transformed, ::mlir::Value target, uint64_t num_loops);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value target, uint64_t num_loops);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 1 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
  ::mlir::DiagnosedSilenceableFailure applyToOne(
      ::mlir::transform::TransformRewriter &rewriter,
      ::mlir::Operation *target,
      ::mlir::transform::ApplyToEachResultList &results,
      ::mlir::transform::TransformState &state);
};
} // namespace transform
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::transform::MakeLoopIndependentOp)

namespace mlir {
namespace transform {

//===----------------------------------------------------------------------===//
// ::mlir::transform::TypeConversionCastShapeDynamicDimsOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class TypeConversionCastShapeDynamicDimsOpGenericAdaptorBase {
public:
  struct Properties {
    using ignore_dynamic_infoTy = ::mlir::UnitAttr;
    ignore_dynamic_infoTy ignore_dynamic_info;

    auto getIgnoreDynamicInfo() const {
      auto &propStorage = this->ignore_dynamic_info;
      return ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(propStorage);
    }
    void setIgnoreDynamicInfo(const ::mlir::UnitAttr &propValue) {
      this->ignore_dynamic_info = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.ignore_dynamic_info == this->ignore_dynamic_info &&
        true;
    }
    bool operator!=(const Properties &rhs) const {
      return !(*this == rhs);
    }
  };
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  TypeConversionCastShapeDynamicDimsOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("transform.type_conversion.tensor.cast_shape_dynamic_dims", odsAttrs.getContext());
  }

  TypeConversionCastShapeDynamicDimsOpGenericAdaptorBase(TypeConversionCastShapeDynamicDimsOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::UnitAttr getIgnoreDynamicInfoAttr();
  bool getIgnoreDynamicInfo();
};
} // namespace detail
template <typename RangeT>
class TypeConversionCastShapeDynamicDimsOpGenericAdaptor : public detail::TypeConversionCastShapeDynamicDimsOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::TypeConversionCastShapeDynamicDimsOpGenericAdaptorBase;
public:
  TypeConversionCastShapeDynamicDimsOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  TypeConversionCastShapeDynamicDimsOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : TypeConversionCastShapeDynamicDimsOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  TypeConversionCastShapeDynamicDimsOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : TypeConversionCastShapeDynamicDimsOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  TypeConversionCastShapeDynamicDimsOpGenericAdaptor(RangeT values, const TypeConversionCastShapeDynamicDimsOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = TypeConversionCastShapeDynamicDimsOp, typename = std::enable_if_t<std::is_same_v<LateInst, TypeConversionCastShapeDynamicDimsOp>>>
  TypeConversionCastShapeDynamicDimsOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class TypeConversionCastShapeDynamicDimsOpAdaptor : public TypeConversionCastShapeDynamicDimsOpGenericAdaptor<::mlir::ValueRange> {
public:
  using TypeConversionCastShapeDynamicDimsOpGenericAdaptor::TypeConversionCastShapeDynamicDimsOpGenericAdaptor;
  TypeConversionCastShapeDynamicDimsOpAdaptor(TypeConversionCastShapeDynamicDimsOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class TypeConversionCastShapeDynamicDimsOp : public ::mlir::Op<TypeConversionCastShapeDynamicDimsOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::ZeroOperands, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::transform::TypeConverterBuilderOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = TypeConversionCastShapeDynamicDimsOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = TypeConversionCastShapeDynamicDimsOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("ignore_dynamic_info")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getIgnoreDynamicInfoAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getIgnoreDynamicInfoAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("transform.type_conversion.tensor.cast_shape_dynamic_dims");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  static ::llvm::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs);
  static ::llvm::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::llvm::LogicalResult readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state);
  void writeProperties(::mlir::DialectBytecodeWriter &writer);
  ::mlir::UnitAttr getIgnoreDynamicInfoAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::UnitAttr>(getProperties().ignore_dynamic_info);
  }

  bool getIgnoreDynamicInfo();
  void setIgnoreDynamicInfoAttr(::mlir::UnitAttr attr) {
    getProperties().ignore_dynamic_info = attr;
  }

  void setIgnoreDynamicInfo(bool attrValue);
  ::mlir::Attribute removeIgnoreDynamicInfoAttr() {
      auto attr = getProperties().ignore_dynamic_info;
      getProperties().ignore_dynamic_info = {};
      return attr;
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, /*optional*/::mlir::UnitAttr ignore_dynamic_info);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, /*optional*/::mlir::UnitAttr ignore_dynamic_info);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, /*optional*/bool ignore_dynamic_info = false);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, /*optional*/bool ignore_dynamic_info = false);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  void populateTypeMaterializations(::mlir::TypeConverter &converter);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 1 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
};
} // namespace transform
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::transform::TypeConversionCastShapeDynamicDimsOp)


#endif  // GET_OP_CLASSES

