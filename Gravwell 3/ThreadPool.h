

namespace Util
{
	namespace Thread
	{
		struct WorkData
		{
			void * allocator;
			void * inData;
			void * outData;
		};

		typedef void(*WorkFunction)(WorkData data);

		struct WorkItem
		{
			WorkFunction func;
			WorkData	 data;
		};

		class ThreadPool
		{
		private:
			PTP_POOL mPool;
			PTP_CALLBACK_ENVIRON mEnviro;
			PTP_CLEANUP_GROUP mCleanGroup;

		public:
			ThreadPool();
			~ThreadPool();

			void initalize( int nbrThreads = 0 );

			void submitWork(WorkItem * item);


						
		};

		int getMaxNumberOfHardwareThreads();
	}

	
	struct Job
	{
		atomic::int waiting;
		Job * dependents[4];
		WorkItem item;
	};

	typedef __int32 JobHandle;

	class Jobs
	{
		
		std::vector<Job> noDep;
		std::vector<Job> Dep;
		
	public:
		Job create(WorkFunction func, void * inData, void * outData, void * allocator = nullptr);
		prepare(Job first, Job second);
		prepare(Job first, Job second, Job third);
		submit(Job job);
		submitMultiple(Job * jobs, int nbr);

	};



}