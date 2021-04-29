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
	mTexture = theRenderer.loadTexture("../textures/ParticleFirecloud.png");
	for (int i = 0; i < size; i++) {
		Particle particle = {startPos, random_unit_vector(),startCol, 0.05, rand() / (RAND_MAX + 1.) };
		mParticles.push_back(particle);
	}
}

void  MyParticleSystem::update(float dt)
{
	for (int i = 0; i < mParticles.size(); i++) {
		Particle p = mParticles[i];
		if (p.color[3] < 0.0) {
			p.pos = startPos;
			p.vel = random_unit_vector();
			p.color = startCol;
			p.size = 0.05;
			p.mass = rand() / (RAND_MAX + 1.);

		}
		else {
			p.vel += vec3(0, -9.8, 0) * dt;
			p.pos = p.pos + p.vel * dt;
			p.color = vec4(p.color[0], p.color[1], p.color[2], p.color[3] - 0.001);
		}
		mParticles[i] = p;
	}

	for (int i = 0; i < mParticles.size();i++) {
		if (i == 0) {
			continue;
		}
		else {
			Particle p = mParticles[i];
			Particle previous = mParticles[i - 1];
			float d1 = length(p.pos - theRenderer.cameraPosition());
			float d2 = length(previous.pos - theRenderer.cameraPosition());
			if (d2 < d1) {
				swap(mParticles[i - 1], mParticles[i]);
			}
		}
	}
}

