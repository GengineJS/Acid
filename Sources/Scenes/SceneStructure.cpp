﻿#include "SceneStructure.hpp"

#include "Physics/Collider.hpp"

namespace acid
{
	SceneStructure::SceneStructure() :
		ISpatialStructure(),
		m_objects(std::vector<std::unique_ptr<GameObject>>())
	{
	}

	SceneStructure::~SceneStructure()
	{
	}

	void SceneStructure::Add(GameObject *object)
	{
		m_objects.emplace_back(object);
	}

	bool SceneStructure::Remove(GameObject *object)
	{
		for (auto it = --m_objects.end(); it != m_objects.begin(); --it)
		{
			if ((*it).get() != object)
			{
				continue;
			}

			m_objects.erase(it);
			return true;
		}

		return false;
	}

	void SceneStructure::Clear()
	{
		m_objects.clear();
	}

	std::vector<GameObject *> SceneStructure::QueryAll()
	{
		auto result = std::vector<GameObject *>();

		for (auto it = m_objects.begin(); it != m_objects.end(); ++it)
		{
			result.emplace_back((*it).get());
		}

		return result;
	}

	std::vector<GameObject *> SceneStructure::QueryFrustum(const Frustum &range)
	{
		auto result = std::vector<GameObject *>();

		for (auto it = m_objects.begin(); it != m_objects.end(); ++it)
		{
			auto collider = (*it)->GetComponent<Collider>();

			if (collider == nullptr || collider->InFrustum(range))
			{
				result.emplace_back((*it).get());
			}
		}

		return result;
	}

	/*std::vector<GameObject *> SceneStructure::QueryBounding(Collider *range)
	{
		auto result = std::vector<GameObject *>();

		for (auto it = m_objects.begin(); it != m_objects.end(); ++it)
		{
			auto gameObject = std::dynamic_pointer_cast<GameObject>(*it);
			auto collider = gameObject->GetComponent<Collider>();

			if (collider == nullptr || range->Intersects(*collider).IsIntersection() || range->Contains(*collider))
			{
				result.emplace_back((*it).get());
			}
		}

		return result;
	}*/

	bool SceneStructure::Contains(GameObject *object)
	{
		for (auto &object2 : m_objects)
		{
			if (object2.get() == object)
			{
				return true;
			}
		}

		return false;
	}
}
