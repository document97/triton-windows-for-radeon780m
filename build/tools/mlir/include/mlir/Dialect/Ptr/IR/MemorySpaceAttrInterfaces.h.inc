/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Interface Declarations                                                     *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
namespace ptr {
class MemorySpaceAttrInterface;
namespace detail {
struct MemorySpaceAttrInterfaceInterfaceTraits {
  struct Concept {
    /// The methods defined by the interface.
    ::mlir::LogicalResult (*isValidLoad)(const Concept *impl, ::mlir::Attribute , ::mlir::Type, ::mlir::ptr::AtomicOrdering, ::mlir::IntegerAttr, ::llvm::function_ref<::mlir::InFlightDiagnostic()>);
    ::mlir::LogicalResult (*isValidStore)(const Concept *impl, ::mlir::Attribute , ::mlir::Type, ::mlir::ptr::AtomicOrdering, ::mlir::IntegerAttr, ::llvm::function_ref<::mlir::InFlightDiagnostic()>);
    ::mlir::LogicalResult (*isValidAtomicOp)(const Concept *impl, ::mlir::Attribute , ::mlir::ptr::AtomicBinOp, ::mlir::Type, ::mlir::ptr::AtomicOrdering, ::mlir::IntegerAttr, ::llvm::function_ref<::mlir::InFlightDiagnostic()>);
    ::mlir::LogicalResult (*isValidAtomicXchg)(const Concept *impl, ::mlir::Attribute , ::mlir::Type, ::mlir::ptr::AtomicOrdering, ::mlir::ptr::AtomicOrdering, ::mlir::IntegerAttr, ::llvm::function_ref<::mlir::InFlightDiagnostic()>);
    ::mlir::LogicalResult (*isValidAddrSpaceCast)(const Concept *impl, ::mlir::Attribute , ::mlir::Type, ::mlir::Type, ::llvm::function_ref<::mlir::InFlightDiagnostic()>);
    ::mlir::LogicalResult (*isValidPtrIntCast)(const Concept *impl, ::mlir::Attribute , ::mlir::Type, ::mlir::Type, ::llvm::function_ref<::mlir::InFlightDiagnostic()>);
  };
  template<typename ConcreteAttr>
  class Model : public Concept {
  public:
    using Interface = ::mlir::ptr::MemorySpaceAttrInterface;
    Model() : Concept{isValidLoad, isValidStore, isValidAtomicOp, isValidAtomicXchg, isValidAddrSpaceCast, isValidPtrIntCast} {}

