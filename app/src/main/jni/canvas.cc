#include "canvas.h"

using namespace v8;
using namespace node;
using namespace std;

canvas::ContextFactory *CanvasRenderingContext2D::canvasContextFactory;

Handle<Object> CanvasRenderingContext2D::Initialize(Isolate *isolate, canvas::ContextFactory *canvasContextFactory) {
  v8::EscapableHandleScope scope(isolate);

  // constructor
  Local<FunctionTemplate> ctor = Nan::New<FunctionTemplate>(New);
  // Local<FunctionTemplate> ctor = Nan::New<FunctionTemplate>(New);
  ctor->InstanceTemplate()->SetInternalFieldCount(1);
  ctor->SetClassName(JS_STR("CanvasRenderingContext2D"));

  // prototype
  // Nan::SetPrototypeMethod(ctor, "save",save);// NODE_SET_PROTOTYPE_METHOD(ctor, "save", save);
  Local<ObjectTemplate> proto = ctor->PrototypeTemplate();

  Nan::SetAccessor(proto,JS_STR("width"), WidthGetter);
  Nan::SetAccessor(proto,JS_STR("height"), HeightGetter);
  Nan::SetAccessor(proto,JS_STR("lineWidth"), LineWidthGetter, LineWidthSetter);
  Nan::SetAccessor(proto,JS_STR("fillStyle"), FillStyleGetter, FillStyleSetter);
  Nan::SetAccessor(proto,JS_STR("strokeStyle"), StrokeStyleGetter, StrokeStyleSetter);
  Nan::SetMethod(proto,"scale", Scale);
  Nan::SetMethod(proto,"rotate", Rotate);
  Nan::SetMethod(proto,"translate", Translate);
  Nan::SetMethod(proto,"transform", Transform);
  Nan::SetMethod(proto,"setTransform", SetTransform);
  Nan::SetMethod(proto,"resetTransform", ResetTransform);
  Nan::SetMethod(proto,"measureText", MeasureText);
  Nan::SetMethod(proto,"beginPath", BeginPath);
  Nan::SetMethod(proto,"closePath", ClosePath);
  Nan::SetMethod(proto,"clip", Clip);
  Nan::SetMethod(proto,"resetClip", ResetClip);
  Nan::SetMethod(proto,"stroke", Stroke);
  Nan::SetMethod(proto,"fill", Fill);
  Nan::SetMethod(proto,"moveTo", MoveTo);
  Nan::SetMethod(proto,"lineTo", LineTo);
  Nan::SetMethod(proto,"arc", Arc);
  Nan::SetMethod(proto,"arcTo", ArcTo);
  Nan::SetMethod(proto,"rect", Rect);
  Nan::SetMethod(proto,"fillRect", FillRect);
  Nan::SetMethod(proto,"strokeRect", StrokeRect);
  Nan::SetMethod(proto,"clearRect", ClearRect);
  Nan::SetMethod(proto,"fillText", FillText);
  Nan::SetMethod(proto,"strokeText", StrokeText);
  Nan::SetMethod(proto,"drawImage", DrawImage);
  Nan::SetMethod(proto,"createImageData", CreateImageData);
  Nan::SetMethod(proto,"getImageData", GetImageData);
  // Nan::SetAccessor(proto,JS_STR("src"), SrcGetter, SrcSetter);
  // Nan::Set(target, JS_STR("Image"), ctor->GetFunction());

  // constructor_template.Reset(Isolate::GetCurrent(), ctor->GetFunction());

  CanvasRenderingContext2D::canvasContextFactory = canvasContextFactory;

  return scope.Escape(ctor->GetFunction());
}

int CanvasRenderingContext2D::GetWidth() {
  return context->getWidth();
}

int CanvasRenderingContext2D::GetHeight() {
  return context->getHeight();
}

void CanvasRenderingContext2D::Scale(double x, double y) {
  context->scale(x, y);
}

void CanvasRenderingContext2D::Rotate(double angle) {
  context->rotate(angle);
}

void CanvasRenderingContext2D::Translate(double x, double y) {
  context->translate(x, y);
}

void CanvasRenderingContext2D::Transform(double a, double b, double c, double d, double e, double f) {
  context->transform(a, b, c, d, e, f);
}

void CanvasRenderingContext2D::SetTransform(double a, double b, double c, double d, double e, double f) {
  context->setTransform(a, b, c, d, e, f);
}

