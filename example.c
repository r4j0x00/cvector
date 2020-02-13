#include <stdio.h>
#include "cvector.h"

int main()
{
	long long *d = new_vec();
	
	for(long long i=25; i>=0; --i) {
		vec_push(d,i*2);
	}
	
	vec_pop(d);
	vec_sort(d);
	vec_printall(d);

	vec_reverse(d);
	vec_printall(d);

	vec_resize(d,10);
	vec_printall(d);

	d[4] = 5;
	vec_printall(d);

	vec_clear(d);
	vec_printall(d);
}