#include <nan.h>

using v8::FunctionTemplate;

NAN_METHOD(value) {
  info.GetReturnValue().Set(Nan::New("Return a string").ToLocalChecked());
}

NAN_MODULE_INIT(InitAll) {
  // this creates a method name "value" line 13
  Nan::Set(
    target, 
    Nan::New("value").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(value)).ToLocalChecked()
  );
}

// hello here refers to the name of this file.
NODE_MODULE(hello, InitAll)