void CanvasRenderingContext2D::ResetTransform() {
  context->resetTransform();
}

double CanvasRenderingContext2D::MeasureText(const std::string &text) {
  return context->measureText(text).width;
}

void CanvasRenderingContext2D::BeginPath() {
  context->beginPath();
}

void CanvasRenderingContext2D::ClosePath() {
  context->closePath();
}

void CanvasRenderingContext2D::Clip() {
  context->clip();
}

void CanvasRenderingContext2D::ResetClip() {
  context->resetClip();
}

void CanvasRenderingContext2D::Stroke() {
  context->stroke();
}

void CanvasRenderingContext2D::Stroke(Path2D &path2d) {
  context->stroke(*path2d.path2d);
}

void CanvasRenderingContext2D::Fill() {
  context->fill();
}

void CanvasRenderingContext2D::Fill(Path2D &path2d) {
  context->fill(*path2d.path2d);
}

void CanvasRenderingContext2D::MoveTo(double x, double y) {
  context->moveTo(x, y);
}

void CanvasRenderingContext2D::LineTo(double x, double y) {
  context->lineTo(x, y);
}

void CanvasRenderingContext2D::Arc(double x, double y, double radius, double startAngle, double endAngle, double anticlockwise) {
  context->arc(x, y, radius, startAngle, endAngle, anticlockwise);
}

void CanvasRenderingContext2D::ArcTo(double x1, double y1, double x2, double y2, double radius) {
  context->arcTo(x1, y1, x2, y2, radius);
}

void CanvasRenderingContext2D::Rect(double x, double y, double w, double h) {
  context->rect(x, y, w, h);
}

void CanvasRenderingContext2D::FillRect(double x, double y, double w, double h) {
  context->fillRect(x, y, w, h);
}

void CanvasRenderingContext2D::StrokeRect(double x, double y, double w, double h) {
  context->strokeRect(x, y, w, h);
}

void CanvasRenderingContext2D::ClearRect(double x, double y, double w, double h) {
  context->clearRect(x, y, w, h);
}

void CanvasRenderingContext2D::FillText(const std::string &text, double x, double y) {
  context->fillText(text, x, y);
}

void CanvasRenderingContext2D::StrokeText(const std::string &text, double x, double y) {
  context->strokeText(text, x, y);
}

void CanvasRenderingContext2D::DrawImage(const CanvasRenderingContext2D &otherContext, double x, double y, double w, double h) {
  context->drawImage(*otherContext.context, x, y, w, h);
}

void CanvasRenderingContext2D::DrawImage(const Image &image, double x, double y, double w, double h) {
  context->drawImage(*image.image, x, y, w, h);
}

void CanvasRenderingContext2D::DrawImage(const ImageData &imageData, double x, double y, double w, double h) {
  context->drawImage(*imageData.imageData, x, y, w, h);
}

void CanvasRenderingContext2D::DrawImage(const ImageBitmap &imageBitmap, double x, double y, double w, double h) {
  context->drawImage(*imageBitmap.imageData, x, y, w, h);
}

void CanvasRenderingContext2D::Save() {
  context->save();
}

void CanvasRenderingContext2D::Restore() {
  context->restore();
}

NAN_METHOD(CanvasRenderingContext2D::New) {
  Nan::HandleScope scope;

  unsigned int width = info[0]->Uint32Value();
  unsigned int height = info[1]->Uint32Value();
  CanvasRenderingContext2D *context = new CanvasRenderingContext2D(width, height);
  context->Wrap(info.This());
  info.GetReturnValue().Set(info.This());
}

NAN_GETTER(CanvasRenderingContext2D::WidthGetter) {
  Nan::HandleScope scope;

  CanvasRenderingContext2D *context = ObjectWrap::Unwrap<CanvasRenderingContext2D>(info.This());

  info.GetReturnValue().Set(JS_INT(context->GetWidth()));
}

NAN_GETTER(CanvasRenderingContext2D::HeightGetter) {
  Nan::HandleScope scope;

  CanvasRenderingContext2D *context = ObjectWrap::Unwrap<CanvasRenderingContext2D>(info.This());

  info.GetReturnValue().Set(JS_INT(context->GetHeight()));
}

NAN_GETTER(CanvasRenderingContext2D::LineWidthGetter) {
  Nan::HandleScope scope;

  CanvasRenderingContext2D *context = ObjectWrap::Unwrap<CanvasRenderingContext2D>(info.This());

  info.GetReturnValue().Set(JS_FLOAT(context->context->lineWidth.get()));
}

