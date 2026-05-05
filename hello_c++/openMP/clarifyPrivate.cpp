#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <iostream>




int main()
{
	int a = 0;
	#pragma omp parallel  num_threads(3)
	#pragma omp for   lastprivate (a)
	for(int i =0;i<10; i++) {
		#pragma omp critical
		a+=i;
		#pragma omp critical
		std:: cout << "The value is " << a  << " "  << i << " the thread num is " << omp_get_thread_num() <<  std::endl;
	}
	std:: cout << "The end  the values " << a << std::endl;

}

// 2494505