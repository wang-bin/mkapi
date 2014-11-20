CXX = g++

TARGET = mkapi
SRC = mkapi.cpp
OBJS = $(SRC:.cpp=.o) 
LLVM_VER=$(shell llvm-config --version) #3.4.2

LLVM_CXXFLAGS=$(shell llvm-config --cxxflags)
LLVM_COMPONENTS=core mc mcparser support bitreader
# 3.4
LLVM_COMPONENTS += transformutils
#3.5
LLVM_COMPONENTS += option

LLVM_LIBS=$(shell llvm-config --libs $(LLVM_COMPONENTS))
LLVM_LDFLAGS=$(LLVM_LIBS) $(shell llvm-config --ldflags)
#why llvm-config --libs --ldflags xxx will link error?
#-lLLVMSupport -lLLVMMC 
CLANG_LDFLAGS = \
  -lclangTooling \
  -lclangFrontendTool -lclangFrontend -lclangDriver \
  -lclangSerialization -lclangCodeGen -lclangParse \
  -lclangSema -lclangStaticAnalyzerFrontend  \
  -lclangStaticAnalyzerCheckers -lclangStaticAnalyzerCore \
  -lclangAnalysis -lclangARCMigrate \
  -lclangEdit -lclangAST -lclangLex -lclangBasic

#3.5 no: -lclangRewriteCore
#3.5 unix
CLANG_LDFLAGS += -lclangRewrite -lz -lncurses

CXXFLAGS = -g $(LLVM_CXXFLAGS)
LDFLAGS = $(CLANG_LDFLAGS) $(LLVM_LDFLAGS)

all: $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $^

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^  $(LDFLAGS)

clean:
	rm -rf *.o *.ll $(TARGET)
