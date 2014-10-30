#include "common.hpp"
#include "objects/Joint.hpp"
#include "objects/RevoluteJoint.hpp"

namespace LuaBox2D {
	void initRevoluteJoint(State * state){
		state->registerInterface<RevoluteJoint>("LuaBox2D_RevoluteJoint");
	}

	b2RevoluteJoint * RevoluteJoint::constructor(State & state){
		Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
		b2Joint * joint = interfaceJoint->get(1);
		if (joint != nullptr){
			if (joint->GetType() == b2JointType::e_revoluteJoint){
				return new b2RevoluteJoint(*dynamic_cast<b2RevoluteJoint*>(joint));
			}else{
				return nullptr;
			}
		}else{
			return nullptr;
		}
	}

	void RevoluteJoint::destructor(State & state, b2RevoluteJoint * object){
		base->destructor(state, object);
	}

	inline int RevoluteJoint::getType(State & state, b2RevoluteJoint * object){
		return base->getType(state, object);
	}

	inline int RevoluteJoint::getBodyA(State & state, b2RevoluteJoint * object){
		return base->getBodyA(state, object);
	}

	inline int RevoluteJoint::getBodyB(State & state, b2RevoluteJoint * object){
		return base->getBodyB(state, object);
	}

	inline int RevoluteJoint::getAnchorA(State & state, b2RevoluteJoint * object){
		return base->getAnchorA(state, object);
	}

	inline int RevoluteJoint::getAnchorB(State & state, b2RevoluteJoint * object){
		return base->getAnchorB(state, object);
	}

	inline int RevoluteJoint::getReactionForce(State & state, b2RevoluteJoint * object){
		return base->getReactionForce(state, object);
	}

	inline int RevoluteJoint::getReactionTorque(State & state, b2RevoluteJoint * object){
		return base->getReactionTorque(state, object);
	}

	inline int RevoluteJoint::getActive(State & state, b2RevoluteJoint * object){
		return base->getActive(state, object);
	}

	inline int RevoluteJoint::getCollideConnected(State & state, b2RevoluteJoint * object){
		return base->getCollideConnected(state, object);
	}
};