    static inline ::mlir::LogicalResult isValidLoad(const Concept *impl, ::mlir::Attribute tablegen_opaque_val, ::mlir::Type type, ::mlir::ptr::AtomicOrdering ordering, ::mlir::IntegerAttr alignment, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
    static inline ::mlir::LogicalResult isValidStore(const Concept *impl, ::mlir::Attribute tablegen_opaque_val, ::mlir::Type type, ::mlir::ptr::AtomicOrdering ordering, ::mlir::IntegerAttr alignment, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
    static inline ::mlir::LogicalResult isValidAtomicOp(const Concept *impl, ::mlir::Attribute tablegen_opaque_val, ::mlir::ptr::AtomicBinOp op, ::mlir::Type type, ::mlir::ptr::AtomicOrdering ordering, ::mlir::IntegerAttr alignment, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
    static inline ::mlir::LogicalResult isValidAtomicXchg(const Concept *impl, ::mlir::Attribute tablegen_opaque_val, ::mlir::Type type, ::mlir::ptr::AtomicOrdering successOrdering, ::mlir::ptr::AtomicOrdering failureOrdering, ::mlir::IntegerAttr alignment, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
    static inline ::mlir::LogicalResult isValidAddrSpaceCast(const Concept *impl, ::mlir::Attribute tablegen_opaque_val, ::mlir::Type tgt, ::mlir::Type src, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
    static inline ::mlir::LogicalResult isValidPtrIntCast(const Concept *impl, ::mlir::Attribute tablegen_opaque_val, ::mlir::Type intLikeTy, ::mlir::Type ptrLikeTy, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  };
  template<typename ConcreteAttr>
  class FallbackModel : public Concept {
  public:
    using Interface = ::mlir::ptr::MemorySpaceAttrInterface;
    FallbackModel() : Concept{isValidLoad, isValidStore, isValidAtomicOp, isValidAtomicXchg, isValidAddrSpaceCast, isValidPtrIntCast} {}

    static inline ::mlir::LogicalResult isValidLoad(const Concept *impl, ::mlir::Attribute tablegen_opaque_val, ::mlir::Type type, ::mlir::ptr::AtomicOrdering ordering, ::mlir::IntegerAttr alignment, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
    static inline ::mlir::LogicalResult isValidStore(const Concept *impl, ::mlir::Attribute tablegen_opaque_val, ::mlir::Type type, ::mlir::ptr::AtomicOrdering ordering, ::mlir::IntegerAttr alignment, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
    static inline ::mlir::LogicalResult isValidAtomicOp(const Concept *impl, ::mlir::Attribute tablegen_opaque_val, ::mlir::ptr::AtomicBinOp op, ::mlir::Type type, ::mlir::ptr::AtomicOrdering ordering, ::mlir::IntegerAttr alignment, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
    static inline ::mlir::LogicalResult isValidAtomicXchg(const Concept *impl, ::mlir::Attribute tablegen_opaque_val, ::mlir::Type type, ::mlir::ptr::AtomicOrdering successOrdering, ::mlir::ptr::AtomicOrdering failureOrdering, ::mlir::IntegerAttr alignment, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
    static inline ::mlir::LogicalResult isValidAddrSpaceCast(const Concept *impl, ::mlir::Attribute tablegen_opaque_val, ::mlir::Type tgt, ::mlir::Type src, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
    static inline ::mlir::LogicalResult isValidPtrIntCast(const Concept *impl, ::mlir::Attribute tablegen_opaque_val, ::mlir::Type intLikeTy, ::mlir::Type ptrLikeTy, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  };
  template<typename ConcreteModel, typename ConcreteAttr>
  class ExternalModel : public FallbackModel<ConcreteModel> {
  public:
    using ConcreteEntity = ConcreteAttr;
  };
};
template <typename ConcreteAttr>
struct MemorySpaceAttrInterfaceTrait;

} // namespace detail
class MemorySpaceAttrInterface : public ::mlir::AttributeInterface<MemorySpaceAttrInterface, detail::MemorySpaceAttrInterfaceInterfaceTraits> {
public:
  using ::mlir::AttributeInterface<MemorySpaceAttrInterface, detail::MemorySpaceAttrInterfaceInterfaceTraits>::AttributeInterface;
  template <typename ConcreteAttr>
  struct Trait : public detail::MemorySpaceAttrInterfaceTrait<ConcreteAttr> {};

  /// This method checks if it's valid to load a value from the memory space
  /// with a specific type, alignment, and atomic ordering.
  /// If `emitError` is non-null then the method is allowed to emit errors.
  ::mlir::LogicalResult isValidLoad(::mlir::Type type, ::mlir::ptr::AtomicOrdering ordering, ::mlir::IntegerAttr alignment, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) const;

  /// This method checks if it's valid to store a value in the memory space
  /// with a specific type, alignment, and atomic ordering.
  /// If `emitError` is non-null then the method is allowed to emit errors.
  ::mlir::LogicalResult isValidStore(::mlir::Type type, ::mlir::ptr::AtomicOrdering ordering, ::mlir::IntegerAttr alignment, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) const;

  /// This method checks if it's valid to perform an atomic operation in the
  /// memory space with a specific type, alignment, and atomic ordering.
  /// If `emitError` is non-null then the method is allowed to emit errors.
  ::mlir::LogicalResult isValidAtomicOp(::mlir::ptr::AtomicBinOp op, ::mlir::Type type, ::mlir::ptr::AtomicOrdering ordering, ::mlir::IntegerAttr alignment, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) const;

  /// This method checks if it's valid to perform an atomic exchange operation
  /// in the memory space with a specific type, alignment, and atomic
  /// orderings.
  /// If `emitError` is non-null then the method is allowed to emit errors.
  ::mlir::LogicalResult isValidAtomicXchg(::mlir::Type type, ::mlir::ptr::AtomicOrdering successOrdering, ::mlir::ptr::AtomicOrdering failureOrdering, ::mlir::IntegerAttr alignment, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) const;

  /// This method checks if it's valid to perform an `addrspacecast` op
  /// in the memory space.
  /// If `emitError` is non-null then the method is allowed to emit errors.
  ::mlir::LogicalResult isValidAddrSpaceCast(::mlir::Type tgt, ::mlir::Type src, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) const;

  /// This method checks if it's valid to perform a `ptrtoint` or `inttoptr`
  /// op in the memory space.
  /// The first type is expected to be integer-like, while the second must be a
  /// ptr-like type.
  /// If `emitError` is non-null then the method is allowed to emit errors.
  ::mlir::LogicalResult isValidPtrIntCast(::mlir::Type intLikeTy, ::mlir::Type ptrLikeTy, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) const;
};
namespace detail {
  template <typename ConcreteAttr>
  struct MemorySpaceAttrInterfaceTrait : public ::mlir::AttributeInterface<MemorySpaceAttrInterface, detail::MemorySpaceAttrInterfaceInterfaceTraits>::Trait<ConcreteAttr> {
  };
}// namespace detail
} // namespace ptr
} // namespace mlir
namespace mlir {
namespace ptr {
template<typename ConcreteAttr>
::mlir::LogicalResult detail::MemorySpaceAttrInterfaceInterfaceTraits::Model<ConcreteAttr>::isValidLoad(const Concept *impl, ::mlir::Attribute tablegen_opaque_val, ::mlir::Type type, ::mlir::ptr::AtomicOrdering ordering, ::mlir::IntegerAttr alignment, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  return (::llvm::cast<ConcreteAttr>(tablegen_opaque_val)).isValidLoad(type, ordering, alignment, emitError);
}
template<typename ConcreteAttr>
::mlir::LogicalResult detail::MemorySpaceAttrInterfaceInterfaceTraits::Model<ConcreteAttr>::isValidStore(const Concept *impl, ::mlir::Attribute tablegen_opaque_val, ::mlir::Type type, ::mlir::ptr::AtomicOrdering ordering, ::mlir::IntegerAttr alignment, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  return (::llvm::cast<ConcreteAttr>(tablegen_opaque_val)).isValidStore(type, ordering, alignment, emitError);
}
template<typename ConcreteAttr>
::mlir::LogicalResult detail::MemorySpaceAttrInterfaceInterfaceTraits::Model<ConcreteAttr>::isValidAtomicOp(const Concept *impl, ::mlir::Attribute tablegen_opaque_val, ::mlir::ptr::AtomicBinOp op, ::mlir::Type type, ::mlir::ptr::AtomicOrdering ordering, ::mlir::IntegerAttr alignment, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  return (::llvm::cast<ConcreteAttr>(tablegen_opaque_val)).isValidAtomicOp(op, type, ordering, alignment, emitError);
}
template<typename ConcreteAttr>
::mlir::LogicalResult detail::MemorySpaceAttrInterfaceInterfaceTraits::Model<ConcreteAttr>::isValidAtomicXchg(const Concept *impl, ::mlir::Attribute tablegen_opaque_val, ::mlir::Type type, ::mlir::ptr::AtomicOrdering successOrdering, ::mlir::ptr::AtomicOrdering failureOrdering, ::mlir::IntegerAttr alignment, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  return (::llvm::cast<ConcreteAttr>(tablegen_opaque_val)).isValidAtomicXchg(type, successOrdering, failureOrdering, alignment, emitError);
}
template<typename ConcreteAttr>
::mlir::LogicalResult detail::MemorySpaceAttrInterfaceInterfaceTraits::Model<ConcreteAttr>::isValidAddrSpaceCast(const Concept *impl, ::mlir::Attribute tablegen_opaque_val, ::mlir::Type tgt, ::mlir::Type src, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  return (::llvm::cast<ConcreteAttr>(tablegen_opaque_val)).isValidAddrSpaceCast(tgt, src, emitError);
}
template<typename ConcreteAttr>
::mlir::LogicalResult detail::MemorySpaceAttrInterfaceInterfaceTraits::Model<ConcreteAttr>::isValidPtrIntCast(const Concept *impl, ::mlir::Attribute tablegen_opaque_val, ::mlir::Type intLikeTy, ::mlir::Type ptrLikeTy, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  return (::llvm::cast<ConcreteAttr>(tablegen_opaque_val)).isValidPtrIntCast(intLikeTy, ptrLikeTy, emitError);
}
template<typename ConcreteAttr>
::mlir::LogicalResult detail::MemorySpaceAttrInterfaceInterfaceTraits::FallbackModel<ConcreteAttr>::isValidLoad(const Concept *impl, ::mlir::Attribute tablegen_opaque_val, ::mlir::Type type, ::mlir::ptr::AtomicOrdering ordering, ::mlir::IntegerAttr alignment, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  return static_cast<const ConcreteAttr *>(impl)->isValidLoad(tablegen_opaque_val, type, ordering, alignment, emitError);
}
template<typename ConcreteAttr>
::mlir::LogicalResult detail::MemorySpaceAttrInterfaceInterfaceTraits::FallbackModel<ConcreteAttr>::isValidStore(const Concept *impl, ::mlir::Attribute tablegen_opaque_val, ::mlir::Type type, ::mlir::ptr::AtomicOrdering ordering, ::mlir::IntegerAttr alignment, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  return static_cast<const ConcreteAttr *>(impl)->isValidStore(tablegen_opaque_val, type, ordering, alignment, emitError);
}
template<typename ConcreteAttr>
::mlir::LogicalResult detail::MemorySpaceAttrInterfaceInterfaceTraits::FallbackModel<ConcreteAttr>::isValidAtomicOp(const Concept *impl, ::mlir::Attribute tablegen_opaque_val, ::mlir::ptr::AtomicBinOp op, ::mlir::Type type, ::mlir::ptr::AtomicOrdering ordering, ::mlir::IntegerAttr alignment, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  return static_cast<const ConcreteAttr *>(impl)->isValidAtomicOp(tablegen_opaque_val, op, type, ordering, alignment, emitError);
}
template<typename ConcreteAttr>
::mlir::LogicalResult detail::MemorySpaceAttrInterfaceInterfaceTraits::FallbackModel<ConcreteAttr>::isValidAtomicXchg(const Concept *impl, ::mlir::Attribute tablegen_opaque_val, ::mlir::Type type, ::mlir::ptr::AtomicOrdering successOrdering, ::mlir::ptr::AtomicOrdering failureOrdering, ::mlir::IntegerAttr alignment, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  return static_cast<const ConcreteAttr *>(impl)->isValidAtomicXchg(tablegen_opaque_val, type, successOrdering, failureOrdering, alignment, emitError);
}
template<typename ConcreteAttr>
::mlir::LogicalResult detail::MemorySpaceAttrInterfaceInterfaceTraits::FallbackModel<ConcreteAttr>::isValidAddrSpaceCast(const Concept *impl, ::mlir::Attribute tablegen_opaque_val, ::mlir::Type tgt, ::mlir::Type src, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  return static_cast<const ConcreteAttr *>(impl)->isValidAddrSpaceCast(tablegen_opaque_val, tgt, src, emitError);
}
template<typename ConcreteAttr>
::mlir::LogicalResult detail::MemorySpaceAttrInterfaceInterfaceTraits::FallbackModel<ConcreteAttr>::isValidPtrIntCast(const Concept *impl, ::mlir::Attribute tablegen_opaque_val, ::mlir::Type intLikeTy, ::mlir::Type ptrLikeTy, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  return static_cast<const ConcreteAttr *>(impl)->isValidPtrIntCast(tablegen_opaque_val, intLikeTy, ptrLikeTy, emitError);
}
} // namespace ptr
} // namespace mlir
