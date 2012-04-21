#include <ruby.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "ewah.h"

typedef VALUE (ruby_method)(...);

typedef struct ewah {
  EWAHBoolArray<uword32> *bits;
} EWAH;

extern "C" VALUE ewah_new(VALUE klass) {
  EWAH *b = ALLOC(EWAH);
  b->bits = new EWAHBoolArray<uword32>();
  VALUE bitset = Data_Wrap_Struct(klass, 0, free, b);
  rb_obj_call_init(bitset, 0, 0);
  return bitset;
}

extern "C" VALUE ewah_init(VALUE self) {
  return self;
}

extern "C" VALUE ewah_set(VALUE self, VALUE position) {
  if (position == Qnil) {
    rb_raise(rb_eRuntimeError, "Position to set not specified");
  }
  
  EWAH *bitset;
  Data_Get_Struct(self, EWAH, bitset);
  bitset->bits->set(FIX2INT(position));
  
  return self;
}

extern "C" VALUE ewah_each(VALUE self) {
  EWAH *bitset;
  Data_Get_Struct(self, EWAH, bitset);
  
  for(EWAHBoolArray<uword32>::const_iterator i = bitset->bits->begin(); i != bitset->bits->end(); ++i)
    rb_yield(INT2FIX(*i));
  
  return Qnil;
}

extern "C" VALUE ewah_swap(VALUE self, VALUE other) {
  EWAH *bitset;
  EWAH *obitset;
  Data_Get_Struct(self, EWAH, bitset);
  Data_Get_Struct(other, EWAH, obitset);
  
  bitset->bits->swap(*(obitset->bits));
  
  return self;
}

extern "C" VALUE ewah_reset(VALUE self) {
  EWAH *bitset;
  Data_Get_Struct(self, EWAH, bitset);
  bitset->bits->reset();
  return self;
}

extern "C" VALUE ewah_size_in_bytes(VALUE self) {
  EWAH *bitset;
  Data_Get_Struct(self, EWAH, bitset);
  return INT2FIX(bitset->bits->sizeInBytes());
}

extern "C" VALUE ewah_logical_or(VALUE self, VALUE other) {
  EWAH *bitset;
  EWAH *obitset;
  Data_Get_Struct(self, EWAH, bitset);
  Data_Get_Struct(other, EWAH, obitset);
  
  VALUE klass = rb_const_get(rb_cObject, rb_intern("EwahBitset"));
  VALUE newBitset = rb_class_new_instance(0, 0, klass);
  
  EWAH *newBits;
  Data_Get_Struct(newBitset, EWAH, newBits);
  bitset->bits->logicalor(*(obitset->bits), *(newBits->bits));
  
  return newBitset;
}

extern "C" VALUE ewah_logical_and(VALUE self, VALUE other) {
  EWAH *bitset;
  EWAH *obitset;
  Data_Get_Struct(self, EWAH, bitset);
  Data_Get_Struct(other, EWAH, obitset);
  
  VALUE klass = rb_const_get(rb_cObject, rb_intern("EwahBitset"));
  VALUE newBitset = rb_class_new_instance(0, 0, klass);
  
  EWAH *newBits;
  Data_Get_Struct(newBitset, EWAH, newBits);
  bitset->bits->logicaland(*(obitset->bits), *(newBits->bits));
  
  return newBitset;
}


static VALUE rb_cC;
extern "C" void Init_ewahbitset() {
  rb_cC = rb_define_class("EwahBitset", rb_cObject);
  rb_define_singleton_method(rb_cC, "new", (ruby_method*) &ewah_new, 0);
  rb_define_method(rb_cC, "initialize", (ruby_method*) &ewah_init, 0);
  rb_define_method(rb_cC, "set", (ruby_method*) &ewah_set, 1);
  rb_define_method(rb_cC, "each", (ruby_method*) &ewah_each, 0);
  rb_define_method(rb_cC, "swap", (ruby_method*) &ewah_swap, 1);
  rb_define_method(rb_cC, "reset", (ruby_method*) &ewah_reset, 0);
  rb_define_method(rb_cC, "logical_or", (ruby_method*) &ewah_logical_or, 1);
  rb_define_method(rb_cC, "logical_and", (ruby_method*) &ewah_logical_and, 1);
  // rb_define_method(rb_cC, "serialize", ewah_serialize, 1);
  // rb_define_method(rb_cC, "deserialize", ewah_deserialize, 1);
  
  rb_define_method(rb_cC, "size_in_bytes", (ruby_method*) ewah_size_in_bytes, 0);
}