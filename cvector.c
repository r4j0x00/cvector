#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define dtype long long
#define vec_resize(d,s) vec_resize_int(&d, s)
#define vec_clear(d) vec_resize_int(&d, 0)
#define vec_push(d,e) vec_push_int(&d, e)
#define vec_pop(d) vec_pop_int(&d)
#define vec_popidx(d,idx) vec_pop_idx_int(&d, idx)

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void vec_push_int(dtype **self, dtype ele) {
	--*self;
	++*self[0];
	*self = (dtype*)realloc(*self, (*self[0]*sizeof(dtype))+sizeof(dtype));
	dtype* s = *self;
	s[*self[0]] = ele;
	++*self;
};

void vec_pop_int(dtype **self) {
	--*self;
	if(!*self[0])
	{
		++*self;
		return;
	}
	--*self[0];
	*self = (dtype*)realloc(*self, (*self[0]*sizeof(dtype))+sizeof(dtype));
	++*self;
};

void vec_pop_idx_int(dtype **self, unsigned int idx)
{
	--*self;
	unsigned int size = *self[0];
	if(!size)
	{
		++*self;
		return;
	}
	assert(idx < size);
	--*self[0];
	dtype *s  = *self+1;
	for(int i=idx; i < size-1; ++i)
	{
		s[i] = s[i+1];
	}
	*self = (dtype*)realloc(*self, (*self[0]*sizeof(dtype))+sizeof(dtype));
	++*self;
}

void vec_printall(dtype *self)
{
	--self;
	printf("[");
	int i;
	for(i=1;i < self[0]; ++i)
	{
		printf("%lld, ",self[i]);
	}
	if(i<=self[0])
		printf("%lld", self[i]);
	puts("]");

}

void vec_sort(dtype *self)
{
	--self;
	qsort(self+1, self[0], sizeof(dtype), cmpfunc);
}

void vec_reverse(dtype *self)
{
	--self;
	dtype tmp;
	int start=1;
	int end = self[0];
	while (start < end)
	{
		tmp = self[start];
		self[start] = self[end];
		self[end] = tmp;
		++start,--end;
	}
}

dtype *new_vec()
{
	dtype* d = (dtype*)malloc(sizeof(dtype)*2);
	d[0] = 0;
	return d+1;
}

long long vec_size(dtype* vec)
{
	return vec[-1];
}

void vec_resize_int(dtype **vec, unsigned int n)
{
	--*vec;
	if(n==*vec[0])
	{
		++*vec;
		return;
	}
	*vec = (dtype*)realloc(*vec,sizeof(dtype)+(n*(sizeof(dtype))));
	
	if(n>*vec[0])
	{
		memset(*vec+*vec[0]+1,0,(n*sizeof(dtype))-*vec[0]*sizeof(dtype));
	}

	*vec[0] = n;
	++*vec;
	return;
}
