#pragma once
#include "Core.h"

void InitConsoleBuffer();
void FlipConsoleBuffer();
void PrintConsoleBuffer(int x, int y, std::string s);
void ReleaseConsoleBuffer();
void RenderConsole(std::string s);
void SetFontSizeBig();
void TextSizeSetUp();


