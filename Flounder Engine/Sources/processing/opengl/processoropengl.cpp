#include "processoropengl.h"

namespace flounder {
	const double processoropengl::MAX_TIME_MILLIS = 8.0f;

	processoropengl::processoropengl()
	{
		m_queue = new queue<requestopengl*>();
	}

	processoropengl::~processoropengl()
	{
		delete m_queue;
	}

	void processoropengl::update()
	{
		double remainingTime = MAX_TIME_MILLIS;
		double start = framework::get()->getTimeMs();

		while (m_queue->hasRequests())
		{
			m_queue->acceptNextRequest()->executeRequestGL();
			double end = framework::get()->getTimeMs();
			double timeTaken = end - start;
			remainingTime -= timeTaken;
			start = end;

			if (remainingTime < 0.0)
			{
				return;
			}
		}
	}

	void processoropengl::addRequestToQueue(irequest *request)
	{
		if (request == NULL)
		{
			return;
		}

		m_queue->addRequest((requestopengl*) request);
	}

	void processoropengl::completeAllRequests()
	{
		while (m_queue->hasRequests())
		{
			m_queue->acceptNextRequest()->executeRequestGL();
		}
	}

	int processoropengl::getRequestId()
	{
		return 2;
	}
}