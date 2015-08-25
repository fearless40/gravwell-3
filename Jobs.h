#include "CriticalSection.h"

namespace Util {
namespace Work {    
    
   

    class Jobs
    {
        private:
        static const int MaxNumberOfWaitingJobs = 100;
        
        typedef uint_32 JobHandle; 
        
    	CriticalSection mCS;
    	
    	// Useing a static array allows me to use less locking. As now I always know who owns a 
    	// job pointer and that the array will never be in validated.
    	Job * mDep[MaxNumberOfWaitingJobs];
    	std::vector<int> mFreeList;
    	ThreadPool & mPool;
    	std::atomic_int SubmitJobsThatDependenciesHaveBeenMetCounter;
    	
        Jobs();
        
        static void JobSubmitDependentWork( WorkData data );
        
        void JobDependentWorkCompleted( Job * job );
    
    public:
        Jobs( ThreadPool & pool );
    
    	void createSubmit(WorkFunction func, void * inData, void * outData);
    
    	// Also will add all the dependents from the job to the waiting array
    	// In debug mode will fail if you attempt to add a Job with its waiting member not = 0 
    	void submit(Job * job);
    	
    	friend class Jobs;
    };
		
}; // Work
}; // Util