NAN_SETTER(CanvasRenderingContext2D::LineWidthSetter) {
  Nan::HandleScope scope;

  CanvasRenderingContext2D *context = ObjectWrap::Unwrap<CanvasRenderingContext2D>(info.This());
  float angle = info.Data()->NumberValue();

  context->context->lineWidth = angle;
}

NAN_GETTER(CanvasRenderingContext2D::FillStyleGetter) {
  // nothing
}

NAN_SETTER(CanvasRenderingContext2D::FillStyleSetter) {
  Nan::HandleScope scope;

  CanvasRenderingContext2D *context = ObjectWrap::Unwrap<CanvasRenderingContext2D>(info.This());
  v8::String::Utf8Value text(info.Data());
  std::string fillStyle(*text, text.length());

  context->context->fillStyle = fillStyle;
}

NAN_GETTER(CanvasRenderingContext2D::StrokeStyleGetter) {
  // nothing
}

NAN_SETTER(CanvasRenderingContext2D::StrokeStyleSetter) {
  Nan::HandleScope scope;

  CanvasRenderingContext2D *context = ObjectWrap::Unwrap<CanvasRenderingContext2D>(info.This());
  v8::String::Utf8Value text(info.Data());
  std::string strokeStyle(*text, text.length());

  context->context->strokeStyle = strokeStyle;
}

NAN_METHOD(CanvasRenderingContext2D::Scale) {
  Nan::HandleScope scope;

  CanvasRenderingContext2D *context = ObjectWrap::Unwrap<CanvasRenderingContext2D>(info.This());
  double x = info[0]->NumberValue();
  double y = info[1]->NumberValue();

  context->Scale(x, y);
}

NAN_METHOD(CanvasRenderingContext2D::Rotate) {
  Nan::HandleScope scope;

  CanvasRenderingContext2D *context = ObjectWrap::Unwrap<CanvasRenderingContext2D>(info.This());
  double angle = info[0]->NumberValue();

  context->Rotate(angle);
}

NAN_METHOD(CanvasRenderingContext2D::Translate) {
  Nan::HandleScope scope;

  CanvasRenderingContext2D *context = ObjectWrap::Unwrap<CanvasRenderingContext2D>(info.This());
  double x = info[0]->NumberValue();
  double y = info[1]->NumberValue();

  context->Translate(x, y);
}

NAN_METHOD(CanvasRenderingContext2D::Transform) {
  Nan::HandleScope scope;

  CanvasRenderingContext2D *context = ObjectWrap::Unwrap<CanvasRenderingContext2D>(info.This());
  double a = info[0]->NumberValue();
  double b = info[1]->NumberValue();
  double c = info[2]->NumberValue();
  double d = info[3]->NumberValue();
  double e = info[4]->NumberValue();
  double f = info[5]->NumberValue();

  context->Transform(a, b, c, d, e, f);
}

NAN_METHOD(CanvasRenderingContext2D::SetTransform) {
  Nan::HandleScope scope;

  CanvasRenderingContext2D *context = ObjectWrap::Unwrap<CanvasRenderingContext2D>(info.This());
  double a = info[0]->NumberValue();
  double b = info[1]->NumberValue();
  double c = info[2]->NumberValue();
  double d = info[3]->NumberValue();
  double e = info[4]->NumberValue();
  double f = info[5]->NumberValue();

  context->SetTransform(a, b, c, d, e, f);
}

NAN_METHOD(CanvasRenderingContext2D::ResetTransform) {
  Nan::HandleScope scope;

  CanvasRenderingContext2D *context = ObjectWrap::Unwrap<CanvasRenderingContext2D>(info.This());

  context->ResetTransform();
}

NAN_METHOD(CanvasRenderingContext2D::MeasureText) {
  Nan::HandleScope scope;

  CanvasRenderingContext2D *context = ObjectWrap::Unwrap<CanvasRenderingContext2D>(info.This());
  v8::String::Utf8Value text(info[0]);
  std::string string(*text, text.length());
  double width = context->MeasureText(string);

  Local<Object> result = Object::New(Isolate::GetCurrent());
  result->Set(JS_STR("width"), JS_FLOAT(width));

  info.GetReturnValue().Set(result);
}

