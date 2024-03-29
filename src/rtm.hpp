#ifndef _RTM_HPP_
#define _RTM_HPP_
#include "util.hpp"
/**
 * @param bitmap triangle intersection vector to be expanded
 * @param out output index place
 * @param vector_size of length of the bitmap
 * */
int expand_avx2(Bitmap *bitmap, int *out, int vector_size);
/**
 * @param bitmap triangle intersection vector to be expanded
 * @param out output index place
 * @param vector_size of length of the bitmap
 * */
 int expand_ctz(Bitmap *bitmap, int *out, int vector_size);
/**
 * @param bitmap triangle intersection vector to be expanded
 * @param out output index place
 * @param vector_size of length of the bitmap
 * */
 int expand_avx2_compress(Bitmap *bitmap, int *out, int vector_size);

/**
 * @param bitmap triangle intersection vector to be expanded
 * @param bitmask index to be excluded
 * @param out output index place
 * @param vector_size of length of the bitmap
 * */
 int maskz_expand_avx2_compress(Bitmap *bitmask, Bitmap *bitmap, Bitmap *buffer, int *out, int vector_size);

/**
 * @param bitmap_a triangle intersection vector to be expanded
 * @param bitmap_b triangle intersection vector to be expanded
 * @param bitmask indexes to be excluded
 * @param out output index place
 * @param vector_size of length of the bitmap
 * */
 int maskzor_expand_avx2_compress(Bitmap *bitmask, Bitmap *bitmap_a, Bitmap *bitmap_b, Bitmap *buffer, int *out, int vector_size);

/**
 * @param bitmap_a triangle intersection vector to be expanded
 * @param bitmap_b triangle intersection vector to be expanded
 * @param bitmask indexes to be excluded
 * @param out output index place
 * @param vector_size of length of the bitmap
 * */
 int maskzor_expand_ctz(Bitmap *bitmask, Bitmap *bitmap_a, Bitmap *bitmap_b, int *out, int vector_size);
 int maskz_expand_ctz(Bitmap *bitmask, Bitmap *bitmap_a, int *out, int vector_size);

/**
 * @param bitmap triangle intersection vector to be expanded
 * @param out output vertex id place
 * @param vector_size of length of the bitmap
 * @param id_list start of the adjacancy list
 * */
int expandToID(Bitmap *bitmap, int *out, int vector_size, int *id_list);

/**
 * 
 * @note set intersection of two list, vec_a and vec_b
 * @return number common vertex
 * @return bitvec the position of common vertex in bitmap format relative to vec_a
 * @param vec_a first list
 * @param size_a size of first list
 * @param vec_b second lsit
 * @param size_b size of the second list
 * */
int mark_intersect(int *set_a, int size_a, int *set_b, int size_b, Bitmap *bitvec);
/**
 * 
 * @note set intersection of two list, vec_a and vec_b
 * @return number common vertex
 * @return bitvec the position of common vertex in bitmap format relative to vec_a
 * @param vec_a first list
 * @param size_a size of first list
 * @param vec_b second lsit
 * @param size_b size of the second list
 * */
int mark_intersect_simd8x(int *set_a, int size_a, int *set_b, int size_b, Bitmap *bitvec);

// /**
//  * 
//  * @note bitwise operation of two bitstream
//  * store out the result of two intersection
//  * */
// void intersect(Bitmap *bitmap_a, Bitmap *bitmap_b, Bitmap *out, int vector_size);
// bool intersect_allzero(Bitmap *bitmap_a, Bitmap *bitmap_b, Bitmap *out, int vector_size);


void bitwise_not(Bitmap *bitmap_a, Bitmap *out, int vector_size);
 void bitwise_and(Bitmap *bitmap_a, Bitmap *bitmap_b, Bitmap *out, int vector_size);
 void bitwise_or(Bitmap *bitmap_a, Bitmap *bitmap_b, Bitmap *out, int vector_size);
 void bitwise_nand(Bitmap *bitmap_a, Bitmap *bitmap_b, Bitmap *out, int vector_size);
void bitwise_andn(Bitmap *bitmap_a, Bitmap *bitmap_b, Bitmap *out, int vector_size);
void double_bitwise_and(Bitmap *bitmask, Bitmap *bitmap_a, Bitmap *bitmap_b, Bitmap *a_out, Bitmap *b_out, int vector_size);

/**
 * @return number of ones in a and b
 * */
 int bitwise_and_count(Bitmap *bitmap_a, Bitmap *bitmap_b, int vector_size);
 int bitwise_and_count(Bitmap *bitmap_a, Bitmap *bitmap_b, Bitmap *out,int vector_size);

/**
 * @return number of ones in a \ b
 * */
 int bitwise_andn_count(Bitmap *bitmap_a, Bitmap *bitmap_b, int vector_size);
 int bitwise_andn_count(Bitmap *bitmap_a, Bitmap *bitmap_b, Bitmap * out, int vector_size);
/**
 * @note fill bitmap with ones from beginning
 * */
void fill_with_one(Bitmap *bitmap, int num_one);

/**
 * @param bitmap bitmap
 * @param index position to be marked as 1
 * */
void mark_as_one(Bitmap *bitmap, int index);
/**
 * @param bitmap bitmap
 * @param index position to be marked as 0
 * */
void mark_as_zero(Bitmap *bitmap, int index);
/**
 * @param bitmap bitmap
 * @param vector_size number byte
 * */
 bool all_zero(Bitmap *bitmap, int vector_size);

/**
 * @param bitmap the coming bitstream
 * @param out place that holds the indices in the bitmap
 * @param start starting point of the bitmap (bits)
 * @param end end place of the bitmap (bits)
 * @return number of indices
 * */
int expand_avx2(Bitmap *bitmap, int *out, int start, int end);
/**
 * @param bitmap the coming bitstream
 * @param out place that holds the vertex ids in the bitmap
 * @param start starting point of the bitmap (bits)
 * @param end end place of the bitmap (bits)
 * @param id_list the id_list corresponds to the bitmap
 * @return number of indices
 * */
int expandToID(Bitmap *bitmap, int *out, int *id_list, int start, int end);

/** 
 * @param bitmap coming bitstream
 * @param vector_size length of the bitstream
 * @return number of 1s in the bitstream
 * */
int count_bitmap(Bitmap *bitmap, int vector_size);
/** 
 * @param bitmap coming bitstream
 * @param vector_size length of the bitstream
 * @param start starting point of the bitmap (bits)
 * @param end end place of the bitmap (bits)
 * @return number of 1s in the bitstream
 * */
int count_bitmap(Bitmap *bitmap, int start, int end);

int find_first_index(Bitmap *bitmap, int vector_size);
int find_last_index(Bitmap *bitmap, int vector_size);

int maskzor_find_first_index(Bitmap * bitmask, Bitmap *bitmap_a, Bitmap * bitmap_b, int vector_size);
int maskzor_find_first_index(Bitmap * bitmask, Bitmap *bitmap_a, Bitmap * bitmap_b, Bitmap *simd_buffer, int vector_size);

#endif