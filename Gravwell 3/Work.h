#pragma once
namespace Util
{
	namespace Work
	{
		struct WorkData
		{
			void * inData;
			void * outData;
		};

		typedef void(*WorkFunction)(WorkData data);

		struct WorkItem
		{
			WorkFunction func;
			WorkData	 data;
		};
	};
};