NAN_METHOD(CanvasRenderingContext2D::BeginPath) {
  Nan::HandleScope scope;

  CanvasRenderingContext2D *context = ObjectWrap::Unwrap<CanvasRenderingContext2D>(info.This());

  context->BeginPath();
}

NAN_METHOD(CanvasRenderingContext2D::ClosePath) {
  Nan::HandleScope scope;

  CanvasRenderingContext2D *context = ObjectWrap::Unwrap<CanvasRenderingContext2D>(info.This());

  context->ClosePath();
}

NAN_METHOD(CanvasRenderingContext2D::Clip) {
  Nan::HandleScope scope;

  CanvasRenderingContext2D *context = ObjectWrap::Unwrap<CanvasRenderingContext2D>(info.This());

  context->Clip();
}

NAN_METHOD(CanvasRenderingContext2D::ResetClip) {
  Nan::HandleScope scope;

  CanvasRenderingContext2D *context = ObjectWrap::Unwrap<CanvasRenderingContext2D>(info.This());

  context->ResetClip();
}

NAN_METHOD(CanvasRenderingContext2D::Stroke) {
  Nan::HandleScope scope;

  CanvasRenderingContext2D *context = ObjectWrap::Unwrap<CanvasRenderingContext2D>(info.This());

  if (info[0]->BooleanValue() && info[0]->ToObject()->Get(JS_STR("constructor"))->ToObject()->Get(JS_STR("name"))->StrictEquals(JS_STR("Path2D"))) {
    Path2D *path2d = ObjectWrap::Unwrap<Path2D>(Local<Object>::Cast(info[0]));

    context->Stroke(*path2d);
  } else {
    context->Stroke();
  }
}

NAN_METHOD(CanvasRenderingContext2D::Fill) {
  Nan::HandleScope scope;

  CanvasRenderingContext2D *context = ObjectWrap::Unwrap<CanvasRenderingContext2D>(info.This());

  if (info[0]->BooleanValue() && info[0]->ToObject()->Get(JS_STR("constructor"))->ToObject()->Get(JS_STR("name"))->StrictEquals(JS_STR("Path2D"))) {
    Path2D *path2d = ObjectWrap::Unwrap<Path2D>(Local<Object>::Cast(info[0]));

    context->Fill(*path2d);
  } else {
    context->Fill();
  }
}

NAN_METHOD(CanvasRenderingContext2D::MoveTo) {
  Nan::HandleScope scope;

  CanvasRenderingContext2D *context = ObjectWrap::Unwrap<CanvasRenderingContext2D>(info.This());
  double x = info[0]->NumberValue();
  double y = info[1]->NumberValue();

  context->MoveTo(x, y);
}

NAN_METHOD(CanvasRenderingContext2D::LineTo) {
  Nan::HandleScope scope;

  CanvasRenderingContext2D *context = ObjectWrap::Unwrap<CanvasRenderingContext2D>(info.This());
  double x = info[0]->NumberValue();
  double y = info[1]->NumberValue();

  context->LineTo(x, y);
}

NAN_METHOD(CanvasRenderingContext2D::Arc) {
  Nan::HandleScope scope;

  CanvasRenderingContext2D *context = ObjectWrap::Unwrap<CanvasRenderingContext2D>(info.This());
  double x = info[0]->NumberValue();
  double y = info[1]->NumberValue();
  double radius = info[2]->NumberValue();
  double startAngle = info[3]->NumberValue();
  double endAngle = info[4]->NumberValue();
  double anticlockwise = info[5]->NumberValue();

  context->Arc(x, y, radius, startAngle, endAngle, anticlockwise);
}

NAN_METHOD(CanvasRenderingContext2D::ArcTo) {
  Nan::HandleScope scope;

  CanvasRenderingContext2D *context = ObjectWrap::Unwrap<CanvasRenderingContext2D>(info.This());
  double x1 = info[0]->NumberValue();
  double y1 = info[1]->NumberValue();
  double x2 = info[2]->NumberValue();
  double y2 = info[3]->NumberValue();
  double radius = info[4]->NumberValue();

  context->ArcTo(x1, y1, x2, y2, radius);
}

