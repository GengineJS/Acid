#pragma once

#include <vector>

#include "../renderer/irenderer.hpp"

#include "particles.hpp"

namespace Flounder
{
	class rendererparticles :
		public irenderer
	{
	private:
		static const int MAX_INSTANCES;
		static const int INSTANCE_DATA_LENGTH;

		shader *m_shader;

		//int m_vaoID;
		//int m_vboID;
		//int m_vaoLength;

		int m_rendered;
	public:
		rendererparticles();

		~rendererparticles();

		void render(const vector4 &clipPlane, const ICamera &camera) override;
	private:
		void prepareRendering(const vector4 &clipPlane, const ICamera &camera);

		void prepareInstance(particle *particle, const ICamera &camera, std::vector<float> *vboData);

		void renderInstances(particletype *particleType, std::vector<float> *vboData);

		void endRendering();
	};
}
