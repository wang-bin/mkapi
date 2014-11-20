QT =

INCLUDEPATH += $$[QT_INSTALL_HEADERS]
SOURCES += mkapi.cpp
OTHER_FILES = Makefile template/capi/name_api.*

LLVM_CXXFLAGS = $$system(llvm-config --cxxflags)
LLVM_COMPONENTS = core mc mcparser support bitreader
LLVM_LIBS = $$system(llvm-config --libs $${LLVM_COMPONENTS})
LLVM_LDFLAGS=$${LLVM_LIBS} $$system(llvm-config --ldflags)
#why llvm-config --libs --ldflags xxx will link error?
#-lLLVMSupport -lLLVMMC
CLANG_LDFLAGS = \
  -lclangTooling \
  -lclangFrontendTool -lclangFrontend -lclangDriver \
  -lclangSerialization -lclangCodeGen -lclangParse \
  -lclangSema -lclangStaticAnalyzerFrontend \
  -lclangStaticAnalyzerCheckers -lclangStaticAnalyzerCore \
  -lclangAnalysis -lclangARCMigrate -lclangRewriteCore \
  -lclangEdit -lclangAST -lclangLex -lclangBasic

QMAKE_CXXFLAGS = $${LLVM_CXXFLAGS}
LIBS = $${CLANG_LDFLAGS} ${LLVM_LDFLAGS}
