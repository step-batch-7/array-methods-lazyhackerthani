#include"array_void.h"
ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper){
  int count = src->length;
  ArrayVoid_ptr result = malloc(sizeof(ArrayVoid));
  result->length = count;
  result->array = calloc(count, sizeof(Object));
  for (int i = 0; i < count; i++)
  {
    result->array[i] = mapper(src->array[i]);
  }
  return result;
}

ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate){
   int count = src->length,index=0;
  Object temp_result[count];
  for (int i = 0; i < count; i++)
  {
    if (predicate(src->array[i])){
      temp_result[index] = src->array[i];
      index++;
    }
  }
  ArrayVoid_ptr result = malloc(sizeof(ArrayVoid));
  result->length = index;
  result->array = calloc(index, sizeof(Object));
  for (int i = 0; i < index; i++)
  {
    result->array[i] = temp_result[i];
}
  return result;
}