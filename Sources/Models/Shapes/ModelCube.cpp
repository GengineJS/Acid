#include "ModelCube.hpp"

#include "Resources/Resources.hpp"
#include "Models/VertexModel.hpp"

namespace acid
{
	std::shared_ptr<ModelCube> ModelCube::Resource(const float &width, const float &height, const float &depth)
	{
		auto resource = Resources::Get()->Get(ToFilename(width, height, depth));

		if (resource != nullptr)
		{
			return std::dynamic_pointer_cast<ModelCube>(resource);
		}

		auto result = std::make_shared<ModelCube>(width, height, depth);
		Resources::Get()->Add(std::dynamic_pointer_cast<IResource>(result));
		return result;
	}

	std::shared_ptr<ModelCube> ModelCube::Resource(const std::string &data)
	{
		auto split = FormatString::Split(data, "_");
		float width = static_cast<float>(atof(split[1].c_str()));
		float height = static_cast<float>(atof(split[2].c_str()));
		float depth = static_cast<float>(atof(split[3].c_str()));
		return Resource(width, height, depth);
	}

	ModelCube::ModelCube(const float &width, const float &height, const float &depth) :
		Model()
	{
		std::vector<IVertex *> vertices = {
			new VertexModel(Vector3(-0.5f, -0.5f, 0.5f), Vector2(0.375f, 1.0f), Vector3(-1.0f, 0.0f, 0.0f), Vector3(0.0f, 1.0f, 0.0f)),
			new VertexModel(Vector3(-0.5f, 0.5f, 0.5f), Vector2(0.625f, 1.0f), Vector3(-1.0f, 0.0f, 0.0f), Vector3(0.0f, 1.0f, 0.0f)),
			new VertexModel(Vector3(-0.5f, -0.5f, -0.5f), Vector2(0.375f, 0.75f), Vector3(-1.0f, 0.0f, 0.0f), Vector3(0.0f, 1.0f, 0.0f)),
			new VertexModel(Vector3(-0.5f, 0.5f, -0.5f), Vector2(0.625f, 0.75f), Vector3(0.0f, 0.0f, -1.0f), Vector3(0.0f, 1.0f, 0.0f)),
			new VertexModel(Vector3(0.5f, -0.5f, 0.5f), Vector2(0.375f, 0.25f), Vector3(1.0f, 0.0f, 0.0f), Vector3(0.0f, 1.0f, 0.0f)),
			new VertexModel(Vector3(0.5f, 0.5f, 0.5f), Vector2(0.625f, 0.25f), Vector3(0.0f, 0.0f, 1.0f), Vector3(0.0f, 1.0f, 0.0f)),
			new VertexModel(Vector3(0.5f, -0.5f, -0.5f), Vector2(0.375f, 0.5f), Vector3(0.0f, 0.0f, -1.0f), Vector3(0.0f, 1.0f, 0.0f)),
			new VertexModel(Vector3(0.5f, 0.5f, -0.5f), Vector2(0.625f, 0.5f), Vector3(1.0f, 0.0f, 0.0f), Vector3(0.0f, 1.0f, 0.0f)),
			new VertexModel(Vector3(-0.5f, -0.5f, -0.5f), Vector2(0.375f, 0.75f), Vector3(0.0f, 0.0f, -1.0f), Vector3(0.0f, 1.0f, 0.0f)),
			new VertexModel(Vector3(0.5f, -0.5f, -0.5f), Vector2(0.375f, 0.5f), Vector3(1.0f, 0.0f, 0.0f), Vector3(0.0f, 1.0f, 0.0f)),
			new VertexModel(Vector3(-0.5f, -0.5f, 0.5f), Vector2(0.375f, 0.0f), Vector3(0.0f, 0.0f, 1.0f), Vector3(0.0f, 1.0f, 0.0f)),
			new VertexModel(Vector3(0.5f, -0.5f, 0.5f), Vector2(0.375f, 0.25f), Vector3(0.0f, 0.0f, 1.0f), Vector3(0.0f, 1.0f, 0.0f)),
			new VertexModel(Vector3(0.5f, -0.5f, -0.5f), Vector2(0.375f, 0.5f), Vector3(0.0f, -1.0f, 0.0f), Vector3(1.0f, 0.0f, 0.0f)),
			new VertexModel(Vector3(-0.5f, -0.5f, 0.5f), Vector2(0.125f, 0.25f), Vector3(0.0f, -1.0f, 0.0f), Vector3(1.0f, 0.0f, 0.0f)),
			new VertexModel(Vector3(-0.5f, -0.5f, -0.5f), Vector2(0.125f, 0.5f), Vector3(0.0f, -1.0f, 0.0f), Vector3(1.0f, 0.0f, 0.0f)),
			new VertexModel(Vector3(-0.5f, 0.5f, -0.5f), Vector2(0.875f, 0.5f), Vector3(0.0f, 1.0f, 0.0f), Vector3(-1.0f, 0.0f, 0.0f)),
			new VertexModel(Vector3(0.5f, 0.5f, 0.5f), Vector2(0.625f, 0.25f), Vector3(0.0f, 1.0f, 0.0f), Vector3(-1.0f, 0.0f, 0.0f)),
			new VertexModel(Vector3(0.5f, 0.5f, -0.5f), Vector2(0.625f, 0.5f), Vector3(0.0f, 1.0f, 0.0f), Vector3(-1.0f, 0.0f, 0.0f)),
			new VertexModel(Vector3(-0.5f, 0.5f, -0.5f), Vector2(0.625f, 0.75f), Vector3(-1.0f, 0.0f, 0.0f), Vector3(0.0f, 1.0f, 0.0f)),
			new VertexModel(Vector3(0.5f, 0.5f, -0.5f), Vector2(0.625f, 0.5f), Vector3(0.0f, 0.0f, -1.0f), Vector3(0.0f, 1.0f, 0.0f)),
			new VertexModel(Vector3(0.5f, 0.5f, 0.5f), Vector2(0.625f, 0.25f), Vector3(1.0f, 0.0f, 0.0f), Vector3(0.0f, 1.0f, 0.0f)),
			new VertexModel(Vector3(-0.5f, 0.5f, 0.5f), Vector2(0.625f, 0.0f), Vector3(0.0f, 0.0f, 1.0f), Vector3(0.0f, 1.0f, 0.0f)),
			new VertexModel(Vector3(0.5f, -0.5f, 0.5f), Vector2(0.375f, 0.25f), Vector3(0.0f, -1.0f, 0.0f), Vector3(1.0f, 0.0f, 0.0f)),
			new VertexModel(Vector3(-0.5f, 0.5f, 0.5f), Vector2(0.875f, 0.25f), Vector3(0.0f, 1.0f, 0.0f), Vector3(-1.0f, 0.0f, 0.0f)),
		};
		std::vector<uint32_t> indices = {
			1, 2, 0, // Front
			3, 6, 8,
			7, 4, 9, // Back
			5, 10, 11,
			12, 13, 14, // Top
			15, 16, 17,
			1, 18, 2, // Bottom
			3, 19, 6,
			7, 20, 4, // Left
			5, 21, 10,
			12, 22, 13, // Right
			15, 23, 16,
		};

		for (auto &vertex : vertices)
		{
			vertex->SetPosition(vertex->GetPosition() * Vector3(width, height, depth));
		}

		Model::Set(vertices, indices, ToFilename(width, height, depth));
	}

	ModelCube::~ModelCube()
	{
	}

	std::string ModelCube::ToFilename(const float &width, const float &height, const float &depth)
	{
		std::stringstream result;
		result << "Cube_" << width << "_" << height << "_" << depth;
		return result.str();
	}
}
