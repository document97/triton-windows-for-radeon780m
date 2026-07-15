/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* TypeDef Definitions                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_TYPEDEF_LIST
#undef GET_TYPEDEF_LIST

::mlir::ptr::PtrType

#endif  // GET_TYPEDEF_LIST

#ifdef GET_TYPEDEF_CLASSES
#undef GET_TYPEDEF_CLASSES

static ::mlir::OptionalParseResult generatedTypeParser(::mlir::AsmParser &parser, ::llvm::StringRef *mnemonic, ::mlir::Type &value) {
  return ::mlir::AsmParser::KeywordSwitch<::mlir::OptionalParseResult>(parser)
    .Case(::mlir::ptr::PtrType::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::ptr::PtrType::parse(parser);
      return ::mlir::success(!!value);
    })
    .Default([&](llvm::StringRef keyword, llvm::SMLoc) {
      *mnemonic = keyword;
      return std::nullopt;
    });
}

static ::llvm::LogicalResult generatedTypePrinter(::mlir::Type def, ::mlir::AsmPrinter &printer) {
  return ::llvm::TypeSwitch<::mlir::Type, ::llvm::LogicalResult>(def)    .Case<::mlir::ptr::PtrType>([&](auto t) {
      printer << ::mlir::ptr::PtrType::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Default([](auto) { return ::mlir::failure(); });
}

namespace mlir {
namespace ptr {
namespace detail {
struct PtrTypeStorage : public ::mlir::TypeStorage {
  using KeyTy = std::tuple<MemorySpaceAttrInterface>;
  PtrTypeStorage(MemorySpaceAttrInterface memorySpace) : memorySpace(std::move(memorySpace)) {}

  KeyTy getAsKey() const {
    return KeyTy(memorySpace);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (memorySpace == std::get<0>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey));
  }

  static PtrTypeStorage *construct(::mlir::TypeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto memorySpace = std::move(std::get<0>(tblgenKey));
    return new (allocator.allocate<PtrTypeStorage>()) PtrTypeStorage(std::move(memorySpace));
  }

  MemorySpaceAttrInterface memorySpace;
};
} // namespace detail
PtrType PtrType::get(::mlir::MLIRContext *context, MemorySpaceAttrInterface memorySpace) {
  return Base::get(context, std::move(memorySpace));
}

PtrType PtrType::get(MemorySpaceAttrInterface memorySpace) {
  return Base::get(memorySpace.getContext(), memorySpace);
}

::mlir::Type PtrType::parse(::mlir::AsmParser &odsParser) {
  ::mlir::Builder odsBuilder(odsParser.getContext());
  ::llvm::SMLoc odsLoc = odsParser.getCurrentLocation();
  (void) odsLoc;
  ::mlir::FailureOr<MemorySpaceAttrInterface> _result_memorySpace;
  // Parse literal '<'
  if (odsParser.parseLess()) return {};

  // Parse variable 'memorySpace'
  _result_memorySpace = ::mlir::FieldParser<MemorySpaceAttrInterface>::parse(odsParser);
  if (::mlir::failed(_result_memorySpace)) {
    odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse Ptr_PtrType parameter 'memorySpace' which is to be a `MemorySpaceAttrInterface`");
    return {};
  }
  // Parse literal '>'
  if (odsParser.parseGreater()) return {};
  assert(::mlir::succeeded(_result_memorySpace));
  return PtrType::get(odsParser.getContext(),
      MemorySpaceAttrInterface((*_result_memorySpace)));
}

void PtrType::print(::mlir::AsmPrinter &odsPrinter) const {
  ::mlir::Builder odsBuilder(getContext());
  odsPrinter << "<";
  odsPrinter.printStrippedAttrOrType(getMemorySpace());
  odsPrinter << ">";
}

MemorySpaceAttrInterface PtrType::getMemorySpace() const {
  return getImpl()->memorySpace;
}

} // namespace ptr
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::ptr::PtrType)
namespace mlir {
namespace ptr {

/// Parse a type registered to this dialect.
::mlir::Type PtrDialect::parseType(::mlir::DialectAsmParser &parser) const {
  ::llvm::SMLoc typeLoc = parser.getCurrentLocation();
  ::llvm::StringRef mnemonic;
  ::mlir::Type genType;
  auto parseResult = generatedTypeParser(parser, &mnemonic, genType);
  if (parseResult.has_value())
    return genType;
  
  parser.emitError(typeLoc) << "unknown  type `"
      << mnemonic << "` in dialect `" << getNamespace() << "`";
  return {};
}
/// Print a type registered to this dialect.
void PtrDialect::printType(::mlir::Type type,
                    ::mlir::DialectAsmPrinter &printer) const {
  if (::mlir::succeeded(generatedTypePrinter(type, printer)))
    return;
  
}
} // namespace ptr
} // namespace mlir

#endif  // GET_TYPEDEF_CLASSES

