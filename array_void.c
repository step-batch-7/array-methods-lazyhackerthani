#include"array_void.h"
ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper){
  int count = src->length;
  ArrayVoid_ptr result = malloc(sizeof(ArrayVoid));
  result->length = count;
  result->array = calloc(count, sizeof(Object));
  for (int i = 0; i < count; i++)
  {
    result->array[i] = MapperVoid(src->array[i]);
  }
  return result;
}