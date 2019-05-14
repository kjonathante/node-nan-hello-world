#include <nan.h>

using v8::FunctionTemplate;
using v8::Isolate;
using v8::Exception;
using v8::String;
using v8::NewStringType;
using v8::Local;
using v8::Value;

NAN_METHOD(value) {
  info.GetReturnValue().Set(
    Nan::New("Hello World").ToLocalChecked()
  );
}

NAN_METHOD(display) {
  Isolate* isolate = info.GetIsolate();

  // Check the number of arguments passed.
  if (info.Length() < 1) {
    // Throw an Error that is passed back to JavaScript
    isolate->ThrowException(
      Exception::TypeError(
        String::NewFromUtf8(
          isolate,
          "Wrong number of arguments",
          NewStringType::kNormal
        ).ToLocalChecked()
      )
    );
    return;
  }
  // info.GetReturnValue().Set(
  //  Nan::New("This is a thing.").ToLocalChecked()
  // );
  info.GetReturnValue().Set( 
    Nan::New( *Nan::Utf8String( info[0] )).ToLocalChecked()
  );
}

NAN_MODULE_INIT(InitAll) {
  // this creates a method name "value" line 13
  Nan::Set(
    target, 
    Nan::New("value").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(value)).ToLocalChecked()
  );
  Nan::Set(
    target, 
    Nan::New("display").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(display)).ToLocalChecked()
  );
}

// hello here refers to the name of this file.
NODE_MODULE(hello, InitAll)