NAN_METHOD(CanvasRenderingContext2D::Rect) {
  Nan::HandleScope scope;

  CanvasRenderingContext2D *context = ObjectWrap::Unwrap<CanvasRenderingContext2D>(info.This());
  double x = info[0]->NumberValue();
  double y = info[1]->NumberValue();
  double w = info[2]->NumberValue();
  double h = info[3]->NumberValue();

  context->Rect(x, y, w, h);

  // info.GetReturnValue().Set(JS_INT(image->GetHeight()));
}

NAN_METHOD(CanvasRenderingContext2D::FillRect) {
  Nan::HandleScope scope;

  CanvasRenderingContext2D *context = ObjectWrap::Unwrap<CanvasRenderingContext2D>(info.This());
  double x = info[0]->NumberValue();
  double y = info[1]->NumberValue();
  double w = info[2]->NumberValue();
  double h = info[3]->NumberValue();

  context->FillRect(x, y, w, h);

  // info.GetReturnValue().Set(JS_INT(image->GetHeight()));
}

NAN_METHOD(CanvasRenderingContext2D::StrokeRect) {
  Nan::HandleScope scope;

  CanvasRenderingContext2D *context = ObjectWrap::Unwrap<CanvasRenderingContext2D>(info.This());
  double x = info[0]->NumberValue();
  double y = info[1]->NumberValue();
  double w = info[2]->NumberValue();
  double h = info[3]->NumberValue();

  context->StrokeRect(x, y, w, h);

  // info.GetReturnValue().Set(JS_INT(image->GetHeight()));
}

NAN_METHOD(CanvasRenderingContext2D::ClearRect) {
  Nan::HandleScope scope;

  CanvasRenderingContext2D *context = ObjectWrap::Unwrap<CanvasRenderingContext2D>(info.This());
  double x = info[0]->NumberValue();
  double y = info[1]->NumberValue();
  double w = info[2]->NumberValue();
  double h = info[3]->NumberValue();

  context->ClearRect(x, y, w, h);

  // info.GetReturnValue().Set(JS_INT(image->GetHeight()));
}

NAN_METHOD(CanvasRenderingContext2D::FillText) {
  Nan::HandleScope scope;

  CanvasRenderingContext2D *context = ObjectWrap::Unwrap<CanvasRenderingContext2D>(info.This());
  v8::String::Utf8Value text(info[0]);
  std::string string(*text, text.length());
  double x = info[1]->NumberValue();
  double y = info[2]->NumberValue();

  context->FillText(string, x, y);

  // info.GetReturnValue().Set(JS_INT(image->GetHeight()));
}

NAN_METHOD(CanvasRenderingContext2D::StrokeText) {
  Nan::HandleScope scope;

  CanvasRenderingContext2D *context = ObjectWrap::Unwrap<CanvasRenderingContext2D>(info.This());
  v8::String::Utf8Value text(info[0]);
  std::string string(*text, text.length());
  double x = info[1]->NumberValue();
  double y = info[2]->NumberValue();

  context->StrokeText(string, x, y);

  // info.GetReturnValue().Set(JS_INT(image->GetHeight()));
}

NAN_METHOD(CanvasRenderingContext2D::DrawImage) {
  Nan::HandleScope scope;

  CanvasRenderingContext2D *context = ObjectWrap::Unwrap<CanvasRenderingContext2D>(info.This());
  if (info[0]->ToObject()->Get(JS_STR("constructor"))->ToObject()->Get(JS_STR("name"))->StrictEquals(JS_STR("CanvasRenderingContext2D"))) {
    CanvasRenderingContext2D *otherContext = ObjectWrap::Unwrap<CanvasRenderingContext2D>(Local<Object>::Cast(info[0]));
    double x = info[1]->NumberValue();
    double y = info[2]->NumberValue();
    double w = info[3]->NumberValue();
    double h = info[4]->NumberValue();

    context->DrawImage(*otherContext, x, y, w, h);
  } else if (info[0]->ToObject()->Get(JS_STR("constructor"))->ToObject()->Get(JS_STR("name"))->StrictEquals(JS_STR("HTMLImageElement"))) {
    Image *image = ObjectWrap::Unwrap<Image>(Local<Object>::Cast(info[0]));
    double x = info[1]->NumberValue();
    double y = info[2]->NumberValue();
    double w = info[3]->NumberValue();
    double h = info[4]->NumberValue();

    context->DrawImage(*image, x, y, w, h);
  } else if (info[0]->ToObject()->Get(JS_STR("constructor"))->ToObject()->Get(JS_STR("name"))->StrictEquals(JS_STR("ImageData"))) {
    ImageData *imageData = ObjectWrap::Unwrap<ImageData>(Local<Object>::Cast(info[0]));
    double x = info[1]->NumberValue();
    double y = info[2]->NumberValue();
    double w = info[3]->NumberValue();
    double h = info[4]->NumberValue();

    context->DrawImage(*imageData, x, y, w, h);
  } else if (info[0]->ToObject()->Get(JS_STR("constructor"))->ToObject()->Get(JS_STR("name"))->StrictEquals(JS_STR("ImageBitmap"))) {
    ImageData *imageBitmap = ObjectWrap::Unwrap<ImageData>(Local<Object>::Cast(info[0]));
    double x = info[1]->NumberValue();
    double y = info[2]->NumberValue();
    double w = info[3]->NumberValue();
    double h = info[4]->NumberValue();

    context->DrawImage(*imageBitmap, x, y, w, h);
  }
}

