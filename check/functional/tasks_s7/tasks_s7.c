#include "config.h" /*Display information in the right way (printf on UNIX...)*/
#include "tpl_os.h"
#include "embUnit.h"

TestRef TaskManagementTest_seq7_t1_instance1(void);
TestRef TaskManagementTest_seq7_t1_instance2(void);
TestRef TaskManagementTest_seq7_t1_instance3(void);
TestRef TaskManagementTest_seq7_t2_instance1(void);
TestRef TaskManagementTest_seq7_t2_instance2(void);
TestRef TaskManagementTest_seq7_t3_instance1(void);
TestRef TaskManagementTest_seq7_t3_instance2(void);

unsigned char instance_t1 = 0;
unsigned char instance_t2 = 0;
unsigned char instance_t3 = 0;

int main(void){
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

void ShutdownHook(StatusType error)
{
	TestRunner_end();
}

TASK(t1)
{
	instance_t1 ++;
	switch(instance_t1)
	{ 
		case 1:	
		{
			TestRunner_start();
			TestRunner_runTest(TaskManagementTest_seq7_t1_instance1());
			break;
		}
		case 2:
		{
			TestRunner_runTest(TaskManagementTest_seq7_t1_instance2());
			break;
		}
		case 3:
		{
			TestRunner_runTest(TaskManagementTest_seq7_t1_instance3());
			ShutdownOS(E_OK);
			break;
		}
		default:
		{
			stdimpl_print("Instance error \n");
			break;
		}
	}
}

TASK(t2)
{
	instance_t2 ++;
	switch(instance_t2)
	{ 
		case 1:	
		{
			TestRunner_runTest(TaskManagementTest_seq7_t2_instance1());
			break;
		}
		case 2:
		{
			TestRunner_runTest(TaskManagementTest_seq7_t2_instance2());
			break;
		}
		default:
		{
			stdimpl_print("Instance error \n");
			break;
		}
	}
}

TASK(t3)
{
	instance_t3 ++;
	switch(instance_t3)
	{ 
		case 1:	
		{
			TestRunner_runTest(TaskManagementTest_seq7_t3_instance1());
			break;
		}
		case 2:
		{
			TestRunner_runTest(TaskManagementTest_seq7_t3_instance2());
			break;
		}
		default:
		{
			stdimpl_print("Instance error \n");
			break;
		}
	}
}