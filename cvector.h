#define dtype long long
#define vec_resize(d,s) vec_resize_int(&d, s)
#define vec_clear(d) vec_resize_int(&d, 0)
#define vec_push(d,e) vec_push_int(&d, e)
#define vec_pop(d) vec_pop_int(&d)

int cmpfunc (const void * a, const void * b);
void vec_push_int(dtype **self, dtype ele);
void vec_pop_int(dtype **self);
void vec_printall(dtype *self);
void vec_sort(dtype *self);
void vec_reverse(dtype *self);
dtype *new_vec();
dtype vec_size(dtype* vec);
void vec_resize_int(dtype **vec, unsigned int n);
