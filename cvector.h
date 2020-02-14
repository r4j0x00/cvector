#define dtype long long
#define vec_resize(d,s) vec_resize_int(&d, s)
#define vec_clear(d) vec_resize_int(&d, 0)
#define vec_push(d,e) vec_push_int(&d, e)
#define vec_pop(d) vec_pop_int(&d)
#define vec_popidx(d,idx) vec_pop_idx_int(&d, idx)
#define vec_remove(d, val) vec_remove_int(&d, val)
#define vec_insert(d, idx, val) vec_insert_int(&d, idx, val)

int cmpfunc (const void * a, const void * b);
void vec_push_int(dtype **self, dtype ele);
void vec_pop_int(dtype **self);
int vec_index(dtype *self, dtype value);
void vec_pop_idx_int(dtype **self, unsigned int idx);
void vec_remove_int(dtype **self, dtype value);
unsigned int vec_count(dtype *self, dtype value);
void vec_printall(dtype *self);
void vec_sort(dtype *self);
void vec_reverse(dtype *self);
dtype *new_vec();
dtype vec_size(dtype* vec);
void vec_resize_int(dtype **vec, unsigned int n);
void vec_insert_int(dtype **vec, unsigned int idx, dtype value);
