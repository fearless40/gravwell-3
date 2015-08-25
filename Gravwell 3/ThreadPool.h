#include <atomic>
#include "Work.h"

namespace Util
{
	namespace Work
	{
		

		class ThreadPool
		{
		private:
			PTP_POOL mPool;
			PTP_CALLBACK_ENVIRON mEnviro;
			PTP_CLEANUP_GROUP mCleanGroup;

		public:
			ThreadPool();
			~ThreadPool();

			void initalize(int nbrThreads = 0);

			void submitWork(WorkItem * item);



		};

		int getMaxNumberOfHardwareThreads();

		

		class Jobs
		{
			CRITICAL_SECTION vectorLock;
			std::vector<Job> Dep;

		public:

			void createSubmit(WorkFunction func, void * inData, void * outData);

			// Also will add all the dependents from the job to the waiting array
			// In debug mode will fail if you attempt to add a Job with its waiting member not = 0 
			submit(Job job);
		};


	};
}