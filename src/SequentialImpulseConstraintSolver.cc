#include "SequentialImpulseConstraintSolver.h"

Persistent<FunctionTemplate> SequentialImpulseConstraintSolver::constructor;

void
SequentialImpulseConstraintSolver::Initialize(Handle<Object> target) {
  HandleScope scope;

  constructor = Persistent<FunctionTemplate>::New(FunctionTemplate::New(SequentialImpulseConstraintSolver::New));
  constructor->InstanceTemplate()->SetInternalFieldCount(1);
  constructor->SetClassName(String::NewSymbol("SequentialImpulseConstraintSolver"));

  Local<ObjectTemplate> proto = constructor->PrototypeTemplate();

  target->Set(String::NewSymbol("SequentialImpulseConstraintSolver"), constructor->GetFunction());
}

Handle<Value>
SequentialImpulseConstraintSolver::New(const Arguments &args) {
  HandleScope scope;
  
  SequentialImpulseConstraintSolver* sequentialImpulseConstraintSolver = new SequentialImpulseConstraintSolver();
  sequentialImpulseConstraintSolver->Wrap(args.This());
  
  return args.This();
}

SequentialImpulseConstraintSolver::SequentialImpulseConstraintSolver(): ObjectWrap() {
  _btSequentialImpulseConstraintSolver = new btSequentialImpulseConstraintSolver();
}

SequentialImpulseConstraintSolver::~SequentialImpulseConstraintSolver() {
  if (_btSequentialImpulseConstraintSolver) {
    //delete _btSequentialImpulseConstraintSolver;
  }
}