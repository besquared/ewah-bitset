#include <ruby.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef VALUE (ruby_method)(...);

// struct rowdata {
//   VALUE ary;
// };
// 
// void fieldcb(void* str, size_t len, void* data) {
//   VALUE ary = ((struct rowdata *)data)->ary;
//   rb_ary_store(ary, RARRAY_LEN(ary), rb_str_new(str, len));
// }
// 
// void rowcb(int c, void* data) {
//   rb_yield(((struct rowdata *)data)->ary);
//   ((struct rowdata *)data)->ary = rb_ary_new();
// }
// 
// static int is_space(unsigned char c) {
//   if (c == CSV_SPACE || c == CSV_TAB) return 1;
//   return 0;
// }
// 
// static int is_term(unsigned char c) {
//   if (c == CSV_CR || c == CSV_LF) return 1;
//   return 0;
// }
//

extern "C" VALUE ewah_init(VALUE self, VALUE position) {
  
  return self;
}

extern "C" VALUE ewah_set(VALUE self, VALUE position) {
  if (position == NULL) {
    rb_raise(rb_eRuntimeError, "Position to set not specified");
  }
  
  // char buf[1024];
  // size_t bytes_read;
  // struct csv_parser p;
  // unsigned char options = 0;
  // 
  // struct rowdata data;
  // data.ary = rb_ary_new();
  // 
  // if(csv_init(&p, options) != 0) {
  //   rb_raise(rb_eRuntimeError, "Failed to initialize csv parser");
  //   exit(EXIT_FAILURE);
  // }
  // 
  // csv_set_space_func(&p, is_space);
  // csv_set_term_func(&p, is_term);  
  // 
  // while((bytes_read = fread(buf, 1, 1024, file)) > 0) {
  //   if(csv_parse(&p, buf, bytes_read, fieldcb, rowcb, &data) != bytes_read) {
  //     rb_raise(rb_eRuntimeError, "Error while parsing file"); //, csv_strerror(csv_error(&p)));
  //   }
  // }
  // 
  // csv_fini(&p, fieldcb, rowcb, &data);
  // csv_free(&p);
  // 
  // if(ferror(file)) {
  //   fclose(file);
  //   rb_raise(rb_eRuntimeError, "Error while reading file");
  // } else {
  //   fclose(file);
  // }
  //
  return Qnil;
}

static VALUE rb_cC;
extern "C" void Init_rubyewah() {
  rb_cC = rb_define_class("EwahBitset", rb_cObject);
  rb_define_method(rb_cC, "initialize", (ruby_method*) &ewah_init, 0);
  rb_define_method(rb_cC, "set", (ruby_method*) &ewah_set, 1);
  // rb_define_method(rb_cC, "each", ewah_each, 1);
  // rb_define_method(rb_cC, "logical_or", ewah_logical_or, 1);
  // rb_define_method(rb_cC, "logical_and", ewah_logical_and, 1);
  // rb_define_method(rb_cC, "size_in_bytes", ewah_size_in_bytes, 1);
  // rb_define_method(rb_cC, "serialize", ewah_serialize, 1);
  // rb_define_method(rb_cC, "deserialize", ewah_deserialize, 1);
}