#include <csetjmp>
#include <cstdio>

#include <zlib/zlib.h> // Must be include the first because Byte definition is ambigous...
extern "C" {
#include <jpeglib/jpeglib.h> // Must be include the first because boolean definition is ambigous...
}

#include <Pcf/System/IO/File.h>
#include "../../../../Includes/Pcf/System/Drawing/Image.h"

#include "Bmp.h"
#include "Gif.h"
#if _WIN32
#pragma warning(push)
#pragma warning(disable:4324)
#pragma warning(disable:4611)
#endif
#include "Jpg.h"
#include "Png.h"
#if _WIN32
#pragma warning(pop)
#endif
#include "Tif.h"

using namespace System;
using namespace System::Drawing;
using namespace System::IO;

const Image Image::None;

Image::Image() {
}

Image::Image(System::IO::Stream& stream) {
  ReadStream(stream);
}

Image::Image(const string& fileName) {
  FileStream fs = File::Open(fileName, FileMode::Open, FileAccess::Read);
  ReadStream(fs);
}

Image::Image(const Image& image) : flags(image.flags), frameDimensionList(image.frameDimensionList), horizontalResolution(image.horizontalResolution), pixelFormat(image.pixelFormat), palette(image.palette), rawData(image.rawData), rawFormat(image.rawFormat), size(image.size), tag(image.tag), verticalResolution(image.verticalResolution) {
}

UniquePointer<Image> Image::FromFile(const string& fileName) {
  return new Image(fileName);
}

UniquePointer<Image> Image::FromStream(System::IO::Stream& stream) {
  return new Image(stream);
}

UniquePointer<Image> Image::FromData(const char* data[]) {
  UniquePointer<Image> image = new Image();
  
  Array<string> infos = string(data[0]).Split(' ');
  int32 columns = Int32::Parse(infos[0]);
  int32 rows = Int32::Parse(infos[1]);
  int32 colors = Int32::Parse(infos[2]);
  int32 charPerPixel = Int32::Parse(infos[3]);
  
  System::Collections::Generic::Dictionary<String, Color> palette;
  
  for (int32 i = 0; i < colors; i++) {
    string colorLine(data[1+i]);
    if (colorLine.Contains("None"))
      palette[colorLine.Substring(0, charPerPixel)] = Color::Transparent;
    else
      palette[colorLine.Substring(0, charPerPixel)] = Color::FromArgb(255, Int32::Parse(colorLine.Substring(4+charPerPixel, 2), 16), Int32::Parse(colorLine.Substring(6+charPerPixel, 2), 16), Int32::Parse(colorLine.Substring(8+charPerPixel, 2), 16));
  }
  
  image->rawData = Array<byte>(columns * rows * 3);
  
  for (int32 i = 0; i < rows; i++) {
    string colorLine(data[1+colors+i]);
    for (int32 j = 0; j < columns; j++) {
      string pixel = colorLine.Substring(0, charPerPixel);
      colorLine = colorLine.Remove(0, charPerPixel);
      image->rawData[(i*columns*3)+(j*3)] = static_cast<byte>(palette[pixel].R());
      image->rawData[(i*columns*3)+(j*3)+1] = static_cast<byte>(palette[pixel].G());
      image->rawData[(i*columns*3)+(j*3)+2] = static_cast<byte>(palette[pixel].B());
    }
  }
 
  image->flags = Imaging::ImageFlags::ReadOnly | Imaging::ImageFlags::HasRealPixelSize | Imaging::ImageFlags::HasRealDpi | Imaging::ImageFlags::ColorSpaceRgb;
  image->frameDimensionList = {Imaging::FrameDimension::Page().Guid};
  //image->horizontalResolution = Convert::ToSingle(bmpInfo.xPixelsPerMeter) / inchesPerMeter;
  image->pixelFormat = Imaging::PixelFormat::Format24bppRgb;
  //image->verticalResolution = Convert::ToSingle(bmpInfo.yPixelsPerMeter) / inchesPerMeter;
  image->size = System::Drawing::Size(columns, rows);
  image->rawFormat = Imaging::ImageFormat::MemoryBmp;
  
  return image;
}

void Image::ReadStream(System::IO::Stream& stream) {
  UniquePointer<BinaryReader> reader = new BinaryReader(stream);
  
  uint16 magicNumber = reader->ReadUInt16();
  reader->BaseStream().Seek(0, Pcf::System::IO::SeekOrigin::Begin);
  
  // List of file signatures
  // http://en.wikipedia.org/wiki/List_of_file_signatures
  
  switch (magicNumber) {
    case 0x4D42: Bmp(stream).Read(*this); break;
    case 0xD8FF: Jpg(stream).Read(*this); break;
    case 0x4947: Gif(stream).Read(*this); break;
    case 0x5089: Png(stream).Read(*this); break;
    case 0x4949: Tif(stream).Read(*this); break;
    case 0x4D4D: Tif(stream).Read(*this); break;
    default: throw OutOfMemoryException(pcf_current_information); break;
  }
}
