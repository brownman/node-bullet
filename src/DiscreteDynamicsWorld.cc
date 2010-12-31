#include "DiscreteDynamicsWorld.h"

#include <iostream>
using namespace std;

Persistent<FunctionTemplate> DiscreteDynamicsWorld::constructor;

void
DiscreteDynamicsWorld::Initialize(Handle<Object> target) {
  HandleScope scope;

  constructor = Persistent<FunctionTemplate>::New(FunctionTemplate::New(DiscreteDynamicsWorld::New));
  constructor->InstanceTemplate()->SetInternalFieldCount(1);
  constructor->SetClassName(String::NewSymbol("DiscreteDynamicsWorld"));
  
  NODE_SET_PROTOTYPE_METHOD(constructor, "setGravity", SetGravity);
  NODE_SET_PROTOTYPE_METHOD(constructor, "addRigidBody", AddRigidBody);
  NODE_SET_PROTOTYPE_METHOD(constructor, "stepSimulation", StepSimulation);

  Local<ObjectTemplate> proto = constructor->PrototypeTemplate();

  target->Set(String::NewSymbol("DiscreteDynamicsWorld"), constructor->GetFunction());
  
  return;
}

Handle<Value>
DiscreteDynamicsWorld::New(const Arguments &args) {
  HandleScope scope;
  
  Local<Object> collisionDispatcherHandle = args[0]->ToObject();
  CollisionDispatcher* collisionDispatcher = ObjectWrap::Unwrap<CollisionDispatcher>(collisionDispatcherHandle);
  
  Local<Object> dbvtBroadphaseHandle = args[1]->ToObject();
  DbvtBroadphase* dbvtBroadphase = ObjectWrap::Unwrap<DbvtBroadphase>(dbvtBroadphaseHandle);
  
  Local<Object> sequentialImpulseConstraintSolverHandle = args[2]->ToObject();
  SequentialImpulseConstraintSolver* sequentialImpulseConstraintSolver = ObjectWrap::Unwrap<SequentialImpulseConstraintSolver>(sequentialImpulseConstraintSolverHandle);
  
  Local<Object> defaultCollisionConfigurationHandle = args[3]->ToObject();
  DefaultCollisionConfiguration* defaultCollisionConfiguration = ObjectWrap::Unwrap<DefaultCollisionConfiguration>(defaultCollisionConfigurationHandle);
  
  DiscreteDynamicsWorld* discreteDynamicsWorld = new DiscreteDynamicsWorld(collisionDispatcher, dbvtBroadphase, sequentialImpulseConstraintSolver, defaultCollisionConfiguration);
  discreteDynamicsWorld->Wrap(args.This());
  
  return scope.Close(args.This());
}

Handle<Value>
DiscreteDynamicsWorld::SetGravity(const Arguments &args) {
  DiscreteDynamicsWorld* discreteDynamicsWorld = ObjectWrap::Unwrap<DiscreteDynamicsWorld>(args.This());
  discreteDynamicsWorld->_btDiscreteDynamicsWorld->setGravity(btVector3(0, -10, 0));
  
  return Undefined();
}

Handle<Value>
DiscreteDynamicsWorld::AddRigidBody(const Arguments &args) {
  DiscreteDynamicsWorld* discreteDynamicsWorld = ObjectWrap::Unwrap<DiscreteDynamicsWorld>(args.This());
  
  Local<Object> rigidBodyHandle = args[0]->ToObject();
  RigidBody* rigidBody = ObjectWrap::Unwrap<RigidBody>(rigidBodyHandle);
  
  discreteDynamicsWorld->_btDiscreteDynamicsWorld->addRigidBody(rigidBody->_btRigidBody);
  
  return Undefined();
}

Handle<Value>
DiscreteDynamicsWorld::StepSimulation(const Arguments &args) {
  DiscreteDynamicsWorld* discreteDynamicsWorld = ObjectWrap::Unwrap<DiscreteDynamicsWorld>(args.This());

  discreteDynamicsWorld->_btDiscreteDynamicsWorld->stepSimulation(100.0);
  
  // btCollisionObject* obj = discreteDynamicsWorld->_btDiscreteDynamicsWorld->getCollisionObjectArray()[0];
  // btRigidBody* body = btRigidBody::upcast(obj);
  // if (body && body->getMotionState())
  // {
  //   btTransform trans;
  //   body->getMotionState()->getWorldTransform(trans);
  //   printf("world pos = %f,%f,%f\n",float(trans.getOrigin().getX()),float(trans.getOrigin().getY()),float(trans.getOrigin().getZ()));
  // }
  // 
  // obj = discreteDynamicsWorld->_btDiscreteDynamicsWorld->getCollisionObjectArray()[1];
  // body = btRigidBody::upcast(obj);
  // if (body && body->getMotionState())
  // {
  //   btTransform trans;
  //   body->getMotionState()->getWorldTransform(trans);
  //   printf("world pos = %f,%f,%f\n",float(trans.getOrigin().getX()),float(trans.getOrigin().getY()),float(trans.getOrigin().getZ()));
  // }
  
  return Undefined();
}

DiscreteDynamicsWorld::DiscreteDynamicsWorld(CollisionDispatcher* collisionDispatcher, DbvtBroadphase* dbvtBroadphase, SequentialImpulseConstraintSolver* sequentialImpulseConstraintSolver, DefaultCollisionConfiguration* defaultCollisionConfiguration): ObjectWrap() {
  // TODO Create and use the actual binded objects instead of this hack
  
  btDefaultCollisionConfiguration* collisionConfiguration = new btDefaultCollisionConfiguration();
  btCollisionDispatcher* dispatcher = new btCollisionDispatcher(collisionConfiguration);
  btDbvtBroadphase* broadphase = new btDbvtBroadphase();
  btSequentialImpulseConstraintSolver* solver = new btSequentialImpulseConstraintSolver();

  _btDiscreteDynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, collisionConfiguration);
  
  // _btDiscreteDynamicsWorld = new btDiscreteDynamicsWorld(collisionDispatcher, dbvtBroadphase, sequentialImpulseConstraintSolver, defaultCollisionConfiguration);;
}

DiscreteDynamicsWorld::~DiscreteDynamicsWorld() {
  if (_btDiscreteDynamicsWorld) {
    free(_btDiscreteDynamicsWorld);
  }
}