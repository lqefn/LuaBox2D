--[[
  
This code is MIT licensed, see http://www.opensource.org/licenses/mit-license.php
(C) 2010 - 2011 Gideros Mobile 
 
]]

local box2d = require "LuaBox2D"

-- this table holds the dynamic bodies and their sprites
local actors = {}

-- create world
local world = box2d.World(box2d.Vec2(0, 9.8))

-- create ground body
local ground = world.createBody(box2d.BodyDef())

-- create an edge shape, and attach it to the ground body as a fixture
local shape = box2d.EdgeShape(box2d.Vec2(0, 350), box2d.Vec2(320, 350))
local fixtureDef = box2d.FixtureDef()
fixtureDef.shape = shape
fixtureDef.density = 0
ground.createFixture(fixtureDef)

-- this box shape will be used while creating the chain elements
local shape = box2d.PolygonShape()
shape.setAsBox(5, 1)

-- and our fixture definition
local fixtureDef = box2d.FixtureDef() 
fixtureDef.shape = shape
fixtureDef.density = 20
fixtureDef.friction = 0.2

-- start to create the bridge
local prevBody = ground

for i=1,30 do
	local bodyDef = box2d.BodyDef()
	bodyDef.type = "dynamic"
	bodyDef.position = box2d.Vec2(164 + i * 8, 150)
	local body = world.createBody(bodyDef)
	body.createFixture(fixtureDef)

	actors[body] = true
	
	-- attach each pair of chain elements with revolute joint
	local jointDef = box2d.RevoluteJointDef()
	jointDef.initialize(prevBody, body, box2d.Vec2(160 + i * 8, 150))
	jointDef.collideConnected = false
	world.createJoint(jointDef)
	
	prevBody = body
end

-- step the world and then update the position and rotation of sprites
local function onEnterFrame()
	world.step(1/60, 8, 3)
	
	for body, _ in pairs(actors) do
		print(body)
		print(body.position.x, body.position.y)
		print(body.angle * 180 / math.pi)
	end
end

for i = 1, 100 do
	onEnterFrame()
end
