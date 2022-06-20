# WordPad

This repo is an attempt to maintain the WordPad source code and keep it useful and relevant.

## Building

To compile, you'll need Visual C++ 2005 or newer.  Make sure you have MFC support installed.  Compile by running NMAKE (or YMAKE for parallel compilation.)

## Contributing

Please keep contributions in the style and spirit of the existing code, and ensure changes build on Visual C++ 2005 or newer.

## License

This code is available under the same license as the sample code, MIT + All rights reserved.

## History

The WordPad source code has been included as a sample in compilers since 1995 under restrictive terms.  These samples are now available under the MIT license, including the version bundled with Visual C++ 2008 and 2010.  This source is a fork of the [most recent code from the 2010 compiler](https://github.com/microsoft/VCSamples/tree/master/VC2010Samples/MFC/ole/wordpad).

## Changes

- Add MIT license to compiled binaries, which is required by the license
- Compile only for Unicode
- Uses RichEdit 2.0 rather than 1.0