NAN_METHOD(CanvasRenderingContext2D::CreateImageData) {
  Nan::HandleScope scope;

  CanvasRenderingContext2D *context = ObjectWrap::Unwrap<CanvasRenderingContext2D>(Local<Object>::Cast(info.This()));
  double w = info[0]->NumberValue();
  double h = info[1]->NumberValue();

  Isolate *isolate = Isolate::GetCurrent();
  Local<Context> isolateContext = isolate->GetCurrentContext();
  Local<Object> global = isolateContext->Global();
  Local<Function> imageDataConstructor = Local<Function>::Cast(global->Get(JS_STR("ImageData")));
  Local<Value> argv[] = {
    Number::New(isolate, w),
    Number::New(isolate, h),
  };
  Local<Object> imageDataObj = imageDataConstructor->NewInstance(sizeof(argv) / sizeof(argv[0]), argv);

  info.GetReturnValue().Set(imageDataObj);
}

NAN_METHOD(CanvasRenderingContext2D::GetImageData) {
  Nan::HandleScope scope;

  CanvasRenderingContext2D *context = ObjectWrap::Unwrap<CanvasRenderingContext2D>(Local<Object>::Cast(info.This()));
  unsigned int x = info[0]->Uint32Value();
  unsigned int y = info[1]->Uint32Value();
  unsigned int w = info[2]->Uint32Value();
  unsigned int h = info[3]->Uint32Value();

  canvas::Surface &surface = context->context->getDefaultSurface();
  std::unique_ptr<canvas::Image> img(surface.createImage(1));
  const canvas::ImageData &imgData = img->getData();
  const unsigned char *srcData = imgData.getData();
  size_t srcWidth = imgData.getWidth();
  size_t srcHeight = imgData.getHeight();

  Isolate *isolate = Isolate::GetCurrent();
  Local<Context> isolateContext = isolate->GetCurrentContext();
  Local<Object> global = isolateContext->Global();
  Local<Function> imageDataConstructor = Local<Function>::Cast(global->Get(JS_STR("ImageData")));
  Local<Value> argv[] = {
    Number::New(isolate, w),
    Number::New(isolate, h),
  };
  Local<Object> imageDataObj = imageDataConstructor->NewInstance(sizeof(argv) / sizeof(argv[0]), argv);
  ImageData *imageData = ObjectWrap::Unwrap<ImageData>(imageDataObj);
  unsigned char *dstData = imageData->imageData->getData();
  for (size_t i = 0; i < h; i++) {
    memcpy(dstData + (i * w * 4), srcData + (y * srcWidth * 4) + (x * 4), w * 4);
  }

  info.GetReturnValue().Set(imageDataObj);
}

NAN_METHOD(CanvasRenderingContext2D::Save) {
  Nan::HandleScope scope;

  CanvasRenderingContext2D *context = ObjectWrap::Unwrap<CanvasRenderingContext2D>(info.This());

  context->Save();
}

NAN_METHOD(CanvasRenderingContext2D::Restore) {
  Nan::HandleScope scope;

  CanvasRenderingContext2D *context = ObjectWrap::Unwrap<CanvasRenderingContext2D>(info.This());

  context->Restore();
}

CanvasRenderingContext2D::CanvasRenderingContext2D(unsigned int width, unsigned int height) {
  context = CanvasRenderingContext2D::canvasContextFactory->createContext(width, height).release();
}
CanvasRenderingContext2D::~CanvasRenderingContext2D () {
  delete context;
}
