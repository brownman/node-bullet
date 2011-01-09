#include "RigidBody.h"

Persistent<FunctionTemplate> RigidBody::constructor;

void
RigidBody::Initialize(Handle<Object> target) {
  HandleScope scope;

  constructor = Persistent<FunctionTemplate>::New(FunctionTemplate::New(RigidBody::New));
  constructor->InstanceTemplate()->SetInternalFieldCount(1);
  constructor->SetClassName(String::NewSymbol("RigidBody"));

  Local<ObjectTemplate> proto = constructor->PrototypeTemplate();

  target->Set(String::NewSymbol("RigidBody"), constructor->GetFunction());
}

Handle<Value>
RigidBody::New(const Arguments &args) {
  HandleScope scope;
  
  RigidBody* rigidBody = new RigidBody();
  rigidBody->Wrap(args.This());
  
  return scope.Close(args.This());
}

RigidBody::RigidBody(): ObjectWrap() {  
  btTransform transform;
  transform.setIdentity();
  transform.setOrigin(btVector3((float)rand()/(float)RAND_MAX*1000.0, (float)rand()/(float)RAND_MAX*1000.0, (float)rand()/(float)RAND_MAX*1000.0));
  // tansform.setOrigin(btVector3(0.0, 0.0, 0.0));
  
  btScalar mass(1.0);
  btVector3 localInertia(0, 0, 0);
  
  btDefaultMotionState* defaultMotionState = new btDefaultMotionState(transform);
  btCollisionShape* groundShape = new btBoxShape(btVector3(btScalar(1.0), btScalar(1.0), btScalar(1.0)));
  groundShape->calculateLocalInertia(mass, localInertia);
  btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, defaultMotionState, groundShape, localInertia);
  _btRigidBody = new btRigidBody(rbInfo);
}

RigidBody::~RigidBody() {
  if (_btRigidBody) {
    //delete _btRigidBody;
  }
}