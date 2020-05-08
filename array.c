#include<stdlib.h>
#include"array.h"
Array *map(Array *src, Mapper mapper){
  int count = src->length;
  Array *result = malloc(sizeof(Array));
  result->length = count;
  result->array = calloc(count, sizeof(int));
  for (int i = 0; i < count; i++)
  {
    result->array[i] = mapper(src->array[i]);
  }
  return result;
}

Array *filter(Array *src, Predicate predicate){
  int count = src->length,index=0;
  int tem_result[count];
  for (int i = 0; i < count; i++)
  {
    if (predicate(src->array[i])){
      tem_result[index] = src->array[i];
      index++;
    }
  }
  Array * result = malloc(sizeof(Array));
  result->length = index;
  result->array = calloc(index, sizeof(int));
  for (int i = 0; i < index; i++)
  {
    result->array[i] = tem_result[i];
}
  return result;
}

int reduce(Array *src, int init, Reducer reducer){
  int count = src->length,result=init;
  for (int i = 0; i < count; i++)
  {
    result = reducer(result,src->array[i]);
  }
  return result;
}