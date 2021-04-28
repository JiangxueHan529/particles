// Bryn Mawr College, alinen, 2020
//
#include "AGL.h"
#include "AGLM.h"
#include <cmath>
#include "myparticlesystem.h"
#include "stdlib.h"

using namespace std;
using namespace agl;
using namespace glm;

void MyParticleSystem::createParticles(int size)
{
	mTexture = theRenderer.loadTexture("../textures/particle.png");
	for (int i = 0; i < size; i++) {
		Particle particle = { vec3(0,0,0), random_unit_vector(),vec4(random_unit_vector(), rand() / (RAND_MAX + 1.)), 0.05, rand() / (RAND_MAX + 1.) };
		mParticles.push_back(particle);
	}
}

void  MyParticleSystem::update(float dt)
{
	for (int i = 0; i < mParticles.size(); i++) {
		Particle p = mParticles[i];
		p.vel += vec3(0, -1, 0);
		vec3 new_pos = p.pos + p.vel * dt;
		if (new_pos[0] < -1) {
			p.vel = reflect(p.vel, vec3(1, 0, 0));
		}
		else if (new_pos[0] > 1) {
			p.vel = reflect(p.vel, vec3(-1, 0, 0));
		}
		else if (new_pos[1] > 1) {
			p.vel = reflect(p.vel, vec3(0, -1, 0));
		}
		else if (new_pos[1] < -1) {
			p.vel = reflect(p.vel, vec3(0, 1, 0));
		}
		else if (new_pos[2] > 1) {
			p.vel = reflect(p.vel, vec3(0, 0, -1));
		}
		else if (new_pos[2] < -1) {
			p.vel = reflect(p.vel, vec3(0, 0, 1));
		}
		p.pos = p.pos + p.vel * dt;
		mParticles[i] = p;
	}
	for (int i = 0; i < mParticles.size();i++) {
		if (i == 0) {
			continue;
		}
		else {
			Particle p = mParticles[i];
			Particle previous = mParticles[i - 1];
			float d2 = length(p.pos - theRenderer.cameraPosition());
			float d1 = length(previous.pos - theRenderer.cameraPosition());
			if (d2 > d1) {
				swap(mParticles[i - 1], mParticles[i]);
			}
		}
	}
}

