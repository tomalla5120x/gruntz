# Gruntz Recreation

This is an attempt of recreating the source code of the 1999 puzzle game named "Gruntz".

This repository is merely a storage space. Don't take anything for granted here - anything here may change at any time without any warning (including project structure, names of the files, classes etc). I also realize that recreating the game is a full-time job for at least a year or two if not more. That's why I don't make any promises - **the project may even not be finished at all**. Take that in mind.

The source code is aimed to be an almost one-to-one functional equivalent of the original assembly. As a consequence:
* the source code contains all original calls to deprecated and/or unsafe functions,
* all the bugs have been recreated as closely as possible.

The recreation was based on: 
* Gruntz 1.0.1.77 (patched English version).
* Executable MD5: 199d4613e4587e1d720623dc11569e4d
* Executable SHA256: ef636e84cd547efe3e835811aefa6cd20964dadb9c2b427aa13860e52b2228d4

The game has been originally compiled with Microsoft Visual C++ compiler (VC6 or earlier - based on a magic number in exception handling structures). Here are the libraries used by the game:
* WinAPI
* MFC (statically linked)
* DirectDraw
* Miles Sound System (statically linked) - responsible for the playback of music
* Smacker (dynamically linked) - part of the RAD Game Tools suite responsible for playback of videos
* WAP32 (Windows Animation Package) - the game engine created by Brian Goble - the Programming God:tm: at Monolith.

Obviously the C standard library functions haven't been rewritten from scratch but matched with existing (current) ones instead. Same applies to MFC functions and classes (see below for details).

The recreation project is being made using Microsoft Visual Studio Community 2019. At the moment of this writing (30.07.2020) the project successfully compiles and includes:
* the check for the Gruntz CD in the drive,
* reading some resources from the binary,
* the advanced options dialog.

## Project structure

The beginnings of the recreation project are simple - there's no structure and files seem more like "bags" for functions and global variables. As the reversing process progresses I group the symbols with similar functionality together to make them more manageable.

The names for all the folders, files, variables, functions, methods, constants, structures, classes - most of them are not a part of the original binary and are solely a result of my intuition. The fields are being filled with data from a file name "large.fnt"? Let's name the class "Font". The purpose of the class is not discovered just yet but it contains a few peculiar object arrays? Just name it "UnknownClassWithPeculiarArrays" until it clarifies later. It may sound silly but it helps to remember them later on. The following are the exceptions:
* names of the classes may have RTTI (Run-Time Type Information) data baked into the binary. They include the mangled names of each class and their inheritance hierarchy. They are reflected one-to-one in the source code.
* many structures, classes and functions have been matched using MSDN (which is an invaluable source for anything WinAPI- and MFC-related) and the source code of the MFC library.
* the game itself has some diagnostic messages which include class and file names.

As a rule of thumb: if the name of a class starts with a "C" prefix - the name is most likely original. The Gruntz source code closely follows the MFC naming convention and prepends most (if not all) class names with that preposterous letter. So you'll see classes like: CGameApp, CGruntzWnd, CGruntzMgr etc.

## Annotations

The source code is being thoroughly annotated to ease the reversing process. The following are examples of such annotations:
* **@address** - an address for a given element in the original binary - a function definition, a global/static variable etc. Some functions may have been inlined in the binary - most of the times they're annotated with "@address: inlined" or something like that.
* **@offset** - offset of the field in the structure
* **@bug** - bugs deliberately recreated from the original binary
* **@legacy** - code which may run differently on newer windows operating systems
* **@todo** - functions yet to be recreated
* **@vftable** - offset of the virtual method in the virtual functions table of the object

## Other notes


The C++ "new" operator is overloaded by MFC and throws a CMemoryException pointer. The code in the binary doesn't seem to catch it in any way so when out of memory happens the application simply crashes. However the pointer returned by the new operator is often compared to NULL and depending on that some custom error handling is employed. I've simulated a few out-of-memory situations and as I suspected the game just crashes with a CMemoryException and the NULL check never happens. It's hard for me to tell whether it's a bug or not. Nonetheless I tried to leave those NULL checks in as they were in the binary originally even though they may never be hit.