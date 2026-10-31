# PCGPE – The PC Game Programmer's Encyclopedia

The **PC Game Programmer's Encyclopedia (PCGPE)**, also known as **PC-GPE**, is a collection of technical documentation covering PC game programming, graphics, sound, hardware, assembly language, and other topics relevant to DOS-era game development.

This repository contains a modern UTF-8 version of the original documentation, together with a small Linux reader written in C.

## About this project

The original PCGPE documentation was written for the DOS era and uses legacy text encoding. I used [dos2ansi](https://github.com/Zirias/dos2ansi) to convert the documents into modern Unicode (UTF-8) text, making them easier to read, browse, and preserve on modern systems.

The converted documentation has been uploaded to this repository and is available for download.

## The reader

I also started developing a terminal-based reader in C for Linux systems, inspired by the aesthetics of **Turbo Vision**. The idea is to bring back some of the original DOS-era experience, with a nostalgic interface reminiscent of the tools and environments of that time.

The reader currently supports:

- Vertical and horizontal scrolling.
- Screen resizing.
- Top-down menus.
- Browsing the converted documentation.

The application is still a work in progress. Not all menus and document links have been implemented, and I may not eventually finish it.

Nevertheless, I wanted to upload what I had so far, rather than risk this little preservation effort being lost to time.

### Building and running

Clone the repository:

```bash
git clone https://github.com/velorek1/pcgpe.git
cd pcgpe
```

Compile and run:

```bash
make && ./pcgpe
```

## Project status

- [x] Initial conversion of documentation to UTF-8.
- [x] Upload of converted documents.
- [x] Initial Linux reader written in C.
- [x] Basic Turbo Vision-inspired interface.
- [ ] Complete conversion and verification of all documents.
- [ ] Finish menus and document navigation links.
- [ ] Further organisation and cleanup.

The documentation and current reader are available in this repository, even though the project remains unfinished.

## Credits

All credit for the original PCGPE goes to **Mark Feldman**, its original author and compiler.

Original documentation and credits:  
https://www.phatcode.net/articles.php?id=247

Conversion tool:  
[dos2ansi](https://github.com/Zirias/dos2ansi)

## Disclaimer

This repository is an effort to preserve and make the original PCGPE documentation more accessible. The Linux reader and UTF-8 conversion are independent preservation efforts; they do not claim authorship of the original material.

All original work and associated credits belong to Mark Feldman.
