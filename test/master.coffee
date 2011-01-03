Bullet = require '../index'
# 
# bullet = new Bullet.Bullet
# console.log bullet

# defaultCollisionConfiguration = new Bullet.DefaultCollisionConfiguration
# console.log 'defaultCollisionConfiguration', defaultCollisionConfiguration
# 
# collisionDispatcher = new Bullet.CollisionDispatcher defaultCollisionConfiguration
# console.log 'collisionDispatcher', collisionDispatcher
# 
# dbvtBroadphase = new Bullet.DbvtBroadphase
# console.log 'dbvtBroadphase', dbvtBroadphase
# 
# sequentialImpulseConstraintSolver = new Bullet.SequentialImpulseConstraintSolver
# console.log 'sequentialImpulseConstraintSolver', sequentialImpulseConstraintSolver

discreteDynamicsWorld = new Bullet.DiscreteDynamicsWorld #collisionDispatcher, dbvtBroadphase, sequentialImpulseConstraintSolver, defaultCollisionConfiguration
console.log 'discreteDynamicsWorld', discreteDynamicsWorld

# discreteDynamicsWorld.setGravity()

# # boxShape = new Bullet.BoxShape
# # console.log 'boxShape', boxShape
# 
# # transform = new Bullet.Transform
# # console.log 'transform', transform

for i in [0...500]
  rigidBody = new Bullet.RigidBody
  console.log 'rigidBody', rigidBody

  discreteDynamicsWorld.addRigidBody rigidBody

fps = 0

setInterval(->
  fps++
  discreteDynamicsWorld.stepSimulation()
, 0)

setInterval(->
  console.log fps
  fps = 0
, 1000)