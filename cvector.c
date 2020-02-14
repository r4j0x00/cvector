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
#define vec_remove(d, val) vec_remove_int(&d, val)
#define vec_insert(d, idx, val) vec_insert_int(&d, idx, val)

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int vec_index(dtype *self, dtype value)
{
	unsigned int size = self[-1];
	for(int i=0;i<size;++i)
	{
		if(self[i] == value)
			return i;
	}
	return -1;
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

void vec_remove_int(dtype **self, dtype value) // Removes the first occurence of a value in the array if found
{
	dtype* s = *self;
	int idx = vec_index(s,value);
	if(idx == -1) return;
	vec_pop_idx_int(self, idx);
}

unsigned int vec_count(dtype *self, dtype value)
{
	unsigned int count = 0;
	unsigned int size = self[-1];
	for(int i=0;i<size;++i)
		if(self[i]==value)
			++count;
	return count;
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

void vec_insert_int(dtype **vec, unsigned int idx, dtype value)
{
	--*vec;
	unsigned int size = *vec[0];
	assert(idx <= size);
	++*vec[0];
	*vec = (dtype*)realloc(*vec, (*vec[0]*sizeof(dtype))+sizeof(dtype));
	++*vec;
	dtype* s = *vec;
	for(int i=size-1;i>idx;--i)
		s[i] = s[i-1];
	s[idx] = value;
	return;
}

dtype* vec_join(dtype *vec1, dtype *vec2)
{
	dtype *new = new_vec();
	unsigned int size_1 = vec_size(vec1);
	unsigned int size_2 = vec_size(vec2);

	vec_resize_int(&new, size_1+size_2);
	int i;
	
	for(i=0; i < size_1; ++i)
		new[i] = vec1[i];

	for(i=0; i < size_2; ++i)
		new[i+size_1] = vec2[i];

	return new;
}
