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

	vec_popidx(d, 4);
	vec_printall(d);
	
	d[0] = 38;
	printf("%d\n",vec_count(d, 38));
	vec_remove(d, 38);
	printf("%d\n",vec_count(d, 38));
	vec_printall(d);

	vec_insert(d, 5, 1337);
	vec_printall(d);
	
	long long* d2 = new_vec();
	vec_push(d2, 12);
	vec_push(d2, 16);

	long long *d3 = vec_join(d2, d);
	vec_printall(d3);

	vec_clear(d);
	vec_printall(d);
}
