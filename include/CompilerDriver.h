#pragma once

#include "Scanner.h"

#include <Visitors/PrintVisitor.h>
#include <Visitors/InterpreterVisitor.h>
#include <Visitors/SymbolTableVisitor.h>

#include <memory>

class Location;

class CompilerDriver
{
 public:
	using Ptr = std::shared_ptr<CompilerDriver>;
	static Ptr Create(bool bTraceParsing, bool bTraceScanning, bool bDebugLocation);
	virtual int Parse(const std::string& f) = 0;
	virtual void SetProgram(const std::shared_ptr<Program>& pProgram) = 0;
	virtual void StartVisitor(PrintVisitor::Ptr pVisitor) = 0;
	virtual void StartVisitor(InterpreterVisitor::Ptr pVisitor) = 0;
	virtual void StartVisitor(SymbolTableVisitor::Ptr pVisitor) = 0;
	virtual ~CompilerDriver() = default;
 protected:
	CompilerDriver() = default;
};